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
        SDL_Renderer* renderer;
        std::array<short, 52> deck;
        std::vector<Card> cards;

        bool isRunning = false;
        int millisecsPreviousFrame = 0;
        double deltaTime = 0.0;

        void load();
        void render();
        void input();
        void unload();  

    public:
        Table(SDL_Renderer* renderer);
        ~Table();

        short loop();
};