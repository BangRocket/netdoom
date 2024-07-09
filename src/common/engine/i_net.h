#ifndef __I_NET_H__
#define __I_NET_H__

#include <stdint.h>

// Called by D_DoomMain.
int I_InitNetwork (void);
void I_NetCmd (void);
void I_NetMessage(const char*, ...);
void I_NetProgress(int val);
void I_NetInit(const char* msg, int num);
bool I_NetLoop(bool (*timer_callback)(void*), void* userdata);
void I_NetDone();

// New functions for client/server support
bool I_StartNetworkAsServer(int port);
bool I_ConnectToServer(const char* address, int port);
void I_RunNetworkServer();
void I_RunNetworkClient();
void PacketSend();
void PacketGet();

// New functions for client/server support
bool StartNetworkGame(int port);
bool ConnectToNetworkGame(const char* address, int port);
void RunNetworkGame();
void SendNetworkMessage(const void* data, size_t length);
void* ReceiveNetworkMessage(size_t* length);
void HandleDisconnection(int playerNum);
void UpdateNetworkStats();
int CalculateAveragePing();
float CalculatePacketLoss();

struct NetworkStats {
    uint64_t bytesSent;
    uint64_t bytesReceived;
    uint64_t packetsSent;
    uint64_t packetsReceived;
    int pingMs;
    float packetLoss;
    uint64_t totalPing;
    uint64_t lastActivityTime[MAXPLAYERS];
};

extern NetworkStats networkStats;

#define PLAYER_TIMEOUT 5000 // 5 seconds timeout

// New variables for client/server support
extern bool isServer;
extern bool isClient;

// Add these declarations
void StoreCommand(int inputSequence, const ticcmd_t& cmd);
ticcmd_t GetStoredCommand(int inputSequence);
extern std::map<int, ticcmd_t> storedCommands;

// Game state structures
struct PlayerState {
    double x, y, z;
    double angle;
    int health;
};

struct GameState {
    int gametic;
    int consoleplayer;
    PlayerState playerStates[MAXPLAYERS];
    int lastProcessedInput[MAXPLAYERS];
    bool isReconciling[MAXPLAYERS];
};

// New functions for network message handling
void SendNetworkMessage(const void* data, size_t length);
void* ReceiveNetworkMessage(size_t* length);

// New variables for client/server support
extern bool isServer;
extern bool isClient;
#define MAX_CLIENTS 16
extern int numClients;
struct ClientInfo {
    sockaddr_in address;
    int player;
};
extern ClientInfo clients[MAX_CLIENTS];

// New functions for client management
bool AddClient(const sockaddr_in* address);
void RemoveClient(const sockaddr_in* address);
int GetClientPlayer(const sockaddr_in* address);

// Game state structures
struct PlayerState {
    double x, y, z;
    double angle;
    int health;
};

struct GameState {
    int gametic;
    int consoleplayer;
    PlayerState playerStates[MAXPLAYERS];
};

enum ENetConstants
{
	MAXNETNODES = 32,	// Increased max computers in a game
	DOOMCOM_ID = 0x12345678,
	BACKUPTICS = 128,	// Increased number of tics to remember
	MAXTICDUP = 5,
	LOCALCMDTICS =(BACKUPTICS*MAXTICDUP),
	MAX_MSGLEN = 14000,

	CMD_SEND = 1,
	CMD_GET = 2,
};

// [RH]
// New generic packet structure:
//
// Header:
//  One byte with following flags.
//  One byte with starttic
//  One byte with master's maketic (master -> slave only!)
//  If NCMD_RETRANSMIT set, one byte with retransmitfrom
//  If NCMD_XTICS set, one byte with number of tics (minus 3, so theoretically up to 258 tics in one packet)
//  If NCMD_QUITTERS, one byte with number of players followed by one byte with each player's consolenum
//  If NCMD_MULTI, one byte with number of players followed by one byte with each player's consolenum
//     - The first player's consolenum is not included in this list, because it always matches the sender
//
// For each tic:
//  Two bytes with consistancy check, followed by tic data
//
// Setup packets are different, and are described just before D_ArbitrateNetStart().

enum ENCMD
{
	NCMD_EXIT				= 0x80,
	NCMD_RETRANSMIT 		= 0x40,
	NCMD_SETUP				= 0x20,
	NCMD_MULTI				= 0x10,		// multiple players in this packet
	NCMD_QUITTERS			= 0x08,		// one or more players just quit (packet server only)
	NCMD_COMPRESSED			= 0x04,		// remainder of packet is compressed

	NCMD_XTICS				= 0x03,		// packet contains >2 tics
	NCMD_2TICS				= 0x02,		// packet contains 2 tics
	NCMD_1TICS				= 0x01,		// packet contains 1 tic
	NCMD_0TICS				= 0x00,		// packet contains 0 tics
};

//
// Network packet data.
//
struct doomcom_t
{
	uint32_t	id;				// should be DOOMCOM_ID
	int16_t	intnum;			// DOOM executes an int to execute commands

// communication between DOOM and the driver
	int16_t	command;		// CMD_SEND or CMD_GET
	int16_t	remotenode;		// dest for send, set by get (-1 = no packet).
	int16_t	datalength;		// bytes in data to be sent

// info common to all nodes
	int16_t	numnodes;		// console is always node 0.
	int16_t	ticdup;			// 1 = no duplication, 2-5 = dup for slow nets

// info specific to this node
	int16_t	consoleplayer;
	int16_t	numplayers;

// packet data to be sent
	uint8_t	data[MAX_MSGLEN];

}; 

extern doomcom_t doomcom;
extern bool netgame, multiplayer;
extern int consoleplayer;

// New variables for client/server support
extern bool isServer;
extern bool isClient;

#endif
