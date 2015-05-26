; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=liebiaokuang
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SZ.h"
LastPage=0

ClassCount=8
Class1=CSZApp
Class2=CSZDoc
Class3=CSZView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_DIALOG1
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=YASUODLG
Resource3=IDD_ABOUTBOX
Class7=JIEYADLG
Resource4=IDD_DIALOG2
Class8=liebiaokuang
Resource5=IDD_DIALOG3

[CLS:CSZApp]
Type=0
HeaderFile=SZ.h
ImplementationFile=SZ.cpp
Filter=N

[CLS:CSZDoc]
Type=0
HeaderFile=SZDoc.h
ImplementationFile=SZDoc.cpp
Filter=N

[CLS:CSZView]
Type=0
HeaderFile=SZView.h
ImplementationFile=SZView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=SZ.cpp
ImplementationFile=SZ.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342177283

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_OPEN
Command2=ID_APP_EXIT
Command3=ID_YASUO
Command4=ID_JIEYA
Command5=ID_APP_ABOUT
CommandCount=5

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_YASUO
Command2=ID_EDIT_COPY
Command3=ID_JIEYA
Command4=ID_FILE_NEW
Command5=ID_OPEN
Command6=ID_FILE_PRINT
Command7=ID_FILE_SAVE
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_CUT
Command16=ID_EDIT_UNDO
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_OPEN
Command2=ID_APP_ABOUT
Command3=ID_YASUO
Command4=ID_JIEYA
CommandCount=4

[DLG:IDD_DIALOG1]
Type=1
Class=YASUODLG
ControlCount=8
Control1=IDC_ADDFILE,button,1342242816
Control2=IDC_YASUOPATH,button,1342242816
Control3=IDC_YASUOLUJING,edit,1350631552
Control4=IDC_SOURCEFILE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_QUEDING1,button,1342242816
Control8=IDC_QUXIAO1,button,1342242816

[CLS:YASUODLG]
Type=0
HeaderFile=YASUODLG.h
ImplementationFile=YASUODLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=YASUODLG

[DLG:IDD_DIALOG2]
Type=1
Class=JIEYADLG
ControlCount=8
Control1=IDC_TIANJIAWENJIAN,button,1342242816
Control2=IDC_JIEYALUJING,button,1342242816
Control3=IDC_QUEDING2,button,1342242816
Control4=IDC_QUXIAO2,button,1342242816
Control5=IDC_YAOJIEYADEWENJIAN,edit,1350631552
Control6=IDC_JIEYALUJINGEDIT,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:JIEYADLG]
Type=0
HeaderFile=JIEYADLG.h
ImplementationFile=JIEYADLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG3]
Type=1
Class=liebiaokuang
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,listbox,1352728835
Control3=IDC_ANNIU1,button,1342242816

[CLS:liebiaokuang]
Type=0
HeaderFile=liebiaokuang.h
ImplementationFile=liebiaokuang.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

