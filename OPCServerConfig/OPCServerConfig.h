
// OPCServerConfig.h : main header file for the OPCServerConfig application
//
#pragma once
#include "pch.h"
#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MainFrm.h"

#include "MySheet.h"

// COPCServerConfigApp:
// See OPCServerConfig.cpp for the implementation of this class
//

class COPCServerConfigApp : public CWinAppEx
{
public:
	COPCServerConfigApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	DECLARE_MESSAGE_MAP()
};

extern COPCServerConfigApp theApp;
