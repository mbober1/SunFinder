cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_SDK_PATH "/home/mbober/Documents/pico-sdk")

include(pico_sdk_import.cmake)

project(main C CXX ASM)

pico_sdk_init()

add_executable(main main.cpp )

pico_set_program_name(main "main")
pico_set_program_version(main "0.1")

pico_enable_stdio_uart(main 1)
pico_enable_stdio_usb(main 0)

target_link_libraries(main pico_stdlib)

target_link_libraries(main
  hardware_pwm
  hardware_adc
  hardware_irq
)
add_subdirectory(Srcpp)

pico_add_extra_outputs(main)


#set(FILE_ELF ${CMAKE_PROJECT_NAME}.elf)
#set(FILE_HEX ${CMAKE_PROJECT_NAME}.hex)









