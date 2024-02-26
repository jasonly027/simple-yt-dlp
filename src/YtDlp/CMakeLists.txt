qt_add_library(yt_dlp STATIC)

target_link_libraries(yt_dlp
    PRIVATE Qt6::Quick
)

qt_add_qml_module(yt_dlp
    URI YtDlp
    VERSION 1.0
    SOURCES
        yt_dlp.cpp yt_dlp.h
        executable_worker.cpp executable_worker.h
        executable_controller.cpp executable_controller.h
        notifications.cpp notifications.h
)
