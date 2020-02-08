// DLGalgoptions.cpp : implementation file
//

#include "stdafx.h"
#include "bivariate.h"
#include "DLGalgoptions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLGalgoptions dialog


DLGalgoptions::DLGalgoptions(CWnd* pParent /*=NULL*/)
	: CDialog(DLGalgoptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLGalgoptions)
	m_detiter = 0;
	m_rnditer = 0;
	//}}AFX_DATA_INIT
}


void DLGalgoptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLGalgoptions)
	DDX_Text(pDX, IDC_DETITER, m_detiter);
	DDV_MinMaxUInt(pDX, m_detiter, 0, 5);
	DDX_Text(pDX, IDC_RNDITER, m_rnditer);
	DDV_MinMaxUInt(pDX, m_rnditer, 0, 10000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLGalgoptions, CDialog)
	//{{AFX_MSG_MAP(DLGalgoptions)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLGalgoptions message handlers
