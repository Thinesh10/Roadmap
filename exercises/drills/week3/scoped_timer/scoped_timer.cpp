#include "scoped_timer.h"
#include <iostream>
#include <format>

ScopedTimer::ScopedTimer(std::string s) noexcept:
    name_(std::move(s)), start_(std::chrono::steady_clock::now()) {};


ScopedTimer::~ScopedTimer() noexcept
{
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_).count();

    try 
    {
        std::cout << std::format("Name {}, Duration {} ms", name_, duration) << std::endl;
    }
    catch (...)
    {
        // to guarantee RAII swallow exceptions
    }
}

