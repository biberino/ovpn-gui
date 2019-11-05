#pragma once

#include <gtkmm.h>

#include "connection_panel.hpp"
#include "log_panel.hpp"
#include "action_panel.hpp"

class Main_Window : public Gtk::Window
{
private:


    Connection_Panel _connection_panel;
    Log_Panel _log_panel;
    Action_Panel _action_panel;

    Gtk::Grid _grid;

public:
    Main_Window (); 
    ~Main_Window ();
};

