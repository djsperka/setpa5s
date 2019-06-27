// CDPA5x.h  : Declaration of ActiveX Control wrapper class(es) created by Microsoft Visual C++

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDPA5x

class CDPA5x : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDPA5x)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xEC05FCDE, 0x300D, 0x4CE3, { 0x97, 0x74, 0xA4, 0xC3, 0x77, 0x50, 0x7B, 0xD7 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID,
						CCreateContext* pContext = nullptr)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
				BSTR bstrLicKey = nullptr)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey);
	}

// Attributes
public:

// Operations
public:

	BOOL Connect(long Interface, long DevNum)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Interface, DevNum);
		return result;
	}
	BOOL SetAtten(float AttVal)
	{
		BOOL result;
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AttVal);
		return result;
	}
	float GetAtten()
	{
		float result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_R4, (void*)&result, nullptr);
		return result;
	}
	BOOL Reset()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	BOOL SetUser(long ParCode, float Val)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_R4 ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ParCode, Val);
		return result;
	}
	CString GetError()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	BOOL Display(LPCTSTR Text, long Position)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Text, Position);
		return result;
	}
	long ConnectPA5(LPCTSTR IntName, long DevNum)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, IntName, DevNum);
		return result;
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}


};
