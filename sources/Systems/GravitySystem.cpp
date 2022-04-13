#include "Systems/GravitySystem.hpp"
#include "Components/VelocityComponent.hpp"
#include "Coordinator.hpp"
#include "Debug.hpp"

GravitySystem::GravitySystem(Coordinator *coordinator)
    : ISystem(coordinator), _gravitationalConstant(1.5f)
{

}

void GravitySystem::setSystemSignature()
{
    ComponentSignature gravitySystemSignature;
    gravitySystemSignature.set(_coordinator->getComponentId<VelocityComponent>(), true);
    _coordinator->setSystemSignature<GravitySystem>(gravitySystemSignature);
}

void GravitySystem::update(float dt)
{
    for (auto entity : entities)
    {
        VelocityComponent &velocity = _coordinator->getComponent<VelocityComponent>(entity);
        velocity.y -= _gravitationalConstant * dt;
    }
}
