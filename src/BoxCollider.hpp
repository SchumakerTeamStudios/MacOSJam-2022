// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
class BoxCollider final {
    public:
        short x, y, w, h;

        BoxCollider();
        BoxCollider(short x, short y, short w, short h);
        ~BoxCollider() = default;

        static bool collide(const BoxCollider& a, const BoxCollider& b);

};