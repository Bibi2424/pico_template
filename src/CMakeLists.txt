add_executable(MMAHD
        main.c
        )

# pull in common dependencies
target_link_libraries(MMAHD 
        pico_stdlib
        dummy_lib
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(MMAHD)

# Enable USB serial
pico_enable_stdio_usb(MMAHD 1)
pico_enable_stdio_uart(MMAHD 0)