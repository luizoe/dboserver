#ifndef _GAMENETWORK_H
#define _GAMENETWORK_H

#include <iostream>
#include <fstream>

// BaseLib
#include <Network.h>
#include <Acceptor.h>
#include <Connector.h>
#include <Session.h>
#include <SessionFactory.h>
#include <Packet.h>
#include <Config.h>
#include <ServerApp.h>
#include <Database.h>
#include <Encoder.h>
#include <TableAll.h>
#include <TwTableAll.h>//Newer Tables

#include "GameProtocol.h"
#include "CharacterManager.h"
#include "ObjectManager.h"

#include "CharacterProfile.h"
#include "NpcProfile.h"
#include "MobProfile.h"

enum GAME_SESSION
{
	SESSION_CLIENT,
	SESSION_SERVER_ACTIVE,
};

const DWORD	MAX_NUMOF_GAME_CLIENT = 3;
const DWORD	MAX_NUMOF_SERVER = 1;
const DWORD	MAX_NUMOF_SESSION = MAX_NUMOF_GAME_CLIENT + MAX_NUMOF_SERVER;

class GameServer;
class GameClientFactory;

class GameClient : public Session
{
	friend class GameClientFactory;
public:
	GameClient(bool IsAliveCheck = false, bool IsOpcodeCheck = false);
	~GameClient();

	int	OnAccept();
	void OnClose();
	int	OnDispatch(Packet* pPacket);
	void Send(void* pData, int nSize);
	void Send(void* pData, int nSize, int nHandle);
	void AddSpawn(unsigned int nHandle, BYTE byType);
	void RemoveSpawn(unsigned int nHandle);
	bool FindSpawn(unsigned int nHandle, BYTE byType);
	void CheckLevelUpdate();

	// Opcode Control
	bool PacketControl(Packet* pPacket);

	// PROTOCOL
	void SendGameEnterRes(sUG_GAME_ENTER_REQ* data);
	void SendCharInfo();
	void SendCharInfoEnd();
	void SendCharWorldInfo();
	void SendCharWorldInfoEnd();
	void SendCharMove(sUG_CHAR_MOVE* data);
	void SendCharItemInfo();
	void SendCharSkillInfo();
	void SendCharQuickSlotInfo();
	void SendCharReadySpawnReq();
	void SendCharReadyRes(sUG_CHAR_READY* pData);
	void CheckCommand(sUG_SERVER_COMMAND* pData);
	void SendCharBuffsInfo();
	void SendAvatarWarFogInfo();
	void SendAuthkeyCommSrvRes();
	void SendGameLeaveRes();
	void SendCharDestMove(sUG_CHAR_DEST_MOVE* pData);
	void SpawnTesteMob(unsigned int id);
	void SendCharJump(sUG_CHAR_JUMP* pData);
	void SendCharJumpEnd();
	void SendCharChangeHeading(sUG_CHAR_CHANGE_HEADING* pData);
	void SendCharExitRes();
	void SendGameExitRes();
	void SendIemMoveRes(sUG_ITEM_MOVE_REQ* pData);
	void UpdateCharObjEquips(HOBJECT hItem, BYTE byPos);
	void SendTSConfirmRes(sUG_TS_CONFIRM_STEP_REQ* pData);
	void SendSocialAction(sUG_SOCIAL_ACTION* pData);
	void SendTutoHintUpdateRes(sUG_TUTORIAL_HINT_UPDATE_REQ* pData);
	void SendSystemText(GameString msg, eSERVER_TEXT_TYPE type);
	void SendSystemText(char* szText, ...);
	void SendWarFogUpdateRes(sUG_WAR_FOG_UPDATE_REQ* pData);
	void SendTSExecObjectRes(sUG_TS_EXCUTE_TRIGGER_OBJECT* pData);
	void SendTargetSelect(sUG_CHAR_TARGET_SELECT* pData);
	void SendCharLevelUp(BYTE byToUp = 1);
	void SendCharStateUpdate(HOBJECT hObject, sCHARSTATE sCharState) ;
	void SendLPUpdate(WORD wCurLp, WORD wMaxLp, HOBJECT hTarget);
	void SendEPUpdate(WORD wCurEp, WORD wMaxEp, HOBJECT hTarget);
	void SendLPEPUpdate(WORD wCurLp, WORD wMaxLp, WORD wCurEp, WORD wMaxEp, HOBJECT hTarget);
	void SendCharAttackBegin(sUG_CHAR_ATTACK_BEGIN* pData);
	void SendCharAttackEnd(sUG_CHAR_ATTACK_END* pData);
	void SendCharAttack(DWORD dwCurrTick);
	void SendToggleFightMode(sUG_CHAR_TOGG_FIGHTING* pData);
	void SendMobGiveExp(TBLIDX mobId);
	void SendGiveExp(DWORD dwExp);
	void SendCharSkillRes(sUG_CHAR_SKILL_REQ* pData);
	void DamagetoTarget(HOBJECT hTarget, WORD wDamage);
	void SendNtlMemberNfy();
	void SendServerContents();

