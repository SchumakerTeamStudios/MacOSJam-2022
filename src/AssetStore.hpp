// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
class AssetStore final {
    
    private:
        inline static AssetStore* instance;
        std::map<short, std::pair<short, SDL_Texture*>> textures;
        AssetStore();
        ~AssetStore();

    public:
        static AssetStore* getInstance();
        void addTexture(SDL_Renderer* renderer, const short assetId, const short value, const std::string& filePath);
        SDL_Texture* getTexture(const short assetId);
        void clearAssets();
};