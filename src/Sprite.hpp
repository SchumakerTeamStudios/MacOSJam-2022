// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
class Sprite {
    
    public:
        short x, y, w, h;
        SDL_Texture* sprite;
        
        Sprite();
        Sprite(short x, short y, short w, short h);

        virtual void draw(SDL_Renderer* renderer) = 0;
        BoxCollider getCollider();
};