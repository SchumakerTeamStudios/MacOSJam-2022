// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Card.hpp"
#include "Common.hpp"
#include "Dealer.hpp"
class Table final {
    
    private:
        inline static AssetStore* assetStore = AssetStore::getInstance();
        SDL_Renderer* renderer;
        std::array<short, 52> deck;
        std::vector<Card> cards;

        bool isRunning = false;
        int millisecsPreviousFrame = 0;
        double deltaTime = 0.0;
        int x = 0, y = 0;
        bool click = false;

        void load();
        void update();
        void render();
        void input();
        void unload(); 
        void setClickable(); 

    public:
        Table(SDL_Renderer* renderer);
        ~Table();

        short loop();
};