#pragma once

#include "Table.h"
#include "NtlCharacter.h"

const DWORD		DBO_MAX_LENGTH_MODEL_NAME = 32;

#pragma pack(push, 4)
struct sCHAR_TBLDAT : public sTBLDAT
{
public:
	DWORD			wBasic_LP;
	WORD			wBasic_EP;
	WORD			wBasic_Physical_Defence;
	WORD			wBasic_Energy_Defence;
	BYTE			byStr;
	BYTE			byCon;
	BYTE			byFoc;
	BYTE			byDex;
	BYTE			bySol;
	BYTE			byEng;
	float			fScale;
	WORD			wAttack_Speed_Rate;
	BYTE			byAttack_Type;
	float			fAttack_Range;
	WORD			wAttack_Rate;
	WORD			wDodge_Rate;
	WORD			wBlock_Rate;
	WORD			wCurse_Success_Rate;
	WORD			wCurse_Tolerance_Rate;
	float			fRadius;
	WORD			wBasic_Aggro_Point;
};
#pragma pack(pop)

// PC
#pragma pack(push, 4)
struct sPC_TBLDAT : public sCHAR_TBLDAT
{
public:
	BYTE			byRace;
	BYTE			byGender;
	BYTE			byClass;
	TBLIDX			prior_Class_Tblidx;
	DWORD			dwClass_Bit_Flag;
	char			szModel_Child[NTL_MAX_LENGTH_MODEL_NAME + 1];
	char			szModel_Adult[NTL_MAX_LENGTH_MODEL_NAME + 1];

	float			fChild_Run_Speed_Origin;
	float			fChild_Run_Speed;
	float			fAdult_Run_Speed_Origin;
	float			fAdult_Run_Speed;

	float unknown1[12];

	WORD			wBasic_RP;
	WORD			wBasic_Physical_Offence;
	WORD			wBasic_Energy_Offence;
	BYTE			byLevel_Up_LP;
	BYTE			byLevel_Up_EP;
	BYTE			byLevel_Up_RP;
	BYTE			byLevel_Up_Physical_Offence;
	BYTE			byLevel_Up_Physical_Defence;
	BYTE			byLevel_Up_Energy_Offence;
	BYTE			byLevel_Up_Energy_Defence;

	DWORD unknown2;

	float			fLevel_Up_Str;
	float			fLevel_Up_Con;
	float			fLevel_Up_Foc;
	float			fLevel_Up_Dex;
	float			fLevel_Up_Sol;
	float			fLevel_Up_Eng;

protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};

struct sPC_TBLDAT2
{
public:
	TBLIDX			tblidx;
	sCHAR_TBLDAT	sCharProfile;
	BYTE			byRace;
	BYTE			byGender;
	BYTE			byClass;
	TBLIDX			prior_Class_Tblidx;
	DWORD			dwClass_Bit_Flag;
	char			szModel_Child[NTL_MAX_LENGTH_MODEL_NAME + 1];
	char			szModel_Adult[NTL_MAX_LENGTH_MODEL_NAME + 1];

	float			fChild_Run_Speed_Origin;
	float			fChild_Run_Speed;
	float			fAdult_Run_Speed_Origin;
	float			fAdult_Run_Speed;

	float unknown1[12];

	WORD			wBasic_RP;
	WORD			wBasic_Physical_Offence;
	WORD			wBasic_Energy_Offence;
	BYTE			byLevel_Up_LP;
	BYTE			byLevel_Up_EP;
	BYTE			byLevel_Up_RP;
	BYTE			byLevel_Up_Physical_Offence;
	BYTE			byLevel_Up_Physical_Defence;
	BYTE			byLevel_Up_Energy_Offence;
	BYTE			byLevel_Up_Energy_Defence;

	DWORD unknown2;

	float			fLevel_Up_Str;
	float			fLevel_Up_Con;
	float			fLevel_Up_Foc;
	float			fLevel_Up_Dex;
	float			fLevel_Up_Sol;
	float			fLevel_Up_Eng;
};
#pragma pack(pop)

class PCTable : public Table
{
public:
	PCTable(void);
	virtual ~PCTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();

	sTBLDAT* FindData(TBLIDX tblidx);
	sTBLDAT* GetPcTbldat(BYTE byRace, BYTE byClass, BYTE byGender);
	bool SetPcTbldat(BYTE byRace, BYTE byClass, BYTE byGender, sTBLDAT* pTbldat);

	virtual bool LoadFromBinary(Serializer& serializer, bool bReload);
	virtual bool SaveToBinary(Serializer& serializer);

protected:
	void Init();
	WCHAR** GetSheetListInWChar() { return &(PCTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);
	sTBLDAT* m_aPcTbldat[RACE_COUNT][PC_CLASS_COUNT][GENDER_COUNT];

private:
	static WCHAR* m_pwszSheetList[];
};
