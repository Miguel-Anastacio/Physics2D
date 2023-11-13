#include"CollisionBody.h"
#include <iostream>
#include <iostream>
namespace Physics2D
{
	struct Collision
	{
		Collision() {};
		Collision(const Manifold& manifold, CollisionBody* b1, CollisionBody* b2)
		{
			Contact = manifold;
			body1 = b1;
			body2 = b2;
		}
		Manifold Contact;
		CollisionBody* body1;
		CollisionBody* body2;

		void Print() const
		{
			std::cout << "Collision ocurred between bodies: " << body1->GetID() << " and " << body2->GetID() << "\n";
			std::cout << "Body " << body1->GetID() << " Pos: "; body1->GetTransform().Position.Print(); std::cout << "\n";
			std::cout << "Body " << body2->GetID() << " Pos: "; body2->GetTransform().Position.Print(); std::cout << "\n";
			std::cout << "****Contact Points" << "\n";
			std::cout << "	A "; Contact.A.Print(); std::cout << "\n";
			std::cout << "	B "; Contact.B.Print(); std::cout << "\n";
			std::cout << "Normal: "; Contact.Normal.Print(); std::cout << "\n";
			std::cout << "Depth: " << Contact.Depth << "\n";

		}
	};

	struct CollisionPair
	{
		CollisionBody* bodyA;
		CollisionBody* bodyB;
	};

}