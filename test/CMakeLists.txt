cmake_minimum_required(VERSION 3.3)

set(REPO ~/ClionProjects/.repo)

project(Test)

project(Example)

include(CTest)
enable_testing()

#INCLUDE_DIRECTORIES(
#        ../include
#)

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

set(test_SRCS ../src/ZTEGraph.cpp ../src/ZTEGenetic.cpp)

add_executable(runGraphTests ${test_SRCS} ZTEGraph_test.cpp )#ZTEGenetic_test.cpp)
target_link_libraries(runGraphTests gtest)

add_executable(runGeneticTests ${test_SRCS} ZTEGenetic_test.cpp)
target_link_libraries(runGeneticTests gtest gmock)
#add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.