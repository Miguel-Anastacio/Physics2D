#include "EngineDataUI.h"
#include "../Utils.hpp"
EngineDataUI::EngineDataUI(const bool& noMove, const bool& noResize, const bool& noCollapse, const std::string& name, const bool& visible)
	: UIPanel(noMove, noResize, noCollapse, name, visible)
{
    ContentsVisibility = true;
}

void EngineDataUI::RenderPanel()
{
    if (Visibility)
    {
        ImGui::Begin(Name.c_str(), nullptr, window_flags);
        ImVec2 panelPos = ImGui::GetCursorScreenPos();
        ImVec2 panelSize = ImGui::GetContentRegionAvail();

        if (ImGui::IsMouseHoveringRect(panelPos, ImVec2(panelPos.x + panelSize.x, panelPos.y + panelSize.y)))
        {
            HoveringUI = true;
        }
        else
        {
            HoveringUI = false;
        }
        if (ContentsVisibility)
        {
         /*   ImGui::Text("FPS: ");
            ImGui::Text("Object Count: ");
            ImGui::Text("Collisions Detected: ");*/
            for (const auto& data : m_Data)
            {
                ImGui::Text(data.Text.c_str());
                ImGui::SameLine();
                ImGui::Text("%.2f", data.Value);
            }

            static bool isKinematic = false;

            if (ImGui::CollapsingHeader("Next Body Spawn", true))
            {
                // set kinematic
                ImGui::Checkbox("Kinematic", &m_BodySpecs.Kinematic);
                // set material
                ImGui::InputFloat("Restitution", &m_BodySpecs.Material.Restitution);
                ImGui::InputFloat("Density", &m_BodySpecs.Material.Density, 0.1, 1.0f);
                // set initial velocity
                float temp[2] = { m_BodySpecs.Velocity.X, m_BodySpecs.Velocity.Y };
                ImGui::InputFloat2("Initial Velocity", temp, "%.0f");
                m_BodySpecs.Velocity = Physics2D::Vector2(temp[0], temp[1]);
                // set apply force at start
                float temp1[2] = { m_BodySpecs.InitialForce.X, m_BodySpecs.InitialForce.Y };
                ImGui::InputFloat2("Initial Force", temp1, "%.0f");
                m_BodySpecs.InitialForce = Physics2D::Vector2(temp1[0], temp1[1]);
                // set friction
                ImGui::InputFloat("Static Friction", &m_BodySpecs.StaticFriction);
                ImGui::InputFloat("Dynamic Friction", &m_BodySpecs.DynamicFriction);
                // set gravity scale
                ImGui::InputFloat("Gravity Scale", &m_BodySpecs.GravityScale,0.0, .0f, "%.2f");

                if (ImGui::TreeNode("Shape"))
                {
                    if (ImGui::TreeNode("Box"))
                    {
                        // set size
                        float temp2[2] = { m_BodySize.X, m_BodySize.Y };
                        ImGui::InputFloat2("Size", temp2, "%.0f");
                        m_BodySize = Physics2D::Vector2(temp2[0], temp2[1]);
                        ImGui::SetNextItemWidth(150);
                        ImVec4 tempColor = SFMLColorToImVec4(m_AabbColor);
                        ImGui::ColorPicker4("##picker", (float*)&tempColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);

                        m_AabbColor = ImVec4ToSFMLColor(tempColor);
                        ImGui::TreePop();
                    }
                    if (ImGui::TreeNode("Circle"))
                    {
                        // set size

                        ImGui::InputFloat("Radius", &m_BodyRadius,0.0, 0.0, "%.0f");
                        ImGui::SetNextItemWidth(150);
                        ImVec4 tempColor = SFMLColorToImVec4(m_CircleColor);
                        ImGui::ColorPicker4("##picker1", (float*)&tempColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
      
                        m_CircleColor = ImVec4ToSFMLColor(tempColor);

                        ImGui::TreePop();
                    }
                    ImGui::TreePop();
                }

            }

        }
        // actual panel render here

        ImGui::End();
    }
}

void EngineDataUI::SetData(float fps, float objCount, float colCount)
{
    m_FPS = fps;
    m_ObjectCount = objCount;
    m_CollisionCount = colCount;
}

void EngineDataUI::SetData(const std::vector<Data>& data)
{
    m_Data = data;
}
