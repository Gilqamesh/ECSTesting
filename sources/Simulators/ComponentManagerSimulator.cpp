#include "Simulators/ComponentManagerSimulator.hpp"
#include "Managers/ComponentManager.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/VelocityComponent.hpp"
#include "Managers/EntityManager.hpp"
#include <vector>
#include <ctime>

void ComponentManagerSimulator::main()
{
    std::srand(42);
    ComponentManager *componentManager = new ComponentManager;
    componentManager->registerComponent<PositionComponent>();
    componentManager->registerComponent<VelocityComponent>();
    componentManager->print();
    std::cout << "componentManager->getComponentId<PositionComponent>(): "
        << (int)componentManager->getComponentId<PositionComponent>() << std::endl;
    std::cout << "componentManager->getComponentId<VelocityComponent>(): "
        << (int)componentManager->getComponentId<VelocityComponent>() << std::endl;
    EntityManager *entityManager = new EntityManager();
    std::vector<Entity> entities;
    for (int i = 0; i < 100; ++i)
    {
        entities.push_back(entityManager->createEntity());
        if (std::rand() % 2)
        {
            componentManager->addComponent<PositionComponent>(entities[i],
                {std::rand() % 100 - 50, std::rand() % 100 - 50, std::rand() % 100 - 50});
        }
        else
        {
            componentManager->addComponent<VelocityComponent>(entities[i],
                {std::rand() % 100 - 50, std::rand() % 100 - 50, std::rand() % 100 - 50});
        }
    }
    int r = std::rand() % 100;
    std::cout << "componentManager->getComponent<VelocityComponent>(r): "
        << componentManager->getComponent<VelocityComponent>(entityManager->) << std::endl;
    r = std::rand() % 100;
    std::cout << "componentManager->getComponent<VelocityComponent>(r): "
        << componentManager->getComponent<PositionComponent>(r) << std::endl;
    componentManager->print();
}
