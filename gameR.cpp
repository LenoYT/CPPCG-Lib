#include "gameR.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <string>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

using namespace std;

GameR::GameR() : W(0), H(0) {}

GameR::GameR(const vector<string>& generate, const vector<string>& canCollide, int width, int height)
    : W(width), H(height), genMW(generate), canCollideWith(canCollide) {
    bytes.push_back("\n" + to_string(W) + "x" + to_string(H));
}

float GameR::random(float x, float y) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(x, y);
    return dis(gen);
}

vector<string> GameR::init(bool genRandBlocks) {
    bytes.resize(H * W);  // Ustawiamy rozmiar wektora bytes
    
    for (int i = 0; i < H * W; i++) {
        if (random(0, 15) < 2) {
            bytes[i] = genMW[static_cast<size_t>(round(random(0, genMW.size() - 1)))];
        } else {
            bytes[i] = " ";
        }
    }

    return bytes;
}

void GameR::render(int player_pos, string PlayerIcon, vector<string> b) {
    system(CLEAR_SCREEN);

    for (int i = 0; i < W + 2; i++) {
        cout << "#";
    }
    cout << "\n";

    for (int i = 0; i < H; i++) {
        cout << "#";  // Left border
        for (int f = 0; f < W; f++) {
            int index = f + i * W;
            if (index != player_pos) {
                cout << b[index];  // Use the getter for Block's character
            } else {
                cout << PlayerIcon;  // Represent player
            }
        }
        cout << "#" << "\n";  // Right border
    }

    // Bottom border
    for (int i = 0; i < W + 2; i++) {
        cout << "#";
    }
    cout << "\n";
}

bool GameR::checkCollision(string with) {
    for (string x : canCollideWith) {
        if (with == x) {
            return true; 
        }
    }
    return false; 
}
