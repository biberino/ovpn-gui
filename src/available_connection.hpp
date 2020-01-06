#pragma once

#include <string>

class Available_Connection
{
private:
    std::string _full_path;
    std::string _display_name;
    std::string _directory;

public:
    Available_Connection(std::string path);
    Available_Connection(const Available_Connection &con);
    ~Available_Connection();

    std::string get_display_name() const;
    std::string get_full_path() const;
    std::string get_directory() const;
};
