/***********************************************************************************************************************
/*
/*    Settings.cpp / mojo_app
/*
/*    Copyright 2009 Robert Sacks.  See end of file for more info.
/*
/**********************************************************************************************************************/

#include "stdafx.h"

using namespace mojo;

//======================================================================================================================
// DEFINES
//======================================================================================================================

#define ENTRY(a,b,c) int ( (BYTE*)&DefaultSettings.a - (BYTE*)&DefaultSettings ),   \
					 b,																\
					 c	// DON'T ERASE THIS LINE


//======================================================================================================================
// DATA
//======================================================================================================================

static const cSettings DefaultSettings ( g_awAppTitle, &g_Version );
	             
cSettings::sEntry cSettings::aTable [] =
{	
	ENTRY ( bLicenseAccepted,						boolean,				L"bLicenseAccepted"						),
	ENTRY ( bConnect,								boolean,				L"bConnect"								),
	ENTRY ( bConnectAutomatically,					boolean,				L"bConnectAutomatically"				),
	ENTRY ( bUseSpecifiedLocalIP,					boolean,				L"bUseSpecifiedLocalIP"					),
	ENTRY ( uSpecifiedLocalIP,						uint,					L"uSpecifiedLocalIP"					),
	ENTRY ( uPort,									uint,					L"uPort"								),
	ENTRY ( bUseNagle,								boolean,				L"bUseNagle"							),
	ENTRY ( bWindowBroadcastIsOn,					boolean,				L"bWindowBroadcastIsOn"					),
	ENTRY ( bComputerBroadcastIsOn,					boolean,				L"bComputerBroadcastIsOn"               ),
	ENTRY ( bShowIpOnMouseoverSettings,             boolean,                L"bShowIpOnMouseoverSettings"           ),
	ENTRY ( bMouseoverDeactivatesScreenSavers,      boolean,                L"bMouseoverDeactivatesScreenSavers"    ),
	ENTRY ( bHideRemoteCursor,                      boolean,                L"bHideRemoteCursor"                    ),
	ENTRY ( bHotkeysAreOn,                          boolean,                L"bHotkeysAreOn"                        ),
	ENTRY ( bMouseoverIsOn,                         boolean,                L"bMouseoverIsOn"                       ),
	ENTRY ( uFinderBroadcastInterval,               uint,                   L"uFinderBroadcastInterval"             ),
	ENTRY ( bRaiseProcessPriority,					boolean,				L"bRaiseProcessPriority"				),
	ENTRY ( bMaximizeTimerResolution,				boolean,				L"bMaximizeTimerResolution"				),
	ENTRY ( uView,									uint,				    L"uView"				                ),
	ENTRY ( uToonIconWidth,							uint,				    L"uToonIconWidth"				        ),
	ENTRY ( uToonIconHeight,						uint,				    L"uToonIconHeight"				        ),
	ENTRY ( uActiveWindowTracking,				    uint,				    L"uActiveWindowTracking"				),
	ENTRY ( uActiveWindowTrackingZ,				    uint,				    L"uActiveWindowTrackingZ"				),
	ENTRY ( uActiveWindowTrackingDelay,				uint,				    L"uActiveWindowTrackingDelay"		    ),
	ENTRY ( bActiveWindowTrackingDelaySystem,		boolean,				L"bActiveWindowTrackingDelaySystem"		),

	// ENTRY ( uWoWIconWidth,							uint,				    L"uWoWIconWidth"				        ),
	// ENTRY ( uWoWIconHeight,						    uint,				    L"uWoWIconHeight"				        ),
};


//======================================================================================================================
// CODE
//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
//  QTY ENTRIES
//  define this virtual function in derived class
//----------------------------------------------------------------------------------------------------------------------
int	cSettings :: qty_entries ()
{
	return sizeof ( aTable ) / sizeof ( sEntry );
}

//----------------------------------------------------------------------------------------------------------------------
//  TABLE
//  define this virtual function in derived class
//----------------------------------------------------------------------------------------------------------------------
cSettings::sEntry * cSettings :: table ( int i )
{ 
   return &aTable[i];
}

//----------------------------------------------------------------------------------------------------------------------
//  INIT
//----------------------------------------------------------------------------------------------------------------------
void cSettings :: init ()
{
	// sSignature						= L"mojo";
	// Version							= g_Version;
	bLicenseAccepted					= false;
	bConnect							= true;
	bConnectAutomatically				= true;
	bUseSpecifiedLocalIP				= false;
	uSpecifiedLocalIP					= 0;
	uPort 								= 7237;
	bUseNagle							= false;
	bWindowBroadcastIsOn                = true;
	bComputerBroadcastIsOn              = false;
	bShowIpOnMouseoverSettings          = false;
	bMouseoverDeactivatesScreenSavers   = true;
	bHideRemoteCursor                   = true;
	bHotkeysAreOn                       = false;
	bMouseoverIsOn                      = true;
	uFinderBroadcastInterval            = 5000;
	bRaiseProcessPriority				= true;
	bMaximizeTimerResolution            = true;
	uView                               = cWinMain::computers;
	uToonIconWidth                      = 50;
	uToonIconHeight                     = 50;
	uActiveWindowTracking               = 0;
	uActiveWindowTrackingZ              = 0;
	uActiveWindowTrackingDelay          = 500;
	bActiveWindowTrackingDelaySystem    = true;


	// uWoWIconWidth                       = 70;
	// uWoWIconHeight                      = 69;
}


/***********************************************************************************************************************
/*
/*    This file is part of Mojo.  For more information, see http://mojoware.org.
/*
/*    You may redistribute and/or modify Mojo under the terms of the GNU General Public License, 
/*    version 3, as published by the Free Software Foundation.  You should have received a copy of the 
/*    license with mojo.  If you did not, go to http://www.gnu.org.
/*     
/*    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
/*    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
/*    PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
/*    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
/*    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/*    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
/*    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
/*    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
/*
/***********************************************************************************************************************/