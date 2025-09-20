#include "raii_class.h"
#include <filesystem>
#include <stdexcept>

explicit RAII::RAII(const std::filesystem::path& path, const char* mode) :
        fp_(std::fopen(path.string().c_str(), mode))
{
    if (!fp_)
    {
        throw std::runtime_error("Failed to open file: " + path.string());
    }
}

