
// JsonMfcTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CJsonMfcTestApp:
// See JsonMfcTest.cpp for the implementation of this class
//

class CJsonMfcTestApp : public CWinApp
{
public:
	CJsonMfcTestApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CJsonMfcTestApp theApp;