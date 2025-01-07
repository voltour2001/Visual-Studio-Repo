#pragma once
#include "GameObject.h"
#include "Box.h"
#include <sgg/graphics.h>

class Asteroid : public GameObject, public Box
{
    graphics::Brush m_brush_asteroid;
    float m_rotation_speed;
    float m_velocity_x;
    float m_velocity_y;

public:
    Asteroid(float x, float y, float size, float vx, float vy)
        : Box(x, y, size, size), m_velocity_x(vx), m_velocity_y(vy) {
    }
    float getVelocityX() const { return m_velocity_x; }
    float getVelocityY() const { return m_velocity_y; }
    void update(float dt) override;
    void draw() override;
};

