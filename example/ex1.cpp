#include "gameR.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

int WIDTH = 10;
int HEIGHT = 10;
int player_pos = 0;
vector<string> generate = {"a", "A", "c"};
vector<string> canCollide = {" ", "a"};

GameR game(generate, canCollide, WIDTH, HEIGHT);
vector<string> map = game.init(true);

void tick() {
    game.render(player_pos, "O", map);

    char go = _getch();

    int movement = 0;
    if (go == 'W' || go == 'w') {
        movement = -WIDTH;
    } else if (go == 'A' || go == 'a') {
        movement = -1;
    } else if (go == 'S' || go == 's') {
        movement = WIDTH;
    } else if (go == 'D' || go == 'd') {
        movement = 1;
    }

    if (player_pos + movement >= 0 && player_pos + movement < HEIGHT * WIDTH && game.checkCollision(map[player_pos + movement])) {
        player_pos += movement;
    }

}

int main() {
    while (true) {
        tick();
    }

    return 0;
}
