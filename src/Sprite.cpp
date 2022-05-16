// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Sprite.hpp"

Sprite::Sprite() : x(0), y(0), w(0), h(0) {}
Sprite::Sprite(short x, short y, short w, short h) : x(x), y(y), w(w), h(h) {}

BoxCollider Sprite::getCollider() { 
    return BoxCollider(x + 12, y + 1, w - 24, h - 6);

    //collider.x = box.x + 12;
    //collider.y = box.y + 1;
    //collider.w = box.w - 24;
    //collider.h = box.h - 6;
}