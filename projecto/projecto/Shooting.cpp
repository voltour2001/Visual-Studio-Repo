#include "Shooting.h"
#include <cmath>

Shooting::Shooting(float x, float y, float vel_x, float vel_y, float lifetime, std::string texture_path)
    : m_pos_x(x), m_pos_y(y), m_vel_x(vel_x), m_vel_y(vel_y), m_lifetime(lifetime)
{
    m_brush_shooting.fill_opacity = 1.0f;
    m_brush_shooting.outline_opacity = 0.0f;
    m_brush_shooting.texture = texture_path;
}

void Shooting::update(float dt)
{
    float delta_time = dt / 1000.0f; // Convert dt to seconds
    m_pos_x += m_vel_x * delta_time;
    m_pos_y += m_vel_y * delta_time;
    m_lifetime -= delta_time;       // Decrease lifetime
}

void Shooting::draw()
{
    graphics::drawRect(m_pos_x, m_pos_y, 0.2f, 0.2f, m_brush_shooting); // Draw projectile
}
