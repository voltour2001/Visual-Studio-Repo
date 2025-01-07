#pragma once
#include "GameObject.h"
#include "box.h"
#include <sgg/graphics.h>
#include "Shooting.h"
#include <vector>
class Player : public GameObject,public Box {
	graphics::Brush m_brush_player;
	float m_pos_x;
	float m_pos_y;
	float m_angle;
	float m_vel_x;
	float m_vel_y;
	float m_acceleration = 4.0f; 
	float m_deceleration = 2.0f;
	float m_fire_rate = 0.2f;            
	float m_fire_timer = 0.0f;
	graphics::Brush m_brush_thrust;
	bool m_is_thrusting = false;    
	

	std::vector<Shooting*> m_shooting; 
	
public:
	Player(std::string name):GameObject(name){}
	void drawPlayerAtPosition(float x, float y);

	void update(float dt) override;
	void init()  override;
	void draw()  override;
	float getPosX() const { return m_pos_x; }
	void shoot(); 
	const std::vector<Shooting*>& getShooting() const { return m_shooting; }
	~Player();
};
