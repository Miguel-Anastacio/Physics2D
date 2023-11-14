#include "ImpulseSolver.h"
#include "../../Collision/Colliders/AabbCollider.h"
#include "../../Collision/Colliders/CircleCollider.h"
namespace Physics2D
{
	void ImpulseSolver::ApplyImpulse(Rigidbody* rb, const Vector2& normal)
	{
		Vector2 relativeVelocity = rb->GetVelocity();

		float velocityAlongNormal = relativeVelocity.Dot(normal);
		if (velocityAlongNormal > 0)
			return;
		float e = rb->GetRestitution();

		float impulseScalar = -(1 + e) * velocityAlongNormal;
		impulseScalar = impulseScalar / rb->GetInvMass();

		Vector2 impulse = normal * impulseScalar;

		rb->SetVelocity(rb->GetVelocity() + impulse * rb->GetInvMass());

	}
	void ImpulseSolver::ApplyImpulse(Rigidbody* rb, Rigidbody* rb2, const Vector2& normal)
	{
		Vector2 relativeVelocity = rb->GetVelocity() - rb2->GetVelocity();

		float velocityAlongNormal = relativeVelocity.Dot(normal);
		if (velocityAlongNormal > 0)
			return;
		float e = std::min(rb->GetRestitution(), rb2->GetRestitution());

		float impulseScalar = -(1 + e) * velocityAlongNormal;
		impulseScalar = impulseScalar / (rb->GetInvMass() + rb2->GetInvMass());

		Vector2 impulse = normal * impulseScalar;

		float massSum = rb->GetMass() + rb2->GetMass();
		float ratio = rb->GetMass() / massSum;
		float ratio2 = rb2->GetMass() / massSum;

		/*rb->SetVelocity(rb->GetVelocity() + impulse * rb->GetInvMass());
		rb2->SetVelocity(rb2->GetVelocity() - impulse * rb2->GetInvMass());*/
		if(rb->IsKinematic())
			rb->SetVelocity(rb->GetVelocity() + impulse * rb->GetInvMass());
		if(rb2->IsKinematic())
			rb2->SetVelocity(rb2->GetVelocity() - impulse * rb2->GetInvMass());

		// FRICTION

		// re calcualte relative velocity
		relativeVelocity = rb->GetVelocity() - rb2->GetVelocity();
		// solve tangent vector 
		Vector2 tangent = relativeVelocity - (normal * relativeVelocity.Dot(normal));
		tangent.Normalize();

		// flip value since friction is applied in the opposite direction of our velocity
		float frictionScalar = -relativeVelocity.Dot(tangent);
		frictionScalar = frictionScalar / (rb->GetInvMass() + rb2->GetInvMass());
		
		// Coloumb's Law Fi <= muFn
		// Force of friction is less or equal to the normal force multiplied by some constant (mu) c depends on the properties of the objects
		// use vector magnitude C = SquareRoot(sqr(A) +sqr(B)) to set mu
		float mu = Vector2(rb->GetStaticFriction(), rb2->GetStaticFriction()).Magnitude();

		// clamp magnitude of friction and create impulse vector
		Vector2 frictionImpulse;
		
		if (abs(frictionScalar) < impulseScalar * mu)
		{
			// represents when an object is at rest or nearly at rest
			// it requires an "energy of activation" in order for objects to start moving when at complete rest. 
			// When two objects are resting upon one another in real life, it takes a fair amount of energy to push on one and get it moving. 
			// However once you get something sliding it is often easier to keep it sliding from then on.
			frictionImpulse = tangent * frictionScalar ;
		}
		else
		{
			float dynammicFriction = Vector2(rb->GetDynamicFriction(), rb2->GetDynamicFriction()).Magnitude();
			frictionImpulse =  tangent * (-impulseScalar) * dynammicFriction;

		}

		if (rb->IsKinematic())
			rb->SetVelocity(rb->GetVelocity() + frictionImpulse * rb->GetInvMass());
		if (rb2->IsKinematic())
			rb2->SetVelocity(rb2->GetVelocity() - frictionImpulse * rb2->GetInvMass());

		if (rb->IsKinematic() && rb2->IsKinematic())
		{

		}
		/*********SOME DEBUG STUFF I USED *******/

		//AabbCollider* temp = dynamic_cast<AabbCollider*>(rb->GetColliderShared().get());
		//if (temp != nullptr)
		//{
		//	if (rb->GetVelocity().MagnitudeSqr() > 0)
		//	{
		//		int a = 0;
		//	}
		//}
		//else
		//{
		//	temp = dynamic_cast<AabbCollider*>(rb2->GetColliderShared().get());
		//	if (temp != nullptr)
		//	{
		//		if (rb2->GetVelocity().MagnitudeSqr() > 0)
		//		{
		//			int a = 0;
		//		}
		//	}
		//}
	}



	void ImpulseSolver::Solve(std::vector<Collision>& collisions, const float& dt)
	{
		for (auto& col : collisions)
		{
			Rigidbody* rb1 = dynamic_cast<Rigidbody*>(col.body1);
			Rigidbody* rb2 = dynamic_cast<Rigidbody*>(col.body2);
			if (rb1 == nullptr && rb2 == nullptr)
				break;
			// only one of the bodies is a rigidbody
			else if (rb1 != nullptr && rb2 == nullptr)
			{
				if(rb1->IsKinematic())
					ApplyImpulse(rb1, col.Contact.Normal);
			}

			else if (rb1 == nullptr && rb2 != nullptr)
			{
				if(rb2->IsKinematic())
					ApplyImpulse(rb2, col.Contact.Normal);
			}
			else
			{
				ApplyImpulse(rb1, rb2, col.Contact.Normal);
				//TestNan(rb1, rb2, col);
			}

		}
	}
	
}