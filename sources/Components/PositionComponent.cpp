#include "Components/PositionComponent.hpp"

std::ostream &operator<<(std::ostream &os, const PositionComponent &a)
{
    os << "{" << a.x << ", " << a.y << ", " << a.z << "}";
    return (os);
}
