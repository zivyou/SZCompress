// SZView.h : interface of the CSZView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SZVIEW_H__DAC9D07B_EF44_4121_B682_1CD3562D92D5__INCLUDED_)
#define AFX_SZVIEW_H__DAC9D07B_EF44_4121_B682_1CD3562D92D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSZView : public CView
{
protected: // create from serialization only
	CSZView();
	DECLARE_DYNCREATE(CSZView)

// Attributes
public:
	CSZDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSZView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSZView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSZView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SZView.cpp
inline CSZDoc* CSZView::GetDocument()
   { return (CSZDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SZVIEW_H__DAC9D07B_EF44_4121_B682_1CD3562D92D5__INCLUDED_)
