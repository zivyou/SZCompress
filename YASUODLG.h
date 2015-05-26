#if !defined(AFX_YASUODLG_H__52A4703D_220D_4243_90F3_30984AD9496F__INCLUDED_)
#define AFX_YASUODLG_H__52A4703D_220D_4243_90F3_30984AD9496F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YASUODLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// YASUODLG dialog

class YASUODLG : public CDialog
{
// Construction
public:
	YASUODLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(YASUODLG)
	enum { IDD = IDD_DIALOG1 };
	CString	m_sourcefile;
	CString	m_yaosuolujing;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(YASUODLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(YASUODLG)
	afx_msg void OnAddfile();
	afx_msg void OnQueding1();
	afx_msg void OnQuxiao1();
	afx_msg void OnYasuopath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YASUODLG_H__52A4703D_220D_4243_90F3_30984AD9496F__INCLUDED_)
