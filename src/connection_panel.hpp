#pragma once

#include <gtkmm.h>
#include <vector>

#include "available_connection.hpp"
#include "action_panel.hpp"
#include "connection_widget.hpp"

class Connection_Panel : public Gtk::ScrolledWindow
{
private:
    Gtk::ListBox _list_box;
    std::vector<Connection_Widget *> _vec_conn_widgets;
    Action_Panel *_action_panel;

public:
    Connection_Panel();
    ~Connection_Panel();
    void set_connections(std::vector<Available_Connection> connections);
    void clear();
    void set_action_panel(Action_Panel *action_panel);
    void set_selected_connection(Available_Connection connection);
};
