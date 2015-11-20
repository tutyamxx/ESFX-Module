/*	AMX Mod X
*		- ESFX Module
*
*	by tuty
*	tuty_max_boy@yahoo.com
*
*
*  This program is free software; you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by the
*  Free Software Foundation; either version 2 of the License, or (at
*  your option) any later version.
*
*  This program is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*  General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software Foundation,
*  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
*  In addition, as a special exception, the author gives permission to
*  link the code of this program with the Half-Life Game Engine ("HL
*  Engine") and Modified Game Libraries ("MODs") developed by Valve,
*  L.L.C ("Valve"). You must obey the GNU General Public License in all
*  respects for all of the code used other than the HL Engine and MODs
*  from Valve. If you modify this file, you may extend this exception
*  to your version of the file, but you are not obligated to do so. If
*  you do not wish to do so, delete this exception statement from your
*  version.
*/

#include <string.h>
#include "esfx.h"



struct ESFModel
{
	bool bSet;
	char* szModel;
};


ESFModel esfmodels[ 32 ];


/*===================================================================================*/


static cell AMX_NATIVE_CALL esf_set_ki(AMX *amx, cell *params) // esf_set_ki(index, ki); = 2 args
{
	// Sets user ki
	// params[1] = index
	// params[2] = ki

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
    edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
       
    pPlayer->v.fuser4 = params[ 2 ];

	return 1;
}

static cell AMX_NATIVE_CALL esf_set_powerlevel(AMX *amx, cell *params) // esf_set_powerlevel(index, powerlevel); = 2 args
{
	// Sets user powerlevel
	// params[1] = index
	// params[2] = powerlevel

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	*((int *)pPlayer->pvPrivateData + ESFX_POWERLEVEL_OFFSET) = params[ 2 ];

	return 1;
}

static cell AMX_NATIVE_CALL esf_get_powerlevel(AMX *amx, cell *params) // esf_get_powerlevel(index); = 1 arg
{
	// Get user powerlevel
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_POWERLEVEL_OFFSET);
}

static cell AMX_NATIVE_CALL esf_get_acpl(AMX *amx, cell *params) // esf_get_acpl(index); = 1 arg
{
	// Get user actual powerlevel
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_ACPL_OFFSET);
}

static cell AMX_NATIVE_CALL esf_set_acpl(AMX *amx, cell *params) // esf_set_acpl(index, acpl); = 2 args
{
	// Set user actual powerlevel
	// params[1] = index
	// params[2] = acpl

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	*((int *)pPlayer->pvPrivateData + ESFX_ACPL_OFFSET) = params[ 2 ];
	   
	return 1;
}

static cell AMX_NATIVE_CALL esf_get_maxhealth(AMX *amx, cell *params) // esf_get_maxhealth(index); = 1 arg
{
	// Get player maxhealth
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_MAXHEALTH_OFFSET);
}

static cell AMX_NATIVE_CALL esf_set_speed(AMX *amx, cell *params) // esf_set_speed(index, speed); = 2 args
{
	// Set player speed
	// params[1] = index
	// params[2] = speed

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	*((int *)pPlayer->pvPrivateData + ESFX_SPEED_OFFSET) = params[ 2 ];
	   
	return 1;
}

static cell AMX_NATIVE_CALL esf_get_speed(AMX *amx, cell *params) // esf_get_speed(index); = 1 arg
{
	// Get player speed
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_SPEED_OFFSET);
}

static cell AMX_NATIVE_CALL esf_set_swoopspeed(AMX *amx, cell *params) // esf_set_swoopspeed(index, sspeed); = 2 args
{
	// Set player swoop speed
	// params[1] = index
	// params[2] = swoop speed

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
    edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
       
    pPlayer->v.fuser1 = params[ 2 ];
       
    return 1;
}

static cell AMX_NATIVE_CALL esf_get_swoopspeed(AMX *amx, cell *params) // esf_get_swoopspeed(index); = 1 arg
{
	// Get player swoopspeed
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
    edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
       
    return pPlayer->v.fuser1;
}

static cell AMX_NATIVE_CALL esf_get_fly(AMX *amx, cell *params) // esf_get_fly(index); = 1 arg
{
	// Check is player is flying
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_FLY_OFFSET );
}

static cell AMX_NATIVE_CALL esf_get_turbo(AMX *amx, cell *params) // esf_get_turbo(index); = 1 arg
{
	// Check if player has turbo on (T key);
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_TURBO_OFFSET);
}

static cell AMX_NATIVE_CALL esf_get_powerup(AMX *amx, cell *params) // esf_get_powerup(index); = 1 arg
{
	// Check if player is charging his power
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_POWERUP_OFFSET);
}    

static cell AMX_NATIVE_CALL esf_get_swooping(AMX *amx, cell *params) // esf_get_swooping(index); = 1 arg
{
	// Check if player is currently swoopin'
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_SWOOPING_OFFSET);
}    

