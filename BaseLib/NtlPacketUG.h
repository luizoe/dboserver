﻿#pragma once

#include "NtlPacketCommon.h"
#include "NtlVector.h"
#include "NtlSkill.h"
#include "NtlItem.h"
#include "NtlParty.h"
#include "NtlQuest.h"
#include "NtlMail.h"
#include "NtlCharacter.h"
#include "NtlGuild.h"
#include "NtlPartyDungeon.h"
#include "NtlDojo.h"
enum eOPCODE_UG
{
	UG_OPCODE_BEGIN = 4001,

	UG_TUTORIAL_HINT_UPDATE_REQ = UG_OPCODE_BEGIN,
	UG_TUTORIAL_WAIT_CANCEL_REQ,
	UG_TUTORIAL_PLAY_QUIT_REQ,
	UG_CHAR_DASH_KEYBOARD,
	UG_CHAR_DASH_MOUSE,
	UG_CHAR_JUMP,
	UG_CHAR_JUMP_END,
	UG_CHAR_FALLING,
	UG_CHAR_TOGG_SITDOWN,
	UG_CHAR_TOGG_FIGHTING,
	UG_CHAR_ATTACK_BEGIN,
	UG_CHAR_ATTACK_END,
	UG_CHAR_CHARGE,
	UG_CHAR_BLOCK_MODE,
	UG_CHAR_TELEPORT_REQ,
	UG_CHAR_BIND_REQ,
	UG_CHAR_REVIVAL_REQ,
	UG_CHAR_SERVER_CHANGE_REQ,
	UG_CHAR_CHANNEL_CHANGE_REQ,
	UG_CHAR_TARGET_SELECT,
	UG_CHAR_TARGET_INFO,
	UG_CHAR_TARGET_FACING,
	UG_CHAR_READY_FOR_COMMUNITY_SERVER_NFY,
	UG_CHAR_READY_TO_SPAWN,
	UG_CHAR_READY,
	UG_CHAR_MOVE,
	UG_CHAR_DEST_MOVE,
	UG_CHAR_CHANGE_HEADING,
	UG_CHAR_MOVE_COLLISION,
	UG_CHAR_MOVE_COLLISION_END,
	UG_CHAR_STANDING_SLIP,
	UG_CHAR_STANDING_SLIP_END,
	UG_CHAR_LOCATION_SYNC,
	UG_CHAR_AIR_MOVE_SYNC,
	UG_CHAR_CHANGE_DIRECTION_ON_FLOATING,
	UG_CHAR_FOLLOW_MOVE,
	UG_CHAR_FOLLOW_MOVE_SYNC,
	UG_GAME_ENTER_REQ,
	UG_GAME_LEAVE_REQ,
	UG_AUTH_KEY_FOR_COMMUNITY_SERVER_REQ,
	UG_ENTER_WORLD,
	UG_LOADING_COMPLETE_NFY,
	UG_SERVER_COMMAND,
	UG_PING,
	UG_SKILL_TARGET_LIST,
	UG_SKILL_LEARN_REQ,
	UG_SKILL_LEARN_BY_ITEM_REQ,
	UG_SKILL_UPGRADE_REQ,
	UG_SKILL_RP_BONUS_SETTING_REQ,
	UG_HTB_START_REQ,
	UG_HTB_LEARN_REQ,
	UG_HTB_FORWARD_REQ,
	UG_HTB_RP_BALL_USE_REQ,
	UG_BUFF_DROP_REQ,
	UG_ITEM_MOVE_REQ,
	UG_ITEM_MOVE_STACK_REQ,
	UG_ITEM_DELETE_REQ,
	UG_ITEM_EQUIP_REPAIR_REQ,
	UG_ITEM_PICK_REQ,
	UG_ITEM_REPAIR_REQ,
	UG_ITEM_USE_REQ,
	UG_ITEM_UPGRADE_REQ,
	UG_ITEM_IDENTIFY_REQ,
	UG_ZENNY_PICK_REQ,
	UG_SHOP_START_REQ,
	UG_SHOP_BUY_REQ,
	UG_SHOP_SELL_REQ,
	UG_SHOP_END_REQ,
	UG_SHOP_SKILL_BUY_REQ,
	UG_PARTY_CREATE_REQ,
	UG_PARTY_DISBAND_REQ,
	UG_PARTY_INVITE_REQ,
	UG_PARTY_INVITE_CHARID_REQ,
	UG_PARTY_INVITE_CHAR_NAME_REQ,
	UG_PARTY_RESPONSE_INVITATION,
	UG_PARTY_LEAVE_REQ,
	UG_PARTY_KICK_OUT_REQ,
	UG_PARTY_CHANGE_LEADER_REQ,
	UG_PARTY_CHANGE_ZENNY_LOOTING_METHOD_REQ,
	UG_PARTY_CHANGE_ITEM_LOOTING_METHOD_REQ,
	UG_BANK_START_REQ,
	UG_BANK_MOVE_REQ,
	UG_BANK_MOVE_STACK_REQ,
	UG_BANK_END_REQ,
	UG_BANK_ZENNY_REQ,
	UG_BANK_BUY_REQ,
	UG_BANK_ITEM_DELETE_REQ,
	UG_SCOUTER_INDICATOR_REQ,
	UG_SCOUTER_PREDICT_REQ,
	UG_SCOUTER_EQUIP_CHECK_REQ,
	UG_SCOUTER_CHIP_REMOVE_ALL_REQ,
	UG_SCOUTER_ACTIVATION_REQ,
	UG_SOCIAL_ACTION,
	UG_TS_CONFIRM_STEP_REQ,
	UG_TS_CONFIRM_STEP_FOR_USE_ITEM_REQ,
	UG_TS_UPDATE_STATE,
	UG_TS_EXCUTE_TRIGGER_OBJECT,
	UG_QUEST_ITEM_MOVE_REQ,
	UG_QUEST_ITEM_DELETE_REQ,
	UG_QUEST_GIVEUP_REQ,
	UG_QUEST_SHARE,
	UG_QUEST_OBJECT_VISIT_REQ,
	UG_FREEBATTLE_CHALLENGE_REQ,
	UG_FREEBATTLE_ACCEPT_RES,
	UG_QUICK_SLOT_UPDATE_REQ,
	UG_QUICK_SLOT_DEL_REQ,
	UG_PET_DISMISS_PET_REQ,
	UG_TRADE_START_REQ,
	UG_TRADE_OK_RES,
	UG_TRADE_ADD_REQ,
	UG_TRADE_DEL_REQ,
	UG_TRADE_MODIFY_REQ,
	UG_TRADE_ZENNY_UPDATE_REQ,
	UG_TRADE_END_REQ,
	UG_TRADE_CANCEL_REQ,
	UG_TRADE_DENY_REQ,
	UG_GUILD_CREATE_REQ,
	UG_GUILD_INVITE_REQ,
	UG_DRAGONBALL_CHECK_REQ,
	UG_DRAGONBALL_REWARD_REQ,
	UG_TIMEQUEST_ENTER_REQ,
	UG_RANKBATTLE_INFO_REQ,
	UG_RANKBATTLE_JOIN_REQ,
	UG_RANKBATTLE_LEAVE_REQ,
	UG_PORTAL_ADD_REQ,
	UG_PORTAL_REQ,
	UG_PRIVATESHOP_CREATE_REQ,
	UG_PRIVATESHOP_EXIT_REQ,
	UG_PRIVATESHOP_OPEN_REQ,
	UG_PRIVATESHOP_CLOSE_REQ,
	UG_PRIVATESHOP_ITEM_UPDATE_REQ,
	UG_PRIVATESHOP_ITEM_INSERT_REQ,
	UG_PRIVATESHOP_ITEM_GET_REQ,
	UG_PRIVATESHOP_ITEM_DELETE_REQ,
	UG_PRIVATESHOP_ITEM_BUYING_REQ,
	UG_PRIVATESHOP_ENTER_REQ,
	UG_PRIVATESHOP_LEAVE_REQ,
	UG_PRIVATESHOP_ITEM_SELECT_REQ,
	UG_PRIVATESHOP_BUSINESS_REQUEST_REQ,
	UG_PRIVATESHOP_BUSINESS_CONSENT_RES,
	UG_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY,
	UG_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_REQ,
	UG_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_REQ,
	UG_PRIVATESHOP_BUSINESS_CANCEL_REQ,
	UG_MAIL_START_REQ,
	UG_MAIL_SEND_REQ,
	UG_MAIL_READ_REQ,
	UG_MAIL_DEL_REQ,
	UG_MAIL_RETURN_REQ,
	UG_MAIL_RELOAD_REQ,
	UG_MAIL_LOAD_REQ,
	UG_MAIL_ITEM_RECEIVE_REQ,
	UG_MAIL_LOCK_REQ,
	UG_MAIL_MULTI_DEL_REQ,
	UG_WAR_FOG_UPDATE_REQ,
	UG_GUILD_FUNCTION_ADD_REQ,
	UG_GUILD_GIVE_ZENNY,
	UG_GUILD_BANK_START_REQ,
	UG_GUILD_BANK_MOVE_REQ,
	UG_GUILD_BANK_MOVE_STACK_REQ,
	UG_GUILD_BANK_END_REQ,
	UG_GUILD_BANK_ZENNY_REQ,
	UG_GUILD_CREATE_MARK_REQ,
	UG_GUILD_CHANGE_MARK_REQ,
	UG_CROSSFIRE_REQ,
	UG_BANK_LOAD_REQ,
	UG_GUILD_CHANGE_NAME_REQ,
	UG_PARTY_SHARETARGET_REQ,
	UG_RIDE_ON_BUS_REQ,
	UG_RIDE_OFF_BUS_REQ,
	UG_TRANSFORM_CANCEL_REQ,
	UG_SHOP_ITEM_IDENTIFY_REQ,
	UG_DICE_ROLL_REQ,
	UG_BUDOKAI_JOIN_INFO_REQ,
	UG_BUDOKAI_JOIN_STATE_REQ,
	UG_BUDOKAI_MUDOSA_INFO_REQ,
	UG_BUDOKAI_MUDOSA_TELEPORT_REQ,
	UG_BUDOKAI_PARTY_MAKER_REQ,
	UG_BUDOKAI_SOCIAL_ACTION,
	UG_BUDOKAI_PRIZEWINNER_NAME_REQ,
	UG_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_REQ,
	UG_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_REQ,
	UG_BUDOKAI_GM_MATCH_PROGRESS_INFO_REQ,
	UG_BUDOKAI_GM_MATCH_ARENA_ENTER_REQ,
	UG_BUDOKAI_GM_MATCH_ARENA_LEAVE_REQ,
	UG_BUDOKAI_JOIN_TEAM_INFO_REQ,
	UG_BUDOKAI_JOIN_TEAM_REQ,
	UG_BUDOKAI_LEAVE_TEAM_REQ,
	UG_BUDOKAI_LEAVE_TEAM_MEMBER_REQ,
	UG_BUDOKAI_JOIN_INDIVIDUAL_REQ,
	UG_BUDOKAI_LEAVE_INDIVIDUAL_REQ,
	UG_SCOUTER_TURN_ON,
	UG_SCOUTER_TURN_OFF,
	UG_SCOUTER_ITEM_SELL_REQ,
	UG_SHOP_EVENTITEM_START_REQ,
	UG_SHOP_EVENTITEM_BUY_REQ,
	UG_SHOP_EVENTITEM_END_REQ,
	UG_SHOP_GAMBLE_BUY_REQ,
	UG_PARTY_DIFF_CHANGE_REQ,
	UG_PARTY_DUNGEON_INIT_REQ,
	UG_VEHICLE_DIRECT_PLAY_CANCEL_NFY,
	UG_VEHICLE_ENGINE_START_REQ,
	UG_VEHICLE_ENGINE_STOP_REQ,
	UG_VEHICLE_END_REQ,
	UG_VEHICLE_STUNT_NFY,
	UG_VEHICLE_FUEL_REMOVE_NFY,
	UG_SKILL_INIT_REQ,
	UG_SKILL_RESET_PLUS_REQ,
	UG_TELEPORT_CONFIRM_REQ,
	UG_HOIPOIMIX_ITEM_CHECK_REQ,
	UG_HOIPOIMIX_ITEM_MAKE_REQ,
	UG_HOIPOIMIX_ITEM_MAKE_EP_REQ,
	UG_HOIPOIMIX_ITEM_MACHINE_DEL_REQ,
	UG_HOIPOIMIX_JOB_SET_REQ,
	UG_HOIPOIMIX_JOB_RESET_REQ,
	UG_HOIPOIMIX_ITEM_CREATE_EX_REQ,
	UG_ITEM_DISASSEMBLE_REQ,
	UG_CASHITEM_START_REQ,
	UG_CASHITEM_END_REQ,
	UG_CASHITEM_MOVE_REQ,
	UG_CASHITEM_USE_REQ,
	UG_CASHITEM_HLSHOP_START_REQ,
	UG_CASHITEM_HLSHOP_END_REQ,
	UG_CASHITEM_HLSHOP_REFRESH_REQ,
	UG_CASHITEM_BUY_REQ,
	UG_CASHITEM_SEND_GIFT_REQ,
	UG_DOJO_CREATE_REQ,
	UG_DOJO_DELETE_REQ,
	UG_DOJO_FUNCTION_ADD_REQ,
	UG_DOJO_BANK_HISTORY_REQ,
	UG_DOGI_CREATE_REQ,
	UG_DOGI_CHANGE_REQ,
	UG_GUILD_DOGI_CREATE_REQ,
	UG_GUILD_DOGI_CHANGE_REQ,
	UG_DOJO_SCRAMBLE_REQ,
	UG_DOJO_SCRAMBLE_RESPONSE_REQ,
	UG_SHOP_NETPYITEM_START_REQ,
	UG_SHOP_NETPYITEM_BUY_REQ,
	UG_SHOP_NETPYITEM_END_REQ,
	UG_WORLD_MAP_STATUS,
	UG_DOJO_NPC_INFO_REQ,
	UG_GAMEGUARD_AUTH_ANSWER_RES,
	UG_GAMEGUARD_HACK_INFO_NFY,
	UG_SKILL_CASTING_CANCELED_NFY,
	UG_PET_ATTACK_TARGET_NFY,
	UG_DURATION_ITEM_BUY_REQ,
	UG_DURATION_RENEW_REQ,
	UG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ,
	UG_GMT_UPDATE_REQ,
	UG_CHAR_LOC_AFTER_KNOCKDOWN_NFY,
	UG_CHAR_LOC_AFTER_SLIDING_NFY,
	UG_CHAR_LOC_AFTER_PUSH_NFY,
	UG_SCS_CHECK_START_RES,
	UG_SCS_CHECK_RES,
	UG_SCS_REPLY_REQ,
	UG_SCS_REMAKE_REQ,
	UG_QUICK_TELEPORT_LOAD_REQ,
	UG_QUICK_TELEPORT_UPDATE_REQ,
	UG_QUICK_TELEPORT_DEL_REQ,
	UG_QUICK_TELEPORT_USE_REQ,
	UG_CHAR_CRESCENT_POPO_REVIVAL_REQ,
	UG_CHARACTER_RENAME_REQ,
	UG_CASHITEM_UPDATE_DURATION_REQ,
	UG_CHAR_DEST_MOVE_SYNC,
	UG_CHAR_NPCSERVER_MOVE_SYNC,
	UG_HOIPOIMIX_ITEM_CREATE_REQ,
	UG_CHAR_EXIT_REQ,
	UG_GAME_EXIT_REQ,
	UG_CHAR_AWAY_REQ,
	UG_CHAR_KEY_UPDATE_REQ,
	UG_CHAR_DIRECT_PLAY_CANCEL,
	UG_CHAR_DIRECT_PLAY_ACK,
	UG_CHAR_KNOCKDOWN_RELEASE_NFY,
	UG_CHAR_SKILL_REQ,
	UG_DRAGONBALL_SCRAMBLE_JOIN_REQ,
	UG_DRAGONBALL_SCRAMBLE_BALL_LOC_REQ,
	UG_CHAR_SKILL_INIT_REQ,
	UG_GUILD_DOGI_DYE_REQ,
	UG_TENKAICHIDAISIJYOU_SELL_REQ,
	UG_TENKAICHIDAISIJYOU_SELL_CANCEL_REQ,
	UG_TENKAICHIDAISIJYOU_BUY_REQ,
	UG_TENKAICHIDAISIJYOU_LIST_REQ,
	UG_MASCOT_SUMMON_REQ,
	UG_MASCOT_UNSUMMON_REQ,
	UG_MASCOT_DELETE_REQ,
	UG_MASCOT_RING_ACTION_REQ,
	UG_MASCOT_RING_REMOVE_ALL_REQ,
	UG_MASCOT_SUMMON_REQ_EX,
	UG_MASCOT_UNSUMMON_REQ_EX,
	UG_MASCOT_DELETE_REQ_EX,
	UG_MASCOT_RING_MATERIAL_DISASSEMBLE_REQ,
	UG_MASCOT_RING_ACTION_END_REQ,
	UG_REMOTE_SHOP_BUY_REQ,
	UG_REMOTE_SHOP_SELL_REQ,
	UG_REMOTE_ITEM_EQUIP_REPAIR_REQ,
	UG_REMOTE_ITEM_REPAIR_REQ,
	UG_REMOTE_SHOP_ITEM_IDENTIFY_REQ,
	UG_WORLD_LAVA_ENTERED_NFY,
	UG_WORLD_LAVA_LEFT_NFY,
	UG_SKILL_ONE_RESET_REQ,
	UG_CASHITEM_INFO_REQ,
	UG_ULTIMATE_DUNGEON_ENTER_REQ,
	UG_PARTY_MATCHING_REGISTER_REQ,
	UG_PARTY_MATCHING_JOIN_REQ,
	UG_PARTY_MATCHING_ROLEPLAY_REQ,
	UG_PARTY_MATCHING_UNREGISTER_REQ,
	UG_PARTY_MATCHING_LIST_REQ,
	UG_PARTY_MATCHING_INFO_REQ,
	UG_PARTY_MATCHING_ENTER_DUNGEON_REQ,
	UG_PARTY_MATCHING_ENTER_DUNGEON_AGREE_NFY,
	UG_DWC_WORLDCOUNT_INFO_REQ,
	UG_DWC_ENTER_REQ,
	UG_DWC_ENTER_CONFIRM_REQ,
	UG_DWC_SCENARIO_INFO_REQ,
	UG_DWC_GET_REWARD_REQ,
	UG_CHARTITLE_SELECT_REQ,
	UG_TMQ_LIMIT_COUNT_PLUS_REQ,
	UG_PARTY_SELECT_STATE_REQ,
	UG_BATTLE_DUNGEON_ENTER_REQ,
	UG_BATTLE_DUNGEON_LEAVE_REQ,
	UG_ITEM_UPGRADE_WORK_REQ,
	UG_ITEM_UPGRADE_PROBABLEITEM_REQ,
	UG_REQUEST_CHAR_HISTORY_DATA_REQ,
	UG_EVENT_REWARD_LOAD_REQ,
	UG_EVENT_REWARD_SELECT_REQ,
	UG_DROPITEM_INFO_REQ,
	UG_ITEM_UPGRADE_BY_COUPON_REQ,
	UG_VEHICLE_FUEL_INSERT_REQ,
	UG_ITEM_EXCHANGE_REQ,
	UG_GAMEGUARD3_AUTH_ANSWER_RES,
	UG_ITEM_UPGRADED_EXCHANGE_REQ,
	UG_ITEM_SEAL_REQ,
	UG_ITEM_SEAL_EXTRACT_REQ,
	UG_PERFORMANCE_DATA_NFY,
	UG_PERFORMANCE_DATA_2_NFY,
	UG_PARTY_CHANGE_ITEM_LOOTING_RANK_METHOD_REQ,
	UG_ITEM_DICE_REQ,
	UG_GIFT_SHOP_START_REQ,
	UG_GIFT_SHOP_BUY_REQ,
	UG_ITEM_SOCKET_INSERT_BEAD_REQ,
	UG_ITEM_SOCKET_DESTROY_BEAD_REQ,
	UG_ITEM_CHAGE_BATTLE_ATTRIBUTE_REQ,
	UG_INVISIBLE_COSTUME_UPDATE_REQ,
	UG_INVENTORY_SORT_REQ,
	UG_ITEM_CHANGE_OPTION_REQ,
	UG_DYNAMIC_FIELD_SYSTEM_BOSS_POSITION_REQ,
	UG_CHAR_AIR_MOVE,
	UG_CHAR_AIR_JUMP,
	UG_CHAR_AIR_DASH,
	UG_CHAR_AIR_FALLING,
	UG_CHAR_AIR_END,
	UG_CHAR_AIR_FOLLOW_MOVE,
	UG_CHAR_AIR_ACCEL,
	UG_CHAR_AIR_POSE_REQ,
	UG_PET_ATTACK_TOGGLE_NFY,
	UG_PET_SKILL_TOGGLE_NFY,
	UG_PET_RECALL_NFY,
	UG_MASCOT_FUSION_REQ,
	UG_MASCOT_SKILL_ADD_REQ,
	UG_MASCOT_SKILL_UPDATE_REQ,
	UG_MASCOT_SKILL_UPGRADE_REQ,
	UG_MASCOT_SKILL_REQ,
	UG_MASCOT_AUTO_LOOTING_REQ,
	UG_MASCOT_REMOTE_SHOP_SELL_REQ,
	UG_MASCOT_SEAL_SET_REQ,
	UG_MASCOT_SEAL_CLEAR_REQ,

