add_executable(PicoTemplate
        main.c
        )

# pull in common dependencies
target_link_libraries(PicoTemplate pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(PicoTemplate)

# Enable USB serial
pico_enable_stdio_usb(PicoTemplate 1)
pico_enable_stdio_uart(PicoTemplate 0)