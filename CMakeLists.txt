cmake_minimum_required(VERSION 3.9) # CMake 最低版本号要求
set(CMAKE_CXX_STANDARD 17)

# 项目信息
project(CPPProj)
set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR 1)
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR 0)
# 加入一个配置头文件，用于处理 CMake 对源码的设置。通过这样的机制，将可以通过预定义一些参数和变量来控制代码的生成
# configure_file 命令用于加入一个配置头文件 config.h ，这个文件由 CMake 从 config.h.in 生成。
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
# 设置动态库输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
# 设置可执行文件输出路径
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# 设置生成可执行文件的名称
SET(EXECUTABLE_FILE_NAME ${CMAKE_PROJECT_NAME}.exe)
# 定义库文件路径
SET(LIBS_PATH ${PROJECT_SOURCE_DIR}/libs)
# 设置头/源文件路径
SET(SRC_PATH ${PROJECT_SOURCE_DIR}/src)

# 查找当前目录下的源文件（不包括头文件），并将名称保存到变量
#AUX_SOURCE_DIRECTORY(. SOURCE_FILES)
set(SOURCE_FILES main.cpp)

# 打印编译目录和项目目录路径
MESSAGE(STATUS "[CUSTOM] Default SOURCE dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "[CUSTOM] Default BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "[CUSTOM] Library Output Path: " ${PROJECT_BINARY_DIR}/lib})
MESSAGE(STATUS "[CUSTOM] Library path: " ${LIBS_PATH})
MESSAGE(STATUS "[CUSTOM] Src path: " ${SRC_PATH})
MESSAGE(STATUS "[CUSTOM] Src static lib name: " ${CMAKE_PROJECT_NAME}_lib)

# include_directories：指定头文件的搜索路径（以便找到相关头文件），相当于指定gcc的-I参数
include_directories(src)
#include_directories("${PROJECT_BINARY_DIR}")

# link_directories：添加动/静态连接库的搜索路径，相当于gcc的-L参数
link_directories(${LIBS_PATH})
# 链接静态库
SET(LIBS_STATIC_LIST
)
# 链接动态库
SET(LIBS_DYNAMIC_LIST
)

# 指明本项目包含一个子目录。这样子目录下的 CMakeLists.txt 文件和源代码也会被处理
add_subdirectory(src)
add_subdirectory(tests)

# 将${SOURCE_FILES}源文件编译成一个名称为${CMAKE_PROJECT_NAME}_run的可执行文件。
add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCE_FILES})

# 添加链接库，相同于指定-l参数(-l指定加载的库文件，-L是指定加载库文件的路径。编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，后面加上.a/.so来确定库的名称)。
# 指明可执行文件 ${CMAKE_PROJECT_NAME}_run 需要连接一个名为 ${CMAKE_PROJECT_NAME}_lib 的链接库
target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib ${LIBS_STATIC_LIST} ${LIBS_DYNAMIC_LIST})


# 让 CMake 支持 gdb 的设置也很容易，只需要指定 Debug 模式下开启 -g 选项：
#set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Doxygen Build
#option(BUILD_DOC "Build Documentation" ON)
#
#find_package(Doxygen)
#if(DOXYGEN_FOUND)
#    set(BUILD_DOC_DIR ${CMAKE_SOURCE_DIR}/build/docs)
#    if(NOT EXISTS ${BUILD_DOC_DIR})
#        file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
#    endif()
#
#    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
#    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#
#    message("Doxygen buld started")
#    add_custom_target(Doxygen ALL
#            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#            COMMENT "Generating API documentation with Doxygen"
#            VERBATIM)
#else(DOXYGEN_FOUND)
#    message("Doxygen needs to be installed to generate the documentation.")
#endif(DOXYGEN_FOUND)