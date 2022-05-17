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
Card::Card(short id, short value, short line, short x, short y, short w, short h) : Sprite(x, y, w, h) {
    this->id = id;
    this->line = line;
    this->value = value;
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
        collider.x = box.x;
        collider.y = box.y;
        collider.w = box.w;
        collider.h = box.h;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &collider);
    }
}