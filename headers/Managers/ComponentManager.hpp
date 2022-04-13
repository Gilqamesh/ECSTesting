#ifndef COMPONENTMANAGER_HPP
# define COMPONENTMANAGER_HPP

# include <unordered_map>
# include "ComponentArray.hpp"
# include "Types.hpp"

/*
 * Bookkeeps component arrays
 * Provides an api to manage entity component relationship
 * Distributes unique IDs for each component (the bit in the bitset for a ComponentSignature)
 */
class ComponentManager
{
std::unordered_map<const char *, ComponentId> NameToId; /* component name to component id */
std::unordered_map<const char *, IComponentArray *> NameToArr; /* component name to component array */
ComponentId currentId;
public:
    ComponentManager()
        : currentId(0) { }

    ~ComponentManager()
    {
        for (auto nameToArrPair : NameToArr)
            delete nameToArrPair.second;
    }

    /*
     * Register component of type T to the manager
     */
    template <typename T>
    void registerComponent()
    {
        // Number of components in the manager reached maximum size MAX_COMPONENTS
        assert(currentId != MAX_COMPONENTS);
        const char *componentType = typeid(T).name();
        // Component type is already registered
        assert(NameToId.count(componentType) == 0);
        NameToId[componentType] = currentId++;
        NameToArr[componentType] = new ComponentArray<T>();
    }

    /*
     * Returns the id (essentially the bit in the bitset) held for the component of type T
     */
    template <typename T>
    ComponentId getComponentId() const
    {
        const char *componentType = typeid(T).name();
        // Component type is not registered
        assert(NameToId.count(componentType));
        return (NameToId.at(componentType));
    }

    /*
     * Adds a component type T to an entity
     */
    template <typename T>
    void addComponent(Entity entity, T component)
    {
        const char *componentType = typeid(T).name();
        // Component type is not registered
        assert(NameToArr.count(componentType));
        return (static_cast<ComponentArray<T> *>(NameToArr[componentType])->insertData(entity, component));
    }

    /*
     * Removes a component of type T from an entity
     */
    template <typename T>
    void removeComponent(Entity entity)
    {
        const char *componentType = typeid(T).name();
        // Component type is not registered
        assert(NameToArr.count(componentType));
        return (static_cast<ComponentArray<T> *>(NameToArr[componentType])->removeData(entity));
    }

    /*
     * Returns the component data of type T in entity
     */
    template <typename T>
    T& getComponent(Entity entity)
    {
        const char *componentType = typeid(T).name();
        // Component type is not registered
        assert(NameToArr.count(componentType));
        return (static_cast<ComponentArray<T> *>(NameToArr[componentType])->getData(entity));
    }

    /*
     * Updates all component arrays when entity is destroyed
     */
    void entityDestroyed(Entity entity)
    {
        for (const auto &nameToArrPair : NameToArr)
        {
            nameToArrPair.second->entityDestroyed(entity);
        }
    }

    /*
     * Prints out the ids associated with component names
     * For each of these components, it also prints their underlying data
     */
    void print() const
    {
        for (const auto &nameToIdPair : NameToId)
        {
            std::cout << "Component name: " << nameToIdPair.first << std::string(", component id: ") << (int)nameToIdPair.second << std::endl;
            NameToArr.at(nameToIdPair.first)->print();
        }
    }
};

#endif
