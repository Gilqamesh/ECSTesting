#ifndef MOVEMENTSYSTEM_HPP
# define MOVEMENTSYSTEM_HPP

# include "Interfaces/ISystem.hpp"

class MovementSystem : public ISystem
{
public:
    MovementSystem(Coordinator *coordinator);
    void update(float dt);
    virtual void setSystemSignature() override;
};

#endif
