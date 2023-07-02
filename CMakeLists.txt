
project(array_library)

add_library(array SHARED src/array.c)
set_property(TARGET array PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(array PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main example/main.c)
target_link_libraries(main PRIVATE array)

