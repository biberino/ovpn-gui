#pragma once

#include <string>

class Available_Connection
{
private:
    std::string _full_path;
    std::string _dispslay_name;

public:
    Available_Connection(std::string path);
    ~Available_Connection();
};