	UG_OPCODE_DUMMY,
	UG_OPCODE_END = UG_OPCODE_DUMMY - 1
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * NtlGetPacketName_UG(WORD wOpCode);
//------------------------------------------------------------------

#pragma pack(1)

//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GAME_ENTER_REQ)
	ACCOUNTID			accountId;
	CHARACTERID			charId;
	BYTE				abyAuthKey[NTL_MAX_SIZE_AUTH_KEY];
	bool				bTutorialMode;	// 튜토리얼 요청 값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GAME_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_AUTH_KEY_FOR_COMMUNITY_SERVER_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ENTER_WORLD)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SERVER_COMMAND)
	WORD				wMessageLengthInUnicode;
	WCHAR				awchCommand[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_READY_FOR_COMMUNITY_SERVER_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_READY_TO_SPAWN)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_READY)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_MOVE)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	sVECTOR3			vCurLoc;
	sVECTOR2			vCurDir;
	BYTE				byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_DEST_MOVE)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	sVECTOR3			vCurLoc;
	sVECTOR3			vDestLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_CHANGE_HEADING)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	sVECTOR3			vCurrentPosition;
	sVECTOR3			vCurrentHeading;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_CHAR_MOVE_SYNC)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	sVECTOR3			vCurLoc;
	sVECTOR3			vCurDir;
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_CHANGE_DIRECTION_ON_FLOATING)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	sVECTOR3			vCurDir;
	BYTE				byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_FOLLOW_MOVE)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	HOBJECT				hTarget;
	float				fDistance;
	BYTE				byMovementReason;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_DASH_KEYBOARD)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	sVECTOR3			vCurLoc;
	sVECTOR2			vCurDir;
	BYTE				byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_DASH_MOUSE)
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	sVECTOR3			vDestLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_JUMP)
	sVECTOR3			vCurrentHeading;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_JUMP_END)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_FALLING)
	bool				bIsFalling;
	sVECTOR3			vCurLoc;
	sVECTOR2			vCurDir;
	BYTE				byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_TOGG_SITDOWN)
	bool				bSitDown;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_TOGG_FIGHTING)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	bool				bFightMode;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_CHAR_TOGG_RUNNING)
	bool				bRunMode;
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_TARGET_SELECT)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_TARGET_INFO)
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_TARGET_FACING)
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_ATTACK_BEGIN)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	BYTE				byType;	// 형석 : 임시
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_ATTACK_END)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	BYTE				byType;	// 형석 : 임시
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_CHARGE)
	bool				bCharge; // ON/OFF
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_BLOCK_MODE)
	bool				bIsOn;		// On/Off
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_TELEPORT_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_BIND_REQ)
	TBLIDX				bindObjectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_REVIVAL_REQ)
	BYTE				byRevivalRequestType;		// eDBO_REVIVAL_REQUEST_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_SERVER_CHANGE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_CHANNEL_CHANGE_REQ)
	SERVERCHANNELID		destServerChannelId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_EXIT_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GAME_EXIT_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_CHAR_AWAY_REQ )
	bool	bIsAway;		// AwayOn 1: Awayoff: 0
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_CHAR_KEY_UPDATE_REQ )
	BYTE	byCount;		// 변경갯수
	sSHORTCUT_UPDATE_DATA asData[NTL_SHORTCUT_MAX_COUNT];	 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_CHAR_DIRECT_PLAY_ACK ) 		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_CHAR_KNOCKDOWN_RELEASE_NFY ) 		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_SKILL_REQ)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	BYTE				bySlotIndex;
	BYTE				byRpBonusType;		// eDBO_RP_BONUS_TYPE
	HOBJECT				hTarget;
	// If skill effect should be applied on a target character, too, the target character must be included in both byApplyTargetCount and ahApplyTarget.
	// 스킬의 타겟 캐릭터가 스킬 적용 대상인 경우에는 타겟 캐릭터도 byApplyTargetCount와 ahApplyTarget에 포함되어야 한다.
	// by YOSHIKI(2007-01-12)
	BYTE				byApplyTargetCount;
	HOBJECT				ahApplyTarget[NTL_MAX_NUMBER_OF_SKILL_TARGET];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SKILL_TARGET_LIST)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	// If skill effect should be applied on a target character, too, the target character must be included in both byApplyTargetCount and ahApplyTarget.
	// 스킬의 타겟 캐릭터가 스킬 적용 대상인 경우에는 타겟 캐릭터도 byApplyTargetCount와 ahApplyTarget에 포함되어야 한다.
	// by YOSHIKI(2007-02-22)
	BYTE				byApplyTargetCount;
	HOBJECT				ahApplyTarget[NTL_MAX_NUMBER_OF_SKILL_TARGET];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SKILL_LEARN_REQ)
	TBLIDX				skillTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SKILL_UPGRADE_REQ)
	BYTE				bySlotIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SKILL_RP_BONUS_SETTING_REQ)
	BYTE				bySlotIndex;
	BYTE				byRpBonusType;		// eDBO_RP_BONUS_TYPE
	bool				bIsRpBonusAuto;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HTB_START_REQ)
	HOBJECT				hTarget;
	BYTE				bySkillSlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HTB_LEARN_REQ)
	HOBJECT				hTrainer; // 트레이너 핸들
	TBLIDX				skillId; // HTB set 테이블 번호
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HTB_FORWARD_REQ)
	sVECTOR3			vCurLoc; // 진행 위치
	sVECTOR2			vCurDir; // 진행 방향
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HTB_RP_BALL_USE_REQ)
	BYTE				byRpBallCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUFF_DROP_REQ)
	BYTE				bySourceType;		// eDBO_OBJECT_SOURCE
	TBLIDX				tblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_MOVE_REQ)
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestPlace;
	BYTE				byDestPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_MOVE_STACK_REQ)
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestPlace;
	BYTE				byDestPos;
	BYTE				byStackCount; 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_DELETE_REQ)
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_EQUIP_REPAIR_REQ)
	HOBJECT				handle;			// NpcHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_PICK_REQ)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	HOBJECT				handle;			// ItemHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_REPAIR_REQ)
	HOBJECT				handle;			// NpcHandle
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_USE_REQ)
	HOBJECT				hTarget;
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_UPGRADE_REQ)
	HOBJECT				handle;				// NpcHandle
	BYTE				byItemPlace;		// 업그레이드 할 아이템의 컨테이너 위치
	BYTE				byItemPos;			// 업그레이드 할 아이템의 위치
	BYTE				byStonPlace;		// 호이포이스톤 컨테이너 위치
	BYTE				byStonPos;			// 호이포이스톤 위치
	BYTE				byPosNum;			// 업그레이드 창의 조합위치: (아이템의 슬롯번호 * 10 + 호이포이스톤슬롯번호) 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ITEM_IDENTIFY_REQ)
	BYTE				byPlace;			// 아이템 확인시의 확인 할 아이템의 컨테이너 위치
	BYTE				byPos;				// 아이템의 포지션.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_ZENNY_PICK_REQ)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	HOBJECT				handle;			// ItemHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_START_REQ)
	HOBJECT				handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_BUY_REQ)
	HOBJECT				handle;
	BYTE				byBuyCount;
	sSHOP_BUY_CART		sBuyData[NTL_MAX_BUY_SHOPPING_CART]; 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_SELL_REQ)
	HOBJECT				handle;
	BYTE				bySellCount;
	sSHOP_SELL_CART		sSellData[NTL_MAX_SELL_SHOPPING_CART]; // 3BYTE * 8 = 24
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_SKILL_BUY_REQ)
	HOBJECT				hNpchandle;
	BYTE				byMerchantTab;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_CREATE_REQ)
	WCHAR				wszPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_DISBAND_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVITE_REQ)
	HOBJECT				hTarget;
	// If the player belong to a party, the part of 'wszPartyName' doesn't need to be sent when inviting another player.
	// 이미 파티에 가입한 상태에서 다른 플레이어를 초대할 때에는 wszPartyName 부분을 전송하지 않아도 된다.
	// by YOSHIKI(2009-02-13)
	WCHAR				wszPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVITE_CHARID_REQ)
	CHARACTERID			targetCharId;
	// If the player belong to a party, the part of 'wszPartyName' doesn't need to be sent when inviting another player.
	// 이미 파티에 가입한 상태에서 다른 플레이어를 초대할 때에는 wszPartyName 부분을 전송하지 않아도 된다.
	// by YOSHIKI(2009-02-13)
	WCHAR				wszPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVITE_CHAR_NAME_REQ)
	WCHAR				wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	// If the player belong to a party, the part of 'wszPartyName' doesn't need to be sent when inviting another player.
	// 이미 파티에 가입한 상태에서 다른 플레이어를 초대할 때에는 wszPartyName 부분을 전송하지 않아도 된다.
	// by YOSHIKI(2009-02-13)
	WCHAR				wszPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_RESPONSE_INVITATION)
	BYTE				byResponse;		// eNTL_INVITATION_RESPONSE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_KICK_OUT_REQ)
	HOBJECT				hTargetMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_CHANGE_LEADER_REQ)
	HOBJECT				hTargetMember;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_PARTY_OPEN_CHARM_SLOT_REQ)
	BYTE				byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_CLOSE_CHARM_SLOT_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_REGISTER_VICTIM_ITEM_REQ)
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestSlotIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_UNREGISTER_VICTIM_ITEM_REQ)
	BYTE				byDestSlotIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_REGISTER_VICTIM_ZENNY_REQ)
	DWORD				dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_UNREGISTER_VICTIM_ZENNY_REQ)
	DWORD				dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_DECLARE_ZENNY_REQ)
	DWORD				dwZennyToDeclare;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_ACTIVATE_CHARM_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_DEACTIVATE_CHARM_REQ)
	BYTE				byCharmInventoryIndex;
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_CHANGE_ZENNY_LOOTING_METHOD_REQ)
	BYTE				byLootingMethod;		// eNTL_PARTY_ZENNY_LOOTING
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_CHANGE_ITEM_LOOTING_METHOD_REQ)
	BYTE				byLootingMethod;		// eNTL_PARTY_ITEM_LOOTING
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_PARTY_INVEST_ZENNY_REQ)
	BYTE			byPos;
	// 'dwZennyToInvest' doesn't mean relative value to the current zenny but final invested zenny.
	// 현재 투자된 포인트와의 상대적인 값이 아니라, 아이템에 최종적으로 투자될 제니이다.
	// by YOSHIKI(2006-11-01)
	DWORD			dwZennyToInvest;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_ITEM_RANK_SET_REQ)
	BYTE				byItemRank; // eITEM_RANK 
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_START_REQ)
	HOBJECT				handle;			// NpcHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_MOVE_REQ)
	HOBJECT				handle;
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestPlace;
	BYTE				byDestPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_MOVE_STACK_REQ)
	HOBJECT				handle;
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestPlace;
	BYTE				byDestPos;
	BYTE				byStackCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_ZENNY_REQ)
	HOBJECT				handle;			// NpcHandle
	DWORD				dwZenny;		// 빼거나 넣을 액수
	bool				bIsSave;		// 1 은 넣을 경우 0 은 빼는경우
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_BUY_REQ)
	HOBJECT				hNpchandle;
	BYTE				byMerchantTab;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BANK_ITEM_DELETE_REQ)
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_INDICATOR_REQ)
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_PREDICT_REQ)
	BYTE				byPusNum;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_EQUIP_CHECK_REQ)  
	HOBJECT				hTarget;			// 확인 하고자 하는 상대 타겟 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_CHIP_REMOVE_ALL_REQ)  
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SOCIAL_ACTION)
	TBLIDX				socialActionId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TS_CONFIRM_STEP_REQ)  
	BYTE				byTsType; // 트리거 타입
	NTL_TS_T_ID			tId;
	NTL_TS_TC_ID		tcCurId;
	NTL_TS_TC_ID		tcNextId;
	DWORD				dwParam;
	BYTE				byEventType;
	DWORD				dwEventData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TS_UPDATE_STATE)
	BYTE				byTsType;	// 트리거 타입
	NTL_TS_T_ID			tId;
	BYTE				byType;
	WORD				wTSState;
	DWORD				dwParam;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TS_EXCUTE_TRIGGER_OBJECT)
	HOBJECT				hSource;
	HOBJECT				hTarget;
	BYTE				byEvtGenType;
	unsigned int		uiParam;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUEST_ITEM_MOVE_REQ)  
	BYTE				bySrcPos;
	BYTE				byDestPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUEST_ITEM_DELETE_REQ)  
	BYTE				byDeletePos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUEST_GIVEUP_REQ)  
	NTL_TS_T_ID			tId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUEST_SHARE)  
	NTL_TS_T_ID			tId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUEST_OBJECT_VISIT_REQ)  
	QUESTID				qId;
	WORLDID				worldId;
	BYTE				byObjType;			// eOBJTYPE
	TBLIDX				objectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_FREEBATTLE_CHALLENGE_REQ)  
	HOBJECT				hTarget;	// 대전신청 상대캐릭터의 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_FREEBATTLE_ACCEPT_RES)  
	BYTE				byAccept; // 1: 수락 0: 거절 2: 수락할상태가 아님 대전 수락 여부
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUICK_SLOT_UPDATE_REQ)  
	TBLIDX				tblidx;
	BYTE				bySlotID;
	BYTE				byType;
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_QUICK_SLOT_DEL_REQ)  
	BYTE				bySlotID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PET_DISMISS_PET_REQ)
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_START_REQ)			// 해당 유저와의 교환 요청
	HOBJECT				hTarget;			// 타겟 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_OK_RES)				// 해당 유져의 응답
	HOBJECT				handle;				// 요청자의 핸들
	BYTE				byOK;				// 승락 유무 1 : 승락 0 : 거부 3: 바쁜상황
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_ADD_REQ)			// 교환창에 아이템 등록
	HOBJECT				hTarget;			// 타겟 핸들
	HOBJECT				hItem;				// 아이템 핸들
	BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_DEL_REQ)			// 교환창에 아이템 삭제
	HOBJECT				hTarget;			// 타겟 핸들
	HOBJECT				hItem;				// 아이템 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_MODIFY_REQ)			// 교환창에 아이템 등록
	HOBJECT				hTarget;			// 타겟 핸들
	HOBJECT				hItem;				// 아이템 핸들
	BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_ZENNY_UPDATE_REQ)	// 교환창에 제니 등록 및 변경
	HOBJECT				hTarget;			// TargetHandle
	DWORD				dwZenny;			// 옮길 만큼의 제니 (자기가 갖고 있는 제니 한도 내)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_END_REQ)			// 교환 완료 버튼 클릭
	HOBJECT				hTarget;			// 타겟 핸들
	DWORD				dwPacketCount;		// 상대방의 변경 카운트 ( 상대방이 물건을 올려놓거나 삭제 혹은 변경 등 패킷받은 개수 )
	bool				bIsSet;				// false : 확인풀기 true: 확인잠금
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_CANCEL_REQ)			// 교환 취소 혹은 캐릭종료 거리 이탈시 사용
	HOBJECT				hTarget;			// 타겟 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TRADE_DENY_REQ)			// 교환 취소 혹은 캐릭종료 거리 이탈시 사용
	bool				bIsDeny;			// TRUE: 거절 하도록 FALSE: 해제 원상태
