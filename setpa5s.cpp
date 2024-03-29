
// setpa5s.cpp : Defines the class behaviors for the application.
//

//#include "windows.h"
#include "stdafx.h"
#include "setpa5s.h"
#include "setpa5sDlg.h"
#include "CDPA5x.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Csetpa5sApp

BEGIN_MESSAGE_MAP(Csetpa5sApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Csetpa5sApp construction

Csetpa5sApp::Csetpa5sApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Csetpa5sApp object

Csetpa5sApp theApp;


// Csetpa5sApp initialization

BOOL Csetpa5sApp::InitInstance()
{
	// parse command line args
	std::wstring sArgs(m_lpCmdLine);
	float a1, a2;
	std::wistringstream sst(sArgs);

#if 0
	int msgboxID = MessageBox(
		NULL,
		(LPCSTR)L"Resource not available\nDo you want to try again?",
		(LPCSTR)L"Account Details",
		MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
	);
#endif

	//  Read in the first integer
	if (!(sst >> a1) || !(sst >> a2))
	{
		MessageBoxA(NULL, "Error parsing input", "setpa5s", MB_OK);
//		MessageBox(NULL, (LPCWSTR)"Error parsing input", (LPCWSTR)"setpa5s", MB_OK);
	}
	else
	{
		InitCommonControls();
		CWinApp::InitInstance();
		AfxEnableControlContainer();

		// open log file
		std::ofstream logfile;
		logfile.open("setpa5.log", std::ofstream::out | std::ofstream::app);

		CDPA5x pa5;
		long l;
		CA2T sUSB("USB");
		l = pa5.ConnectPA5(sUSB, 1);
		logfile << "pa5.ConnectPA5(\"USB\",1) returned " << l << std::endl;
		pa5.SetAtten(49.8);

		//l = ThePA52.ConnectPA5("USB", 2);
		//logfile << "ThePA52.ConnectPA5(\"USB\", 2) returned " << l << std::endl;
		//ThePA52.SetAtten(atof(AttenuationString));

		l = pa5.ConnectPA5(sUSB, 2);
		logfile << "pa5.ConnectPA5(\"USB\",2) same object returned " << l << std::endl;
		pa5.SetAtten(49.9);


#if 0
		CDPA5x pa51;
		CDPA5x pa52;
		bool bFail = false;
		CA2T sUSB("USB");
		// do first one...
		if (pa51.ConnectPA5(sUSB, 1) == 0)
		{
			MessageBoxA(NULL, "Cannot connect to PA5 #1/2", "setpa5s", MB_OK);
			return FALSE;
		}
		else
		{
			float f = pa51.GetAtten();
			std::ostringstream oss;
			oss << "atten " << f;
			MessageBoxA(NULL, oss.str().c_str(), "setpa5s", MB_OK);
		}

		// do first one...
		if (pa52.ConnectPA5(sUSB, 2) == 0)
		{
			MessageBoxA(NULL, "Cannot connect to PA5 #2/2", "setpa5s", MB_OK);
			return FALSE;
		}

		BOOL b1, b2;
		CString cs1, cs2;
		b1 = pa51.SetAtten(a1);
		cs1 = pa51.GetError();
		b2 = pa52.SetAtten(a2);
		cs2 = pa52.GetError();

		if (cs1.GetLength() > 0)
		{
			CStringA strA(cs1); // a helper string
			LPCSTR ptr = strA;
			MessageBoxA(NULL, ptr, "setpa5s#1", MB_OK);
		}
		if (cs2.GetLength() > 0)
		{
			CStringA strA(cs2); // a helper string
			LPCSTR ptr = strA;
			MessageBoxA(NULL, ptr, "setpa5s#2", MB_OK);
		}
#endif
	}
	return FALSE;
}

