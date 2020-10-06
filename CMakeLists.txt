cmake_minimum_required(VERSION 3.10)

project(esptestlibproj C CXX)

include_directories(src)

add_library(esptestlib src/tryingthis.cpp)
# target_include_directories(esptestlib PUBLIC src/tryingthis.hpp)

file(GLOB_RECURSE TEST_HEADERS "include/*.hpp" "include/*.h" "include/*.inl")
target_sources(esptestlib PRIVATE ${TEST_HEADERS}) # for intellisense
target_include_directories(esptestlib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src # DIFFERENT THEN ADD_SUBDIRECTORY ABOVE?
)

# target_sources(esptestlib PRIVATE src/tryingthis.hpp) # for intellisense
# target_compile_features(esptestlib PUBLIC cxx_std_11)

# target_include_directories(esptestlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
# set_target_properties(esptestlib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(test src/example.cpp)
target_link_libraries(test esptestlib)