static cell AMX_NATIVE_CALL esf_get_attackcharge(AMX *amx, cell *params) // esf_get_attackcharge(index); = 1 arg
{
	// Check if player is charging an attack
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_ATTACKCHARGE_OFFSET);
}    

static cell AMX_NATIVE_CALL esf_get_advancedmelee(AMX *amx, cell *params) // esf_get_advancedmelee(index); = 1 arg
{
	// Check if player is in advanced melee
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_ADVMELEE_OFFSET);
}  

static cell AMX_NATIVE_CALL esf_get_block(AMX *amx, cell *params) // esf_get_block(index); = 1 arg
{
	// Check if player is blocking an attack
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_BLOCK_OFFSET);
}  

static cell AMX_NATIVE_CALL esf_get_wallground(AMX *amx, cell *params) // esf_get_wallground(index); =  1 arg
{
	// Client has been thrown into Wall / on Ground
	// params[1] = index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_WALLGND_OFFSET);
}

static cell AMX_NATIVE_CALL esf_set_maxhealth(AMX *amx, cell *params) // esf_set_maxhealth(index, health); = 2 args
{
	// Set maxhealth to a player
	// params[1] = index
	// params[2] = health

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	*((int *)pPlayer->pvPrivateData + ESFX_MAXHEALTH_OFFSET) = params[ 2 ];
	  
	// Writing maxhealth message to client...
	MESSAGE_BEGIN(MSG_ONE, GET_USER_MSG_ID(PLID, "MaxHealth", NULL), NULL, pPlayer);
	WRITE_BYTE(params[ 2 ]); 
	MESSAGE_END();
	   
	return 1;
}

static cell AMX_NATIVE_CALL esf_get_playerclass(AMX *amx, cell *params) // esf_get_playerclass(index); = 1 arg
{
	// Get the player class
	// params[1] = index
	// ---------------------
	// If playerclass == 
	
	/*  ESF_CLASS_NONE = 0,
        ESF_CLASS_BUU = 1,
        ESF_CLASS_GOKU = 2,
        ESF_CLASS_GOHAN = 3,
        ESF_CLASS_KRILLIN = 4,
        ESF_CLASS_FRIEZA = 5,
        ESF_CLASS_PICCOLO = 6,
        ESF_CLASS_TRUNKS = 7,
        ESF_CLASS_VEGETA = 8,
        ESF_CLASS_CELL = 9
	*/

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
    edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
       
    return pPlayer->v.playerclass;
}

static cell AMX_NATIVE_CALL esf_get_user_deaths(AMX *amx, cell *params) // esf_get_user_deaths(index); = 1 arg
{
	// Return player deaths
	// params[1] =  index

	// Check index
	CHECK_PLAYER( params[ 1 ] );

	// Fetch player pointer
	edict_t *pPlayer = MF_GetPlayerEdict( params[ 1 ] );
	   
	return *((int *)pPlayer->pvPrivateData + ESFX_DEATHS_OFFSET); // offset by ConnorMcLeod
}

static cell AMX_NATIVE_CALL esf_set_frags(AMX* amx, cell* params) // esf_set_frags(index, frags); = 2 args
{
	// Set player frags
	// params[1] = index
	// params[2] = frags

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);
	   
	pPlayer->v.frags = params[ 2 ];
	   
	return 1;
}

static cell AMX_NATIVE_CALL esf_get_ki(AMX* amx, cell* params) // esf_get_ki(index); = 1 arg
{
	// Get player kinetik energy (KI)
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);
	   
	return pPlayer->v.fuser4;
}

static cell AMX_NATIVE_CALL esf_set_model(AMX *amx, cell *params) // esf_set_model(index, const model[]); = 2 args
{
	// Set player a new model
	// params[1] = index
	// params[2] = const model

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	int length;

	// Setting new model to player [ .. ]
	esfmodels[params[1]-1].szModel = (char*)STRING( ALLOC_STRING( MF_GetAmxString(amx, params[2], 1, &length) ) );
	esfmodels[params[1]-1].bSet = true;

	return 1; 
}

static cell AMX_NATIVE_CALL esf_reset_model(AMX *amx, cell *params) // esf_reset_model(index); = 1 arg
{
	// Reset player model!
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[1]);

	// Remove that ugly model :)
	esfmodels[params[1]-1].bSet = false;

	return 1; 
}

static cell AMX_NATIVE_CALL esf_set_adpl(AMX *amx, cell *params) // esf_set_adpl(index, adpl); = 2 args
{
	// Set player ADPL
	// params[1] = index
	// params[2] = adpl

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	*((int *)pPlayer->pvPrivateData + ESFX_ADPL_OFFSET) = params[ 2 ];

	return 1;
}

static cell AMX_NATIVE_CALL esf_get_adpl(AMX *amx, cell *params) // esf_get_adpl(index); = 1 arg
{
	// Get player ADPL
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	return *((int *)pPlayer->pvPrivateData + ESFX_ADPL_OFFSET);
}

