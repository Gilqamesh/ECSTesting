#include "Managers/EntityManager.hpp"
#include <cassert>

EntityManager::EntityManager()
    : availableEntitiesQueueIndex(0)
{
    for (unsigned int i = 0; i < availableEntitiesQueue.size(); ++i)
        availableEntitiesQueue[i] = Entity(i);
}

Entity EntityManager::createEntity(void)
{
    // Entities have reached the max allowed number MAX_ENTITIES
    assert(availableEntitiesQueueIndex < MAX_ENTITIES);

    return (availableEntitiesQueue[availableEntitiesQueueIndex++]);
}

void EntityManager::destroyEntity(Entity entity)
{
    // there are no entities in the entity manager to destroy
    assert(availableEntitiesQueueIndex > 0);

    entityComponentSignature[entity._id].reset();
    availableEntitiesQueue[--availableEntitiesQueueIndex] = entity;
}

void EntityManager::setComponentSignature(Entity entity, ComponentSignature componentSignature)
{
    // entity id is out of range 
    assert(entity._id < MAX_ENTITIES);

    entityComponentSignature[entity._id] = componentSignature;
}

ComponentSignature EntityManager::getComponentSignature(Entity entity) const
{
    // Entity does not exist in the EntityManager
    assert(entity._id < MAX_ENTITIES);

    return (entityComponentSignature[entity._id]);
}
