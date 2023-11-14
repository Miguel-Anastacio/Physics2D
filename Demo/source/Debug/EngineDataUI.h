#pragma once
#include "UIPanel.h"
#include"Dynamics/Rigidbody.h"
#include <SFML/Graphics/Color.hpp>


class EngineDataUI :  public UIPanel
{
public:
	EngineDataUI(const bool& noMove, const bool& noResize, const bool& noCollapse, const std::string& name, const bool& visible);
	void RenderPanel() override;
	void SetData(float fps, float objCount, float colCount);
	void SetData(const std::vector<Data>& data);

	inline Physics2D::RigidBodyInit GetBodySpecs() const { return m_BodySpecs; }
	inline Physics2D::Vector2 GetBodySize() const { return m_BodySize; }
	inline float GetBodyRadius() const { return m_BodyRadius; }

	inline sf::Color GetCircleColor() const { return m_CircleColor; }
	inline sf::Color  GetAabbColor() const { return m_AabbColor; }
public:
	bool HoveringUI = false;
protected:
	float m_FPS;
	float m_ObjectCount;
	float m_CollisionCount;
	std::vector<Data> m_Data;
	Physics2D::RigidBodyInit m_BodySpecs;
	Physics2D::Vector2 m_BodySize = Physics2D::Vector2(20, 20);
	float m_BodyRadius = 10;

	sf::Color  m_CircleColor = sf::Color(0, 0, 255, 255);
	sf::Color  m_AabbColor = sf::Color(0, 255, 0, 255);
};

