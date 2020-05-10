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
qt5_add_resources(resource.qrc)

include_directories(../include)

add_executable(beergame
        main.cpp
        Game.cpp
        Player.cpp
        PlayerEvent.cpp
        Shipment.cpp
        Order.cpp
        Instructor.cpp
        UniqueID.cpp
        Exceptions.cpp
        welcome.cpp
        welcome.ui
        instrwindow.cpp
        instrwindow.ui
        playerwindow.cpp
        playerwindow.ui
        ../include/welcome.h
        ../include/instrwindow.h
        ../include/playerwindow.h

        )

target_link_libraries(beergame PRIVATE Qt5::Widgets)

ADD_CUSTOM_TARGET(debug
        COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
        COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
        )

ADD_CUSTOM_TARGET(release
        COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
        COMMENT "Switch CMAKE_BUILD_TYPE to Release"
        )