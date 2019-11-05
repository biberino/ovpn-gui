#include "action_panel.hpp"

Action_Panel::Action_Panel(/* args */)
{
    _grid.attach(_lbl_connection_name, 0, 0, 1, 1);
    _grid.attach(_btn_connect, 0, 1, 1, 1);
    _btn_connect.set_label("Connect");
    add(_grid);
    show_all_children();

    _btn_connect.signal_clicked()
        .connect(sigc::mem_fun(*this,
                               &Action_Panel::on_button_connect_click));

    _dispatcher.connect(sigc::mem_fun(*this, &Action_Panel::on_dispatcher_emit));
}

Action_Panel::~Action_Panel()
{
    if (_current_connection)
        delete _current_connection;
}

void Action_Panel::set_selected_connection(Available_Connection connection)
{
    if (_current_connection)
        delete _current_connection;
    _current_connection = new Available_Connection(connection);

    _lbl_connection_name.set_text(_current_connection->get_display_name());
}

void Action_Panel::on_button_connect_click()
{
    if (!_current_connection)
        return;

    if (_map_handlers.find(_current_connection->get_display_name()) != _map_handlers.end())
        return;
    Connection_Handler::handler_info h(this, *_current_connection);
    Connection_Handler *c = new Connection_Handler(h);

    _map_handlers[_current_connection->get_display_name()] = c;
    c->start();
}

void Action_Panel::on_dispatcher_emit()
{
    std::lock_guard<std::mutex> lock(_mutex);
    for( auto h: _vec_handlers_to_be_deleted)
    {
        if (_map_handlers.find(h) == _map_handlers.end())
            continue;
        //destructor will join
        delete _map_handlers[h];
        _map_handlers.erase(h);
    }

    _vec_handlers_to_be_deleted.clear();
}

void Action_Panel::delete_handler_object(std::string identifier)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _vec_handlers_to_be_deleted.push_back(identifier);
    _dispatcher.emit();
}
