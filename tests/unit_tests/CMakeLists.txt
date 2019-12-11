include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 查找当前目录下的所有源文件，并将名称保存到 UNIT_TEST_SRCS 变量
aux_source_directory(. UNIT_TEST_SRCS)

add_executable(Unit_Tests_run
#    ${UNIT_TEST_SRCS}
#    test_example.cpp
#    test_snppet.cpp
    test_mycpp.cpp
)

target_link_libraries(Unit_Tests_run gtest gtest_main)
target_link_libraries(Unit_Tests_run ${CMAKE_PROJECT_NAME}_lib)