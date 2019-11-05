#pragma once

#include <gtkmm.h>
#include "available_connection.hpp"


class Connection_Panel;

class Connection_Widget : public Gtk::EventBox
{
private:
    Gtk::Label _lbl;
    Gtk::Grid _grid;
    Available_Connection _connection;

    Connection_Panel *_parent;

    bool on_click(GdkEventButton *event);

public:
    Connection_Widget(Connection_Panel *parent, Available_Connection connection);
    ~Connection_Widget();
};


