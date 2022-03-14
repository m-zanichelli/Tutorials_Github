cmake_minimum_required(VERSION 3.5)

project(Tutorial VERSION 1.0)
add_executable(${PROJECT_NAME} main.cpp )

#adder use logic
option(USE_ADDER "A simple library to add two floats" ON)
if (USE_ADDER)
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIBS Adder)
    list(APPEND EXTRA_INCLUDES "${PROJEC_SOURCE_DIR}/Adder")
    target_include_directories(${PROJECT_NAME}
        PUBLIC Adder
        )
    target_link_directories(${PROJECT_NAME}
        PRIVATE Adder
        )
endif()


configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})




add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES}

)
target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    ${EXTRA_LIBS}
)

target_link_libraries(${PROJECT_NAME} adder glfw)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/config.h" DESTINATION include)
