cmake_minimum_required(VERSION 3.16)

project(DnDGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

add_executable(DnDGame
    Armor.cpp
    Character.cpp
    CharacterCreator.cpp
    ChoiceMenu.cpp
    Game.cpp
    general_utility.cpp
    Item.cpp
    MainMenu.cpp
    main.cpp
    npc.cpp
    Settings.cpp
    TextHandler.cpp
    TextInput.cpp
    Weapon.cpp
)

target_link_libraries(DnDGame PRIVATE
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
)