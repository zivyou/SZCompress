// SZDoc.h : interface of the CSZDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SZDOC_H__D4F5171E_A886_4C67_A304_ED62F671E3F0__INCLUDED_)
#define AFX_SZDOC_H__D4F5171E_A886_4C67_A304_ED62F671E3F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSZDoc : public CDocument
{
protected: // create from serialization only
	CSZDoc();
	DECLARE_DYNCREATE(CSZDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSZDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSZDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSZDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SZDOC_H__D4F5171E_A886_4C67_A304_ED62F671E3F0__INCLUDED_)
