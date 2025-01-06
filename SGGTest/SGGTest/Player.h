#pragma once

#include "graphics.h"

class Player {
private:
	float x, y;		// Position
	float size;		// Size of ship
	float speed;	// Movement speed

public:
	Player(float startX, float startY, float shipSize, float shipSpeed);
	
	void update(float ms);	// Updates player position based on input
	void draw();			// Draws the player on the screen
};