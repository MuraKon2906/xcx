#pragma once

#include <filesystem>
namespace fs = std::filesystem;
void hello_from_build();
void _check_build(fs::path prj_path);