END_PROTOCOL()
//------------------------------------------------------------------	
BEGIN_PROTOCOL(UG_GUILD_CREATE_REQ)
	HOBJECT				hGuildManagerNpc;
	WCHAR				wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_INVITE_REQ)
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TUTORIAL_HINT_UPDATE_REQ)
	DWORD				dwTutorialHint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TUTORIAL_WAIT_CANCEL_REQ)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TUTORIAL_PLAY_QUIT_REQ)

END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_TIMEQUEST_ROOM_LIST_REQ)
	HOBJECT				hTimeQuestNpc;		// 해당 타임머신퀘스트 NPC의 핸들 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TIMEQUEST_ROOM_INFO_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TIMEQUEST_ROOM_JOIN_REQ)
	HOBJECT				hTimeQuestNpc;		// 해당 타임머신퀘스트 NPC의 핸들
	BYTE				byTimeQuestMode;	// 개인 or Party ( eTIMEQUEST_MODE )
	bool				bIsRetry;			// 재신청인지 아닌지를 나타냄
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TIMEQUEST_ROOM_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TIMEQUEST_ROOM_TELEPORT_REQ)
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_INFO_REQ)
	BYTE					byBattleMode;		// eRANKBATTLE_MODE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_JOIN_REQ)
	HOBJECT					hBoardObject;
	TBLIDX					rankBattleTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_LEAVE_REQ)
	TBLIDX					rankBattleTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_RANKBATTLE_ROOM_LIST_REQ)
	HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
	WORD				wPage;				// 게시판의 출력 Page
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_ROOM_INFO_REQ)
	HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
	ROOMID				roomId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_ROOM_CREATE_REQ)
	HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_ROOM_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_ROOM_CHALLENGE_REQ)
	HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
	ROOMID				roomId;				// 방 번호
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_RANKBATTLE_ROOM_MATCH_CANCEL_REQ)
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DRAGONBALL_CHECK_REQ)
	HOBJECT				hObject;						  // TS Object 제단	 
	sITEM_POSITION_DATA sData[NTL_ITEM_MAX_DRAGONBALL];   // 인벤상의 드래곤볼아이템
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DRAGONBALL_REWARD_REQ)
	HOBJECT				hObject;						  // TS Object 제단	
	TBLIDX				rewardTblidx;					  // 선택 보상 테이블 인덱스
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_CREATE_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_EXIT_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_OPEN_REQ )
	WCHAR					wcPrivateShopName[NTL_MAX_PRIVATESHOP_NAME_IN_UNICODE + 1];	
	bool					bIsOwnerEmpty; //true이면 주인이 자리를 비운것
	BYTE					byNoticeSize;
	WCHAR					wcNotice[NTL_MAX_PRIVATESHOP_NOTICE_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_CLOSE_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
//아직 미정 (사용하지 마세요 - 삭제 가능성 있음)
BEGIN_PROTOCOL( UG_PRIVATESHOP_ITEM_GET_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_ITEM_INSERT_REQ )
	BYTE							byPrivateShopInventorySlotPos;
	BYTE							byInventoryPlace;
	BYTE							byInventoryPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_ITEM_UPDATE_REQ )
	BYTE							byPrivateShopInventorySlotPos;
	DWORD							dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_ITEM_DELETE_REQ )
	BYTE							byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_ITEM_BUYING_REQ )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos[NTL_MAX_BUY_SHOPPING_CART];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_ENTER_REQ )
	HOBJECT						hOwner;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_LEAVE_REQ )
	HOBJECT						hOwner;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_ITEM_SELECT_REQ )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos;
	BYTE						byItemState;//eITEMSTATE 값을 갖는다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_START_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_SEND_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	BYTE byMailType;	// eMAIL_TYPE	
	sITEM_POSITION_DATA sItemData;	// 아이템포지션
	DWORD dwZenny;		// Req or Give Zenny
	BYTE byDay;		// 유효만료날짜 최대 10일
	WCHAR wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];	// 받을 캐릭 이름
	BYTE  byTextSize;	// 가변길이 패킷용 텍스트 사이즈
	WCHAR wszText[NTL_MAX_LENGTH_OF_MAIL_MESSAGE + 1];	// 메일내용
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_READ_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	MAILID	mailID;	// 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_DEL_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	MAILID	mailID;	// 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_RETURN_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	MAILID	mailID;	// 메일 아이디	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_RELOAD_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_LOAD_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	BYTE	byCount;
	MAILID	aMailID[NTL_MAX_MAIL_SLOT_COUNT];	// 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_ITEM_RECEIVE_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	MAILID	mailID;	// 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_LOCK_REQ )
	HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	MAILID	mailID;	// 메일 아이디
	bool	bIsLock;		// Lock 1: Unlock: 0
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_MAIL_MULTI_DEL_REQ )
	HOBJECT	hObject;								// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
	BYTE	byCount;
	MAILID	aMailID[NTL_MAX_COUNT_OF_MULTI_DEL];		// 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_BUSINESS_REQUEST_REQ )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos;
	TBLIDX						itemNo;//클라이언트와 서버에 아이템이 동일한지 검사하기 위함
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_BUSINESS_CONSENT_RES )
	bool						bResult;
	TBLIDX						itemNo;//클라이언트와 서버에 아이템이 동일한지 검사하기 위함
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_REQ )
	DWORD						dwPriceFluctuationsZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_REQ )
	HOBJECT						hOwner;
	unsigned __int16			nPriceFluctuationsCounter;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PRIVATESHOP_BUSINESS_CANCEL_REQ )
	HOBJECT						hOwner;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL( UG_PORTAL_START_REQ )
	HOBJECT				handle;			// 해당 NPC 검사후 포탈 정보 로딩
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PORTAL_ADD_REQ )
	HOBJECT				handle;			
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PORTAL_REQ )
	HOBJECT				handle;			
	BYTE				byPoint;		// 0~7까지 선택된 인덱스
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PING )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_WAR_FOG_UPDATE_REQ )
	HOBJECT				hObject;			// Object Handle		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_FUNCTION_ADD_REQ)
	HOBJECT				hGuildManagerNpc;
	BYTE				byFunction;			// 추가할 기능 번호 eDBO_GUILD_FUNCTION
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_GIVE_ZENNY)
	HOBJECT				hGuildManagerNpc;
	DWORD				dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_BANK_START_REQ)
	HOBJECT				handle;			// 창고 NpcHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_BANK_MOVE_REQ)
	HOBJECT				handle;			// 창고 NpcHandle	
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestPlace;
	BYTE				byDestPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_BANK_MOVE_STACK_REQ)
	HOBJECT				handle;			// 창고 NpcHandle
	BYTE				bySrcPlace;
	BYTE				bySrcPos;
	BYTE				byDestPlace;
	BYTE				byDestPos;
	BYTE				byStackCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_BANK_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GUILD_BANK_ZENNY_REQ)
	HOBJECT				handle;			// NpcHandle
	DWORD				dwZenny;		// 빼거나 넣을 액수
	bool				bIsSave;		// 1 은 넣을 경우 0 은 빼는경우
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_CROSSFIRE_REQ )
	HOBJECT				hAnotherUser;		//유져가 선택한 User 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_GUILD_CREATE_MARK_REQ )
	sDBO_GUILD_MARK		sMark;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_GUILD_CHANGE_MARK_REQ )
	sDBO_GUILD_MARK		sMark;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_BANK_LOAD_REQ )
	HOBJECT				handle;			// NpcHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_GUILD_CHANGE_NAME_REQ )
	HOBJECT				hGuildManagerNpc;
	WCHAR				wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_PARTY_SHARETARGET_REQ )
	BYTE				bySlot;
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_RIDE_ON_BUS_REQ )
	HOBJECT				hTarget;			// NpcHandle
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_RIDE_OFF_BUS_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_TRANSFORM_CANCEL_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_ITEM_IDENTIFY_REQ)
	HOBJECT				hNpchandle;		// NpcHandle
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DICE_ROLL_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_JOIN_INDIVIDUAL_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_LEAVE_INDIVIDUAL_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_JOIN_TEAM_INFO_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_JOIN_TEAM_REQ)
	WCHAR				wszTeamName[NTL_MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_LEAVE_TEAM_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_LEAVE_TEAM_MEMBER_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_JOIN_INFO_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_JOIN_STATE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_MUDOSA_INFO_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_MUDOSA_TELEPORT_REQ)
	BYTE			byMudosaIndex;				// 무도사 인덱스
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_PARTY_MAKER_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_SOCIAL_ACTION)
	ANIMATIONID			socialAction;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_PRIZEWINNER_NAME_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_GM_MATCH_PROGRESS_INFO_REQ)
	BYTE				byMatchType;	// eBUDOKAI_MATCH_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_GM_MATCH_ARENA_ENTER_REQ)
	BYTE				byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE				byMatchWorldType;	// eMATCHWORLD_TYPE
	BYTE				byMatchDepth;		// eBUDOKAI_MATCH_DEPTH
	BYTE				byMatchIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_BUDOKAI_GM_MATCH_ARENA_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_TURN_ON)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_TURN_OFF)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SCOUTER_ITEM_SELL_REQ)
	BYTE			byPlace;
	BYTE			byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_EVENTITEM_START_REQ)
	HOBJECT				handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_EVENTITEM_BUY_REQ)
	HOBJECT				handle;
	BYTE				byBuyCount;
	sSHOP_BUY_CART		sBuyData[NTL_MAX_BUY_SHOPPING_CART]; 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_EVENTITEM_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_GAMBLE_BUY_REQ)
	HOBJECT				handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_DIFF_CHANGE_REQ)
	ePARTY_DUNGEON_STATE eDiff;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_DUNGEON_INIT_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SKILL_INIT_REQ)
	HOBJECT				handle;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(UG_PARTY_CHARM_DICE_ROLL_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_LOCK_REQ)
	bool				bIsOpen;	// 1: Open 0:Close
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_RESET_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_ACCEPTED_REQ)
	BYTE				byItemSlot;	// 파티인벤 해당 슬롯 아이템 낙찰
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_GIVE_REQ)
	BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템 
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_DICE_START_REQ)
	BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PARTY_INVEN_DICE_ROLL_REQ)
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_TELEPORT_CONFIRM_REQ)
	bool				bTeleport;		// true : 확인, false : 취소
	BYTE				byTeleportIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HOIPOIMIX_ITEM_CHECK_REQ)			// 만들아이템 선택 (필요한 아이템 수량 체크)
	HOBJECT				objHandle;
	TBLIDX				recipeTblidx;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HOIPOIMIX_ITEM_MAKE_REQ)			// 아이템 만들기
	HOBJECT				objHandle;
	TBLIDX				recipeTblidx;	
	bool				bIsEPUseSuccess;			// EP 사용유무
