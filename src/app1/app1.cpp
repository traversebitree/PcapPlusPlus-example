#include <iostream>
#include "IPv4Layer.h"
#include "Packet.h"
#include "PcapFileDevice.h"
#include <filesystem>
#include <fmt/format.h>
#include <span>

int main(int argc, const char *argv[])
{
    std::span<const char *> args = std::span(argv, size_t(argc));
    std::filesystem::path exe_dir = std::filesystem::path(std::string(args[0])).parent_path();

    // open a pcap file for reading
    if (std::filesystem::exists(exe_dir / "IoT_Dataset_ServiceScan__00008_20180515135407.pcap"))
    {
        fmt::print("Exist");
    }
    else
    {
        fmt::print("No Exist");
    }
    pcpp::PcapFileReaderDevice reader((exe_dir / "IoT_Dataset_ServiceScan__00008_20180515135407.pcap").generic_string());
    if (!reader.open())
    {
        std::cerr << "Error opening the pcap file" << std::endl;
        return 1;
    }

    // read the first (and only) packet from the file
    pcpp::RawPacket rawPacket;
    if (!reader.getNextPacket(rawPacket))
    {
        std::cerr << "Couldn't read the first packet in the file" << std::endl;
        return 1;
    }

    // parse the raw packet into a parsed packet
    pcpp::Packet parsedPacket(&rawPacket);

    // verify the packet is IPv4
    if (parsedPacket.isPacketOfType(pcpp::IPv4))
    {
        // extract source and dest IPs
        pcpp::IPv4Address srcIP = parsedPacket.getLayerOfType<pcpp::IPv4Layer>()->getSrcIPv4Address();
        pcpp::IPv4Address destIP = parsedPacket.getLayerOfType<pcpp::IPv4Layer>()->getDstIPv4Address();

        // print source and dest IPs
        std::cout << "Source IP is '" << srcIP << "'; Dest IP is '" << destIP << "'" << std::endl;
    }

    // close the file
    reader.close();

    return 0;
}