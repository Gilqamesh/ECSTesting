#include "Simulators/ComponentArraySimulator.hpp"
#include "ComponentArray.hpp"
#include "Managers/EntityManager.hpp"
#include <iostream>
#include <ctime>

void ComponentArraySimulator::main()
{
    std::srand(42);
    ComponentArray<int> componentArr;
    EntityManager entityManager;
    std::vector<Entity> entities;
    for (int i = 0; i < MAX_ENTITIES; ++i)
    {
        Entity tmp = entityManager.createEntity();
        entities.push_back(tmp);
        componentArr.insertData(tmp, i);
    }
    // componentArr.print();
    for (int i = 0; i < MAX_ENTITIES; ++i)
    {
        int rand = std::rand() % MAX_ENTITIES;
        // std::cout << "rand: " << rand << std::endl;
        componentArr.entityDestroyed(entities[rand]);
        // componentArr.print();
    }
}
