// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Card.hpp"

Card::Card() : Sprite() {}
Card::Card(short id) : Sprite() {
    this->id = id;
    AssetStore* assetStore = AssetStore::getInstance();
    sprite = assetStore->getTexture(id);
}
Card::Card(short id, short line, short x, short y, short w, short h) : Sprite(x, y, w, h) {
    this->id = id;
    this->line = line;
    sprite = assetStore->getTexture(id);
}
Card::~Card() {}

void Card::draw(SDL_Renderer* renderer) {
    if (!destroyed) {
        SDL_Rect rect;
        rect.x = x; rect.y = y;
        rect.w = w; rect.h = h;
        SDL_RenderCopy(renderer, sprite, NULL, &rect);

        BoxCollider box = getCollider();
        SDL_Rect collider; 
        collider.x = box.x + 12;
        collider.y = box.y + 1;
        collider.w = box.w - 24;
        collider.h = box.h - 6;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &collider);
    }
}