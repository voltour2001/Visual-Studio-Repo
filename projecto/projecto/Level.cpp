#include "Level.h"
#include"sgg/graphics.h"
#include "GameState.h"
#include"Player.h"
#include <cstdlib>
#include <ctime>
void Level::update(float dt)

{
   
	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	GameObject::update(dt);
}

void Level::init()
{
    m_brush_background.outline_opacity = 0.0f;
    m_brush_background.texture = m_state->getFullAssetPath("stars.png");

    for (auto p_gob : m_static_objects)
        if (p_gob) p_gob->init();
    for (auto p_gob : m_dynamic_objects)
        if (p_gob) p_gob->init();
    
}


void Level::draw()
{   
    float w = m_state->getCanvasWidth();
    float h = m_state->getCanvasHeight();

    
	graphics::drawRect(w / 2.0f, h / 2.0f, w, h, m_brush_background);
	
	if (m_state->getPlayer()->isActive()) {
		m_state->getPlayer()->draw();
	}
	for (auto p_gob : m_static_objects)
		if (p_gob) p_gob->draw();
	for (auto p_gob : m_dynamic_objects)
		if (p_gob) p_gob->draw();
    
    
}

Level::Level(const std::string& name)
{
}

Level::~Level()
{
	for (auto p_gob : m_static_objects)
		if (p_gob) delete p_gob;
	for (auto p_gob : m_dynamic_objects)
		if (p_gob) delete p_gob;
}
void Level::spawnAsteroid()
{
    float screen_width = m_state->getCanvasWidth();
    float screen_height = m_state->getCanvasHeight();

    
    float x = (rand() % 2 == 0) ? -0.5f : screen_width + 0.5f;
    float y = (rand() % 2 == 0) ? -0.5f : screen_height + 0.5f;

    
    float vx = (rand() % 200 - 100) / 100.0f; 
    float vy = (rand() % 200 - 100) / 100.0f;

    
    float size = 0.5f + (rand() % 3) * 0.5f; 

    m_asteroids.push_back(new Asteroid(x, y, size, vx, vy));
}
