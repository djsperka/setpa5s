#pragma once

class CCustomCmdLine : public CCommandLineInfo
{
	int count;
public:
	CString LastCmdLineParam;
	void ParseParam(const TCHAR* pszParam,BOOL bFlag,BOOL bLast);
	CCustomCmdLine(void);
	~CCustomCmdLine(void);
	bool bUse[2];
	float fAtten[2];
};
