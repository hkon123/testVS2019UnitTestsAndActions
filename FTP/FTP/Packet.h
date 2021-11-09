#pragma once
#include <string>
#include <iostream>

class Packet
{
private:
	int destPort, seqNr, ackNr, option, length;
	std::string data, temp_ip, temp_datagram;
	unsigned char* raw_data;
	

public:
	Packet(std::string destIpIn, int destPortIn, int seqNrIn, int ackNrIn, int optionIn, std::string dataIn);
	Packet();
	void setRaw_data();
	void stripPacket();
	int getSeqNr();
	int getAckNr();
	int getOption();
	int getLength();
	std::string getData();

};

