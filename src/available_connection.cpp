#include "available_connection.hpp"
#include "helpers.hpp"

Available_Connection::Available_Connection(std::string path)
{
    //eg /etc/ovpn-gui/lala.ovpn
    _full_path = path;

    _dispslay_name = split(split(_full_path, '/').back(),'.')[0];

}

Available_Connection::~Available_Connection()
{
}