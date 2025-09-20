#pragma once

#include <chrono>

class ScopedTimer
{
    public:
        explicit ScopedTimer(std::string name) noexcept;
        ~ScopedTimer() noexcept;

        ScopedTimer(const ScopedTimer& st) = delete;
        ScopedTimer& operator=(const ScopedTimer& st) = delete;

        ScopedTimer(ScopedTimer&& ) = default;
        ScopedTimer& operator=(ScopedTimer&& ) = default;


    private:
        std::string name_;
        std::chrono::steady_clock::time_point start_;
}