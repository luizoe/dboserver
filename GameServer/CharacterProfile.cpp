#include "CharacterProfile.h"
#include "GameNetwork.h"

CharacterProfile::CharacterProfile(GameClient* pClient)
{
	this->pServer = (GameServer*)_GetApp();
	this->pClient = pClient;
	dwLastAttack = 0;
}

void CharacterProfile::Init()
{
	hSerialID = pServer->AcquireSerialID();
	byServerID = pServer->ServerID;
	byChannelID = pServer->ChannelID;
	memset(&sPcProfile, 0, sizeof(sPC_PROFILE));
	memset(&sCharState, 0, sizeof(sCHARSTATE));
	memset(&sWorldInfo, 0, sizeof(sWORLD_INFO));
	bIsSit = false;
	bIsMoving = false;
}

CharacterProfile::~CharacterProfile()
{
	this->pServer = NULL;
	this->pClient = NULL;
}

void CharacterProfile::UpdateCharExp()
{
	pServer->ServerDB->ExecuteQuery("UPDATE `character` SET `CurExp` = '%u' WHERE `ID` = '%u';", sPcProfile.dwCurExp, hCharID);
}

void CharacterProfile::UpdateCharLevel()
{
	pServer->ServerDB->ExecuteQuery("UPDATE `character` SET `Level` = '%d' WHERE `ID` = '%u';", sPcProfile.byLevel, hCharID);
}

void CharacterProfile::LoadWarFogFlags()
{
	memset(&acWarFogFlag, 0xFF, NTL_MAX_SIZE_WAR_FOG);
	// NEED MORE RESEARCH
	/*if (pServer->ServerDB->ExecuteSelect("SELECT `Object` FROM `warfog` WHERE `CharID` = '%u';", hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			HOBJECT Obj = pServer->ServerDB->getInt("Object");
			int uiArrayPos = Obj / 8;
			BYTE byCurBit = (BYTE)(Obj % 8);

			acWarFogFlag[uiArrayPos] |= 0x01ui8 << byCurBit;
		}
	}*/
}

bool CharacterProfile::CheckWarFogFlags(HOBJECT hObject)
{
	bool ret = false;
	if (pServer->ServerDB->ExecuteSelect("SELECT `Object` FROM `warfog` WHERE `CharID` = '%u';", hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			if (hObject == pServer->ServerDB->getInt("Object")) ret = true;
		}
	}
	return ret;
}

bool CharacterProfile::AddWarFogFlags(HOBJECT hObject)
{
	bool ret = CheckWarFogFlags(hObject);

	if (false == ret)
	{
		pServer->ServerDB->ExecuteQuery("INSERT INTO `warfog` (`CharID`,`Object`) VALUES ('%u','%u');", hCharID, hObject);
	}

	return !ret;
}

void CharacterProfile::GetItemBrief(sITEM_BRIEF& sBrief, HOBJECT hItem)
{
	if (hItem == INVALID_HOBJECT)
	{
		sBrief.tblidx = INVALID_ITEMID;
	}
	else
	{
		for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; ++i)
		{
			if (asItemProfile[i].handle == hItem)
			{
				sBrief.tblidx = asItemProfile[i].tblidx;
				sBrief.byBattleAttribute = asItemProfile[i].byBattleAttribute;
				sBrief.byGrade = asItemProfile[i].byGrade;
				sBrief.byRank = asItemProfile[i].byRank;
				sBrief.aOptionTblidx[0] = asItemProfile[i].aOptionTblidx[0];
				sBrief.aOptionTblidx[1] = asItemProfile[i].aOptionTblidx[1];
			}
		}
	}
}

void CharacterProfile::UpdateItemInventoryPosition(HOBJECT hItem, BYTE byPlace, BYTE byPos)
{
	pServer->ServerDB->ExecuteQuery("UPDATE `inventory` SET `Place` = '%d', `Slot` = '%d' WHERE `ID` = '%u' AND `CharID` = '%u';",
		byPlace, byPos, hItem, hCharID);
	for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; ++i)
	{
		if (asItemProfile[i].handle == hItem)
		{
			asItemProfile[i].byPlace = byPlace;
			asItemProfile[i].byPos = byPos;
		}
	}
}

