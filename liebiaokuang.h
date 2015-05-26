#if !defined(AFX_LIEBIAOKUANG_H__63A72FA3_F28D_4699_8A9D_005D30579245__INCLUDED_)
#define AFX_LIEBIAOKUANG_H__63A72FA3_F28D_4699_8A9D_005D30579245__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// liebiaokuang.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// liebiaokuang dialog

class liebiaokuang : public CDialog
{
// Construction
public:
	liebiaokuang(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(liebiaokuang)
	enum { IDD = IDD_DIALOG3 };
	CListBox	m_listbox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(liebiaokuang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(liebiaokuang)
	afx_msg void OnAnniu1();
	afx_msg void OnDblclkList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIEBIAOKUANG_H__63A72FA3_F28D_4699_8A9D_005D30579245__INCLUDED_)
