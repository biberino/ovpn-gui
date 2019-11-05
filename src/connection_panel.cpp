#include <iostream>
#include "connection_panel.hpp"

Connection_Panel::Connection_Panel()
{
    set_size_request(400, 400);
    _list_box.set_selection_mode(Gtk::SELECTION_NONE);
    add(_list_box);
    show_all_children();
}

void Connection_Panel::set_action_panel(Action_Panel *action_panel)
{
    _action_panel = action_panel;
}

Connection_Panel::~Connection_Panel()
{
}

void Connection_Panel::set_selected_connection(Available_Connection connection)
{
    if (_action_panel)
        _action_panel->set_selected_connection(connection);
}

void Connection_Panel::set_connections(std::vector<Available_Connection> connections)
{
    for (auto c : connections)
    {
        _vec_conn_widgets.push_back(new Connection_Widget(this, c));
        _list_box.add(*_vec_conn_widgets.back());
    }
}

void Connection_Panel::clear()
{
    for (auto w : _list_box.get_children())
    {
        delete w;
    }
    _vec_conn_widgets.clear();
}
