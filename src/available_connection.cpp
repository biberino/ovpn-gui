#include "available_connection.hpp"
#include "helpers.hpp"

Available_Connection::Available_Connection(std::string path)
{
    //eg /etc/ovpn-gui/lala.ovpn
    _full_path = path;

    _display_name = split(split(_full_path, '/').back(), '.')[0];
}

Available_Connection::Available_Connection(const Available_Connection &con)
{
    _full_path = con.get_full_path();
    _display_name = con.get_display_name();
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
