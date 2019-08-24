project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
)
set(SOURCE_FILES
)

# file(GLOB...) allows for wildcard additions
file(GLOB SNIPPET_SRCS "./snippet/*.cpp")   # aux_source_directory(./snippet SNIPPET_SRCS)
#include_directories(./snippet)

aux_source_directory(./mycpp MYCPP_SRCS)

# 生成动态库(libmymath.so)
#ADD_LIBRARY(mymath SHARED ${SRC_LIST})
# 生成静态库（libmymath.a，target名字只能有一个，所以不能与动态库的名字一样）
#ADD_LIBRARY(mymath_static STATIC ${SRC_LIST})
# 但是可以通过下面的命令更改静态库target生成的库名，这样就和动态库的名字一样的了
#SET_TARGET_PROPERTIES(mymath_static PROPERTIES OUTPUT_NAME "mymath")

if (EXISTS ${SOURCE_FILES})
    # 使用命令 add_library 将指定的源文件编译为静态链接库
    add_library(${CMAKE_PROJECT_NAME}_lib STATIC    # The library contains header and source files.
        ${SOURCE_FILES}
        ${HEADER_FILES}
    )
    # 使用命令 add_library 将指定的源文件编译为动态链接库
    add_library(${CMAKE_PROJECT_NAME}_lib SHARED
        ${SNIPPET_SRCS}
        ${MYCPP_SRCS}
    )
else()
    add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)    # The library only contains header files.
endif()