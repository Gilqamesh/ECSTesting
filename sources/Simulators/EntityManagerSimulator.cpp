#include "Simulators/EntityManagerSimulator.hpp"
#include "Managers/EntityManager.hpp"
#include <vector>
#include <ctime>

void EntityManagerSimulator::main()
{
    std::srand(42);
    EntityManager *entityManager = new EntityManager();
    std::vector<Entity> entities;
    for (unsigned int i = 0; i < 100; ++i)
    {
        entities.push_back(entityManager->createEntity());
    }
}
