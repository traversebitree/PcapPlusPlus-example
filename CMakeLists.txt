cmake_minimum_required(VERSION 3.25)
project(app LANGUAGES CXX VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

set(BUILD_SHARED_LIBS FALSE CACHE INTERNAL "Build Dll" FORCE)

# Fetch winpcap or npcap sdk
FetchContent_Declare(
    pcap
    SYSTEM

    # URL https://npcap.com/dist/npcap-sdk-1.13.zip
    URL https://www.winpcap.org/install/bin/WpdPack_4_1_2.zip
)
FetchContent_MakeAvailable(pcap)

# Fetch PcapPlusPlus library (lib), git_tag is https://github.com/seladb/PcapPlusPlus/commit/4e5b3e781d75395aaf3688cb542232540002225e
FetchContent_Declare(
    pcapplusplus
    SYSTEM
    GIT_REPOSITORY https://ghproxy.com/https://github.com/seladb/PcapPlusPlus
    GIT_TAG 4e5b3e781d75395aaf3688cb542232540002225e
)
set(PCAP_ROOT "${pcap_SOURCE_DIR}")
set(Packet_ROOT "${pcap_SOURCE_DIR}")
FetchContent_MakeAvailable(pcapplusplus)

# Fetch fmt library (dll)
set(BUILD_SHARED_LIBS TRUE CACHE INTERNAL "Build Dll" FORCE)
FetchContent_Declare(
    fmt
    SYSTEM
    GIT_REPOSITORY https://ghproxy.com/https://github.com/fmtlib/fmt
    GIT_TAG 9.1.0
)
FetchContent_MakeAvailable(fmt)

# cpp source is at src/app1/app1.cpp, an example from PcapPlusPlus webpage
add_subdirectory(src/app1)
