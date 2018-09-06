cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

project(test)

set(NAME create)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -stdlib=libc++")

find_package(Boost REQUIRED system serialization)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(
	${NAME}
	main.cpp
	Levels.cpp
	Map.cpp
	Error.cpp
)

target_link_libraries( ${NAME} PUBLIC ${Boost_LIBRARIES} )
