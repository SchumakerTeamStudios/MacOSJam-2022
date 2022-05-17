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
    short x = 365;
    short y = 65;
    
    short index = 0;
    for (short i = 0; i < 7; i++) { // lines of the pyramid
        for (short j = 0; j <= i; j++) { // cards on the line
            short id = deck[index];
            cards.push_back(Card(id, i, x + (j * 44), y + (i * 26), 64, 64));
            index++;
        }
        x -= 22;
    }
    cards.at(27).sprite = assetStore->getTexture(50);
    cards.at(27).value = 13;

    cards.at(27).y = 300;
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
        update();
        render();
        SDL_Delay(deltaTime);
    }
    return 1;
}

void Table::update() {
    setClickable();
    BoxCollider pointer = BoxCollider(x, y, 3, 3);
    if (click) {
        click = false;
        for (auto& card : cards) {
            if (!card.destroyed && card.clickable) {
                if (BoxCollider::collide(pointer, card.getCollider())) {
                    if (card.value == 13) {
                        std::cout << " king " << std::endl;
                        card.destroyed = true;
                    } else {
                        if (pair < 3) {
                            if (card1 == nullptr) {
                                card1 = &card;      
                                std::cout << " first card selected " << std::endl;
                                break;
                            } else {
                                if (card2 == nullptr) {
                                    card2 = &card;  
                                    std::cout << " second card selected " << std::endl;
                                    break;  
                                }
                            }

                            pair++;
                            if (pair > 1) {
                                std::cout << " break loop " << std::endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (card1 != nullptr && card2 != nullptr) {
            pair = 0;
            std::cout << " pair = 0 " << std::endl;
            auto res = card1->value + card2->value;
            if (res == 13) {
                card1->destroyed = true;
                card2->destroyed = true;
                std::cout << " cards destroyed " << std::endl;
            }
            card1 = nullptr;
            card2 = nullptr;
            std::cout << " pointers cleared " << std::endl;
        }
    } else {
        for (auto& card : cards) {
            if (!card.destroyed && card.clickable) {
                if (BoxCollider::collide(pointer, card.getCollider())) {
                    card.hoverOn();
                } else {
                     card.hoverOff();
                }
            }
        }
    }
}

void Table::render() {
    SDL_SetRenderDrawColor(renderer, 0, 64, 0, 255);
    SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, background, NULL, &rectBackground);
    
    for (auto& card : cards) {
        card.draw(renderer);
    }
    
    SDL_RenderPresent(renderer);   
}

void Table::setClickable() {
    for (char i = 21; i < 28; i++) {
        if (!cards.at(i).destroyed) {
            cards.at(i).clickable = true;
        }
    }

    short z = 20;
    for (char x = 5; x >= 0; x--) {
        for (short y = 0; y < (x + 1) ; y++) {
            bool v1 = cards.at(z + (x + 1)).destroyed; 
            bool v2 = cards.at(z + (x + 2)).destroyed;
            bool v3 = (v1 && v2);
            cards.at(z).clickable = v3;
            //if (v3) {
            //   cards.at(z).sprite = assetStore->getTexture(52);
            //}
            z--;
        }
    }
}

void Table::input() {
    SDL_Event sdlEvent;
    SDL_GetMouseState(&x, &y);
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                exit(0);
            break;
            case SDL_MOUSEBUTTONDOWN:
                click = true;
            break;
        }
    }
}

void Table::unload() {

}