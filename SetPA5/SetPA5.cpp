// SetPA5.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SetPA5.h"
#include "SetPA5Dlg.h"
#include <fstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSetPA5App

BEGIN_MESSAGE_MAP(CSetPA5App, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSetPA5App construction

CSetPA5App::CSetPA5App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CSetPA5App object

CSetPA5App theApp;


// CSetPA5App initialization

BOOL CSetPA5App::InitInstance()
{
	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	ParseCommandLine(BaseCommandLine);
	InitCommonControls();
	CWinApp::InitInstance();
	AfxEnableControlContainer();

	CSetPA5Dlg dlg;
	dlg.AttenuationString=BaseCommandLine.LastCmdLineParam;
	dlg.bUsePA51 = BaseCommandLine.bUse[0];
	dlg.fAtten1 = BaseCommandLine.fAtten[0];
	dlg.bUsePA52 = BaseCommandLine.bUse[1];
	dlg.fAtten2 = BaseCommandLine.fAtten[1];
	
	//	if(strcmp(dlg.AttenuationString,"Hello")==0) _exit(0);
	m_pMainWnd = &dlg;

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
