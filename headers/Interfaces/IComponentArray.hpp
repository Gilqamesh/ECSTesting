#ifndef ICOMPONENTARRAY_HPP
# define ICOMPONENTARRAY_HPP

class Entity;

class IComponentArray
{
public:
    virtual ~IComponentArray() = default;
    virtual void entityDestroyed(Entity entity) = 0;
    virtual void print() const = 0;
};

#endif
