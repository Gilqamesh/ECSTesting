#include <ctime>
#include <cstdint>
#include <vector>

int main()
{
    std::vector<int> entities;
    std::srand(42);
    for (int i = 0; i < UINT16_MAX; ++i)
        entities.push_back(i);
    for (int i = 0; i < UINT16_MAX; ++i)
    {
        int rand = std::rand() % UINT16_MAX;
        ++rand;
    }
}