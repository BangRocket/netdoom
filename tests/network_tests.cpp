#include <gtest/gtest.h>
#include "d_net.h"  // Assuming this is the header for network-related functions

TEST(NetworkTest, ConnectionEstablishment) {
    // Test connection establishment
    EXPECT_TRUE(I_InitNetwork());
}

TEST(NetworkTest, DataTransmission) {
    // Test data transmission
    const char* test_data = "Hello, World!";
    EXPECT_TRUE(NET_SendPacket(1, test_data, strlen(test_data)));
    // Note: You'll need to implement a way to receive and verify the data
}

TEST(NetworkTest, ConnectionClosure) {
    // Test connection closure
    EXPECT_TRUE(I_ShutdownNetwork());
}
