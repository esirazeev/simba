#include <chrono>
#include <format>
#include <logger.hpp>
#include <timer.hpp>

#include "pcap/reader/reader.hpp"
// #include "build/release/_deps/pcap_reader-src/pcap/reader/reader.hpp"

void print_packets_in_range(uint64_t packet_from, uint64_t packet_to = std::numeric_limits<uint64_t>::max())
{
	pcap::Reader reader("C:\\Users\\8483ed\\Documents\\vscode\\cpp\\simba\\.data\\file.pcap");
	logger::println(std::format("pcap::FileReader [info]: file size {} bytes", reader.fileSize()));

	pcap::RawPacket packet;

	timer_start();

	while (reader.readPackets() < packet_to and reader.readNextPacket(packet))
		;

	std::ofstream file("osi_bin_packet_data");
	file.write(reinterpret_cast<const char*>(packet.data().data()), packet.data().size());

	timer_stop();

	logger::println("--------------------------------------------------------------------");
	logger::println(std::format("pcap::FileReader [info]: file reading finished"));
	logger::println(std::format("pcap::FileReader [info]: read bytes  : {}", reader.readBytes()));
	logger::println(std::format("pcap::FileReader [info]: read packets: {}", reader.readPackets()));
	logger::println(std::format("reading time (ms): {}", timer_result_milliseconds()));
}

int main(int argc, const char** argv)
{
	std::ios::sync_with_stdio(false);

	if (argc == 1)
	{
		print_packets_in_range(1);
	}
	else if (argc == 3)
	{
		print_packets_in_range(std::stoi(argv[1]), std::stoi(argv[2]));
	}

	return 0;
}
