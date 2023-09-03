cmake_minimum_required(VERSION 3.27.4)

project(shiza
	VERSION 0.0
	DESCRIPTION "A full optimized and fast programming language for real chads"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# I think we would like here to compile everything, everything could contain main file so we can test that
# For now it would be only main
add_executable(shiza src/main.cc)

# I guess this sucks, but for now let it be. We will have to change it later
target_compile_options(shiza PRIVATE -Wall -Wextra)
