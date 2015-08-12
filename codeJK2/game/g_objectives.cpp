/*
===========================================================================
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#include "g_headers.h"

//g_objectives.cpp
//reads in ext_data\objectives.dat to objectives[]

#include "g_local.h"
#include "g_items.h"

#include "objectives.h"

qboolean	missionInfo_Updated;


/*
============
OBJ_SetPendingObjectives
============
*/
void OBJ_SetPendingObjectives(gentity_t *ent)
{
	int i;

	for (i=0;i<MAX_OBJECTIVES;++i)
	{
		if ((ent->client->sess.mission_objectives[i].status == OBJECTIVE_STAT_PENDING) && 
			(ent->client->sess.mission_objectives[i].display))
		{
			ent->client->sess.mission_objectives[i].status = OBJECTIVE_STAT_FAILED;
		}
	}
}

/*
============
OBJ_SaveMissionObjectives
============
*/
void OBJ_SaveMissionObjectives( gclient_t *client )
{
	gi.AppendToSaveGame(INT_ID('O','B','J','T'), client->sess.mission_objectives, sizeof(client->sess.mission_objectives));
}


/*
============
OBJ_SaveObjectiveData
============
*/
void OBJ_SaveObjectiveData(void)
{
	gclient_t *client;

	client = &level.clients[0];

	OBJ_SaveMissionObjectives( client );
}

/*
============
OBJ_LoadMissionObjectives
============
*/
void OBJ_LoadMissionObjectives( gclient_t *client )
{
	gi.ReadFromSaveGame(INT_ID('O','B','J','T'), (void *) &client->sess.mission_objectives, sizeof(client->sess.mission_objectives), NULL);
}


/*
============
OBJ_LoadObjectiveData
============
*/
void OBJ_LoadObjectiveData(void)
{
	gclient_t *client;

	client = &level.clients[0];

	OBJ_LoadMissionObjectives( client );
}

