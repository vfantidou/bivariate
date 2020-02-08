; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=QueryPSet3D
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bivariate.h"
LastPage=0

ClassCount=7
Class1=CBivariateApp
Class2=CAboutDlg
Class3=CBivariateDoc
Class4=CBivariateView
Class5=DLGalgoptions
Class6=CMainFrame
Class7=QueryPSet3D

ResourceCount=4
Resource1=IDD_ABOUTBOX (English (U.S.))
Resource2=IDD_ALGOPTIONS
Resource3=IDR_MAINFRAME (English (U.S.))
Resource4=IDD_PSET3D

[CLS:CBivariateApp]
Type=0
BaseClass=CWinApp
HeaderFile=bivariate.h
ImplementationFile=bivariate.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=bivariate.cpp
ImplementationFile=bivariate.cpp
LastObject=CAboutDlg

[CLS:CBivariateDoc]
Type=0
BaseClass=CDocument
HeaderFile=bivariateDoc.h
ImplementationFile=bivariateDoc.cpp

[CLS:CBivariateView]
Type=0
BaseClass=CView
HeaderFile=bivariateView.h
ImplementationFile=bivariateView.cpp
LastObject=ID_FRACTAL_DATASET
Filter=C
VirtualFilter=VWC

[CLS:DLGalgoptions]
Type=0
BaseClass=CDialog
HeaderFile=DLGalgoptions.h
ImplementationFile=DLGalgoptions.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=CMainFrame

[CLS:QueryPSet3D]
Type=0
BaseClass=CDialog
HeaderFile=QueryPSet3D.h
ImplementationFile=QueryPSet3D.cpp
LastObject=65535

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_ALGOPTIONS]
Type=1
Class=DLGalgoptions
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DETITER,edit,1350639744
Control7=IDC_RNDITER,edit,1350639744

[DLG:IDD_PSET3D]
Type=1
Class=QueryPSet3D
ControlCount=8
Control1=IDC_VIEW3D,static,1342181636
Control2=IDC_PLIST,listbox,1352734721
Control3=IDC_EDIT_Z,edit,1350631552
Control4=65535,static,1342308354
Control5=IDC_SET,button,1342242816
Control6=IDC_OPTIONS,button,1342242816
Control7=IDC_ZHEIGHT,msctls_trackbar32,1342242850
Control8=IDC_GLOPTIONS,SysTabControl32,1342177282

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_ACTIONS_BIVARIATE
Command8=ID_ACTIONS_DET
Command9=ID_ACTIONS_RND
Command10=ID_FRACTAL_DATASET
Command11=ID_ACTIONS_OPTIONS
Command12=ID_VIEW_AXIS
Command13=ID_VIEW_DATAMESH
Command14=ID_VIEW_LOWERGRID
Command15=ID_VIEW_UPERGRID
Command16=ID_VIEW_DATAPOINTS
Command17=ID_VIEW_PERSPECTIVE
Command18=ID_VIEW_ORTHOGRAPHIC
Command19=ID_COLOR_INVERT
Command20=ID_ATTRACTOR_POINTS
Command21=ID_ATTRACTOR_MESH
Command22=ID_ATTRACTOR_SOLID
Command23=ID_MISC_STATISTICS
Command24=ID_MISC_ANIMATE
Command25=ID_APP_ABOUT
CommandCount=25

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

