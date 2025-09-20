#pragma once

#include <cstdio>
#include <filesystem>
#include <memory>

class RAII
{
    public:
        explicit RAII(const std::filesystem::path& path, const char* mode);
        ~RAII() noexcept = default;
        
        RAII(const RAII& r) = delete;
        RAII& operator=(const RAII& r) = delete;

        RAII(RAII&& f) noexcept = default;
        RAII& operator=(RAII&& f) noexcept = default;

        [[nodiscard]] FILE* get() const noexcept { return fp_.get(); };

    private:
        struct deleter 
        {
            void operator()(FILE* f) const noexcept
            {
                if (f) std::fclose(f);
            }
        };

    std::unique_ptr<FILE, deleter> fp_{};
};