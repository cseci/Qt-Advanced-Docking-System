cmake_minimum_required(VERSION 3.5)
project(ads_example_simple)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} 5.5 COMPONENTS Core Gui Widgets QuickWidgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set_target_properties(${PROJECT} PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    EXPORT_NAME "Qt Advanced Docking System Simple Example"
)

qt5_wrap_ui(UIS MainWindow.ui)
set(COMPILE_OBJECTS main.cpp
    MainWindow.cpp
    ${UIS}
    )

if(ANDROID)
    set(QT_ADS_LIBRARY_NAME qtadvanceddocking_arm64-v8a)
    add_library(${PROJECT_NAME} SHARED
    ${COMPILE_OBJECTS}
)
else()
    set(QT_ADS_LIBRARY_NAME qtadvanceddocking)
    add_executable(${PROJECT_NAME} ${COMPILE_OBJECTS})
endif()
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../src")

target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_ADS_LIBRARY_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core
                                           Qt${QT_VERSION_MAJOR}::Gui 
					   Qt${QT_VERSION_MAJOR}::Widgets
					   Qt${QT_VERSION_MAJOR}::QuickWidgets
					   )

