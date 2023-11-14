#include "SmoothPositionSolver.h"
#include "../../Collision/Colliders/AabbCollider.h"
namespace Physics2D
{
	void SmoothPositionSolver::Solve(std::vector<Collision>& collisions, const float& dt)
	{
		for (auto& col : collisions)
		{
			Rigidbody* bodyA = static_cast<Rigidbody*>(col.body1);
			Rigidbody* bodyB = static_cast<Rigidbody*>(col.body2);
			
			const float InvMassA = bodyA ? bodyA->GetInvMass() : 0.0f;
			const float InvMassB = bodyB ? bodyB->GetInvMass() : 0.0f;
			if (InvMassA == 0 && InvMassB == 0)
				break;

			Vector2 resolution = col.Contact.B - col.Contact.A;
			const float percent = 0.4f;
			const float slop = 0.03f;

			Vector2 correction = col.Contact.Normal * percent * std::max(resolution.Magnitude() -slop, 0.0f) / (InvMassA + InvMassB);
			if (bodyA != nullptr && bodyA->IsKinematic())
			{
				bodyA->SetPosition(bodyA->GetPosition() + correction * InvMassA);

			}
			if (bodyB != nullptr && bodyB->IsKinematic())
			{
				bodyB->SetPosition(bodyB->GetPosition() - correction * InvMassB);
			}
			//if ((bodyA != nullptr && bodyA->IsKinematic()) && (bodyB != nullptr && bodyB->IsKinematic()))
			//{
			//	/*********SOME DEBUG STUFF I USED *******/

			//	AabbCollider* temp = dynamic_cast<AabbCollider*>(bodyA->GetColliderShared().get());
			//	AabbCollider* temp1 = dynamic_cast<AabbCollider*>(bodyB->GetColliderShared().get());
			//	if (temp != nullptr && temp1 != nullptr)
			//	{
			//		if(col.Contact.Normal.X != 0)
			//			//TestNan(bodyA, bodyB, col);
			//			int a = 0;
			//		//col.Print()
			//		
			//	}

			//}

		}
	}


}