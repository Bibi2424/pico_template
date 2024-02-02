add_executable(test_dummy_lib_app
    test_dummy_app.c
)

target_link_libraries(test_dummy_lib_app
    dummy_lib
    Unity
)

add_test(test_dummy_lib_test test_dummy_lib_app)