	//CASH/EVENT SHOPS
	void SendEventItemStartRes();
	void SendEventItemEndRes();
	void SendNetpyItemStartRes();
	void SendNetpyItemEndRes();

	bool IsClosed() { return bIsClosed; }
	bool IsSpawnReady() { return bIsSpawnReady; }
	bool IsReadyToUpdate() { return bIsReadyToUpdate; }
	CharacterProfile* GetProfile() { return pProfile; }

private:
	PacketEncoder _packetEncoder;
	GameServer* pServer;
	CharacterProfile* pProfile;

	bool bIsClosed;
	bool goCharServer;
	bool bIsSpawnReady;
	bool bIsReadyToUpdate;

	typedef std::map<unsigned int, BYTE> OBJSPAWNLIST;
	typedef OBJSPAWNLIST::iterator OBJSPAWNLISTIT;
	typedef OBJSPAWNLIST::value_type OBJSPAWNLISTVAL;
	OBJSPAWNLIST objSpawn;
};

class GameClientFactory : public SessionFactory
{
public:
	Session* CreateSession(unsigned short sessionType)
	{
		Session* pSession = NULL;
		switch (sessionType)
		{
		case SESSION_CLIENT:
		{
			pSession = new GameClient;
		}
		break;

		default:
			break;
		}
		return pSession;
	}
};

class ClientLink
{
public:
	ClientLink(GameClient* pClient) { m_pClient = pClient; }
	~ClientLink(void) {}
	GameClient* GetClient() { return m_pClient; }
protected:
	GameClient* m_pClient;
};

class GameServer : public ServerApp
{
public:
	int	OnInitApp();
	int	OnCreate();
	void OnDestroy() {}
	int	OnConfiguration(const char* ConfigFile);
	int OnCommandArgument(int argc, _TCHAR* argv[]) { return 0; }
	int	OnAppStart();

	unsigned int AcquireSerialID();

	CharacterManager* GetClientManager() { return _charManager; }
	ObjectManager* GetObjectManager() { return _objManager; }
	TableContainer* GetTableContainer() { return m_pTableContainer; }
	TwTableAll* GetTwTable(){ return m_pTwTableAll; }

	bool LoadTableData();
	void LoadSpawns();
	int LoadSpawns(TBLIDX worldTblidx, bool bIsNpc);

	void Run()
	{
		DWORD TickCur, TickOld = ::GetTickCount();

		while (IsRunnable())
		{
			TickCur = ::GetTickCount();
			if (TickCur - TickOld >= 10000)
			{
				TickOld = TickCur;
			}
		}
	}

private:
	Acceptor _clientAcceptor;
	CharacterManager* _charManager;
	ObjectManager* _objManager;
	TableContainer* m_pTableContainer;
	TwTableAll* m_pTwTableAll;

public:
	Config* ServerCfg;
	Database* ServerDB;
	int ServerID;
	int ChannelID;
	unsigned int m_uiSerialID;
	char* chatServerIP;
	int chatServerPort;
	char* gameDataPath;
	int nMobExpMulti;
};

#endif