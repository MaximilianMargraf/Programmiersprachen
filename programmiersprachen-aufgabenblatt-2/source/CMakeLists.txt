# Build example
add_executable(example
  window.cpp
  glew.c
  color.hpp
  vec2.cpp
  mat2.cpp
  rectangle.cpp
  circle.cpp
  example.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build clock
add_executable(clock
  window.cpp
  glew.c
  color.hpp
  vec2.cpp
  mat2.cpp
  rectangle.cpp
  circle.cpp
  clock.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  color.hpp
  circle.cpp
  rectangle.cpp
  tests.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )


