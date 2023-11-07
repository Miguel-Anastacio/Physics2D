#include "Object.h"
namespace Physics2D
{
    Object::Object(float mass)
        : m_Mass(mass)
    {

    }
    float Object::GetMass()
    {
        return m_Mass;
    }
    Vector2 Object::GetPosition()
    {
        return m_Position;
    }

    Vector2 Object::GetForce()
    {
        return m_Force;
    }

    Vector2 Object::GetVelocity()
    {
        return m_Velocity;
    }
    void Object::SetForce(const Vector2& force)
    {
        m_Force = force;
    }
    void Object::SetPosition(const Vector2& position)
    {
        m_Position = position;
    }
    void Object::SetPosition(const float& x, const float& y)
    {
        m_Position.X = x;
        m_Position.Y = y;
    }
    void Object::SetVelocity(const Vector2& velocity)
    {
        m_Velocity = velocity;
    }
}