#include "Asteroid.h"
#include <sgg/graphics.h>
#include "GameState.h"

void Asteroid::update(float dt)
{
    // Move asteroid
    m_pos_x += m_velocity_x * dt;
    m_pos_y += m_velocity_y * dt;

    // Wrap around the screen
    float screen_width = m_state->getCanvasWidth();
    float screen_height = m_state->getCanvasHeight();
    if (m_pos_x < 0) m_pos_x += screen_width;
    if (m_pos_x > screen_width) m_pos_x -= screen_width;
    if (m_pos_y < 0) m_pos_y += screen_height;
    if (m_pos_y > screen_height) m_pos_y -= screen_height;
}

void Asteroid::draw()
{
    graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush_asteroid);
}
