#include"CollisionBody.h"
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

		bool operator < (const CollisionPair& other) const
		{
			uint64_t otherHash = std::hash<int>{}((uint64_t)other.bodyA + (uint64_t)other.bodyB + other.bodyA->GetID() + other.bodyB->GetID());
			uint64_t thisHash = std::hash<int>{}((uint64_t)bodyA + (uint64_t)bodyB + bodyA->GetID() + bodyB->GetID());
			//uint64_t thisHash = (uint64_t)bodyA + (uint64_t)bodyB;
			//uint64_t thisHash = std::hash<uint64_t>{}(bodyA->GetID() + bodyB->GetID());

			return (otherHash < thisHash);
		}
		//bool operator<(const CollisionPair& other) const 
		//{
		//	return 

		//}
	};

	struct CollisionPairTest
	{
		CollisionBody* bodyA;
		CollisionBody* bodyB;

		//bool operator < (const CollisionPairTest& other) const
		//{
		//	//uint64_t otherHash = std::hash<int>{}((uint64_t)other.bodyA + (uint64_t)other.bodyB + other.bodyA->GetID() + other.bodyB->GetID());
		//	//uint64_t thisHash = std::hash<int>{}((uint64_t)bodyA + (uint64_t)bodyB + bodyA->GetID() + bodyB->GetID());
		//	uint64_t otherHash = (uint64_t)bodyA + (uint64_t)bodyB << 8;
		//	uint64_t thisHash = (uint64_t)other.bodyA + (uint64_t)other.bodyB << 8;

		//	return (otherHash < thisHash);
		//}
		//bool operator<(const CollisionPair& other) const 
		//{
		//	return 

		//}
	};

	static bool SortPairs(const CollisionPair& lhs, const CollisionPair& rhs)
	{
		if (lhs.bodyA->GetID() < rhs.bodyA->GetID())
		{
			return true;
		}
		if (lhs.bodyA->GetID() == rhs.bodyA->GetID())
			return lhs.bodyB->GetID() < rhs.bodyB->GetID();

		return false;
	}
}