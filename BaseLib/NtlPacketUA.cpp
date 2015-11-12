﻿#include "stdafx.h"
#include "NtlPacketUA.h"

const char * s_packetName_UA[] =
{
	DECLARE_PACKET_NAME( UA_LOGIN_REQ ),
	DECLARE_PACKET_NAME( UA_LOGIN_REQ_KOREA_CJ ),
	DECLARE_PACKET_NAME( UA_LOGIN_TW_REQ ),
	DECLARE_PACKET_NAME( UA_LOGIN_HK_REQ ),

	DECLARE_PACKET_NAME( UA_LOGIN_CREATEUSER_REQ ),
	DECLARE_PACKET_NAME( UA_LOGIN_DISCONNECT_REQ ),
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * NtlGetPacketName_UA(WORD wOpCode)
{
	if( wOpCode < UA_OPCODE_BEGIN )
	{
		return "NOT DEFINED PACKET NAME : OPCODE LOW";
	}

	if( wOpCode > UA_OPCODE_END )
	{
		return "NOT DEFINED PACKET NAME : OPCODE HIGH";
	}

	int nIndex = wOpCode - UA_OPCODE_BEGIN;
	if( nIndex >= _countof( s_packetName_UA ) )
	{
		return "OPCODE BUFFER OVERFLOW";
	}

	return s_packetName_UA[ nIndex ];
}
//------------------------------------------------------------------
