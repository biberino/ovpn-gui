project(ovpn-gui)

set (CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

add_subdirectory(src)