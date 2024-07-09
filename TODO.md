# GZDoom Todo List

## Network Implementation

1. Error Handling
   - [x] Add try-catch blocks around network code (done in I_InitNetwork)
   - [x] Create specific error types for network-related issues (NetworkException class added)
   - [x] Add error handling to I_InitNetwork function (done)

2. Message Serialization and Deserialization
   - [x] Implement robust serialization system for game state (SerializeAndSendGameState and ReceiveAndDeserializeGameState functions added)
   - [ ] Add versioning to network messages for future compatibility

3. Game Synchronization
   - [x] Develop system to handle network latency and packet loss (basic implementation in RunNetworkGame)
   - [x] Implement client-side prediction and server reconciliation (basic implementation added)

4. Multiple Game Rooms/Lobbies
   - [ ] Create lobby system for players to join before starting a game
   - [ ] Implement room creation and management

5. Security Measures
   - [ ] Implement encryption for sensitive data
   - [ ] Add authentication system for players

6. Network Performance
   - [ ] Implement delta compression for game state updates
   - [ ] Add bandwidth throttling and prioritization of network messages

7. Player Connection/Disconnection Handling
   - [x] Implement graceful disconnection handling (HandleDisconnection function added)
   - [ ] Add reconnection functionality for temporarily disconnected players

8. Matchmaking System
   - [ ] Implement skill-based matchmaking
   - [ ] Add support for custom game settings

9. Voice Chat Functionality
   - [ ] Add voice chat support for in-game communication
   - [ ] Implement push-to-talk and always-on voice options

10. Network Diagnostics and Debugging
    - [x] Create network statistics display for players (DisplayNetworkStats function added)
    - [ ] Implement logging for network-related events and errors

11. Multiplayer User Interface
    - [ ] Create intuitive menus for joining and hosting games
    - [ ] Add visual feedback for network status and quality

12. Anti-Cheat Measures
    - [ ] Develop server-side validation for player actions
    - [ ] Implement reporting system for suspicious behavior

13. Dedicated Servers
    - [ ] Create separate dedicated server application
    - [ ] Implement server browser functionality

14. Client-Server Communication
    - [x] Implement efficient protocols for frequent updates (e.g., player positions)
    - [ ] Add support for UDP hole punching for peer-to-peer connections

15. Cross-Platform Multiplayer
    - [ ] Ensure network code compatibility across different platforms
    - [ ] Add platform-specific optimizations where necessary

16. Network Code Refactoring
    - [x] Separate client and server logic (done in RunNetworkGame)
    - [x] Implement proper error handling (done with try-catch blocks and NetworkException)
    - [x] Improve code organization and modularity

17. Game State Management
    - [x] Create GameState structure (done)
    - [x] Implement state synchronization between server and clients (basic implementation added)

18. Network Initialization
    - [x] Add support for starting as server or client (done in I_InitNetwork)
    - [ ] Implement dynamic port selection for clients

19. Message Handling
    - [x] Implement separate functions for sending and receiving different types of messages (done)
    - [ ] Add message queuing system for reliable delivery

20. Input Prediction and Reconciliation
    - [x] Add client-side input prediction
    - [x] Implement server-side reconciliation
    - [ ] Improve smoothing for reconciliation

21. Game State Synchronization
    - [x] Implement frequent state updates for critical game elements
    - [ ] Add interpolation for smoother movement between updates
    - [ ] Implement delta compression for state updates

22. Error Handling and Recovery
    - [ ] Implement automatic reconnection attempts on connection loss
    - [ ] Add better error messages and handling for common network issues

23. Bandwidth Optimization
    - [ ] Implement efficient serialization for game state
    - [ ] Add priority system for network messages

24. Multiplayer Game Modes
    - [ ] Implement additional game modes (e.g., team deathmatch, capture the flag)
    - [ ] Add support for custom game rules and modifiers

25. Network Security
    - [ ] Implement basic anti-cheat measures
    - [ ] Add server-side validation for critical game actions

26. Multiplayer UI/UX
    - [ ] Create user-friendly server browser
    - [ ] Implement party system for playing with friends

27. Network Performance Monitoring
    - [x] Implement ping measurement and display (done in DisplayNetworkStats)
    - [x] Add network quality indicators (packet loss, jitter) (done in DisplayNetworkStats)

