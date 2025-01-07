#pragma once
#include "GameObject.h"
#include "sgg/graphics.h"
#include <list>
#include"Asteroid.h"
class Level : public GameObject {
	graphics::Brush m_brush_background;
	const float m_block_size = 1.0f;
	float m_center_x = 5.0f;
	float m_center_y = 5.0f;
	std::vector<Asteroid*> m_asteroids; 
	float m_spawn_timer = 0.0f;
	float m_spawn_interval = 3.0f;

	std::vector<GameObject*>m_static_objects;
	std::list<GameObject*>m_dynamic_objects;
public:
	void update(float dt) override;
	void init()  override;
	void draw()  override;
	Level(const std::string& name = "Level1");
	~Level();
	void spawnAsteroid();
};
