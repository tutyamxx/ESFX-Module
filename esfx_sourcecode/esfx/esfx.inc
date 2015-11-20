/* EsfX functions
*
* by tuty
*
* This file is provided as is (no warranties).
*/



///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

#if defined _esfx_included
  #endinput
#endif
#define _esfx_included

#if AMXX_VERSION_NUM >= 175
 #pragma reqlib esfx
 #if !defined AMXMODX_NOAUTOLOAD
  #pragma loadlib esfx
 #endif
#else
 #pragma library esfx
#endif

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////





/* Set a amount of KI to a specified player */
native esf_set_ki(index, ki);


/* Set powerlevel to a player */
native esf_set_powerlevel(index, pl);


/* Get powerlevel from a player */
native esf_get_powerlevel(index);


/* Get actual powerlevel from a player */
native esf_get_acpl(index);


/* Set actual powerlevel to a player */
native esf_set_acpl(index, acpl);


/* Get player maxhealth */
native esf_get_maxhealth(index);


/* Set player speed */
native esf_set_speed(index, speed);


/* Get player speed */
native esf_get_speed(index);


/* Set player swoopspeed */
native esf_set_swoopspeed(index, sspeed);


/* Get players swoopspeed */
native esf_get_swoopspeed(index);


/* Return if a player is flying */
native esf_get_fly(index);


/* Return if player has turbo activated */
native esf_get_turbo(index);


/* Return if a player is chargin' his power */
native esf_get_powerup(index);


/* Return if player is swooping */
native esf_get_swooping(index);


/* Return if player is charging an attack */
native esf_get_attackcharge(index);


/* Return if player is in advanced melee */
native esf_get_advancedmelee(index);


/* Return if player is blocking an attack */
native esf_get_block(index);


/*  Get if player has been thrown into wall or on ground */
native esf_get_wallground(index);


/* Get player deaths */
native esf_get_user_deaths(index);


/* Set maxhealth to a player */
native esf_set_maxhealth(index, health);


/* Get player class */
native esf_get_playerclass(index);


/* Set player frags  */
native esf_set_frags(index, frags);


/* Get player KI */
native esf_get_ki(index);


/* Set model to a player */
native esf_set_model(index, const model[]);


/* Reset player model */
native esf_reset_model(index);


/* Set player ADPL */
native esf_set_adpl(index, adpl);


/* Get player ADPL */
native esf_get_adpl(index);


/* Set player hidden powerup */
native esf_set_hiddenpowerup(index, hpwp);


/* Check if player is in thrown away */
native esf_get_throw_away(index);


/* Check if player is in Throw*/
native esf_get_throw(index);


/* Check if player is performing a Beam Jump */
native esf_get_beamjump(index);


/* Check if player is in freefall like after jumping of ground */
native esf_get_freefall(index);