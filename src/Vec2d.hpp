// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once

struct Vec2d {
    float x, y;

    Vec2d();
    Vec2d(float x, float y);
    
    ~Vec2d() = default;

    void Add(const Vec2d& v);                 // v1.Add(v2)
    void Sub(const Vec2d& v);                 // v1.Sub(v2)
    void Scale(const float n);                // v1.Scale(n)
    Vec2d Rotate(const float a) const;        // v1.Rotate(angle)

    float Magnitude() const;                  // v1.Magnitude()
    float MagnitudeSquared() const;           // v1.MagnitudeSquared()

    Vec2d& Normalize();                       // v1.Normalize()
    Vec2d UnitVector() const;                 // v1.UnitVector()
    Vec2d Normal() const;                     // n = v1.Normal()

    float Dot(const Vec2d& v) const;          // v1.Dot(v2)
    float Cross(const Vec2d& v) const;        // v1.Cross(v2)

    Vec2d& operator = (const Vec2d& v);       // v1 = v2
    bool operator == (const Vec2d& v) const;  // v1 == v2
    bool operator != (const Vec2d& v) const;  // v1 != v2
    
    Vec2d operator + (const Vec2d& v) const;  // v1 + v2
    Vec2d operator - (const Vec2d& v) const;  // v1 - v2
    Vec2d operator * (const float n) const;   // v1 * n
    Vec2d operator / (const float n) const;   // v1 / n
    Vec2d operator - ();                      // -v1

    Vec2d& operator += (const Vec2d& v);     // v1 += v2
    Vec2d& operator -= (const Vec2d& v);     // v1 -= v2
    Vec2d& operator *= (const float n);      // v1 *= n
    Vec2d& operator /= (const float n);      // v1 /= n
};