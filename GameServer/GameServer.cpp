#include "GameNetwork.h"
int GameServer::OnInitApp()
{
	_MaxSessionCount = MAX_NUMOF_SESSION;

	_SessionFactory = new GameClientFactory;
	if (NULL == _SessionFactory)
	{
		return 1;//ERR_SYS_MEMORY_ALLOC_FAIL;
	}

	return 0;
}

int GameServer::OnCreate()
{
	int rc = 0;
	rc = _clientAcceptor.Create(ServerCfg->GetStr("Server", "IP"),
		ServerCfg->GetInt("Server", "Port"),
		SESSION_CLIENT,
		MAX_NUMOF_GAME_CLIENT, 5, 2, MAX_NUMOF_GAME_CLIENT);
	if (0 != rc)
	{
		return rc;
	}

	rc = _network.Associate(&_clientAcceptor, true);
	if (0 != rc)
	{
		return rc;
	}

	_charManager = new CharacterManager();
	_charManager->Init();
	_objManager = new ObjectManager();
	_objManager->Init();

	ServerDB = new Database();
	if (!ServerDB->Connect(
		ServerCfg->GetStr("MySQL", "Host"),
		ServerCfg->GetStr("MySQL", "Database"),
		ServerCfg->GetStr("MySQL", "User"),
		ServerCfg->GetStr("MySQL", "Password"),
		ServerCfg->GetInt("MySQL", "Port")))
		return 2;//ERR_DBSERVER_CONNECT

	ServerID = ServerCfg->GetInt("Server", "ID");
	ChannelID = ServerCfg->GetInt("Server", "ChannelID");
	chatServerIP = ServerCfg->GetStr("ChatServer", "IP");
	chatServerPort = ServerCfg->GetInt("ChatServer", "Port");
	gameDataPath = ServerCfg->GetStr("GameData", "Path");
	nMobExpMulti = ServerCfg->GetInt("Multipliers", "MobExp");

	m_uiSerialID = INVALID_DWORD;

	ServerDB->ExecuteQuery("CALL `spClearOnline`('%u');", ServerID);
	return 0;
}

int GameServer::OnConfiguration(const char* ConfigFile)
{
	ServerCfg = new Config(ConfigFile);
	return 0;
}

int GameServer::OnAppStart()
{
	// TABLE CONTAINER LOAD
	Logger::Log("Loading Game Data Tables ... PLEASE WAIT\n");
	if (LoadTableData())
		Logger::Log("LOADED!\n");
	else
		return 3;//ERR_TABLE_LOAD

	// Load MOBs/NPCs Spawns
	//LoadSpawns();

	Logger::Log("Server listening on %s:%d\n", _clientAcceptor.GetListenIP(), _clientAcceptor.GetListenPort());
	return 0;
}

unsigned int GameServer::AcquireSerialID()
{
	if (m_uiSerialID++)
	{
		if (m_uiSerialID == INVALID_DWORD)
			m_uiSerialID = 0;
	}

	return m_uiSerialID;
}

bool GameServer::LoadTableData()
{
	m_pTwTableAll = new TwTableAll();
	m_pTwTableAll->SetPath("C:/Games/DBOProject/Snaity/dboservetw/TwTables/decrypted");
	m_pTwTableAll->LoadTables();
	return true;
}

void GameServer::LoadSpawns()
{
	int count = 0;

	Logger::Log("Loading NPCs spawns ...\n");
	for (TableContainer::SPAWNTABLEIT it = GetTableContainer()->BeginNpcSpawnTable(); GetTableContainer()->EndNpcSpawnTable() != it; ++it)
	{
		count += LoadSpawns(it->first, true);
	}
	Logger::Log("Loaded %d NPCs Spawns.\n", count);
	count = 0;
	Logger::Log("Loading MOBs spawns ...\n");
	for (TableContainer::SPAWNTABLEIT it = GetTableContainer()->BeginMobSpawnTable(); GetTableContainer()->EndMobSpawnTable() != it; ++it)
	{
		count += LoadSpawns(it->first, false);
	}
	Logger::Log("Loaded %d MOBs Spawns.\n", count);
}

int GameServer::LoadSpawns(TBLIDX worldTblidx, bool bIsNpc)
{
	int count = 0;

	if (bIsNpc)
	{
		SpawnTable* pSpawnTbl = GetTableContainer()->GetNpcSpawnTable(worldTblidx);
		
		for (Table::TABLEIT it = pSpawnTbl->Begin(); it != pSpawnTbl->End(); ++it, ++count)
		{
			sSPAWN_TBLDAT* pSpawnData = (sSPAWN_TBLDAT*)it->second;

			NpcProfile* obj = new NpcProfile(worldTblidx, pSpawnData->tblidx);
			obj->Init();
			GetObjectManager()->AddObject(obj->GetSerialID(), obj, eOBJTYPE::OBJTYPE_NPC);
		}
	}
	else
	{
		SpawnTable* pSpawnTbl = GetTableContainer()->GetMobSpawnTable(worldTblidx);
		
		for (Table::TABLEIT it = pSpawnTbl->Begin(); it != pSpawnTbl->End(); ++it, ++count)
		{
			sSPAWN_TBLDAT* pSpawnData = (sSPAWN_TBLDAT*)it->second;

			MobProfile* obj = new MobProfile(worldTblidx, pSpawnData->tblidx, pSpawnData->mob_Tblidx);
			obj->Init();
			GetObjectManager()->AddObject(obj->GetSerialID(), obj, eOBJTYPE::OBJTYPE_MOB);
		}
	}
	return count;
}