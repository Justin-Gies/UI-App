cmake_minimum_required(VERSION 3.10)

project(ui-app)
set (SOURCES
    "src/main.c"
    "src/resources.rc"
)

add_executable(ui-app WIN32 ${SOURCES})

target_include_directories(ui-app PRIVATE "include")

target_link_libraries(ui-app PRIVATE user32.lib gdi32.lib shell32.lib)