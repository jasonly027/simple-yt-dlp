message(STATUS "Installing pybind11")

CPMAddPackage("gh:pybind/pybind11@2.11")
target_link_libraries(web-media-downloader-gui PRIVATE
    pybind11::embed
)
