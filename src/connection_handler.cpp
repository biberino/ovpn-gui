#include "connection_handler.hpp"
#include "action_panel.hpp"

Connection_Handler::Connection_Handler(handler_info info)
    : _info(info)
{
}

Connection_Handler::~Connection_Handler()
{
    if (_thread)
    {
        _thread->join();
        delete _thread;
    }
    std::cout << "Conection Handler for: " << _info._connection.get_display_name() << " destroyed" << std::endl;
}

void Connection_Handler::run()
{
    std::cout << "Connection " << _info._connection.get_display_name() << " has started!" << std::endl;

    _info._action_panel->delete_handler_object(_info._connection.get_display_name());
}

void Connection_Handler::start()
{
    if (_thread)
    {
        std::cout << "Es läuft bereits ein Thread!" << std::endl;
        return;
    }

    _thread = new std::thread(&Connection_Handler::run, this);
}
