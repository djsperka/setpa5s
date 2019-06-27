// SetPA5.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "customcmdline.h"


// CSetPA5App:
// See SetPA5.cpp for the implementation of this class
//

class CSetPA5App : public CWinApp
{
public:
	CCustomCmdLine BaseCommandLine;
	CSetPA5App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSetPA5App theApp;