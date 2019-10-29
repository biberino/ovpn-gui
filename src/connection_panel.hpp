#pragma once

#include <gtkmm.h>

class Connection_Panel : public Gtk::ScrolledWindow
{
private:
    Gtk::Button _test;
public:
    Connection_Panel(/* args */);
    ~Connection_Panel();
};


