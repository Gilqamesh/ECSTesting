#include "Simulators/ComponentArraySimulator.hpp"
#include "Simulators/ComponentManagerSimulator.hpp"
#include "Simulators/SystemManagerSimulator.hpp"
#include "Simulators/CoordinatorSimulator.hpp"
#include <exception>
#include <iostream>

int main()
{
    // ComponentArray Simulation
    // try
    // {
    //     ComponentArraySimulator *componentArraySimulator = new ComponentArraySimulator();
    //     componentArraySimulator->main();
    //     delete componentArraySimulator;
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // ComponentManager Simulation
    // try
    // {
    //     ComponentManagerSimulator *componentManagerSimulator = new ComponentManagerSimulator();
    //     componentManagerSimulator->main();
    //     delete componentManagerSimulator;
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // SystemManager Simulation
    // try
    // {
    //     SystemManagerSimulator *systemManagerSimulator = new SystemManagerSimulator();
    //     systemManagerSimulator->main();
    //     delete systemManagerSimulator;
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // Coordinator Simulation
    try
    {
        CoordinatorSimulator *coordinatorSimulator = new CoordinatorSimulator();
        coordinatorSimulator->main();
        delete coordinatorSimulator;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