HOBJECT CharacterProfile::GetInventoryItemSerialID(BYTE byPlace, BYTE byPos)
{
	HOBJECT ret = INVALID_HOBJECT;
	if (pServer->ServerDB->ExecuteSelect("SELECT `ID` FROM `inventory` WHERE `Place` = '%d' AND `Slot` = '%d' AND `CharID` = '%u';",
		byPlace, byPos, hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			ret = pServer->ServerDB->getInt("ID");
		}
	}
	return ret;
}

TBLIDX CharacterProfile::GetInventoryItemID(BYTE byPlace, BYTE byPos)
{
	TBLIDX ret = INVALID_TBLIDX;
	if (pServer->ServerDB->ExecuteSelect("SELECT `ItemID` FROM `inventory` WHERE `Place` = '%d' AND `Slot` = '%d' AND `CharID` = '%u';",
		byPlace, byPos, hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			ret = pServer->ServerDB->getInt("ItemID");
		}
	}
	return ret;
}

void CharacterProfile::InsertOnlineData()
{
	pServer->ServerDB->ExecuteQuery("CALL `spInsertOnline`('%u','%u','%u','%u','%u');",
		AccountID, hCharID, byServerID, byChannelID, hSerialID);
}

void CharacterProfile::RemoveOnlineData()
{
	pServer->ServerDB->ExecuteQuery("CALL `spDeleteOnline`('%u','%u');",
		AccountID, hCharID);
}

int CharacterProfile::LoadQuickslotData()
{
	int count = 0;
	if (pServer->ServerDB->ExecuteSelect("SELECT * FROM `quickslot` WHERE `CharID`='%u';", this->hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			asQuickSlotData[count].tblidx = pServer->ServerDB->getInt("TblID");
			asQuickSlotData[count].bySlot = pServer->ServerDB->getInt("Slot");
			asQuickSlotData[count].byType = pServer->ServerDB->getInt("Type");
			asQuickSlotData[count].hItem = pServer->ServerDB->getInt("Item");
			count++;
		}
	}
	return count;
}

int CharacterProfile::LoadSkillData()
{
	int count = 0;
	if (pServer->ServerDB->ExecuteSelect("SELECT * FROM `skills` WHERE `CharID`='%u';", this->hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			asSkillInfo[count].tblidx = pServer->ServerDB->getInt("SkillID");
			asSkillInfo[count].bySlotId = pServer->ServerDB->getInt("Slot");
			asSkillInfo[count].bIsRpBonusAuto = pServer->ServerDB->getBoolean("IsRpBonusAuto");
			asSkillInfo[count].byRpBonusType = pServer->ServerDB->getInt("RpBonusType");
			asSkillInfo[count].dwTimeRemaining = pServer->ServerDB->getInt("RemainSec");
			asSkillInfo[count].nExp = pServer->ServerDB->getInt("Exp");
			count++;
		}
	}
	return count;
}

