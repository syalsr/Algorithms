#pragma once

#include <cstring>
#include <vector>
std::size_t fibonacci(std::size_t number)
{
    std::vector<std::size_t> fib(number, 0);
    fib[0] = 1; fib[1] = 1;
    for(std::size_t i = 2; i < number; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib.back();
}