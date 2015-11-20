#ifndef __MODULECONFIG_H__
#define __MODULECONFIG_H__

#define MODULE_NAME "ESF X"
#define MODULE_VERSION "3.0.1.24"
#define MODULE_AUTHOR "tuty"
#define MODULE_URL ""
#define MODULE_LOGTAG "ESF X"
#define MODULE_LIBRARY "esfx"
#define MODULE_LIBCLASS ""

#define MODULE_RELOAD_ON_MAPCHANGE

#ifdef __DATE__
#define MODULE_DATE __DATE__
#else 
#define MODULE_DATE "17.04.2010"
#endif 

#define USE_METAMOD

#define FN_AMXX_ATTACH          OnAmxxAttach
#define FN_AMXX_PLUGINSLOADED   OnPluginsLoaded

#ifdef USE_METAMOD

#define FN_StartFrame			StartFrame	

#endif 

#endif 
