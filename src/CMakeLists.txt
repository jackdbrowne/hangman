include_directories(${CMAKE_SOURCE_DIR}/includes)
# link_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(hangman game.c list.c)