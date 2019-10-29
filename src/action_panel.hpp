#pragma once

#include <gtkmm.h>

class Action_Panel : public Gtk::ScrolledWindow
{
private:
    Gtk::Button _test;

public:
    Action_Panel(/* args */);
    ~Action_Panel();
};

