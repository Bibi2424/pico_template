add_executable(${PROJECT_NAME}
    main.c
    )

# pull in common dependencies
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    pico_led_lib
    )

if(PICO_BOARD STREQUAL pico_w)
target_link_libraries(${PROJECT_NAME}
    pico_cyw43_arch_none
    )
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

# Enable USB serial
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)