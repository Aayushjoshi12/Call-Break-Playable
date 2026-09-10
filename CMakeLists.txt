cmake_minimum_required(VERSION 3.16)
project(MyGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    enet
    GIT_REPOSITORY https://github.com/lsalzman/enet.git
    GIT_TAG        v1.3.18
)
FetchContent_MakeAvailable(enet)

set(JSON_BuildTests OFF CACHE INTERNAL "")
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

set(CORE_SOURCES
    src/Backend/Implementation/entities.cpp
    src/Backend/Implementation/GameManager.cpp
    src/Backend/Implementation/TimeManager.cpp
    src/Backend/Implementation/RoundManager.cpp
)

set(WINDOWS_RAYLIB_DEFINES WIN32_LEAN_AND_MEAN NOGDI NOUSER NOMINMAX _WINSOCK_DEPRECATED_NO_WARNINGS)

add_executable(MyGame
    src/main.cpp
    src/Frontend/Implementation/Homedesign.cpp
    src/Frontend/Implementation/shuffling.cpp
    src/Frontend/Implementation/HandleMusic.cpp
    src/Frontend/Implementation/score.cpp
    src/Frontend/Implementation/RendererInterface.cpp
    src/Frontend/Implementation/bid_screen.cpp
    src/Frontend/Implementation/Dealing_Cards.cpp
    src/Network/Implementation/Client.cpp
    src/Frontend/Implementation/lobby.cpp
    ${CORE_SOURCES}
)
target_link_libraries(MyGame PRIVATE raylib enet nlohmann_json::nlohmann_json)
target_include_directories(MyGame PRIVATE ${enet_SOURCE_DIR}/include)

if(WIN32)
    target_compile_definitions(MyGame PRIVATE ${WINDOWS_RAYLIB_DEFINES})
    target_link_options(MyGame PRIVATE -static)
endif()

add_executable(MyGameServer
    src/server_main.cpp
    src/Network/Implementation/Server.cpp
    ${CORE_SOURCES}
)
target_link_libraries(MyGameServer PRIVATE raylib enet nlohmann_json::nlohmann_json)
target_include_directories(MyGameServer PRIVATE ${enet_SOURCE_DIR}/include)

if(WIN32)
    target_compile_definitions(MyGameServer PRIVATE ${WINDOWS_RAYLIB_DEFINES})
    target_link_options(MyGameServer PRIVATE -static)
endif()