END_PROTOCOL()
//------------------------------------------------------------------			
BEGIN_PROTOCOL(UG_HOIPOIMIX_ITEM_MAKE_EP_REQ)		// 아이템 만들기 중 EP 넣기
	TBLIDX				recipeTblidx;	
END_PROTOCOL()
//------------------------------------------------------------------	
BEGIN_PROTOCOL(UG_HOIPOIMIX_ITEM_MACHINE_DEL_REQ)			// 머신 삭제
	HOBJECT				objHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HOIPOIMIX_JOB_SET_REQ)			// 잡 세팅
	HOBJECT				hNpchandle;
	BYTE				byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_HOIPOIMIX_JOB_RESET_REQ)			// 잡 리셋
	HOBJECT				hNpchandle;
	BYTE				byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_VEHICLE_DIRECT_PLAY_CANCEL_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_VEHICLE_ENGINE_START_REQ )
	TBLIDX				idFuelItemTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_VEHICLE_ENGINE_STOP_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_VEHICLE_END_REQ )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_VEHICLE_STUNT_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_VEHICLE_FUEL_REMOVE_NFY )
	TBLIDX				idFuelItemTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOJO_CREATE_REQ )
	HOBJECT				hObject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOJO_DELETE_REQ )
	HOBJECT				hObject;
	TBLIDX				dojoTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DOJO_FUNCTION_ADD_REQ)
	HOBJECT				hGuildManagerNpc;
	BYTE				byFunction;			// 추가할 기능 번호 eDBO_GUILD_FUNCTION
	BYTE				byPlace;			// 호이포이락이 필요시 인벤위치 불필요시 INVALID_BYTE
	BYTE				byPos;				// 호이포이락이 필요시 인벤위치 불필요시 INVALID_BYTE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOJO_BANK_HISTORY_REQ )
	HOBJECT				hObject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOGI_CREATE_REQ )
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOGI_CHANGE_REQ )
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_GUILD_DOGI_CREATE_REQ )
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_GUILD_DOGI_CHANGE_REQ )
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOJO_SCRAMBLE_REQ )			// 도장쟁탈전 신청 (도전자)
	HOBJECT				hNpcHandle;				// 도장관리인
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UG_DOJO_SCRAMBLE_RESPONSE_REQ )		// 도장쟁탈전 신청에 대한 응답 (도장주인)
	bool				bIsAccept;				// 신청에 대한 응답 1:받기 0:거절
