// liebiaokuang.cpp : implementation file
//

#include "stdafx.h"
#include "SZ.h"
#include "liebiaokuang.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;

static CString lujin;    //�ļ�·��
static FILE *file;       //�򿪵��ļ�ָ��
static int file_length;       //�ļ���С
static int point;             //�ļ��ڲ�λ��ָ��
static int level;
static biaozhi = false;
char * cTemp = new char[10];
char cTemp1[10][10];
int k = 0;

#endif

/////////////////////////////////////////////////////////////////////////////
// liebiaokuang dialog


liebiaokuang::liebiaokuang(CWnd* pParent /*=NULL*/)
	: CDialog(liebiaokuang::IDD, pParent)
{
	//{{AFX_DATA_INIT(liebiaokuang)
	//}}AFX_DATA_INIT

}


void liebiaokuang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(liebiaokuang)
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(liebiaokuang, CDialog)
	//{{AFX_MSG_MAP(liebiaokuang)
	ON_BN_CLICKED(IDC_ANNIU1, OnAnniu1)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// liebiaokuang message handlers




void liebiaokuang::OnAnniu1() 
{
	// TODO: Add your control notification handler code here
	
	char szSelected[MAX_PATH];
    BROWSEINFO bi;
    LPITEMIDLIST pidl;
    bi.hwndOwner=this->m_hWnd;
    bi.pidlRoot=NULL;
    bi.pszDisplayName=szSelected;
    bi.lpszTitle="ѡ��ѹ���ļ�";
    bi.ulFlags=BIF_BROWSEINCLUDEFILES;
    bi.lpfn=NULL;
    bi.iImage=NULL;
    if((pidl=SHBrowseForFolder(&bi))!=NULL)
	{
		if(SUCCEEDED(SHGetPathFromIDList(pidl,szSelected)))
		{
			lujin=szSelected;
		}
	}
	


	file = fopen((LPSTR)(LPCSTR)lujin,"r");

	char sign;
    char name[100];

	fseek(file,0,SEEK_END);
	file_length = ftell(file);
	fseek(file,0,SEEK_SET);
	point = 0;

	
	level = int(fgetc(file));	
    sign = fgetc(file);
	memset(name,0,100);
	char c;
	int i = 0;
	while((c = fgetc(file))!= '\t')
		name[i++] = c;
	fgetc(file);

	CString str;
	str.Format(_T("..."));
	m_listbox.AddString(str);
    m_listbox.AddString(name);

	strcpy(cTemp1[k],name);     
}




void liebiaokuang::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	//char sign;
    char name[100];
	if(m_listbox.GetCurSel() == 0)
	{   //������һ��Ŀ¼
		level--;
		//AfxMessageBox(cTemp1[k]);
		k--;
		fseek(file,0,SEEK_SET);
		point = 0;

		biaozhi = false;
		int levelt;

		m_listbox.SendMessage(LB_RESETCONTENT);   //���б���ÿ�
		CString str;
		str.Format(_T("..."));
		m_listbox.AddString(str);

		while(point < file_length)
		{
			levelt = int(fgetc(file));
			char sign = fgetc(file);
			
			//��������
			memset(name,0,100);
			char c;int i = 0;
			while((c = fgetc(file))!= '\t')
			    name[i++] = c;
             fgetc(file);         //�������з�
			
			//������ļ�
			if(sign == 'f')
			{
				char number[20];
				char c;
				
				//�����ļ�����ʼλ��
				int j = 0;
				memset(number,0,20);
				while((c = fgetc(file)) != '\t')
				{
					number[j++] = c;
				}
				fgetc(file);
				
				//�����ļ��Ľ���λ��
				j = 0;
				memset(number,0,20);
				while((c = fgetc(file)) != '\t')
				{
					number[j++] = c;
				}
				fgetc(file);
			}
			
			if(k == 0)
			{
				CString str;
				str.Format(_T(name));
				m_listbox.AddString(str);
				goto err;
			}
			else if(levelt == level-1 && !strcmp(name,cTemp1[k]))
			{
				while(point < file_length)
				{
					levelt = int(fgetc(file));
					char sign = fgetc(file);
					memset(name,0,100);
					char c;
					int i = 0;
					while((c = fgetc(file))!= '\t')
						name[i++] = c;
					fgetc(file);
					
					if(sign == 'f')
					{
						char number[20];
						char c;
						int j = 0;
						memset(number,0,20);
						while((c = fgetc(file)) != '\t')
						{
							number[j++] = c;
						}	
						fgetc(file);
						j = 0;
						memset(number,0,20);
						while((c = fgetc(file)) != '\t')
						{
							number[j++] = c;
						}
						fgetc(file);
					}
					if(level > levelt) goto err;
					if(level == levelt)
					{
						CString str;
						str.Format(_T(name));
						m_listbox.AddString(str);
					}
					point = ftell(file);
				}
			}
			point = ftell(file);

		}
	}

	else   //if(m_listbox.GetCurSel() != 0)
	{
		int index = m_listbox.GetCurSel();
	    CString temp;
		m_listbox.GetText(index,temp);

		m_listbox.SendMessage(LB_RESETCONTENT);
		CString str;
		str.Format(_T("..."));
		m_listbox.AddString(str);

		fseek(file,0,SEEK_SET);
		point = 0;
        
		
		
		cTemp = new char[10] ;
		cTemp = (LPSTR)(LPCTSTR)temp;
		k++;
		strcpy(cTemp1[k],cTemp);      


		while(point < file_length)
		{
			int levelt = int(fgetc(file));
			char sign = fgetc(file);
			memset(name,0,100);
			char c;
			int i = 0;
			while((c = fgetc(file))!= '\t')
				name[i++] = c;
			fgetc(file);
			
			if(sign == 'f')
			{
				char number[20];char c;int j = 0;
				memset(number,0,20);
				while((c = fgetc(file)) != '\t')
				{
					number[j++] = c;
				}
				fgetc(file);
				j = 0;
				memset(number,0,20);
				while((c = fgetc(file)) != '\t')
				{
					number[j++] = c;
				}
				fgetc(file);
			}
			point = ftell(file);
           
			
			if(levelt == level &&!strcmp(name,cTemp))
			{
				if(sign == 'f') {AfxMessageBox("�Ѿ�û���²�Ŀ¼��");goto err;}
				level++;
				while(point < file_length)
				{
					levelt = int(fgetc(file));
					char sign = fgetc(file);
					memset(name,0,100);
					char c;
					int i = 0;
					while((c = fgetc(file))!= '\t')
						name[i++] = c;
					fgetc(file);
					
					if(sign == 'f')
					{
						char number[20];
						char c;
						int j = 0;
						memset(number,0,20);
						while((c = fgetc(file)) != '\t')
						{
							number[j++] = c;
						}	
						fgetc(file);
						j = 0;
						memset(number,0,20);
						while((c = fgetc(file)) != '\t')
						{
							number[j++] = c;
						}
						fgetc(file);
					}
					if(level > levelt) goto err;
					if(level == levelt)
					{
					    CString str;
					    str.Format(_T(name));
					    m_listbox.AddString(str);
					}
					point = ftell(file);
				}
			}
		}

	}

err: ;	
}