stringID_table_t objectiveTable[] =
{
	//=================================================
	//
	//=================================================
	ENUM2STRING(KEJIM_POST_OBJ1),		//# KEJIM POST
	ENUM2STRING(KEJIM_POST_OBJ2),			//# KEJIM POST
	ENUM2STRING(KEJIM_BASE_OBJ1),			//# KEJIM BASE
	ENUM2STRING(KEJIM_BASE_OBJ2),			//# KEJIM BASE
	ENUM2STRING(KEJIM_BASE_OBJ3),			//# KEJIM BASE
	ENUM2STRING(ARTUS_MINE_OBJ1),			//# ARTUS MINE
	ENUM2STRING(ARTUS_MINE_OBJ2),			//# ARTUS MINE
	ENUM2STRING(ARTUS_MINE_OBJ3),			//# ARTUS MINE
	ENUM2STRING(ARTUS_DETENTION_OBJ1),		//# ARTUS DETENTION
	ENUM2STRING(ARTUS_DETENTION_OBJ2),		//# ARTUS DETENTION
	ENUM2STRING(ARTUS_TOPSIDE_OBJ1),			//# ARTUS TOPSIDE
	ENUM2STRING(ARTUS_TOPSIDE_OBJ2),			//# ARTUS TOPSIDE
	ENUM2STRING(YAVIN_TEMPLE_OBJ1),			//# YAVIN TEMPLE
	ENUM2STRING(YAVIN_TRIAL_OBJ1),			//# YAVIN TRIAL
	ENUM2STRING(YAVIN_TRIAL_OBJ2),			//# YAVIN TRIAL
	ENUM2STRING(NS_STREETS_OBJ1),			//# NS STREETS
	ENUM2STRING(NS_STREETS_OBJ2),			//# NS STREETS
	ENUM2STRING(NS_STREETS_OBJ3),			//# NS STREETS
	ENUM2STRING(NS_HIDEOUT_OBJ1),			//# NS HIDEOUT
	ENUM2STRING(NS_HIDEOUT_OBJ2),			//# NS HIDEOUT
	ENUM2STRING(NS_STARPAD_OBJ1),			//# NS STARPAD
	ENUM2STRING(NS_STARPAD_OBJ2),			//# NS STARPAD
	ENUM2STRING(NS_STARPAD_OBJ3),			//# NS STARPAD
	ENUM2STRING(NS_STARPAD_OBJ4),			//# NS STARPAD
	ENUM2STRING(NS_STARPAD_OBJ5),			//# NS STARPAD
	ENUM2STRING(BESPIN_UNDERCITY_OBJ1),		//# BESPIN UNDERCITY
	ENUM2STRING(BESPIN_UNDERCITY_OBJ2),		//# BESPIN UNDERCITY
	ENUM2STRING(BESPIN_STREETS_OBJ1),		//# BESPIN STREETS
	ENUM2STRING(BESPIN_STREETS_OBJ2),		//# BESPIN STREETS
	ENUM2STRING(BESPIN_PLATFORM_OBJ1),		//# BESPIN PLATFORM
	ENUM2STRING(BESPIN_PLATFORM_OBJ2),		//# BESPIN PLATFORM
	ENUM2STRING(CAIRN_BAY_OBJ1),				//# CAIRN BAY
	ENUM2STRING(CAIRN_BAY_OBJ2),				//# CAIRN BAY
	ENUM2STRING(CAIRN_ASSEMBLY_OBJ1),		//# CAIRN ASSEMBLY	
	ENUM2STRING(CAIRN_REACTOR_OBJ1),			//# CAIRN REACTOR
	ENUM2STRING(CAIRN_REACTOR_OBJ2),			//# CAIRN REACTOR
	ENUM2STRING(CAIRN_DOCK1_OBJ1),			//# CAIRN DOCK1
	ENUM2STRING(CAIRN_DOCK1_OBJ2),			//# CAIRN DOCK1
	ENUM2STRING(DOOM_COMM_OBJ1),				//# DOOM COMM
	ENUM2STRING(DOOM_COMM_OBJ2),				//# DOOM COMM
	ENUM2STRING(DOOM_COMM_OBJ3),				//# DOOM COMM
	ENUM2STRING(DOOM_DETENTION_OBJ1),		//# DOOM DETENTION
	ENUM2STRING(DOOM_DETENTION_OBJ2),		//# DOOM DETENTION
	ENUM2STRING(DOOM_SHIELDS_OBJ1),			//# DOOM SHIELDS
	ENUM2STRING(DOOM_SHIELDS_OBJ2),			//# DOOM SHIELDS
	ENUM2STRING(YAVIN_SWAMP_OBJ1),			//# YAVIN SWAMP
	ENUM2STRING(YAVIN_SWAMP_OBJ2),			//# YAVIN SWAMP
	ENUM2STRING(YAVIN_CANYON_OBJ1),			//# YAVIN CANYON
	ENUM2STRING(YAVIN_CANYON_OBJ2),			//# YAVIN CANYON
	ENUM2STRING(YAVIN_COURTYARD_OBJ1),		//# YAVIN COURTYARD
	ENUM2STRING(YAVIN_COURTYARD_OBJ2),		//# YAVIN COURTYARD
	ENUM2STRING(YAVIN_FINAL_OBJ1),			//# YAVIN FINAL
	ENUM2STRING(KEJIM_POST_OBJ3),			//# KEJIM POST - GRAPHICS IN IT. 
	ENUM2STRING(KEJIM_POST_OBJ4),			//# KEJIM POST - GRAPHICS IN IT. 
	ENUM2STRING(KEJIM_POST_OBJ5),			//# KEJIM POST - GRAPHICS IN IT. 
	ENUM2STRING(ARTUS_DETENTION_OBJ3),		//# ARTUS DETENTION
	ENUM2STRING(DOOM_COMM_OBJ4),			//# DOOM COMM - GRAPHICS IN IT. IT MUST BE LAST IN THE LIST
	ENUM2STRING(DOOM_SHIELDS_OBJ3),			//# DOOM SHIELDS
	ENUM2STRING(DEMO_OBJ1),					//# DEMO 
	ENUM2STRING(DEMO_OBJ2),					//# DEMO 
	ENUM2STRING(DEMO_OBJ3),					//# DEMO 
	ENUM2STRING(DEMO_OBJ4),					//# DEMO 

	//stringID_table_t Must end with a null entry
	{ "", 0 }
};

stringID_table_t missionFailedTable[] =
{
	ENUM2STRING(MISSIONFAILED_JAN),			//# JAN DIED
	ENUM2STRING(MISSIONFAILED_LUKE),		//# LUKE DIED
	ENUM2STRING(MISSIONFAILED_LANDO),		//# LANDO DIED
	ENUM2STRING(MISSIONFAILED_R5D2),		//# R5D2 DIED
	ENUM2STRING(MISSIONFAILED_WARDEN),		//# THE WARDEN DIED
	ENUM2STRING(MISSIONFAILED_PRISONERS),	//#	TOO MANY PRISONERS DIED
	ENUM2STRING(MISSIONFAILED_EMPLACEDGUNS),//#	ALL EMPLACED GUNS GONE
	ENUM2STRING(MISSIONFAILED_LADYLUCK),	//#	LADY LUCK DISTROYED
	ENUM2STRING(MISSIONFAILED_KYLECAPTURE),	//# KYLE HAS BEEN CAPTURED	
	ENUM2STRING(MISSIONFAILED_TOOMANYALLIESDIED),	//# TOO MANY ALLIES DIED

	//stringID_table_t Must end with a null entry
	{ "", 0 }
};