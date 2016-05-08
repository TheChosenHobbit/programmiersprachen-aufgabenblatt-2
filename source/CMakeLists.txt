# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  color.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(example glfw ${COPY_BINARY})


# Build tests
add_executable(tests
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  glew.c
  color.cpp
  tests.cpp)
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES})


# Build analog_watch
add_executable(analog_watch
  window.cpp
  glew.c
  circle.cpp
  vec2.cpp
  mat2.cpp
  analog_watch.cpp)
target_link_libraries(analog_watch
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(analog_watch glfw ${COPY_BINARY})
