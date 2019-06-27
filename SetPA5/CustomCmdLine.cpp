#include "StdAfx.h"
#include "customcmdline.h"
#include <fstream>
#include <sstream>

CCustomCmdLine::CCustomCmdLine(void)
	: bUse{ false, false }
	, fAtten{ 0.0, 0.0 }
{
}

CCustomCmdLine::~CCustomCmdLine(void)
{
}

void CCustomCmdLine::ParseParam(const TCHAR* pszParam,BOOL bFlag,BOOL bLast)
{
	CString sArg(pszParam);
	std::string s(sArg);
	float atten = 0.0;
	if (count > 1) return;	// ignore all args after second
	//std::ofstream logfile;
	//logfile.open("setpa5.log", std::ofstream::out | std::ofstream::app);

	std::istringstream iss(s);
	if (iss >> atten)
	{
		bUse[count] = true;
		fAtten[count] = atten;
		//logfile << "count " << count << "arg " << s << " atten " << atten << std::endl;
	}
	else
	{
		bUse[count] = false; // initialized but here for clarity
		//logfile << "count " << count << " arg " << s << " bad format " << std::endl;
	}
	count++;
}
