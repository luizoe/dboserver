#include "CharNetwork.h"

int CharServer::OnInitApp()
{
	_MaxSessionCount = MAX_NUMOF_SESSION;

	_SessionFactory = new CharClientFactory;
	if (NULL == _SessionFactory)
	{
		return 1;//ERR_SYS_MEMORY_ALLOC_FAIL;
	}

	return 0;
}

int CharServer::OnCreate()
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

	ServerDB = new Database();
	if (!ServerDB->Connect(
		ServerCfg->GetStr("MySQL", "Host"),
		ServerCfg->GetStr("MySQL", "Database"),
		ServerCfg->GetStr("MySQL", "User"),
		ServerCfg->GetStr("MySQL", "Password"),
		ServerCfg->GetInt("MySQL", "Port")))
		return 2;//ERR_DBSERVER_CONNECT

	// TABLE CONTAINER LOAD
	gameDataPath = ServerCfg->GetStr("GameData", "Path");
	Logger::Log("Loading Game Data Tables ... PLEASE WAIT\n");
	if (LoadTableData())
		Logger::Log("LOADED!\n");
	else
		return 3;//ERR_TABLE_LOAD

	return 0;
}

int CharServer::OnConfiguration(const char* ConfigFile)
{
	ServerCfg = new Config(ConfigFile);
	return 0;
}

int CharServer::OnAppStart()
{
	Logger::Log("Server listening on %s:%d\n", _clientAcceptor.GetListenIP(), _clientAcceptor.GetListenPort());
	return 0;
}

bool CharServer::LoadTableData()
{
	m_pTwTableAll = new TwTableAll();
	m_pTwTableAll->SetPath("C:/Games/DBOProject/Snaity/dboservetw/TwTables/decrypted");
	m_pTwTableAll->LoadTables();
	return true;
}