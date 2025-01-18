cmake_minimum_required(VERSION 3.5)

project(main VERSION 1.0.0)
# if(${CMAKE_BUILD_TYPE} MATCHES Debug)
#     add_executable(main SRC)
# else()
#     add_executable(main SRC)
# endif()
add_executable(main
    ${CMAKE_SOURCE_DIR}/headers/vectors.h
    ${CMAKE_SOURCE_DIR}/headers/linmath.h

    ${CMAKE_SOURCE_DIR}/includes/glad/glad.c
    ${CMAKE_SOURCE_DIR}/src/engine_data.c
    ${CMAKE_SOURCE_DIR}/src/assets/loadmodel.c
    ${CMAKE_SOURCE_DIR}/src/graphics/opengl/shader_compillers.c
    ${CMAKE_SOURCE_DIR}/src/graphics/opengl/graphics.c
    ${CMAKE_SOURCE_DIR}/src/inputs.c
    ${CMAKE_SOURCE_DIR}/src/fileloader.c
    ${CMAKE_SOURCE_DIR}/src/main.c
)

target_include_directories(main
    PRIVATE ${CMAKE_SOURCE_DIR}/headers/
    PRIVATE ${CMAKE_SOURCE_DIR}/includes/glad/
    PRIVATE ${CMAKE_SOURCE_DIR}/includes/glfw/
    PRIVATE ${CMAKE_SOURCE_DIR}/includes/gl/
    PRIVATE ${CMAKE_SOURCE_DIR}/includes/
)

target_link_libraries(main
    PRIVATE ${CMAKE_SOURCE_DIR}//includes/glfw/glfw3.dll
)

configure_file(shaders/frag.glsl shaders/frag.glsl COPYONLY)
configure_file(shaders/vert.glsl shaders/vert.glsl COPYONLY)
configure_file(models/testcube.glb models/testcube.glb COPYONLY)
configure_file(models/triangle.glb models/triangle.glb COPYONLY)

# install(TARGETS main RUNTIME DESTINATION "./")
# install(DIRECTORY "${PROJECT_SOURCE_DIR}/shaders/" DESTINATION "shaders/")
# include(CPack)