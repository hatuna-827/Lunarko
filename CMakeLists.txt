cmake_minimum_required(VERSION 3.16)
project(Lunarko)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE TEST_FILES test/*.cpp)
qt_add_executable(Lunarko
    ${SRC_FILES}
    # ${TEST_FILES}
    resources/app.qrc
)

target_link_libraries(Lunarko
    PRIVATE Qt6::Widgets
)
