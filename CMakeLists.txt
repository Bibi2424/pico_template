cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(TARGET_GROUP production CACHE STRING "Group to build")

if(TARGET_GROUP STREQUAL production)
	include(pico-sdk/pico_sdk_init.cmake)

	project(MMAHD C CXX ASM)

	# Initialize the SDK
	pico_sdk_init()

	add_subdirectory(src)
	add_subdirectory(lib)

elseif(TARGET_GROUP STREQUAL test)
	# Test will be run with computer compiler
	project(MMAHD_test C CXX ASM)
    include(CTest)

	add_subdirectory(lib)
    add_subdirectory(unity)
    add_subdirectory(test)

# elseif(TARGET_GROUP STREQUAL on_target_test)
	# TODO:
	
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")

endif()

