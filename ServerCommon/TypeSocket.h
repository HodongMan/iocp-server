#pragma once


static const int MAX_INTERNAL_PACKETS = 500;


enum class SendResponse
{
	FAILED,
	WOULDBLOCK,
	OK
};