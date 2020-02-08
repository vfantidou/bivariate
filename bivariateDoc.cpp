// bivariateDoc.cpp : implementation of the CBivariateDoc class
//

#include "stdafx.h"
#include "bivariate.h"

#include "bivariateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBivariateDoc

IMPLEMENT_DYNCREATE(CBivariateDoc, CDocument)

BEGIN_MESSAGE_MAP(CBivariateDoc, CDocument)
	//{{AFX_MSG_MAP(CBivariateDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBivariateDoc construction/destruction

CBivariateDoc::CBivariateDoc()
:data1(4,4,1,Point_3d(0,0,0),Point_3d(3,3,0)),
data2(3,3,1,Point_3d(0,0,0),Point_3d(4,4,0))
{
	data1[0].z=0.1f;
	data1[1].z=0.4f;
	data1[2].z=0.6f;
	data1[3].z=0.2f;
	data1[4].z=0.2f;
	data1[5].z=0.1f;
	data1[6].z=0.3f;
	data1[7].z=0.6f;
	data1[8].z=0.5f;
	data1[9].z=0.0f;
	data1[10].z=0.4f;
	data1[11].z=0.3f;
	data1[12].z=0.3f;
	data1[13].z=0.6f;
	data1[14].z=0.3f;
	data1[15].z=0.4f;

	data2[0].z=0.1f;
	data2[1].z=0.0f;
	data2[2].z=0.6f;
	data2[3].z=0.2f;
	data2[4].z=0.2f;
	data2[5].z=0.0f;
	data2[6].z=0.0f;
	data2[7].z=0.6f;
	data2[8].z=0.5f;

	/*
	data2[0].z=0.1f;	data2[1].z=0.0f;	data2[2].z=0.6f;	data2[3].z=0.2f;
	data2[4].z=0.2f;	data2[5].z=0.0f;	data2[6].z=0.0f;	data2[7].z=0.6f;
	data2[8].z=0.5f;	data2[9].z=0.0f;	data2[10].z=0.2f;	data2[11].z=0.4f;
	data2[12].z=0.3f;	data2[13].z=0.3f;	data2[14].z=0.3f;	data2[15].z=0.5f;
/*
	data2[0].z=0.1f;
	data2[1].z=0.4f;
	data2[2].z=0.6f;
	data2[3].z=0.2f;
	data2[4].z=0.1f;
	data2[5].z=0.2f;
	data2[6].z=0.1f;
	data2[7].z=0.3f;
	data2[8].z=0.6f;
	data2[9].z=0.2f;
	data2[10].z=0.5f;
	data2[11].z=0.0f;
	data2[12].z=0.4f;
	data2[13].z=0.3f;
	data2[14].z=0.5f;
	data2[15].z=0.3f;
	data2[16].z=0.6f;
	data2[17].z=0.3f;
	data2[18].z=0.4f;
	data2[19].z=0.3f;
	data2[20].z=0.1f;
	data2[21].z=0.4f;
	data2[22].z=0.6f;
	data2[23].z=0.2f;
	data2[24].z=0.1f;
*/
}

CBivariateDoc::~CBivariateDoc()
{
}

BOOL CBivariateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBivariateDoc serialization

void CBivariateDoc::Serialize(CArchive& ar)
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
// CBivariateDoc diagnostics

#ifdef _DEBUG
void CBivariateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBivariateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBivariateDoc commands
