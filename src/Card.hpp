// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"

class Card final : public Sprite {
    public:
        short id;
        bool destroyed;

        Card();
        Card(short id);
        Card(short id, short x, short y, short w, short h);
        ~Card();

        void draw(SDL_Renderer* renderer) override;
};