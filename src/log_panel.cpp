#include "log_panel.hpp"

Log_Panel::Log_Panel(/* args */)
{
    _ref_text_buffer = Gtk::TextBuffer::create();
    _ref_text_buffer->set_text("INIT\n");
    _log_view.set_buffer(_ref_text_buffer);
    _log_view.set_editable(false);
    set_size_request(500, 300);

    _grid.attach(_log_view, 0, 0, 1, 1);

    add(_grid);

    show_all_children();
}

Log_Panel::~Log_Panel()
{
}

void Log_Panel::append_message(std::string msg)
{
    _ref_text_buffer->place_cursor(_ref_text_buffer->end());
    _ref_text_buffer->insert_at_cursor(msg);

    /**scroll down **/
    Glib::RefPtr<Gtk::Adjustment> adj = get_vadjustment();
    adj->set_value(adj->get_upper());
}
