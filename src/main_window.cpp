#include "main_window.hpp"
#include <vector>
#include <iostream>
#include "helpers.hpp"

Main_Window::Main_Window()
{
    set_default_size(800, 800);
    set_title("Open VPN GUI");

    _grid.attach(_connection_panel, 0, 0, 1, 1);
    _grid.attach(_action_panel, 1, 0, 1, 1);
    _grid.attach(_log_panel, 0, 1, 2, 1);

    _connection_panel.set_connections(scan_config_dir("/home/biber/robin/sandbox/test/"));
    _connection_panel.set_action_panel(&_action_panel);

    add(_grid);

    show_all_children();
}

Main_Window::~Main_Window()
{
}