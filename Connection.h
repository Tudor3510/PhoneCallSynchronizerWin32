#pragma once

#include <WinSock2.h>
#include "MessageParser.h"

class Connection {
public:
	static const DWORD CONNECTED = 0x01;
	static const DWORD DISCONNECTED = 0x02;

	SOCKET socketConnection;
	DWORD ConnectionStatus;


private:
	static const DWORD BUFFER_LENGTH = 200;
	CHAR buffer[BUFFER_LENGTH];
	DWORD receivedLength;

	static const ULONGLONG DROPOUT_TIME = 120000;			//2 minutes



	MessageParser messageParser;
	ULONGLONG lastTimeMessageReceived;
	

	VOID CALLBACK Synchronize(PVOID lpParam, BOOLEAN TimerOrWaitFired)
	{
		DWORD receivedLength = recv(socketConnection, buffer, BUFFER_LENGTH, NULL);

		if (messageParser.parseMessage(buffer, receivedLength) == MessageParser::KEEP_ALIVE_MESSAGE)
		{
			ULONGLONG currentTimeMessageReceived = GetTickCount64();

			if (lastTimeMessageReceived - currentTimeMessageReceived == DROPOUT_TIME)
		}
	}
};