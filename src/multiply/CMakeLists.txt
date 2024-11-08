add_library(multiply STATIC
    multiply.cpp
)

target_include_directories(multiply PUBLIC include)


find_package(fmt)
find_package(spdlog)

target_link_libraries(multiply 
    fmt::fmt 
    spdlog::spdlog
)

