cmake_minimum_required(VERSION 3.5)

project(GigaChadArbitrage VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network Widgets REQUIRED)

include_directories(
    src
    src/AbstractRequests
    )

set(PROJECT_SOURCES
        src/main.cpp

		src/CoinState.h
		src/config.h
		src/irkenArbitrageScaner.h
		
		src/AbstractRequests/abstractrequests.h

        README.md
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GigaChadArbitrage
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/coin.h
        src/controlUnit.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GigaChadArbitrage APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GigaChadArbitrage SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GigaChadArbitrage
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GigaChadArbitrage
    PRIVATE 
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Threads::Threads)
set_target_properties(GigaChadArbitrage PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GigaChadArbitrage)
endif()