28. Host Migration
    - [x] Implement system to handle host disconnection gracefully
    - [ ] Add voting system for new host selection

29. Spectator Mode
    - [x] Implement spectator mode for multiplayer games
    - [x] Add controls for spectators to switch between players

30. Network Game Saving/Loading
    - [x] Add ability to save and load multiplayer game states
    - [x] Ensure synchronization when loading saved games

31. Network Debugging Tools
    - [ ] Implement network traffic visualization
    - [ ] Add detailed logging for network events and packet contents

32. Connection Type Optimization
    - [ ] Implement adaptive packet sizes based on connection quality
    - [ ] Add support for different network protocols (TCP/UDP) based on data criticality

33. Network Game Replays
    - [ ] Add ability to record and playback multiplayer matches
    - [ ] Implement system for sharing and viewing replays

34. Lag Compensation
    - [ ] Add server-side lag compensation for hit detection
    - [ ] Implement client-side movement prediction with reconciliation

35. Game State Compression
    - [ ] Implement efficient compression algorithms for game state data
    - [ ] Add support for partial state updates to reduce bandwidth usage

36. Game Join Process
    - [ ] Implement robust handshake process for joining games
    - [ ] Add support for late-join functionality in ongoing matches

37. Physics Object Synchronization
    - [ ] Implement efficient synchronization for physics-based objects
    - [ ] Add interpolation and extrapolation for smoother physics interactions

38. Game State Rewinding
    - [ ] Add ability to rewind and replay game state for reconciliation
    - [ ] Implement efficient storage system for historical game states

39. Game Time Synchronization
    - [ ] Implement robust time synchronization system across clients
    - [ ] Add support for handling clients with varying pings and update rates

40. Game State Prediction
    - [ ] Add client-side state prediction for smoother gameplay
    - [ ] Implement server-side validation of predicted states

41. Network API Refinement
    - [x] Add NET_GetLatency function
    - [x] Add NET_IsConnected function

## Build System Refactoring

1. CMakePresets.json
   - [ ] Create CMakePresets.json file for common build configurations
   - [ ] Define presets for Debug, Release, and RelWithDebInfo builds
   - [ ] Include platform-specific presets for Windows, macOS, and Linux

2. Dependency Management
   - [ ] Implement Conan or vcpkg for third-party library management
   - [ ] Update CMakeLists.txt files to use package manager for dependencies
   - [ ] Remove FetchContent declarations for zlib, bzip2, and asmjit

3. Modularization
   - [ ] Create separate CMake files for platform-specific code
   - [ ] Move Windows-specific code to cmake/platform_windows.cmake
   - [ ] Move macOS-specific code to cmake/platform_macos.cmake
   - [ ] Move Linux-specific code to cmake/platform_linux.cmake
   - [ ] Update main CMakeLists.txt to include platform-specific files

4. Compiler Flags
   - [ ] Refactor compiler flag setting in main CMakeLists.txt
   - [ ] Create functions for setting common flags across targets
   - [ ] Implement separate compile options for different build types

5. Target Management
   - [ ] Reorganize target definitions in src/CMakeLists.txt
   - [ ] Group related targets and their properties
   - [ ] Implement better handling of optional features (e.g., VM JIT)

6. Installation and Packaging
   - [ ] Improve installation rules in main CMakeLists.txt
   - [ ] Create CPack configuration for generating installers
   - [ ] Implement platform-specific packaging options

7. Build Optimization
   - [ ] Implement parallel compilation where possible
   - [ ] Optimize include directories to reduce compilation time
   - [ ] Investigate and implement precompiled headers for major components

8. Testing
   - [ ] Set up CTest integration for running tests
   - [ ] Create test targets for different components
   - [ ] Implement code coverage reporting

9. Documentation
   - [ ] Update README.md with new build instructions
   - [ ] Create BUILDING.md with detailed build process explanation
   - [ ] Document new CMake options and their effects

10. Continuous Integration
    - [ ] Update CI scripts to use new CMake presets
    - [ ] Implement matrix builds for different configurations
    - [ ] Set up automated package generation in CI

11. Cleanup
    - [ ] Remove deprecated or unused CMake code
    - [ ] Ensure consistent naming conventions across CMake files
    - [ ] Refactor redundant code into reusable functions or macros