bool CharacterProfile::InsertNextBagSlot(sGU_ITEM_CREATE& sPacket, ITEMID item, BYTE qtd)
{
	memset(&sPacket, 0, sizeof(sPacket));

	sITEM_TBLDAT* sItem = (sITEM_TBLDAT*)pServer->GetTableContainer()->GetItemTable()->FindData(item);

	if (!sItem)
		return false;

	TBLIDX bags[6];
	memset(bags, 0, sizeof(bags));
	int bagscount[6];
	memset(bagscount, 0, sizeof(bagscount));

	for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; ++i)
	{
		if (asItemProfile[i].byPlace == CONTAINER_TYPE_BAGSLOT)
		{			
			switch (asItemProfile[i].byPos)
			{
				case 0: bags[0] = asItemProfile[i].tblidx; break;
				case 1: bags[1] = asItemProfile[i].tblidx; break;
				case 2: bags[2] = asItemProfile[i].tblidx; break;
				case 3: bags[3] = asItemProfile[i].tblidx; break;
				case 4: bags[4] = asItemProfile[i].tblidx; break;
				case 6: bags[5] = asItemProfile[i].tblidx; break;
			}
		}
	}

	HOBJECT hItem = INVALID_HOBJECT;
	int lastbagslot = 0;
	int lastbag = 0;
	
	for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; ++i)
	{
		if (asItemProfile[i].byPlace == (lastbag + 1) && lastbag < 6)
		{
			sITEM_TBLDAT* sBag = (sITEM_TBLDAT*)pServer->GetTableContainer()->GetItemTable()->FindData(bags[lastbag]);
			
			if (!sBag) continue;

			if (asItemProfile[i].handle != INVALID_HOBJECT && asItemProfile[i].tblidx != INVALID_TBLIDX)
			{
				bagscount[lastbag]++;
				lastbagslot = bagscount[lastbag];
			}

			if (bagscount[lastbag] == sBag->byBag_Size) lastbag++;
		}
	}

	// Bags start from 1 to 6, and array os bags from 0 to 5, add 1 to fix
	lastbag++;
	lastbagslot++;
	
	for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; ++i)
	{
		if (asItemProfile[i].handle == INVALID_HOBJECT && asItemProfile[i].tblidx == INVALID_TBLIDX)
		{
			// (nItemID,nCharID,nPlace,nSlot,nStack,nRank,nCurDur,nNeedToIdentify,nGrade,nBattleAttribute,nRestrictType,nMaker,nOpt1,nOpt2,nDurationType);
			if (pServer->ServerDB->ExecuteSp("CALL `spInsertItem`('%u','%u','%d','%d','%d','%d','%d','0','0','%d','0','','%u','0','%d');",
				item, hCharID, lastbag, lastbagslot, qtd, sItem->byRank, sItem->byDurability, sItem->byBattle_Attribute, sItem->Item_Option_Tblidx, sItem->byDurationType))
			{
				do {
					pServer->ServerDB->GetResultSet();
					while (pServer->ServerDB->Fetch()) {
						hItem = pServer->ServerDB->getInt("LastID");
					}
				} while (pServer->ServerDB->GetMoreResults());
			}

			sPacket.bIsNew = true;
			sPacket.wOpCode = GU_ITEM_CREATE;
			sPacket.handle = hItem;
			sPacket.sItemData.itemId = hItem;
			sPacket.sItemData.charId = hCharID;
			sPacket.sItemData.itemNo = item;
			sPacket.sItemData.byCurrentDurability = sItem->byDurability;
			sPacket.sItemData.byPlace = lastbag;
			sPacket.sItemData.byPosition = lastbagslot;
			sPacket.sItemData.byStackcount = qtd;
			sPacket.sItemData.byRank = sItem->byRank;
			sPacket.sItemData.bNeedToIdentify = false;
			sPacket.sItemData.aOptionTblidx[0] = sItem->Item_Option_Tblidx;
			sPacket.sItemData.byBattleAttribute = sItem->byBattle_Attribute;
			sPacket.sItemData.byDurationType = sItem->byDurationType;
			sPacket.sItemData.byGrade = 0;

			asItemProfile[i].handle = sPacket.sItemData.itemId;
			asItemProfile[i].tblidx = item;
			asItemProfile[i].byCurDur = sPacket.sItemData.byCurrentDurability;
			asItemProfile[i].byPlace = sPacket.sItemData.byPlace;
			asItemProfile[i].byPos = sPacket.sItemData.byPosition;
			asItemProfile[i].byStackcount = sPacket.sItemData.byStackcount;
			asItemProfile[i].byRank = sPacket.sItemData.byRank;
			asItemProfile[i].aOptionTblidx[0] = sPacket.sItemData.aOptionTblidx[0];
			asItemProfile[i].aOptionTblidx[1] = sPacket.sItemData.aOptionTblidx[1];
			asItemProfile[i].bNeedToIdentify = sPacket.sItemData.bNeedToIdentify;
			asItemProfile[i].byBattleAttribute = sPacket.sItemData.byBattleAttribute;
			asItemProfile[i].byDurationType = sPacket.sItemData.byDurationType;
			asItemProfile[i].byGrade = sPacket.sItemData.byGrade;
			break;
		}
	}

	return true;
}

