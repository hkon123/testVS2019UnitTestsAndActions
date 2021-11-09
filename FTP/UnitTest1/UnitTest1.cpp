#include "pch.h"
#include "CppUnitTest.h"
#include "../FTP/Packet.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PacketTests
{
	TEST_CLASS(setValues)
	{
	public:
		
		TEST_METHOD(setSeqNrLow)
		{
			Packet testPacket(
				"test", 6969, 150, 180, 10, "test"
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(150, testPacket.getSeqNr());
		}
		TEST_METHOD(setSeqNrHigh)
		{
			Packet testPacket(
				"test", 6969, 1234, 3216, 10, "test"
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(1234, testPacket.getSeqNr());
		}
		TEST_METHOD(setAckNrLow)
		{
			Packet testPacket(
				"test", 6969, 150, 180, 10, "test"
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(180, testPacket.getAckNr());
		}
		TEST_METHOD(setAckNrHigh)
		{
			Packet testPacket(
				"test", 6969, 1234, 3216, 10, "test"
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(3216, testPacket.getAckNr());
		}
		TEST_METHOD(setOption)
		{
			Packet testPacket(
				"test", 6969, 150, 180, 10, "test"
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(10, testPacket.getOption());
		}
		TEST_METHOD(setLengthShort)
		{
			std::string data = "test";
			Packet testPacket(
				"test", 6969, 150, 180, 10, data
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual((int)data.length(), testPacket.getLength());
		}
		TEST_METHOD(setLengthLong)
		{
			std::string data = "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				 "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				 "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				 "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				 "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest";
			Packet testPacket(
				"test", 6969, 150, 180, 10, data
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual((int)data.length(), testPacket.getLength());
		}
		TEST_METHOD(setDataShort)
		{
			std::string data = "test";
			Packet testPacket(
				"test", 6969, 150, 180, 10, data
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(data, testPacket.getData());
		}
		TEST_METHOD(setDataLong)
		{
			std::string data = "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				"testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				"testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				"testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"
				"testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest";
			Packet testPacket(
				"test", 6969, 150, 180, 10, data
			);
			testPacket.setRaw_data();
			testPacket.stripPacket();
			Assert::AreEqual(data, testPacket.getData());
		}
	};
}
