#include "Player.h"
#include "GameState.h"
#include <sgg/graphics.h>
#include <numbers>
constexpr float PI = 3.14159265358979323846f;

void Player::update(float dt)
{
    float delta_time = dt / 1000.0f; // Convert ms to seconds
    if (m_fire_timer > 0.0f)
        m_fire_timer -= delta_time;

    const float rotation_speed = 180.0f; // Speed of rotation in degrees per second

    // Flip the rotation directions for A and D
    if (graphics::getKeyState(graphics::SCANCODE_A))
        m_angle += rotation_speed * delta_time; // Rotate clockwise
    if (graphics::getKeyState(graphics::SCANCODE_D))
        m_angle -= rotation_speed * delta_time; // Rotate counter-clockwise

    // Keep angle within 0-360 degrees
    if (m_angle < 0.0f) m_angle += 360.0f;
    if (m_angle >= 360.0f) m_angle -= 360.0f;

    // Move forward with "W" key
    if (graphics::getKeyState(graphics::SCANCODE_W))
    {
        m_vel_x += m_acceleration * delta_time * cos(m_angle * PI / 180.0f);
        m_vel_y -= m_acceleration * delta_time * sin(m_angle * PI / 180.0f);
    }

    // Apply deceleration to slow down the player
    m_vel_x -= m_vel_x * m_deceleration * delta_time;
    m_vel_y -= m_vel_y * m_deceleration * delta_time;

    // Update position based on velocity
    m_pos_x += m_vel_x * delta_time;
    m_pos_y += m_vel_y * delta_time;

    // Screen wrapping logic
    float screen_width = m_state->getCanvasWidth();
    float screen_height = m_state->getCanvasHeight();

    if (m_pos_x < 0) m_pos_x += screen_width;
    else if (m_pos_x > screen_width) m_pos_x -= screen_width;

    if (m_pos_y < 0) m_pos_y += screen_height;
    else if (m_pos_y > screen_height) m_pos_y -= screen_height;

    // Shooting with "RETURN" key
    if (graphics::getKeyState(graphics::SCANCODE_RETURN) && m_fire_timer <= 0.0f)
    {
        shoot();
        m_fire_timer = m_fire_rate;
    }

    // Update shooting projectiles
    for (auto it = m_shooting.begin(); it != m_shooting.end();)
    {
        (*it)->update(dt);
        if ((*it)->isExpired()) {
            delete* it;
            it = m_shooting.erase(it);
        }
        else {
            ++it;
        }
    }
    GameObject::update(dt);
}



void Player::init()
{
	m_pos_x = 5.0f;
	m_pos_y = 5.0f;
    m_angle = 0.0f;
	m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
	m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y;
	m_brush_player.fill_opacity = 1.0f;
	m_brush_player.outline_opacity = 0.0f;
	m_brush_player.texture = m_state->getFullAssetPath("asteroidstr.png");
    m_brush_thrust.fill_opacity = 1.0f;
    m_brush_thrust.outline_opacity = 0.0f;
    m_brush_thrust.texture = m_state->getFullAssetPath("thrust.png"); 

}

void Player::draw()
{
    float player_draw_x = m_pos_x;
    float player_draw_y = m_pos_y;

   
    graphics::setOrientation(m_angle);
    drawPlayerAtPosition(player_draw_x, player_draw_y);
    graphics::resetPose();
    for (auto shooting : m_shooting)
        shooting->draw();
}
void Player::drawPlayerAtPosition(float x, float y)
{
    if (m_is_thrusting) {
        graphics::drawRect(x, y, 0.5f, 0.5f, m_brush_thrust);
    }
    else {
        graphics::drawRect(x, y, 0.5f, 0.5f, m_brush_player);
    }
}
void Player::shoot()
{
    float shooting_speed = 8.0f;
    float vel_x = shooting_speed * cos(m_angle * PI / 180.0f);
    float vel_y = -shooting_speed * sin(m_angle * PI / 180.0f);

    m_shooting.push_back(new Shooting(
        m_pos_x, m_pos_y, vel_x, vel_y, 2.0f, m_state->getFullAssetPath("shooting.png")
    ));
}

Player::~Player()
{
    for (auto shooting : m_shooting)
        delete shooting;
}

