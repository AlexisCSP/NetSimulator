#include <gtest/gtest.h>
#include "../include/NetSimulator/ipv4.h"

TEST(IPv4ConstructorTest, LocalhostAddress) {
    uint8_t localhost[4] = {127, 0, 0, 1};
    IPv4 ip("127.0.0.1");
    ASSERT_EQ(*(uint32_t *)localhost, ip.address());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}