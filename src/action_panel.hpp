#pragma once

#include <gtkmm.h>
#include <vector>
#include <unordered_map>
#include <mutex>
#include "available_connection.hpp"
#include "connection_handler.hpp"
#include "log_panel.hpp"

class Action_Panel : public Gtk::ScrolledWindow
{
private:
    Gtk::Button _btn_connect;
    Gtk::Button _btn_end;
    Gtk::Grid _grid;
    Gtk::Label _lbl_connection_name;

    Log_Panel *log_panel;

    Available_Connection *_current_connection= nullptr;
    std::unordered_map<std::string, Connection_Handler *> _map_handlers;

    std::mutex _mutex;
    Glib::Dispatcher _dispatcher;

    std::vector<std::string> _vec_handlers_to_be_deleted;

protected:
    void on_button_connect_click();
    void on_button_end_click();

    void on_dispatcher_emit();

public:
    Action_Panel(/* args */);
    ~Action_Panel();

    void set_selected_connection(Available_Connection connection);
    void delete_handler_object(std::string identifier);
    void set_log_panel(Log_Panel *lp);
    void forward_log_message(std::string msg);
};
