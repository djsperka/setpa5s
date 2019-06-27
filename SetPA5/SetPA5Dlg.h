// SetPA5Dlg.h : header file
//

#pragma once
#include "x1.h"


// CSetPA5Dlg dialog
class CSetPA5Dlg : public CDialog
{
// Construction
public:
	CSetPA5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SETPA5_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CX1 ThePA5;
	CX1 ThePA52;
	double Attenuation;
	CString AttenuationString;
	bool bUsePA51;
	bool bUsePA52;
	float fAtten1;
	float fAtten2;
};
