#ifndef GAMER_HPP
#define GAMER_HPP

#include <vector>
#include <string>

using namespace std;

class GameR {
    public:
        // Konstruktor domyślny
        GameR();

        // Konstruktor przyjmujący generate, width, height
        GameR(const vector<string>& generate, const vector<string>& canCollide, int width, int height);

        // Random
        float random(float x, float y);

        // Init
        vector<string> init(bool genRandBlocks);

        // Funkcja renderująca obraz
        void render(int player_pos, string PlayerIcon, vector<string> b);

        // Collision Check
        bool checkCollision(string with);

    private:
        vector<string> bytes;  // Przechowuje wynik przetwarzania
        vector<string> genMW;
        vector<string> canCollideWith;

        int W;
        int H;
};

#endif
