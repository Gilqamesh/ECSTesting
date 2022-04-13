#include "./Coordinator.hpp"

Coordinator::Coordinator()
{
    _entityManager = new EntityManager();
    _componentManager = new ComponentManager();
    _systemManager = new SystemManager(this);
}

Coordinator::~Coordinator()
{
    delete _entityManager;
    delete _componentManager;
    delete _systemManager;
}

Entity Coordinator::createEntity()
{
    return (_entityManager->createEntity());
}

void Coordinator::destroyEntity(Entity entity)
{
    _entityManager->destroyEntity(entity);
    _systemManager->entityDestroyed(entity);
    _componentManager->entityDestroyed(entity);
}
