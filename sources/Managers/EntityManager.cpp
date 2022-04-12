#include "Managers/EntityManager.hpp"
#include <cassert>

EntityManager::EntityManager()
    : numberOfEntities(0)
{

}

Entity EntityManager::createEntity(void)
{
    // Entities have reached the max allowed number MAX_ENTITIES
    assert(numberOfEntities < MAX_ENTITIES);

    entitySignatures[numberOfEntities] = Signature();
    return (Entity(numberOfEntities++));
}

void EntityManager::destroyEntity(Entity entity)
{
    // Entity does not exist in the EntityManager
    assert(entity._id < numberOfEntities);

    entitySignatures[entity._id] = entitySignatures[--numberOfEntities];
}

void EntityManager::setSignature(Entity entity, Signature signature)
{
    // Entity does not exist in the EntityManager
    assert(entity._id < numberOfEntities);

    entitySignatures[entity._id] = signature;
}

Signature EntityManager::getSignature(Entity entity) const
{
    // Entity does not exist in the EntityManager
    assert(entity._id < numberOfEntities);

    return (entitySignatures[entity._id]);
}

Entity EntityManager::getEntity(EntityId id) const
{
    // entityid does not exist in the EntityManager
    assert(id < numberOfEntities);

    return ();
}
