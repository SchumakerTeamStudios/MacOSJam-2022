// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "AssetStore.hpp"

AssetStore::AssetStore() {}
AssetStore::~AssetStore() {
    clearAssets();
}

AssetStore* AssetStore::getInstance() {
    if (instance == 0) {
        instance = new AssetStore();
    }
    return instance;
}

void AssetStore::addTexture(SDL_Renderer* renderer, const short assetId, const std::string& filePath) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    textures.emplace(assetId, texture);
}

SDL_Texture* AssetStore::getTexture(const short assetId) {
    return textures[assetId];
}

void AssetStore::clearAssets() {
    for (auto texture: textures) {
        SDL_DestroyTexture(texture.second);
    }
    textures.clear();
}

