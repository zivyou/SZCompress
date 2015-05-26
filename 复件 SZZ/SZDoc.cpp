// SZDoc.cpp : implementation of the CSZDoc class
//

#include "stdafx.h"
#include "SZ.h"

#include "SZDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSZDoc

IMPLEMENT_DYNCREATE(CSZDoc, CDocument)

BEGIN_MESSAGE_MAP(CSZDoc, CDocument)
	//{{AFX_MSG_MAP(CSZDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSZDoc construction/destruction

CSZDoc::CSZDoc()
{
	// TODO: add one-time construction code here

}

CSZDoc::~CSZDoc()
{
}

BOOL CSZDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSZDoc serialization

void CSZDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSZDoc diagnostics

#ifdef _DEBUG
void CSZDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSZDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSZDoc commands
