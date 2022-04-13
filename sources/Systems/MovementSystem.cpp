#include "Systems/MovementSystem.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/VelocityComponent.hpp"
#include "Coordinator.hpp"

MovementSystem::MovementSystem(Coordinator *coordinator)
    : ISystem(coordinator)
{

}

void MovementSystem::update(float dt)
{
    for (auto entity : entities)
    {
        PositionComponent &position = _coordinator->getComponent<PositionComponent>(entity);
        VelocityComponent &velocity = _coordinator->getComponent<VelocityComponent>(entity);
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
        position.z += velocity.z * dt;
    }
}

void MovementSystem::setSystemSignature()
{
    ComponentSignature movementSystemSignature;
    movementSystemSignature.set(_coordinator->getComponentId<PositionComponent>(), true);
    movementSystemSignature.set(_coordinator->getComponentId<VelocityComponent>(), true);
    _coordinator->setSystemSignature<MovementSystem>(movementSystemSignature);
}
