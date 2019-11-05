#include "connection_panel.hpp"
#include "connection_widget.hpp"
#include <iostream>

Connection_Widget::Connection_Widget(Connection_Panel *parent, Available_Connection connection)
    : _connection(connection)
{
    _parent = parent;
    _lbl.set_text(connection.get_display_name());
    _grid.attach(_lbl, 0, 0, 1, 1);
    add(_grid);
    add_events(Gdk::EventMask::BUTTON_PRESS_MASK);
    signal_button_press_event().connect(
        sigc::mem_fun(*this, &Connection_Widget::on_click));
    show_all_children();
}

bool Connection_Widget::on_click(GdkEventButton *event)
{
    std::cout << _connection.get_display_name() << std::endl;
    _parent->set_selected_connection(_connection);
}

Connection_Widget::~Connection_Widget()
{
}