#include "amxxmodule.h"

#define ESFX_POWERLEVEL_OFFSET   460
#define ESFX_ACPL_OFFSET         463
#define ESFX_MAXHEALTH_OFFSET    142
#define ESFX_SPEED_OFFSET        462
#define ESFX_FLY_OFFSET          195
#define ESFX_TURBO_OFFSET        196
#define ESFX_POWERUP_OFFSET      199
#define ESFX_SWOOPING_OFFSET     317
#define ESFX_ATTACKCHARGE_OFFSET 200
#define ESFX_ADVMELEE_OFFSET     298
#define ESFX_BLOCK_OFFSET        198
#define ESFX_WALLGND_OFFSET      230
#define ESFX_DEATHS_OFFSET       604 // connor
#define ESFX_ADPL_OFFSET		 461
#define ESFX_HPOWERUP_OFFSET	 199
#define ESFX_THROWA_OFFSET		 230
#define ESFX_THROW_OFFSET		 300
#define ESFX_FREEFALL_OFFSET	 27


#define CHECK_PLAYER(x) \
	if (x < 1 || x > gpGlobals->maxClients) { \
		MF_LogError(amx, AMX_ERR_NATIVE, "Player out of range (%d)", x); \
		return 0; \
	} else { \
		if (!MF_IsPlayerIngame(x) || FNullEnt(MF_GetPlayerEdict(x))) { \
			MF_LogError(amx, AMX_ERR_NATIVE, "Invalid player %d", x); \
			return 0; \
		} \
	}
