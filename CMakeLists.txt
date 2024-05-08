cmake_minimum_required(VERSION 3.20.0)
project(WxForm  VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(default_build_type "Release")
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()


IF (WIN32)
    # Укажите путь до папки wxWidgets
    set(wxWidgets_ROOT_DIR "c:/wxwidgets/3.2.2")
    # set(wxWidgets_LIB_DIR "c:/wxwidgets/3.2.2/lib/gcc_x64_lib")
    set(wxWidgets_LIB_DIR "c:/wxwidgets/3.2.2/lib/gcc_x64_dll")
ENDIF()
if(MINGW)
    link_libraries(ws2_32 wsock32)
endif()



find_package(wxWidgets REQUIRED COMPONENTS aui html net core base)
include(${wxWidgets_USE_FILE})


file(GLOB project
    src/*
    src/res/*
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # С консолью
    add_executable(${PROJECT_NAME} ${project})
    message("-- Bullet: Debug build")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Без консоли 
    add_executable(${PROJECT_NAME} WIN32 ${project})
    message("-- Bullet: Release build")
else()
    message("-- Bullet: Unknown build type") # <---- This is the result, why?
endif()

if(wxWidgets_FOUND)

    # Динамическая  сборка
    target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

    # Статическая  сборка
    # target_link_libraries(${PROJECT_NAME} 
    #     "${wxWidgets_LIB_DIR}/libwxmsw32u_core.a" 
    #     "${wxWidgets_LIB_DIR}/libwxbase32u.a" 
    #     "${wxWidgets_LIB_DIR}/libwxpng.a" 
    #     "${wxWidgets_LIB_DIR}/libwxzlib.a" 
    #     ${wxWidgets_LIBRARIES})

    # target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS})
    message(STATUS "Found wxWidgets ${wxWidgets_VERSION_STRING}")
else()
    message(STATUS "wxWidgets Not Found")
endif()
