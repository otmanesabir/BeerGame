# Specify minimum required version of cmake
cmake_minimum_required(VERSION 3.10)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/local/opt/qt;/home/linuxbrew/.linuxbrew/opt/qt;C:\\Qt")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
qt5_add_resources(resource.qrc)

include_directories(../include)

add_executable(beergame-client
        run-client.cpp
        client.cpp
        client.h
)


add_executable(beergame-server
        run-server.cpp
        server.cpp
        server.h
        # BELOW IS COMMON
        ../src/Game.cpp
        ../src/Player.cpp
        ../src/PlayerEvent.cpp
        ../src/Shipment.cpp
        ../src/Order.cpp
        ../src/Instructor.cpp
        ../src/UniqueID.cpp
        ../src/Exceptions.cpp
        ../src/welcome.cpp
        ../src/welcome.ui
        ../src/instrwindow.cpp
        ../src/instrwindow.ui
        ../src/playerwindow.cpp
        ../src/playerwindow.ui
        ../include/welcome.h
        ../include/instrwindow.h
        ../include/playerwindow.h
)

target_link_libraries(beergame-client PRIVATE Qt5::Widgets Qt5::Network)
target_link_libraries(beergame-server PRIVATE Qt5::Widgets Qt5::Network)