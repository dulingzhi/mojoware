/***********************************************************************************************************************
/*
/*    balloon.cpp / mojo_app
/*   
/*    Copyright 2009 Robert Sacks.  See end of file for more info.
/*
/**********************************************************************************************************************/

#include "stdafx.h"

#pragma once


//======================================================================================================================
//  CODE
//======================================================================================================================


//----------------------------------------------------------------------------------------------------------------------
//  DISPLAY BALLOON
//  test is limited to 80 bytes (40 wchar_t's)
//----------------------------------------------------------------------------------------------------------------------
HWND display_balloon ( HWND hCtrl, const wchar_t * pTitle, const wchar_t * pBody )
{
	HWND hParent = GetParent ( hCtrl );

    HWND hTip = CreateWindowEx ( 	WS_EX_TOPMOST,
        							TOOLTIPS_CLASS, 
									NULL,
        							WS_POPUP | TTS_NOPREFIX | TTS_ALWAYSTIP | TTS_BALLOON, // | TTS_CLOSE ,		
        							CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        							hParent, 
									NULL, 
									g_hInstance,
									NULL);

    if ( ! hTip )
        return NULL;

	//-------------------------------------------------
	//  SET NEW WINDOW PROC AND STORE ADDRESS OF OLD
	//  ONE IN USER DATA SO NEW ONE CAN CALL IT
	//-------------------------------------------------

#if 0
	WNDPROC pfOldProc = (WNDPROC) GetWindowLongPtr ( hTip, GWLP_WNDPROC );
	SetWindowLongPtr ( hTip, GWLP_WNDPROC, (LONG_PTR) balloon_proc );
	SetWindowLongPtr ( hTip, GWLP_USERDATA, (LONG_PTR) pfOldProc );
#endif

	//-------------------------------------------------
	//  ASSOCIATE THE BALLOON WITH THE CLIENT RECT
	//-------------------------------------------------

	TOOLINFO ti;
    ti.cbSize 	= sizeof(TOOLINFO);
    ti.uFlags 	= TTF_IDISHWND | TTF_SUBCLASS; //  TTF_TRACK ; // | TTF_ABSOLUTE;
    ti.hwnd 	= hCtrl; // hParent;
    ti.hinst 	= g_hInstance;
    ti.lpszText = (LPWSTR) pBody;
    ti.uId 		= (UINT_PTR)hCtrl; // hParent;
    GetClientRect ( hParent, &ti.rect );

    SendMessage ( hTip, TTM_ADDTOOL, 0, (LPARAM) (LPTOOLINFO) &ti);	

	//-------------------------------------------------
	//  SET ICON WITH TITLE
	//-------------------------------------------------

	SendMessage ( hTip, TTM_SETTITLE, (WPARAM) TTI_INFO, (LPARAM) pTitle );
 
	//-------------------------------------------------
	//  ACTIVATE AND DISPLAY IT IN CENTER OF
	//  OF CONTROL'S RECT
	//-------------------------------------------------

	RECT r;
	GetWindowRect ( hCtrl, &r );

	SendMessage ( hTip, TTM_TRACKACTIVATE, (WPARAM)TRUE, (LPARAM)&ti);
	SendMessage ( hTip, TTM_TRACKPOSITION, 0, (LPARAM) MAKELONG ( ( r.left + r.right )/2, ( r.top + r.bottom )/2 ) );

    return hTip;
}


/***********************************************************************************************************************
/*
/*    This file is part of Mojo.  For more information, see http://mojoware.org.
/*
/*    You may redistribute and/or modify Mojo under the terms of the GNU General Public License, version 3, as
/*    published by the Free Software Foundation.  You should have received a copy of the license with mojo.  If you
/*    did not, go to http://www.gnu.org.
/* 
/*    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
/*    NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
/*    IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/*    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
/*    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
/*    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
/*    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
/*
/***********************************************************************************************************************/