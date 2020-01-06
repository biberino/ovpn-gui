#include "available_connection.hpp"
#include "helpers.hpp"
#include <iostream>

Available_Connection::Available_Connection(std::string path)
{
    //eg /etc/ovpn-gui/lala.ovpn
    _full_path = path;

    std::vector<std::string> buffer;
    buffer = split(_full_path, '/');
    _display_name = split(buffer.back(), '.')[0];
    _directory = "";
    for (size_t i = 1; i < buffer.size() - 1; i++)
    {
        _directory = _directory + "/" + buffer[i];
    }
}

Available_Connection::Available_Connection(const Available_Connection &con)
{
    _full_path = con.get_full_path();
    _display_name = con.get_display_name();
    _directory = con.get_directory();
}

Available_Connection::~Available_Connection()
{
}

std::string Available_Connection::get_display_name() const
{
    return _display_name;
}

std::string Available_Connection::get_full_path() const
{
    return _full_path;
}

std::string Available_Connection::get_directory() const
{
    return _directory;
}
