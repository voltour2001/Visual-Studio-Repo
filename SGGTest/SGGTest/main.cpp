#include "graphics.h"
#include "Player.h"

Player player(600.0f, 400.0f, 50.0f, 200.0f);  // Initial player setup

void update(float ms) {
    player.update(ms);  // Update player position
}

void draw() {
    player.draw();  // Draw player
}

int main() {
    graphics::createWindow(1200, 800, "Asteroids Game");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::startMessageLoop();  // Starts the game loop

    return 0;
}
