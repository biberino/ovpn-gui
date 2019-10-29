link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(ovpn-gui
            main.cpp
            main_window.cpp
            helpers.cpp
            available_connection.cpp
            log_panel.cpp
            action_panel.cpp
            connection_panel.cpp
            )


target_link_libraries(ovpn-gui
                    ${GTKMM_LIBRARIES})