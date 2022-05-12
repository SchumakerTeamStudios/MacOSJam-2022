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
    assetStore->addTexture(renderer, 0, "/data/clubs_02.png");
    assetStore->addTexture(renderer, 1, "/data/clubs_03.png");
    assetStore->addTexture(renderer, 2, "/data/clubs_04.png");
    assetStore->addTexture(renderer, 3, "/data/clubs_05.png");
    assetStore->addTexture(renderer, 4, "/data/clubs_06.png");
    assetStore->addTexture(renderer, 5, "/data/clubs_07.png");
    assetStore->addTexture(renderer, 6, "/data/clubs_08.png");
    assetStore->addTexture(renderer, 7, "/data/clubs_09.png");
    assetStore->addTexture(renderer, 8, "/data/clubs_10.png");
    assetStore->addTexture(renderer, 9, "/data/clubs_A.png");
    assetStore->addTexture(renderer, 10, "/data/clubs_J.png");
    assetStore->addTexture(renderer, 11, "/data/clubs_K.png");
    assetStore->addTexture(renderer, 12, "/data/clubs_Q.png");
    assetStore->addTexture(renderer, 13, "/data/diamonds_02.png");
    assetStore->addTexture(renderer, 14, "/data/diamonds_03.png");
    assetStore->addTexture(renderer, 15, "/data/diamonds_04.png");
    assetStore->addTexture(renderer, 16, "/data/diamonds_05.png");
    assetStore->addTexture(renderer, 17, "/data/diamonds_06.png");
    assetStore->addTexture(renderer, 18, "/data/diamonds_07.png");
    assetStore->addTexture(renderer, 19, "/data/diamonds_08.png");
    assetStore->addTexture(renderer, 20, "/data/diamonds_09.png");
    assetStore->addTexture(renderer, 21, "/data/diamonds_10.png");
    assetStore->addTexture(renderer, 22, "/data/diamonds_A.png");
    assetStore->addTexture(renderer, 23, "/data/diamonds_J.png");
    assetStore->addTexture(renderer, 24, "/data/diamonds_K.png");
    assetStore->addTexture(renderer, 25, "/data/diamonds_Q.png");
    assetStore->addTexture(renderer, 26, "/data/hearts_02.png");
    assetStore->addTexture(renderer, 27, "/data/hearts_03.png");
    assetStore->addTexture(renderer, 28, "/data/hearts_04.png");
    assetStore->addTexture(renderer, 29, "/data/hearts_05.png");
    assetStore->addTexture(renderer, 30, "/data/hearts_06.png");
    assetStore->addTexture(renderer, 31, "/data/hearts_07.png");
    assetStore->addTexture(renderer, 32, "/data/hearts_08.png");
    assetStore->addTexture(renderer, 33, "/data/hearts_09.png");
    assetStore->addTexture(renderer, 34, "/data/hearts_10.png");
    assetStore->addTexture(renderer, 35, "/data/hearts_A.png");
    assetStore->addTexture(renderer, 36, "/data/hearts_J.png");
    assetStore->addTexture(renderer, 37, "/data/hearts_K.png");
    assetStore->addTexture(renderer, 38, "/data/hearts_Q.png");
    assetStore->addTexture(renderer, 39, "/data/spades_02.png");
    assetStore->addTexture(renderer, 40, "/data/spades_03.png");
    assetStore->addTexture(renderer, 41, "/data/spades_04.png");
    assetStore->addTexture(renderer, 42, "/data/spades_05.png");
    assetStore->addTexture(renderer, 43, "/data/spades_06.png");
    assetStore->addTexture(renderer, 44, "/data/spades_07.png");
    assetStore->addTexture(renderer, 45, "/data/spades_08.png");
    assetStore->addTexture(renderer, 46, "/data/spades_09.png");
    assetStore->addTexture(renderer, 47, "/data/spades_10.png");
    assetStore->addTexture(renderer, 48, "/data/spades_A.png");
    assetStore->addTexture(renderer, 49, "/data/spades_J.png");
    assetStore->addTexture(renderer, 50, "/data/spades_K.png");
    assetStore->addTexture(renderer, 51, "/data/spades_Q.png");
    assetStore->addTexture(renderer, 52, "/data/card_back.png");

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
