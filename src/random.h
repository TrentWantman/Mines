#pragma once
#include <random>

class random
{
    static std::mt19937 Random;
public:

    static int Int(int min, int max);
};