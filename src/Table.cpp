// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Table.hpp"
Table::Table(SDL_Renderer* renderer) {
    this->renderer = renderer;
    load();
}

Table::~Table() {
    unload();
}

void Table::load() {
    Dealer dealer;
    deck = dealer.newShuffledDeck();
    short x = 100;
    short y = 100;
    for (short i = 0; i < deck.size(); i++) {
        short id = deck[i];
        cards.push_back(Card(id, x + (i *  64), y, 64, 64));
    }
}  

short Table::loop() {
    isRunning = true;
    int timeToWait = 0;
    while(isRunning) {
        timeToWait = Common::MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
        if (timeToWait > 0 && timeToWait <= Common::MILLISECS_PER_FRAME) {
            SDL_Delay(timeToWait);
        }
        deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;
        millisecsPreviousFrame = SDL_GetTicks();

        input();
        render();
        SDL_Delay(deltaTime);
    }
    return 1;
}

void Table::render() {
    SDL_SetRenderDrawColor(renderer, 0, 64, 0, 255);
    SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, background, NULL, &rectBackground);
    
    for (auto card : cards) {
        card.draw(renderer);
    }
    
    SDL_RenderPresent(renderer);   

}

void Table::input() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                exit(0);
            break;
        }
    }
}

void Table::unload() {

}