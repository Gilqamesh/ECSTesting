#ifndef VELOCITYCOMPONENT_HPP
# define VELOCITYCOMPONENT_HPP

# include <iostream>

struct VelocityComponent
{
    float x;
    float y;
    float z;
};

std::ostream &operator<<(std::ostream &os, const VelocityComponent &a);

#endif
