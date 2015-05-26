// JIEYADLG.cpp : implementation file
//

#include "stdafx.h"
#include "SZ.h"
#include "JIEYADLG.h"
#include "DDeCompress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JIEYADLG dialog


JIEYADLG::JIEYADLG(CWnd* pParent /*=NULL*/)
	: CDialog(JIEYADLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(JIEYADLG)
	m_yaojieyadewenjian = _T("");
	m_jieyalujingedit = _T("");
	//}}AFX_DATA_INIT
}


void JIEYADLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JIEYADLG)
	DDX_Text(pDX, IDC_YAOJIEYADEWENJIAN, m_yaojieyadewenjian);
	DDX_Text(pDX, IDC_JIEYALUJINGEDIT, m_jieyalujingedit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JIEYADLG, CDialog)
	//{{AFX_MSG_MAP(JIEYADLG)
	ON_BN_CLICKED(IDC_JIEYALUJING, OnJieyalujing)
	ON_BN_CLICKED(IDC_QUEDING2, OnQueding2)
	ON_BN_CLICKED(IDC_QUXIAO2, OnQuxiao2)
	ON_BN_CLICKED(IDC_TIANJIAWENJIAN, OnTianjiawenjian)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JIEYADLG message handlers

void JIEYADLG::OnJieyalujing() 
{
	// TODO: Add your control notification handler code here
	char szSelected[MAX_PATH];
    BROWSEINFO bi;
    LPITEMIDLIST pidl;
    bi.hwndOwner=this->m_hWnd;
    bi.pidlRoot=NULL;
    bi.pszDisplayName=szSelected;
    bi.lpszTitle="解压路径";
    bi.ulFlags=BIF_BROWSEINCLUDEFILES;
    bi.lpfn=NULL;
    bi.iImage=NULL;
    if((pidl=SHBrowseForFolder(&bi))!=NULL)
	{
		if(SUCCEEDED(SHGetPathFromIDList(pidl,szSelected)))
		{
			m_jieyalujingedit=szSelected;
		}
	}
	SetDlgItemText(IDC_JIEYALUJINGEDIT,m_jieyalujingedit);	
}

void JIEYADLG::OnQueding2() 
{
	// TODO: Add your control notification handler code here
	DDeCompress * a = new DDeCompress((LPSTR)(LPCSTR)m_yaojieyadewenjian,(LPSTR)(LPCSTR)m_jieyalujingedit);
	int k = a ->unComp();
	if(k == -1) 
	{
		AfxMessageBox("解压完成！");
		OnCancel();
	}
}

void JIEYADLG::OnQuxiao2() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
		
}

void JIEYADLG::OnTianjiawenjian() 
{
	// TODO: Add your control notification handler code here
	char szSelected[MAX_PATH];
    BROWSEINFO bi;
    LPITEMIDLIST pidl;
    bi.hwndOwner=this->m_hWnd;
    bi.pidlRoot=NULL;
    bi.pszDisplayName=szSelected;
    bi.lpszTitle="要解压的文件";
    bi.ulFlags=BIF_BROWSEINCLUDEFILES;
    bi.lpfn=NULL;
    bi.iImage=NULL;
    if((pidl=SHBrowseForFolder(&bi))!=NULL)
	{
		if(SUCCEEDED(SHGetPathFromIDList(pidl,szSelected)))
		{
			m_yaojieyadewenjian=szSelected;
		}
	}
	SetDlgItemText(IDC_YAOJIEYADEWENJIAN,m_yaojieyadewenjian);	
}