int CharacterProfile::LoadItemData()
{
	for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; ++i)
	{
		asItemProfile[i].handle = INVALID_HOBJECT;
		asItemProfile[i].tblidx = INVALID_TBLIDX;
	}
	int count = 0;
	if (pServer->ServerDB->ExecuteSelect("SELECT * FROM `inventory` WHERE `CharID`='%u';", hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			asItemProfile[count].handle = pServer->ServerDB->getInt("ID");
			asItemProfile[count].tblidx = pServer->ServerDB->getInt("ItemID");
			asItemProfile[count].byPlace = pServer->ServerDB->getInt("Place");
			asItemProfile[count].byPos = pServer->ServerDB->getInt("Slot");
			asItemProfile[count].byStackcount = pServer->ServerDB->getInt("Stack");
			asItemProfile[count].byRank = pServer->ServerDB->getInt("Rank");
			asItemProfile[count].byCurDur = pServer->ServerDB->getInt("CurDur");
			asItemProfile[count].bNeedToIdentify = pServer->ServerDB->getBoolean("NeedToIdentify");
			asItemProfile[count].byGrade = pServer->ServerDB->getInt("Grade");
			asItemProfile[count].byBattleAttribute = pServer->ServerDB->getInt("BattleAttribute");
			asItemProfile[count].byRestrictType = pServer->ServerDB->getInt("RestrictType");
			memcpy(asItemProfile[count].awchMaker, charToWChar(pServer->ServerDB->getString("Maker")), NTL_MAX_SIZE_CHAR_NAME_UNICODE);
			asItemProfile[count].aOptionTblidx[0] = pServer->ServerDB->getInt("Opt1");
			asItemProfile[count].aOptionTblidx[1] = pServer->ServerDB->getInt("Opt2");
			asItemProfile[count].byDurationType = pServer->ServerDB->getInt("DurationType");
			asItemProfile[count].nUseStartTime = pServer->ServerDB->getInt("UseStartTime");
			asItemProfile[count].nUseEndTime = pServer->ServerDB->getInt("UseEndTime");
			count++;
		}
	}
	return count;
}

void CharacterProfile::UpdatePositions(sVECTOR2 Dir, sVECTOR3 Loc)
{
	sCharState.sCharStateBase.vCurLoc = Loc;
	sCharState.sCharStateBase.vCurDir.x = Dir.x;
	sCharState.sCharStateBase.vCurDir.y = 0.0f;
	sCharState.sCharStateBase.vCurDir.z = Dir.z;
	pServer->ServerDB->ExecuteQuery("CALL `spUpdatePosition`('%u', '%f', '%f', '%f');", hCharID, Loc.x, Loc.y, Loc.z);
	pServer->ServerDB->ExecuteQuery("CALL `spUpdateDirection`('%u', '%f', '%f', '%f');", hCharID, Dir.x, 0.0f, Dir.z);
}

void CharacterProfile::UpdatePositions(sVECTOR3 Dir, sVECTOR3 Loc)
{
	sCharState.sCharStateBase.vCurLoc = Loc;
	sCharState.sCharStateBase.vCurDir = Dir;
	pServer->ServerDB->ExecuteQuery("CALL `spUpdatePosition`('%u', '%f', '%f', '%f');", hCharID, Loc.x, Loc.y, Loc.z);
	pServer->ServerDB->ExecuteQuery("CALL `spUpdateDirection`('%u', '%f', '%f', '%f');", hCharID, Dir.x, Dir.y, Dir.z);
}

void CharacterProfile::LoadWorldInfoData()
{
	if (pServer->ServerDB->ExecuteSelect("SELECT * FROM `character` WHERE `AccID`='%d' AND `ID`='%d';", AccountID, hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			sWorldInfo.tblidx = pServer->ServerDB->getInt("worldTblidx");
			sWorldInfo.worldID = pServer->ServerDB->getInt("worldId");
			sWorldInfo.hTriggerObjectOffset = 133000; // WHAT IS THIS??
			sWorldInfo.sRuleInfo.byRuleType = GAMERULE_NORMAL;
		}
	}
}

