cmake_minimum_required(VERSION 3.10)

project(ui-app)
set (SOURCES
    "src/main.c"
    "src/resources.rc"
    "src/window.c"
    "src/settings.c"
    "src/edit_menu.c"
    "src/file_menu.c"
    "src/load_settings.c"
    "src/save_settings.c"
    "src/menu.c"
    "src/settings.c"
)

add_executable(ui-app WIN32 ${SOURCES})

target_include_directories(ui-app PRIVATE "inc")

target_link_libraries(ui-app PRIVATE user32.lib gdi32.lib shell32.lib)