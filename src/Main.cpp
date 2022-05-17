// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Common.hpp"
#include "Splash.hpp"
#include "Menu.hpp"
#include "Table.hpp"

SDL_Window* window;
SDL_Renderer* renderer;

void splash();
short loadMenu();
void setUp();
bool load(AssetStore* assetStore);
void logic();
short game();
void quit();

int main(int argc, char* argv[]) {
    setUp();
    AssetStore* assetStore = AssetStore::getInstance();
    std::future<bool> loading = std::async(load, assetStore);
    
    splash();
    logic();
    quit();
    return 0;
}

void logic() {
    short stage = 0;
    for (;;) {
        switch(stage) {
        case 0:
            stage = loadMenu();         
            break;

        case 1:
            stage = game();
            break;
        
        case 2:
            break;
        }
    }
}

short loadMenu() {
    Menu* menu = new Menu(renderer);
    short code = menu->update();
    delete menu;
    return code;
}

short game() {
    Table* level = new Table(renderer);
    short code = level->loop();
    delete level;
    return code;
}

void setUp() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow(
        Common::TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Common::WIDTH,
        Common::HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_METAL 
    );
    
    SDL_Surface* iconSurface = IMG_Load("data/joypad.png");
    SDL_SetWindowIcon(window, iconSurface);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);   
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 256);
}

bool load(AssetStore* assetStore) {
    assetStore->addTexture(renderer, 0, 2, "/data/clubs_02.png");
    assetStore->addTexture(renderer, 1, 3, "/data/clubs_03.png");
    assetStore->addTexture(renderer, 2, 4, "/data/clubs_04.png");
    assetStore->addTexture(renderer, 3, 5, "/data/clubs_05.png");
    assetStore->addTexture(renderer, 4, 6, "/data/clubs_06.png");
    assetStore->addTexture(renderer, 5, 7, "/data/clubs_07.png");
    assetStore->addTexture(renderer, 6, 8, "/data/clubs_08.png");
    assetStore->addTexture(renderer, 7, 9, "/data/clubs_09.png");
    assetStore->addTexture(renderer, 8, 10, "/data/clubs_10.png");
    assetStore->addTexture(renderer, 9, 1, "/data/clubs_A.png");
    assetStore->addTexture(renderer, 10, 11, "/data/clubs_J.png");
    assetStore->addTexture(renderer, 11, 13, "/data/clubs_K.png");
    assetStore->addTexture(renderer, 12, 12, "/data/clubs_Q.png");
    assetStore->addTexture(renderer, 13, 2, "/data/diamonds_02.png");
    assetStore->addTexture(renderer, 14, 3, "/data/diamonds_03.png");
    assetStore->addTexture(renderer, 15, 4, "/data/diamonds_04.png");
    assetStore->addTexture(renderer, 16, 5, "/data/diamonds_05.png");
    assetStore->addTexture(renderer, 17, 6, "/data/diamonds_06.png");
    assetStore->addTexture(renderer, 18, 7, "/data/diamonds_07.png");
    assetStore->addTexture(renderer, 19, 8, "/data/diamonds_08.png");
    assetStore->addTexture(renderer, 20, 9, "/data/diamonds_09.png");
    assetStore->addTexture(renderer, 21, 10, "/data/diamonds_10.png");
    assetStore->addTexture(renderer, 22, 1, "/data/diamonds_A.png");
    assetStore->addTexture(renderer, 23, 11, "/data/diamonds_J.png");
    assetStore->addTexture(renderer, 24, 13, "/data/diamonds_K.png");
    assetStore->addTexture(renderer, 25, 12, "/data/diamonds_Q.png");
    assetStore->addTexture(renderer, 26, 2, "/data/hearts_02.png");
    assetStore->addTexture(renderer, 27, 3, "/data/hearts_03.png");
    assetStore->addTexture(renderer, 28, 4, "/data/hearts_04.png");
    assetStore->addTexture(renderer, 29, 5, "/data/hearts_05.png");
    assetStore->addTexture(renderer, 30, 6, "/data/hearts_06.png");
    assetStore->addTexture(renderer, 31, 7, "/data/hearts_07.png");
    assetStore->addTexture(renderer, 32, 8, "/data/hearts_08.png");
    assetStore->addTexture(renderer, 33, 9, "/data/hearts_09.png");
    assetStore->addTexture(renderer, 34, 10, "/data/hearts_10.png");
    assetStore->addTexture(renderer, 35, 1, "/data/hearts_A.png");
    assetStore->addTexture(renderer, 36, 11, "/data/hearts_J.png");
    assetStore->addTexture(renderer, 37, 13, "/data/hearts_K.png");
    assetStore->addTexture(renderer, 38, 12, "/data/hearts_Q.png");
    assetStore->addTexture(renderer, 39, 2, "/data/spades_02.png");
    assetStore->addTexture(renderer, 40, 3, "/data/spades_03.png");
    assetStore->addTexture(renderer, 41, 4, "/data/spades_04.png");
    assetStore->addTexture(renderer, 42, 5, "/data/spades_05.png");
    assetStore->addTexture(renderer, 43, 6, "/data/spades_06.png");
    assetStore->addTexture(renderer, 44, 7, "/data/spades_07.png");
    assetStore->addTexture(renderer, 45, 8, "/data/spades_08.png");
    assetStore->addTexture(renderer, 46, 9, "/data/spades_09.png");
    assetStore->addTexture(renderer, 47, 10, "/data/spades_10.png");
    assetStore->addTexture(renderer, 48, 1, "/data/spades_A.png");
    assetStore->addTexture(renderer, 49, 11, "/data/spades_J.png");
    assetStore->addTexture(renderer, 50, 13, "/data/spades_K.png");
    assetStore->addTexture(renderer, 51, 12, "/data/spades_Q.png");
    assetStore->addTexture(renderer, 52, 0, "/data/card_back.png");

    return true;
}

void quit() {
    SDL_Quit();
	TTF_Quit();
}

void splash() {
    Splash* splash = new Splash(renderer);
    delete splash;
    splash = nullptr;
}
