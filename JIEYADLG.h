#if !defined(AFX_JIEYADLG_H__30E45A5D_60A2_4B05_9C6C_EEB35FEE2B9B__INCLUDED_)
#define AFX_JIEYADLG_H__30E45A5D_60A2_4B05_9C6C_EEB35FEE2B9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JIEYADLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// JIEYADLG dialog

class JIEYADLG : public CDialog
{
// Construction
public:
	JIEYADLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(JIEYADLG)
	enum { IDD = IDD_DIALOG2 };
	CString	m_yaojieyadewenjian;
	CString	m_jieyalujingedit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JIEYADLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JIEYADLG)
	afx_msg void OnJieyalujing();
	afx_msg void OnQueding2();
	afx_msg void OnQuxiao2();
	afx_msg void OnTianjiawenjian();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIEYADLG_H__30E45A5D_60A2_4B05_9C6C_EEB35FEE2B9B__INCLUDED_)
