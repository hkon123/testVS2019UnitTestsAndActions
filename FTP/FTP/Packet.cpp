#include "Packet.h"


Packet::Packet() {
	raw_data = new unsigned char[1024];
	temp_datagram = "data";
}

Packet::Packet(std::string destIpIn, int destPortIn, int seqNrIn, int ackNrIn, int optionIn, std::string dataIn) {
	temp_ip = destIpIn;
	destPort = destPortIn;
	seqNr = seqNrIn;
	ackNr = ackNrIn;
	option = optionIn;
	data = dataIn;
	length = Packet::data.length();
	raw_data = new unsigned char[1024];
}

void Packet::setRaw_data() {
	int majorByte;
	raw_data[0] = (unsigned char)seqNr;
	majorByte = seqNr / 256;
	raw_data[1] = (unsigned char)majorByte;
	raw_data[2] = (unsigned char)ackNr;
	majorByte = ackNr / 256;
	raw_data[3] = (unsigned char)majorByte;
	raw_data[4] = (unsigned char)option;
	raw_data[5] = (unsigned char)length;
	majorByte = length / 256;
	raw_data[6] = (unsigned char)majorByte;
	const char* dataArray = data.c_str();
	for (int i = 0; i < data.size(); i++) {
		raw_data[7 + i] = dataArray[i];
	}
}

void Packet::stripPacket() {
	seqNr = (int)raw_data[0] + (int)raw_data[1] * 256;
	ackNr = (int)raw_data[2] + (int)raw_data[3] * 256;
	option = (int)raw_data[4];
	length = (int)raw_data[5] + (int)raw_data[6] * 256;
	unsigned char* dataArray = new unsigned char[1024];
	for (int i = 0; i < length; i++) {
		dataArray[i] = raw_data[7 + i];
	}
	std::string str(reinterpret_cast<char*>(dataArray));
	data = str.substr(0,length);
}

int Packet::getSeqNr() {
	return seqNr;
}

int Packet::getAckNr() {
	return ackNr;
}
int Packet::getOption() {
	return option;
}
int Packet::getLength() {
	return length;
}
std::string Packet::getData() {
	return data;
}



int main() {
	return 0;
}