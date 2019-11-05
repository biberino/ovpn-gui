#pragma once

#include <vector>
#include <string>
#include "available_connection.hpp"

std::vector<std::string> split(const std::string &s, char delimiter);
std::vector<Available_Connection> scan_config_dir(std::string path);
