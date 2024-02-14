set_target_properties(simple-yt-dlp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER net.jasonly027.simple-yt-dlp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_sources(simple-yt-dlp PRIVATE
    main.cpp
)

add_subdirectory(YtDlp)
target_link_libraries(simple-yt-dlp
PRIVATE
    Qt6::Quick
    yt_dlpplugin
)