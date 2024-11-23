add_library(pico_led_lib STATIC
    pico_led.c
    )

target_link_libraries(pico_led_lib
    pico_stdlib
    )

if(PICO_BOARD STREQUAL pico_w)
target_link_libraries(pico_led_lib
    pico_cyw43_arch_none
    )
endif()

target_include_directories(pico_led_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)