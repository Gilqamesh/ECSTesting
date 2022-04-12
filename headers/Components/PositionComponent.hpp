#ifndef POSITIONCOMPONENT_HPP
# define POSITIONCOMPONENT_HPP

# include <iostream>

struct PositionComponent
{
    int x;
    int y;
    int z;
};

std::ostream &operator<<(std::ostream &os, const PositionComponent &a);

#endif
