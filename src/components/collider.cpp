#include "raylib.h"
#include "collider.hpp"
#include <vector>

bool Collider::CheckCollision(Collider& other) {
    if (CheckCollisionRecs(
        { this->position.x, this->position.y, this->size.x, this->size.y },
        { other.position.x, other.position.y, other.size.x, other.size.y }
    )) {
        return true;
    }
    return false;
}

// bool Collider::CheckCollisions(std::vector<Collider*> & others) {
//     for (auto& other : others) {
//         if (CheckCollision(other)) {
//             return true;
//         }
//     }
//     return false;
// }

bool Collider::IsMouseOver() {
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, { this->position.x, this->position.y, this->size.x, this->size.y });
}