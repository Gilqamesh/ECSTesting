#ifndef ENTITYMANAGER_HPP
# define ENTITYMANAGER_HPP

# include "Entity.hpp"
# include <stack>
# include <unordered_map>
# include <array>
# include <bitset>
# include "Managers/ComponentManager.hpp"

/*
 * Distributes available entities
 * Bookkeeps entities component signature
 */
class EntityManager
{
std::array<ComponentSignature, MAX_ENTITIES> entityComponentSignature; /* the array is indexed by the entity id, each element holds the components of an entity */
std::array<Entity, MAX_ENTITIES> availableEntitiesQueue; /* available entities to distribute held by the entity manager */
EntityId availableEntitiesQueueIndex;
public:
    /*
     * Initializes the available entities to distribute later
     */
    EntityManager();

    /*
     * Returns an available entity
     */
    Entity createEntity(void);

    /*
     * Destroys entity and adds it back to the entity manager as an available entity
     */
    void destroyEntity(Entity entity);

    /*
     * Sets the component signature for the entity
     */
    void setComponentSignature(Entity entity, ComponentSignature ComponentSignature);

    /*
     * Gets the component signature for the entit
     */
    ComponentSignature getComponentSignature(Entity entity) const;
};

#endif
