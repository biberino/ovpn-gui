#pragma once

#include <gtkmm.h>
#include <string>
#include <mutex>


class Log_Panel : public Gtk::ScrolledWindow
{
private:
    Gtk::Grid _grid;
    Gtk::TextView _log_view;
    Glib::RefPtr<Gtk::TextBuffer> _ref_text_buffer;

    std::mutex _mutex;


public:
    Log_Panel(/* args */);
    ~Log_Panel();
    void append_message(std::string msg);
};
