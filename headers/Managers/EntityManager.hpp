#ifndef ENTITYMANAGER_HPP
# define ENTITYMANAGER_HPP

# include "Entity.hpp"
# include <unordered_map>
# include <array>
# include <bitset>
# include "Managers/ComponentManager.hpp"

# define MAX_ENTITIES UINT16_MAX

class EntityManager
{
// shouldn't need this
// std::unordered_map<EntityId, Signature> entityToSignature; /* entity id -> signature */
std::array<Signature, MAX_ENTITIES> entitySignatures;
EntityId numberOfEntities;
public:
    EntityManager();
    Entity createEntity(void);
    void destroyEntity(Entity entity);
    void setSignature(Entity entity, Signature signature);
    Signature getSignature(Entity entity) const;

    /*
     * Get entity based on id
     */
    Entity getEntity(EntityId id) const;
};

#endif
