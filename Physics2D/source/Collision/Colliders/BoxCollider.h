#pragma once
#include "Collider.h"
namespace Physics2D
{
	class BoxCollider : public Collider
	{

	public:
		BoxCollider();
		~BoxCollider();
		/*CollisionPoints TestCollisionBox(const Transform* transform, const BoxShape* box, const Transform* cirlceTransform) override;
		CollisionPoints TestCollisionCircle(const Transform* transform, const CircleShape* cirle, const Transform* cirlceTransform) override;*/
	private:
	};
}
