#pragma once

#include <thread>
#include <pstreams/pstream.h>
#include <iostream>

#include "available_connection.hpp"


class Action_Panel;

class Connection_Handler
{
public:
    struct handler_info
    {
        Action_Panel *_action_panel;
        Available_Connection _connection;
        handler_info(Action_Panel *action_panel,
                     Available_Connection connection) : _connection(connection)
        {
            _action_panel = action_panel;
        }
        handler_info(handler_info &h)
            : _connection(h._connection)
        {
            _action_panel = h._action_panel;
        }
    };

private:
    std::thread *_thread = nullptr;
    redi::ipstream *stream = nullptr;

    void run();

    handler_info _info;

public:
    Connection_Handler(handler_info info);
    ~Connection_Handler();

    /**
     * Starts a Thread handling the OVPN connection */
    void start();
    /**
     * Kills the OVPN connection if it was started */
    void end();
};
