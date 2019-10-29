#include <iostream>
#include <gtkmm.h>

#include "main_window.hpp"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "biber.ovpn.gui");
    Main_Window main_window;

    std::setlocale(LC_ALL, "C");

    std::srand(std::time(nullptr));

    return app->run(main_window);
}