static cell AMX_NATIVE_CALL esf_set_hiddenpowerup(AMX *amx, cell *params) // esf_set_hiddenpowerup(index, hpwp); = 2 args
{
	// Set player hidden powerup
	// params[1] = index
	// params[2] = hidden power up

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	*((int *)pPlayer->pvPrivateData + ESFX_HPOWERUP_OFFSET) = params[ 2 ];

	return 1;
}

static cell AMX_NATIVE_CALL esf_get_throw_away(AMX *amx, cell *params) // esf_get_throw_away(index); = 1 arg
{
	// Client is in thrown away
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	return *((int *)pPlayer->pvPrivateData + ESFX_THROWA_OFFSET);
}

static cell AMX_NATIVE_CALL esf_get_throw(AMX *amx, cell *params) // esf_get_throw(index); =  1 arg
{
	// Client is in Throw
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	return *((int *)pPlayer->pvPrivateData + ESFX_THROW_OFFSET);
}

static cell AMX_NATIVE_CALL esf_get_beamjump(AMX *amx, cell *params) // esf_get_beamjump(index); = 1 arg
{
	// Get when a player performs a BeamJump
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	return pPlayer->v.movetype == 15;
}

static cell AMX_NATIVE_CALL esf_get_freefall(AMX *amx, cell *params) // esf_get_freefall(index); = 1 arg
{
	// Client is in freefall like after jumping of ground
	// params[1] = index

	// Check index
	CHECK_PLAYER(params[ 1 ]);

	// Fetch player pointer
	edict_t* pPlayer = MF_GetPlayerEdict(params[ 1 ]);

	return *((int *)pPlayer->pvPrivateData + ESFX_FREEFALL_OFFSET);
}
/*===================================================================================*/

AMX_NATIVE_INFO esf_Exports[] = {
	{"esf_set_ki",			  esf_set_ki},
	{"esf_set_powerlevel",	  esf_set_powerlevel},
	{"esf_get_powerlevel",	  esf_get_powerlevel},
	{"esf_get_acpl",		  esf_get_acpl},
	{"esf_set_acpl",		  esf_set_acpl},
	{"esf_get_maxhealth",	  esf_get_maxhealth},
	{"esf_set_speed",		  esf_set_speed},
	{"esf_get_speed",		  esf_get_speed},
	{"esf_set_swoopspeed",	  esf_set_swoopspeed},
	{"esf_get_swoopspeed",	  esf_get_swoopspeed},
	{"esf_get_fly",			  esf_get_fly},
	{"esf_get_turbo",		  esf_get_turbo},
	{"esf_get_powerup",		  esf_get_powerup},
	{"esf_get_swooping",      esf_get_swooping},
	{"esf_get_attackcharge",  esf_get_attackcharge},
	{"esf_get_advancedmelee", esf_get_advancedmelee},
	{"esf_get_block",	      esf_get_block},
	{"esf_get_wallground",	  esf_get_wallground},
	{"esf_get_user_deaths",   esf_get_user_deaths},
	{"esf_set_maxhealth",	  esf_set_maxhealth},
	{"esf_get_playerclass",   esf_get_playerclass},
	{"esf_set_frags",         esf_set_frags},
	{"esf_get_ki",            esf_get_ki},
	{"esf_set_model",         esf_set_model},
	{"esf_reset_model",       esf_reset_model},
	{"esf_set_adpl",		  esf_set_adpl},
	{"esf_get_adpl",		  esf_get_adpl},
	{"esf_set_hiddenpowerup", esf_set_hiddenpowerup},
	{"esf_get_throw_away",	  esf_get_throw_away},
	{"esf_get_throw",		  esf_get_throw},
	{"esf_get_beamjump",	  esf_get_beamjump},
	{"esf_get_freefall",	  esf_get_freefall},

	{NULL,					NULL}
};

void OnAmxxAttach()
{
	// Adding the natives
	MF_AddNatives(esf_Exports);
}

void OnPluginsLoaded()
{
	for( int i = 0; i < 32; i++ )
	{
		esfmodels[i].bSet = false;
	}
}

void StartFrame()
{
	edict_t* ent = NULL;
	while( !FNullEnt( ent = FIND_ENTITY_BY_STRING( ent, "classname", "player" ) ) )
	{
		if( esfmodels[ENTINDEX(ent)-1].bSet )
		{
			ent->v.modelindex = MODEL_INDEX( esfmodels[ENTINDEX(ent)-1].szModel );
			ent->v.model = MAKE_STRING( esfmodels[ENTINDEX(ent)-1].szModel );
		}
	}
	RETURN_META( MRES_HANDLED );
}

// End of code.. Enjoy! This was made by Tuty!
// Contact me on Y!M: tuty_max_boy@yahoo.com
// Or AIM: Ttutyy


/*===================================================================================*/
