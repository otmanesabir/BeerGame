set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(GTest REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

if (COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif (COMMAND cmake_policy)

set(CMAKE_PREFIX_PATH "/usr/local/opt/qt;/home/linuxbrew/.linuxbrew/opt/qt;C:\\Qt")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_add_resources(resource.qrc)

include_directories(../include)

add_executable(beergame-test
        tests_sprint5.cpp
        gameTests.cpp
        instructorTests.cpp
        cExceptionsTests.cpp
        playerTests.cpp
        UniqueIDTests.cpp

        ../src/Instructor.cpp
        ../src/Game.cpp
        ../src/Player.cpp
        ../src/Order.cpp
        ../src/PlayerEvent.cpp
        ../src/Order.cpp
        ../src/Shipment.cpp
        ../src/UniqueID.cpp
        ../src/Exceptions.cpp

        ../src/welcome.ui
        ../src/welcome.cpp
        ../src/instrwindow.cpp
        ../src/instrwindow.ui
        ../src/playerwindow.cpp
        ../src/playerwindow.ui
        ../src/instrgeneratepassword.cpp
        ../src/instrgeneratepassword.ui
        ../include/instrgeneratepassword.h
        ../include/welcome.h
        ../include/instrwindow.h
        ../include/playerwindow.h
        PlayerEventTests.cpp OrderTests.cpp ShipmentTests.cpp)


target_link_libraries(beergame-test
        GTest::GTest GTest::Main Qt5::Widgets)

ADD_CUSTOM_TARGET(debug-test
        COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
        COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
        )

ADD_CUSTOM_TARGET(release-test
        COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
        COMMENT "Switch CMAKE_BUILD_TYPE to Release"
        )