END_PROTOCOL()
//------------------------------------------------------------------						
BEGIN_PROTOCOL(UG_SHOP_NETPYITEM_START_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_NETPYITEM_BUY_REQ)
	BYTE				byBuyCount;
	sSHOP_BUY_CART		sBuyData[NTL_MAX_BUY_SHOPPING_CART]; 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SHOP_NETPYITEM_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_WORLD_MAP_STATUS)
	bool				bIsWorldMapOpen;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DOJO_NPC_INFO_REQ)
	HOBJECT				hNpcHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GAMEGUARD_AUTH_ANSWER_RES)
	BYTE				byDataSize;
	BYTE				abyData[UCHAR_MAX];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GAMEGUARD_HACK_INFO_NFY)
	WORD				wDataSize;
	BYTE				abyData[USHRT_MAX];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_SKILL_CASTING_CANCELED_NFY)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_PET_ATTACK_TARGET_NFY)
	BYTE				byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DURATION_ITEM_BUY_REQ)
	TBLIDX				merchantTblidx;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_DURATION_RENEW_REQ)
	HOBJECT				hItemHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_START_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_MOVE_REQ)
	DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_USE_REQ)
	DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_HLSHOP_START_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_HLSHOP_END_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CASHITEM_BUY_REQ)
	BYTE				byBuyCount;
	DWORD				adwIdxHlsTable[NTL_MAX_BUY_HLSSHOP_CART];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_GMT_UPDATE_REQ)
	sGAME_MANIA_TIME	sNext;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_LOC_AFTER_KNOCKDOWN_NFY)
	sVECTOR3			vCurLoc;
	sVECTOR2			vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_LOC_AFTER_SLIDING_NFY)
	sVECTOR3			vCurLoc;
	sVECTOR2			vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UG_CHAR_LOC_AFTER_PUSH_NFY)
	sVECTOR3			vCurLoc;
	sVECTOR2			vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
#pragma pack()





