cmake_minimum_required(VERSION 3.16)
project(CaliforniaTrail)

option(SDL "Build the program for SDL" ON)
include_directories("${PROJECT_SOURCE_DIR}/lib/PDCurses")
message("Build with SDL=OFF for console support")

if(SDL)
    # Checks to see if git is present
    find_package(Git REQUIRED)

    # Initialize the submodule if not already done so

    # Import SDL2 library
    #add_subdirectory(${PROJECT_SOURCE_DIR}/lib/SDL)
    #add_subdirectory(${PROJECT_SOURCE_DIR}/lib/SDL_ttf)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL_TTF_LIBRARIES})
    find_package(SDL2_ttf REQUIRED)
    include_directories(${SDL_TTF_LIBRARIES})

    set(PDC_FONT, "${PROJECT_SOURCE_DIR}/res/curses_640x300.bmp")

    # Import PDCurses library

    set(LIBRARIES SDL2::SDL2 SDL2_ttf::SDL2_ttf)
else()
    if(WIN32)
        # Checks to see if git is present
        find_package(Git REQUIRED)

        
    else()
        set(LIBRARIES ncurses tinfo)
    endif(WIN32)
endif(SDL)

file(GLOB PROJECT_HEADERS src/*.h)
file(GLOB PROJECT_SOURCES src/*.cpp)

file(GLOB PDCC lib/PDCurses/*.c)
file(GLOB PDCH lib/PDCurses/*.h)


add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PDCC} ${PDCH})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})