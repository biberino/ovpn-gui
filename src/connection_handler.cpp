#include <unistd.h>
#include <fstream>
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

    std::string command = "sudo -A openvpn --config " + _info._connection.get_full_path()
                            + " --writepid " + _info._connection.get_display_name() + ".pid";
    chdir(_info._connection.get_directory().c_str());
    std::cout << command << std::endl;
    std::cout << _info._connection.get_directory() << std::endl;
    redi::ipstream in(command);
    stream = &in;

    std::string line;
    //this is blocking and will end as soon as the process ends
    while (std::getline(in, line))
    {
        //std::cout << line << std::endl;
        _info._action_panel->forward_log_message(line);
    }

    //delete this handler object from parent
    _info._action_panel->delete_handler_object(_info._connection.get_display_name());
}

void Connection_Handler::start()
{
    if (_thread)
    {
        std::cout << "A thread for this handler is already running!" << std::endl;
        return;
    }

    _thread = new std::thread(&Connection_Handler::run, this);
}

void Connection_Handler::end()
{
    /* doesn't word since we are not root */
    //if (stream)
    //    stream->rdbuf()->killpg();

    std::string pid_file = _info._connection.get_directory() + "/" + _info._connection.get_display_name() + ".pid";
    std::ifstream f(pid_file);
    std::string pid;
    if (f.good())
    {
        f >> pid;
    }else
    {
        std::cout << "Could not open pid file: " << pid_file << std::endl;
    }

    system(("sudo -A kill " + pid).c_str());
}
