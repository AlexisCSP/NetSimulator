# # Locate GTest
find_package (GTest REQUIRED)
include_directories (${GTEST_INCLUDE_DIRS})

# Link Tests with what we want to test and the GTest and pthread library
add_executable (IPv4Test ipv4_test.cpp)
add_executable (HttpTest http_test.cpp)

target_link_libraries (IPv4Test IPv4 ${GTEST_LIBRARIES} pthread)
target_link_libraries (HttpTest Http ${GTEST_LIBRARIES} pthread)

# add_test (NAME IPv4Test COMMAND TestIPv4)
gtest_discover_tests(IPv4Test)
gtest_discover_tests(HttpTest)