#include "main_window.hpp"

Main_Window::Main_Window ()
{
    set_default_size(800, 800);
    set_title("Open VPN GUI");

    _grid.attach(_connection_panel,0,0,1,1);
    _grid.attach(_action_panel,1,0,1,1);
    _grid.attach(_log_panel,0,1,2,1);

    _log_panel.append_message("lalalalalalalla\n");
    _log_panel.append_message("lalalalalalalla\n");
    _log_panel.append_message("lalalalalalalla\n");
    _log_panel.append_message("lalalalalalalla\n");

    add(_grid);

    show_all_children();
}

Main_Window::~Main_Window ()
{
}