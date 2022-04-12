#include "Components/VelocityComponent.hpp"

std::ostream &operator<<(std::ostream &os, const VelocityComponent &a)
{
    os << "{" << a.x << ", " << a.y << ", " << a.z << "}";
    return (os);
}
