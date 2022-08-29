cmake_minimum_required (VERSION 3.8)

project ("moving_dude")

include_directories("include")

set(SFML_DIR ./lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS graphics audio system window REQUIRED)

# Add source to this project's executable.
add_executable (moving_dude "src/main.cpp"  "src/App.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET moving_dude PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-audio sfml-system sfml-window)

# TODO: Add tests and install targets if needed.
