#pragma once
#pragma once
#include "GameObject.h"
#include <sgg/graphics.h>
#include "box.h"

class Shooting : public GameObject, Box {
    float m_pos_x;
    float m_pos_y;
    float m_vel_x;
    float m_vel_y;
    float m_lifetime;
    graphics::Brush m_brush_shooting;

public:
    Shooting(float x, float y, float vel_x, float vel_y, float lifetime, std::string texture_path);
    void update(float dt) override;
    void draw() override;
    bool isExpired() const { return m_lifetime <= 0.0f; }
};

