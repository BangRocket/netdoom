#include <gtest/gtest.h>
#include "d_net.h"  // Assuming this is the header for network-related functions

TEST(NetworkTest, ConnectionEstablishment) {
    EXPECT_TRUE(NET_ConnectToServer("localhost", 12345));
}

TEST(NetworkTest, DataTransmission) {
    const char* test_data = "Hello, World!";
    EXPECT_TRUE(NET_SendPacket(NetPacketType::PlayerUpdate, test_data, strlen(test_data)));
    
    // Receive and verify the data
    NetPacketType receivedType;
    char receivedData[MAX_PACKET_SIZE];
    size_t receivedSize = MAX_PACKET_SIZE;
    EXPECT_TRUE(NET_ReceivePacket(&receivedType, receivedData, &receivedSize));
    EXPECT_EQ(receivedType, NetPacketType::PlayerUpdate);
    EXPECT_STREQ(receivedData, test_data);
}

TEST(NetworkTest, ConnectionClosure) {
    NET_DisconnectFromServer();
}

TEST(NetworkTest, Latency) {
    EXPECT_GE(NET_GetLatency(), 0);
}

TEST(NetworkTest, ConnectionStatus) {
    EXPECT_TRUE(NET_IsConnected());
}
