#ifndef VELOCITYCOMPONENT_HPP
# define VELOCITYCOMPONENT_HPP

# include <iostream>

struct VelocityComponent
{
    int x;
    int y;
    int z;
};

std::ostream &operator<<(std::ostream &os, const VelocityComponent &a);

#endif
