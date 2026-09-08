//
// key.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "rr.h"
#include "key.h"
#include <winreg.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKey

void CKey::Close()
{
	if (m_hKey != NULL)
	{
		LONG lRes = RegCloseKey(m_hKey);
		if (lRes != ERROR_SUCCESS)
		{
			RRAssert(FALSE);
		}
		m_hKey = NULL;
	}
}

BOOL CKey::Create(HKEY hKey, LPCTSTR lpszKeyName)
{
	RRAssert(hKey != NULL);
	if (hKey == NULL)
		return FALSE;

	Close();
	return (RegCreateKey(hKey, lpszKeyName, &m_hKey) == ERROR_SUCCESS);
}

BOOL CKey::Open(HKEY hKey, LPCTSTR lpszKeyName)
{
	RRAssert(hKey != NULL);
	if (hKey == NULL)
		return FALSE;

	Close();
	return (RegOpenKey(hKey, lpszKeyName, &m_hKey) == ERROR_SUCCESS);
}

BOOL CKey::SetStringValue(LPCTSTR lpszValue, LPCTSTR lpszValueName)
{
	RRAssert(m_hKey != NULL);
	if (m_hKey == NULL)
		return FALSE;

	return (RegSetValueEx(m_hKey, lpszValueName, NULL, REG_SZ, (BYTE * const)lpszValue, (lstrlen(lpszValue)+1)*sizeof(TCHAR)) == ERROR_SUCCESS);
}

BOOL CKey::GetStringValue(CString& str, LPCTSTR lpszValueName)
{
	RRAssert(m_hKey != NULL);
	if (m_hKey == NULL)
		return FALSE;

	str.Empty();
	DWORD dw = 0;
	DWORD dwType = 0;
	LONG lRes = RegQueryValueEx(m_hKey, (LPTSTR)lpszValueName, NULL, &dwType, NULL, &dw);
	if (lRes != ERROR_SUCCESS || dwType != REG_SZ ||
		dw < sizeof(TCHAR) || (dw % sizeof(TCHAR)) != 0)
	{
		return FALSE;
	}

	const int nChars = (int)(dw / sizeof(TCHAR));
	LPTSTR lpsz = str.GetBuffer(nChars + 1);
	lRes = RegQueryValueEx(m_hKey, lpszValueName, NULL, &dwType,
		(BYTE*)lpsz, &dw);
	if (lRes != ERROR_SUCCESS || dwType != REG_SZ)
	{
		str.ReleaseBuffer(0);
		return FALSE;
	}
	lpsz[nChars] = NULL;
	str.ReleaseBuffer();
	return TRUE;
}
