#ifndef COMPONENTARRAY_HPP
# define COMPONENTARRAY_HPP

# include "Interfaces/IComponentArray.hpp"
# include <array>
# include <unordered_map>
# include "Entity.hpp"
# include <string>
# include <typeinfo>
# include <iostream>
# include <functional>

/*
 * Bookkeeps what entities are associated with a specific implementation of a Component
 */
template <typename T>
class ComponentArray : public IComponentArray
{
std::array<T, MAX_ENTITIES>        data; /* packed component data for entities */
std::unordered_map<Entity, size_t, std::hash<int> > entityToData; /* maps entity id to 'data' index */
std::unordered_map<size_t, Entity> dataToEntity; /* maps 'data' index to entity id */
size_t                             currentSize; /* size of valid entries in 'data' */
public:
    ComponentArray()
        : currentSize(0) { }
    
    /*
     * Adds entity to the component array
     * Essentially adding a new component to an Entity
     */
    void insertData(Entity entity, T component)
    {
        // "Entity already exists in component."
        assert(entityToData.count(entity) == 0);

        entityToData[entity] = currentSize;
        dataToEntity[currentSize] = entity;
        data[currentSize++] = component;
    }

    /*
     * Removes an entity from the component array
     * Essentially removes a component from an Entity
     */
    void removeData(Entity entity)
    {
        // "Entity does not exist in component."
        assert(entityToData.count(entity));

        size_t removedIndex = entityToData[entity];
        // replacing the old 'data' with the last 'data'
        data[removedIndex] = data[currentSize - 1];
        Entity lastEntity = dataToEntity[currentSize - 1];
        entityToData[lastEntity] = removedIndex;
        dataToEntity[removedIndex] = lastEntity;

        // erasing old entry
        entityToData.erase(entity);
        dataToEntity.erase(--currentSize);
    }

    /*
     * Returns the component associated with the entity
     */
    T& getData(Entity entity)
    {
        // "Entity does not exist in component."
        assert(entityToData.count(entity));

        return (data[entityToData[entity]]);
    }

    /*
     * Removes the entity from the component array
     */
    virtual void entityDestroyed(Entity entity) override
    {
        if (entityToData.count(entity))
            removeData(entity);
    }

    /*
     * Prints the entities stored in the component array
     */
    virtual void print() const override
    {
        for (size_t i = 0; i < currentSize; ++i)
            std::cout << data.at(i) << " ";
        std::cout << std::endl;
    }
};

#endif
