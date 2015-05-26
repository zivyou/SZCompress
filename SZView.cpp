// SZView.cpp : implementation of the CSZView class
//

#include "stdafx.h"
#include "SZ.h"

#include "SZDoc.h"
#include "SZView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSZView

IMPLEMENT_DYNCREATE(CSZView, CView)

BEGIN_MESSAGE_MAP(CSZView, CView)
	//{{AFX_MSG_MAP(CSZView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSZView construction/destruction

CSZView::CSZView()
{
	// TODO: add construction code here

}

CSZView::~CSZView()
{
}

BOOL CSZView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSZView drawing

void CSZView::OnDraw(CDC* pDC)
{
	CSZDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSZView printing

BOOL CSZView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSZView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSZView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSZView diagnostics

#ifdef _DEBUG
void CSZView::AssertValid() const
{
	CView::AssertValid();
}

void CSZView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSZDoc* CSZView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSZDoc)));
	return (CSZDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSZView message handlers
