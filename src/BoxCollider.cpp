// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "BoxCollider.hpp"

BoxCollider::BoxCollider() : x(0), y(0), w(0), h(0) {}
BoxCollider::BoxCollider(short x, short y, short w, short h) : x(x), y(y), w(w), h(h) {}

bool BoxCollider::collide(const BoxCollider& a, const BoxCollider& b) {
    int pwA = a.x + a.w;
    int pwB = b.x + b.w;

    int phA = a.y + a.h;
    int phB = b.y + b.h;

    if (pwA > b.x && a.x < pwB && phA > b.y && a.y < phB) {
        return true;
    }
    return false;
}
