cmake_minimum_required(VERSION 3.19)

project(simple-yt-dlp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(AddDependencies)

# Add Binary
qt_add_executable(simple-yt-dlp)
add_subdirectory(src)
qt_add_qml_module(simple-yt-dlp
        URI SimpleYtDlp
        VERSION 1.0
        QML_FILES src/Main.qml
)

include(GNUInstallDirs)
install(TARGETS simple-yt-dlp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
