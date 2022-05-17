// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"
class Card final : public Sprite {
    
    private:
        inline static AssetStore* assetStore = AssetStore::getInstance();
        short hover = 5;
        bool isHover = false;

    public:
        short id;
        short value;
        bool destroyed = false;
        bool clickable = false;
        bool selected = false;
        short line = -1;
        
        Card();
        Card(short id);
        Card(short id, short line, short x, short y, short w, short h);
        ~Card();

        void draw(SDL_Renderer* renderer) override;
        void hoverOn();
        void hoverOff();
};