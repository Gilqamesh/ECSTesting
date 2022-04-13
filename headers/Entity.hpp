#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <cstdint>

typedef uint16_t EntityId;
# define MAX_ENTITIES UINT16_MAX

class EntityManager;

class Entity
{
    EntityId _id;
    friend class EntityManager;
    // Entity creation has to go through the EntityManager
    Entity(EntityId id);
public:
    operator int() const { return (int)_id; }
    Entity();
    EntityId getId() const;
};

#endif