void CharacterProfile::CalculateAtributes()
{
	sPC_TBLDAT* pPcTbl = (sPC_TBLDAT*)pServer->GetTableContainer()->GetPcTable()->GetPcTbldat(byRace, byClass, byGender);

	if (pPcTbl)
	{
		sPcProfile.avatarAttribute.wBaseMaxEP = pPcTbl->wBasic_EP;
		sPcProfile.avatarAttribute.dwBaseMaxLP = pPcTbl->wBasic_LP;
		sPcProfile.avatarAttribute.wBaseMaxRP = pPcTbl->wBasic_RP;
		sPcProfile.avatarAttribute.wBaseStr = pPcTbl->byStr;
		sPcProfile.avatarAttribute.wBaseFoc = pPcTbl->byFoc;
		sPcProfile.avatarAttribute.wBaseSol = pPcTbl->bySol;
		sPcProfile.avatarAttribute.wBaseDex = pPcTbl->byDex;
		sPcProfile.avatarAttribute.wBaseCon = pPcTbl->byCon;
		sPcProfile.avatarAttribute.wBaseEng = pPcTbl->byEng;
		sPcProfile.avatarAttribute.fBaseAttackRange = pPcTbl->fAttack_Range;
		sPcProfile.avatarAttribute.wBaseAttackRate = pPcTbl->wAttack_Rate;
		sPcProfile.avatarAttribute.wBaseAttackSpeedRate = pPcTbl->wAttack_Speed_Rate;
		sPcProfile.avatarAttribute.wBaseBlockRate = pPcTbl->wBlock_Rate;
		sPcProfile.avatarAttribute.wBaseCurseSuccessRate = pPcTbl->wCurse_Success_Rate;
		sPcProfile.avatarAttribute.wBaseCurseToleranceRate = pPcTbl->wCurse_Tolerance_Rate;
		sPcProfile.avatarAttribute.wBaseDodgeRate = pPcTbl->wDodge_Rate;
		sPcProfile.avatarAttribute.wBasePhysicalOffence = (pPcTbl->byLevel_Up_Physical_Offence * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBasePhysicalDefence = (pPcTbl->byLevel_Up_Physical_Defence * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseEnergyOffence = (pPcTbl->byLevel_Up_Energy_Offence * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseEnergyDefence = (pPcTbl->byLevel_Up_Energy_Defence * sPcProfile.byLevel);

		sPcProfile.avatarAttribute.wBaseMaxEP += (pPcTbl->byLevel_Up_EP * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.dwBaseMaxLP += (pPcTbl->byLevel_Up_LP * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseMaxRP += (pPcTbl->byLevel_Up_RP * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseStr += (BYTE)(pPcTbl->fLevel_Up_Str * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseDex += (BYTE)(pPcTbl->fLevel_Up_Dex * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseFoc += (BYTE)(pPcTbl->fLevel_Up_Foc * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseEng += (BYTE)(pPcTbl->fLevel_Up_Eng * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseCon += (BYTE)(pPcTbl->fLevel_Up_Con * sPcProfile.byLevel);
		sPcProfile.avatarAttribute.wBaseSol += (BYTE)(pPcTbl->fLevel_Up_Sol * sPcProfile.byLevel);

		sPcProfile.avatarAttribute.dwBaseMaxLP += (WORD)((sPcProfile.avatarAttribute.wBaseCon * sPcProfile.byLevel) * 4.7);
		sPcProfile.avatarAttribute.wBaseMaxEP += (WORD)((sPcProfile.avatarAttribute.wBaseEng * sPcProfile.byLevel) * 4.7);

		sPcProfile.avatarAttribute.wLastMaxEP = sPcProfile.avatarAttribute.wBaseMaxEP;
		sPcProfile.avatarAttribute.dwLastMaxLP = sPcProfile.avatarAttribute.dwBaseMaxLP;
		sPcProfile.avatarAttribute.wLastMaxRP = sPcProfile.avatarAttribute.wBaseMaxRP;
		sPcProfile.avatarAttribute.wLastStr = sPcProfile.avatarAttribute.wBaseStr;
		sPcProfile.avatarAttribute.wLastDex = sPcProfile.avatarAttribute.wBaseDex;
		sPcProfile.avatarAttribute.wLastFoc = sPcProfile.avatarAttribute.wBaseFoc;
		sPcProfile.avatarAttribute.wLastEng = sPcProfile.avatarAttribute.wBaseEng;
		sPcProfile.avatarAttribute.wLastCon = sPcProfile.avatarAttribute.wBaseCon;
		sPcProfile.avatarAttribute.wLastSol = sPcProfile.avatarAttribute.wBaseSol;
		sPcProfile.avatarAttribute.wLastPhysicalOffence = sPcProfile.avatarAttribute.wBasePhysicalOffence;
		sPcProfile.avatarAttribute.wLastPhysicalDefence = sPcProfile.avatarAttribute.wBasePhysicalDefence;
		sPcProfile.avatarAttribute.wLastEnergyOffence = sPcProfile.avatarAttribute.wBaseEnergyOffence;
		sPcProfile.avatarAttribute.wLastEnergyDefence = sPcProfile.avatarAttribute.wBaseEnergyDefence;
	}
}

void CharacterProfile::LoadCharacterData()
{
	if (pServer->ServerDB->ExecuteSelect("SELECT * FROM `character` WHERE `AccID`='%u' AND `ID`='%u';", AccountID, hCharID))
	{
		while (pServer->ServerDB->Fetch())
		{
			memset(&sPcProfile, 0, sizeof(sPcProfile));
			sPcProfile.charId = pServer->ServerDB->getInt("ID");
			memcpy(sPcProfile.awchName, charToWChar(pServer->ServerDB->getString("Name")), NTL_MAX_SIZE_CHAR_NAME_UNICODE);
			memcpy(wszCharName, charToWChar(pServer->ServerDB->getString("Name")), NTL_MAX_SIZE_CHAR_NAME_UNICODE);
			byRace = pServer->ServerDB->getInt("Race");
			byClass = pServer->ServerDB->getInt("Class");
			byGender = pServer->ServerDB->getInt("Gender");
			sPcProfile.byLevel = pServer->ServerDB->getInt("Level");
			this->bIsGameMaster = sPcProfile.bIsGameMaster = pServer->ServerDB->getBoolean("IsGameMaster");
			sPcProfile.dwCurExp = pServer->ServerDB->getInt("CurExp");
			sPcProfile.bIsAdult = pServer->ServerDB->getBoolean("Adult");
			sPcProfile.dwTutorialHint = pServer->ServerDB->getInt("TutorialHint");
			sPcProfile.dwZenny = pServer->ServerDB->getInt("Money");
			sPcProfile.sPcShape.byFace = pServer->ServerDB->getInt("Face");
			sPcProfile.sPcShape.byHair = pServer->ServerDB->getInt("Hair");
			sPcProfile.sPcShape.byHairColor = pServer->ServerDB->getInt("HairColor");
			sPcProfile.sPcShape.bySkinColor = pServer->ServerDB->getInt("SkinColor");
			sPcProfile.byBindType = pServer->ServerDB->getInt("BindType");
			sPcProfile.bindObjectTblidx = pServer->ServerDB->getInt("bindObjectTblid");
			sPcProfile.bindWorldId = pServer->ServerDB->getInt("bindWorldId");
			sPcProfile.bChangeClass = pServer->ServerDB->getBoolean("ChangeClass");
			sPcProfile.dwReputation = pServer->ServerDB->getInt("Reputation");
			sPcProfile.dwMudosaPoint = pServer->ServerDB->getInt("MudosaPoint");
			sPcProfile.dwSpPoint = pServer->ServerDB->getInt("SpPoint");
			sPcProfile.sMarking.dwCode = pServer->ServerDB->getInt("Marking");
			sPcProfile.guildId = pServer->ServerDB->getInt("GuildID");

			memset(&sCharState, 0, sizeof(sCharState));
			sCharState.sCharStateBase.vCurLoc.x = pServer->ServerDB->getFloat("PositionX");
			sCharState.sCharStateBase.vCurLoc.y = pServer->ServerDB->getFloat("PositionY");
			sCharState.sCharStateBase.vCurLoc.z = pServer->ServerDB->getFloat("PositionZ");
			sCharState.sCharStateBase.vCurDir.x = pServer->ServerDB->getFloat("DirectionX");
			sCharState.sCharStateBase.vCurDir.y = pServer->ServerDB->getFloat("DirectionY");
			sCharState.sCharStateBase.vCurDir.z = pServer->ServerDB->getFloat("DirectionZ");

			sCharState.sCharStateBase.byStateID = CHARSTATE_SPAWNING;
			sCharState.sCharStateDetail.sCharStateSpawning.byTeleportType = TELEPORT_TYPE_GAME_IN;

			sCharState.sCharStateBase.dwConditionFlag = 0;
			sCharState.sCharStateBase.bFightMode = false;
			sCharState.sCharStateBase.byStateID = 0;
			sCharState.sCharStateBase.dwStateTime = (DWORD)time(NULL);
			sCharState.sCharStateBase.aspectState.sAspectStateBase.byAspectStateId = ASPECTSTATE_INVALID;
			sCharState.sCharStateBase.aspectState.sAspectStateDetail.sGreatNamek.bySourceGrade = 0;
			sCharState.sCharStateBase.aspectState.sAspectStateDetail.sKaioken.bySourceGrade = 0;
			sCharState.sCharStateBase.aspectState.sAspectStateDetail.sPureMajin.bySourceGrade = 0;
			sCharState.sCharStateBase.aspectState.sAspectStateDetail.sSuperSaiyan.bySourceGrade = 0;
			sCharState.sCharStateBase.aspectState.sAspectStateDetail.sVehicle.idVehicleTblidx = 0;

			sPC_TBLDAT* pPcTbl = (sPC_TBLDAT*)pServer->GetTableContainer()->GetPcTable()->GetPcTbldat(byRace, byClass, byGender);
			sEXP_TBLDAT* pExpTbl = (sEXP_TBLDAT*)pServer->GetTableContainer()->GetExpTable()->FindData(sPcProfile.byLevel);

			if (pPcTbl && pExpTbl)
			{
				sPcProfile.tblidx = pPcTbl->tblidx;
				sPcProfile.dwMaxExpInThisLevel = pExpTbl->dwNeed_Exp;
				sPcProfile.wCurEP = pPcTbl->wBasic_EP;
				sPcProfile.dwCurLP = pPcTbl->wBasic_LP;
				sPcProfile.wCurRP = pPcTbl->wBasic_RP;
				sPcProfile.avatarAttribute.fLastRunSpeed = (sPcProfile.bIsAdult) ? pPcTbl->fAdult_Run_Speed : pPcTbl->fChild_Run_Speed;
			}
		}
	}
}

void CharacterProfile::GetObjectCreate(sGU_OBJECT_CREATE& sPacket)
{
	memset(&sPacket, 0, sizeof(sPacket));
	sPacket.wOpCode = GU_OBJECT_CREATE;
	sPacket.handle = GetSerialID();
	sPacket.sObjectInfo.objType = OBJTYPE_PC;
	sPacket.sObjectInfo.pcBrief.charId = hCharID;
	sPacket.sObjectInfo.pcBrief.tblidx = sPcProfile.tblidx;
	sPacket.sObjectInfo.pcBrief.byLevel = sPcProfile.byLevel;
	sPacket.sObjectInfo.pcBrief.wAttackSpeedRate = sPcProfile.avatarAttribute.wLastAttackSpeedRate;
	sPacket.sObjectInfo.pcBrief.wCurEP = sPcProfile.wCurEP;
	sPacket.sObjectInfo.pcBrief.wCurLP = sPcProfile.dwCurLP;
	sPacket.sObjectInfo.pcBrief.wMaxEP = sPcProfile.avatarAttribute.wLastMaxEP;
	sPacket.sObjectInfo.pcBrief.wMaxLP = sPcProfile.avatarAttribute.dwLastMaxLP;
	sPacket.sObjectInfo.pcBrief.fSpeed = sPcProfile.avatarAttribute.fLastRunSpeed;
	memcpy(sPacket.sObjectInfo.pcBrief.awchName, sPcProfile.awchName, NTL_MAX_SIZE_CHAR_NAME_UNICODE);
	sPacket.sObjectInfo.pcBrief.sMarking.dwCode = sPcProfile.sMarking.dwCode;
	sPacket.sObjectInfo.pcBrief.bIsAdult = sPcProfile.bIsAdult;
	memcpy(&sPacket.sObjectInfo.pcBrief.sPcShape, &sPcProfile.sPcShape, sizeof(sPcProfile.sPcShape));
	memcpy(&sPacket.sObjectInfo.pcState, &sCharState, sizeof(sCharState));

	for (int i = 0; i < EQUIP_SLOT_TYPE_COUNT; i++)
	{
		sPacket.sObjectInfo.pcBrief.sItemBrief[i].tblidx = INVALID_ITEMID;
	}

	for (int i = 0; i < NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM; i++)
	{
		int slot = asItemProfile[i].byPos;
		if (asItemProfile[i].byPlace == CONTAINER_TYPE_EQUIP &&
			((slot >= EQUIP_SLOT_TYPE_FIRST) && (slot <= EQUIP_SLOT_TYPE_LAST)))
		{
			sPacket.sObjectInfo.pcBrief.sItemBrief[slot].tblidx = asItemProfile[i].tblidx;
			sPacket.sObjectInfo.pcBrief.sItemBrief[slot].byBattleAttribute = asItemProfile[i].byBattleAttribute;
			sPacket.sObjectInfo.pcBrief.sItemBrief[slot].byGrade = asItemProfile[i].byGrade;
			memcpy(sPacket.sObjectInfo.pcBrief.sItemBrief[slot].aOptionTblidx, asItemProfile[i].aOptionTblidx, 2);
			sPacket.sObjectInfo.pcBrief.sItemBrief[slot].byRank = asItemProfile[i].byRank;
		}
	}
}