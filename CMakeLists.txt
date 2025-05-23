# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")


cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(st7789_test C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(st7789_test
    st7789_test.c
    st7789/st7789.c
)

target_include_directories(st7789_test PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/st7789
)

target_link_libraries(st7789_test pico_stdlib hardware_spi)

pico_add_extra_outputs(st7789_test)
