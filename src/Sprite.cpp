// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Sprite.hpp"

Sprite::Sprite() : x(0), y(0), w(0), h(0) {}
Sprite::Sprite(short x, short y, short w, short h) : x(x), y(y), w(w), h(h) {}

BoxCollider Sprite::getCollider() { 
    return BoxCollider(x, y, w, h);
}