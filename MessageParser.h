#pragma once

#include <Windows.h>

class MessageParser{
public:
	static const DWORD KEEP_ALIVE_MESSAGE = 0x01;
	static const DWORD CALL_MESSAGE = 0x02;

	DWORD parseMessage(const char* message, DWORD& length)
	{
		if (strncmp(message, KEEP_ALIVE_MESSAGE_STRING, KEEP_ALIVE_MESSAGE_STRING_LENGTH) == 0)
		{
			return KEEP_ALIVE_MESSAGE;
		}

		if (strncmp(message, CALL_MESSAGE_STRING, CALL_MESSAGE_STRING_LENGTH) == 0)
		{
			return CALL_MESSAGE;
		}


		return NULL;
	}
private:
	static constexpr CHAR KEEP_ALIVE_MESSAGE_STRING[] = "keep_alive_message";
	static const DWORD KEEP_ALIVE_MESSAGE_STRING_LENGTH = 18;

	static constexpr CHAR CALL_MESSAGE_STRING[] = "not";
	static const DWORD CALL_MESSAGE_STRING_LENGTH = 3;
};