// SZ.h : main header file for the SZ application
//

#if !defined(AFX_SZ_H__691C2FC5_93EA_48E7_BAE8_6D077402AFFE__INCLUDED_)
#define AFX_SZ_H__691C2FC5_93EA_48E7_BAE8_6D077402AFFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSZApp:
// See SZ.cpp for the implementation of this class
//

class CSZApp : public CWinApp
{
public:
	CSZApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSZApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSZApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SZ_H__691C2FC5_93EA_48E7_BAE8_6D077402AFFE__INCLUDED_)
