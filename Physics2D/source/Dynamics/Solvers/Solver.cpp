#include "Solver.h"
#include "../../Collision/Colliders/AabbCollider.h"
#include "../../Collision/Colliders/CircleCollider.h"
bool Physics2D::Solver::TestNan(Rigidbody* rb, Rigidbody* rb2, const Collision& collision)
{
	if (collision.body1 == nullptr)
		std::cout << "******** Body " << collision.body1->GetID() << " is null \n";
	if (collision.body2 == nullptr)
		std::cout << "******** Body " << collision.body2->GetID() << " is null \n";

	/*if (std::isnan(collision.Contact.Normal.X))
	{
	*/	collision.Print();
		AabbCollider* temp = dynamic_cast<AabbCollider*>(collision.body1->GetColliderShared().get());
		if (temp != nullptr)
			std::cout << "Body " << collision.body1->GetID() << " is Aabb \n";
		CircleCollider* temp1 = dynamic_cast<CircleCollider*>(collision.body1->GetColliderShared().get());
		if (temp1 != nullptr)
			std::cout << "Body " << collision.body1->GetID() << " is circle\n";

		temp = dynamic_cast<AabbCollider*>(collision.body2->GetColliderShared().get());
		if (temp != nullptr)
			std::cout << "Body " << collision.body2->GetID() << " is aabb \n";
		temp1 = dynamic_cast<CircleCollider*>(collision.body2->GetColliderShared().get());
		if (temp1 != nullptr)
			std::cout << "Body " << collision.body2->GetID() << " is circle\n";

		return true;
	/*}
	else if (std::isnan(collision.Contact.Normal.Y))
	{
		collision.Print();
		return true;
	}*/
	return false;
}