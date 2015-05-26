// YASUODLG.cpp : implementation file
//

#include "stdafx.h"
#include "SZ.h"
#include "YASUODLG.h"
#include "Compress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// YASUODLG dialog


YASUODLG::YASUODLG(CWnd* pParent /*=NULL*/)
	: CDialog(YASUODLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(YASUODLG)
	m_sourcefile = _T("");
	m_yaosuolujing = _T("");
	//}}AFX_DATA_INIT
}


void YASUODLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(YASUODLG)
	DDX_Text(pDX, IDC_SOURCEFILE, m_sourcefile);
	DDX_Text(pDX, IDC_YASUOLUJING, m_yaosuolujing);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(YASUODLG, CDialog)
	//{{AFX_MSG_MAP(YASUODLG)
	ON_BN_CLICKED(IDC_ADDFILE, OnAddfile)
	ON_BN_CLICKED(IDC_QUEDING1, OnQueding1)
	ON_BN_CLICKED(IDC_QUXIAO1, OnQuxiao1)
	ON_BN_CLICKED(IDC_YASUOPATH, OnYasuopath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// YASUODLG message handlers

void YASUODLG::OnAddfile() 
{
	// TODO: Add your control notification handler code here
	char szSelected[MAX_PATH];
    BROWSEINFO bi;
    LPITEMIDLIST pidl;
    bi.hwndOwner=this->m_hWnd;
    bi.pidlRoot=NULL;
    bi.pszDisplayName=szSelected;
    bi.lpszTitle="要压缩的文件";
    bi.ulFlags=BIF_BROWSEINCLUDEFILES;
    bi.lpfn=NULL;
    bi.iImage=NULL;
    if((pidl=SHBrowseForFolder(&bi))!=NULL)
	{
		if(SUCCEEDED(SHGetPathFromIDList(pidl,szSelected)))
		{
			m_sourcefile=szSelected;
		}
	}
	SetDlgItemText(IDC_SOURCEFILE,m_sourcefile);
}

void YASUODLG::OnQueding1() 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	Compress * a = new Compress((LPSTR)(LPCSTR)m_yaosuolujing, (LPSTR)(LPCSTR)m_sourcefile);
	int k = a->comp();
	if(k == -1) 
	{
		AfxMessageBox("压缩完成！");
		OnCancel();
	}
}

void YASUODLG::OnQuxiao1() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void YASUODLG::OnYasuopath() 
{
	// TODO: Add your control notification handler code here
	char szSelected[MAX_PATH];
    BROWSEINFO bi;
    LPITEMIDLIST pidl;
    bi.hwndOwner=this->m_hWnd;
    bi.pidlRoot=NULL;
    bi.pszDisplayName=szSelected;
    bi.lpszTitle="压缩路径（如果不存在被创建）";
    bi.ulFlags=BIF_BROWSEINCLUDEFILES;
    bi.lpfn=NULL;
    bi.iImage=NULL;
    if((pidl=SHBrowseForFolder(&bi))!=NULL)
	{
		if(SUCCEEDED(SHGetPathFromIDList(pidl,szSelected)))
		{
			m_yaosuolujing=szSelected;
		}
	}
	SetDlgItemText(IDC_YASUOLUJING,m_yaosuolujing);	
}
