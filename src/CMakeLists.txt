set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}\
                    -Wall \
                    -Wextra \
                    -Weffc++ \
                    -Werror=uninitialized \
                    -Werror=return-type \
                    -Wconversion \
                    -Wsign-compare \
                    -Werror=unused-result \
                    -Werror=suggest-override \
                    -Wzero-as-null-pointer-constant \
                    -Wmissing-declarations \
                    -Wold-style-cast \
                    -Werror=vla \
                    -Wnon-virtual-dtor"
)

add_subdirectory(multiply)
