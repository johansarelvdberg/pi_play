# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

include_directories(.)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/pi/dev/pico/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(Test C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Test Test.cpp functions.cpp)

pico_set_program_name(Test "Test")
pico_set_program_version(Test "0.1")

pico_enable_stdio_uart(Test 1)
pico_enable_stdio_usb(Test 0)

# Add the standard library to the build
target_link_libraries(Test
        pico_stdlib
        pico_multicore)

# Add the standard include files to the build
target_include_directories(Test PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# set the floating point compiler
pico_set_float_implementation(Test pico)
pico_set_double_implementation(Test pico)

# multi core
pico_enable_stdio_usb(Test 0)
pico_enable_stdio_uart(Test 1)


pico_add_extra_outputs(Test)