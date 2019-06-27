// SetPA5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetPA5.h"
#include "SetPA5Dlg.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSetPA5Dlg dialog



CSetPA5Dlg::CSetPA5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetPA5Dlg::IDD, pParent)
	, Attenuation(0)
	, AttenuationString(_T(""))
	, bUsePA51(false)
	, bUsePA52(false)
	, fAtten1(0.0)
	, fAtten2(0.0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetPA5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_X1, ThePA5);
}

BEGIN_MESSAGE_MAP(CSetPA5Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CSetPA5Dlg message handlers

BOOL CSetPA5Dlg::OnInitDialog()
{

	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
//	ThePA52.ConnectPA5("USB", 1);
//	ThePA52.SetAtten(55.2);
//	ThePA52.SetAtten(atof(AttenuationString));

	// open log file
	//std::ofstream logfile;
	//logfile.open("setpa5.log", std::ofstream::out | std::ofstream::app);

	if (bUsePA51)
	{
		long l;
		l = ThePA5.ConnectPA5("USB", 1);
		//logfile << "ThePA5.ConnectPA5(\"USB\",1) returned " << l << std::endl;
		l = ThePA5.SetAtten(fAtten1);
		//logfile << "ThePA5.SetAtten(" << fAtten1 << ") returned " << l << std::endl;
	}
	else
	{
		//logfile << "Skipping pa5-1" << std::endl;
	}

	if (bUsePA52)
	{
		long l;
		l = ThePA5.ConnectPA5("USB", 2);
		//logfile << "ThePA5.ConnectPA5(\"USB\",2) returned " << l << std::endl;
		l = ThePA5.SetAtten(fAtten2);
		//logfile << "ThePA5.SetAtten(" << fAtten2 << ") returned " << l << std::endl;
	}
	else
	{
		//logfile << "Skipping pa5-2" << std::endl;
	}

#if 0
	long l;
	l = ThePA5.ConnectPA5("USB",1);
	logfile << "ThePA5.ConnectPA5(\"USB\",1) returned " << l << std::endl;
	ThePA5.SetAtten(atof(AttenuationString));

	//l = ThePA52.ConnectPA5("USB", 2);
	//logfile << "ThePA52.ConnectPA5(\"USB\", 2) returned " << l << std::endl;
	//ThePA52.SetAtten(atof(AttenuationString));

	l = ThePA5.ConnectPA5("USB", 2);
	logfile << "ThePA5.ConnectPA5(\"USB\",2) same object returned " << l << std::endl;
	ThePA5.SetAtten(atof(AttenuationString));
#endif
	_exit(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSetPA5Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSetPA5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

