#include "Player.h"

Player::Player(float startX, float startY, float shipSize, float shipSpeed)
	: x(startX), y(startY), size(shipSize), speed(shipSpeed) {}

void Player::update(float ms) {
	const float move = speed * ms / 1000.0f;

    if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP)) {
        y -= move;  // Move up
    }
    if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN)) {
        y += move;  // Move down
    }
    if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT)) {
        x -= move;  // Move left
    }
    if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT)) {
        x += move;  // Move right
    }
}

void Player::draw() {
    graphics::Brush br;
    br.fill_color[0] = 0.5f;  // Red
    br.fill_color[1] = 0.5f;  // Green
    br.fill_color[2] = 1.0f;  // Blue
    br.outline_opacity = 0.0f;

    graphics::drawRect(x, y, size, size, br);
}