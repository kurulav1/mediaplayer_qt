set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED)

add_executable(media-player
    main.cpp
    mainwindow.cpp
    mainwindow.h
    media.cpp
    media.h
    metadata.cpp
    metadata.h
)

target_link_libraries(
    media-player
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Multimedia
    PRIVATE tag
    PRIVATE z
)
