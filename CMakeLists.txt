cmake_minimum_required(VERSION 3.19)

project(web-media-downloader-gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(web-media-downloader-gui
    src/testpy.h src/testpy.cpp)
add_subdirectory(src)
add_subdirectory(qml)

set_target_properties(web-media-downloader-gui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER net.jasonly027.web-media-downloader-gui
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(web-media-downloader-gui
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS web-media-downloader-gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Dependencies
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(CPM)

include(AddPybind)
