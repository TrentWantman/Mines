#include "random.h"
#include <ctime>

std::mt19937 random::Random(time(0));

int random::Int(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(Random);
}