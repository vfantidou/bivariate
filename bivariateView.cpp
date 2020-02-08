// bivariateView.cpp : implementation of the CBivariateView class
//

#include "stdafx.h"
#include "bivariate.h"
#include "DLGalgoptions.h"
#include "QueryPSet3D.h"

#include "bivariateDoc.h"
#include "bivariateView.h"
#include "gl\gl.h"
#include "gl\glu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBivariateView

IMPLEMENT_DYNCREATE(CBivariateView, CView)

BEGIN_MESSAGE_MAP(CBivariateView, CView)
	//{{AFX_MSG_MAP(CBivariateView)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_ACTIONS_BIVARIATE, OnActionBivariate)
	ON_COMMAND(ID_ACTIONS_DET, OnActionsDet)
	ON_UPDATE_COMMAND_UI(ID_ACTIONS_DET, OnUpdateActionsDet)
	ON_COMMAND(ID_ACTIONS_RND, OnActionsRnd)
	ON_UPDATE_COMMAND_UI(ID_ACTIONS_RND, OnUpdateActionsRnd)
	ON_COMMAND(ID_VIEW_AXIS, OnViewAxis)
	ON_UPDATE_COMMAND_UI(ID_VIEW_AXIS, OnUpdateViewAxis)
	ON_COMMAND(ID_VIEW_DATAMESH, OnViewDatamesh)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DATAMESH, OnUpdateViewDatamesh)
	ON_COMMAND(ID_VIEW_DATAPOINTS, OnViewDatapoints)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DATAPOINTS, OnUpdateViewDatapoints)
	ON_COMMAND(ID_VIEW_LOWERGRID, OnViewLowergrid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LOWERGRID, OnUpdateViewLowergrid)
	ON_COMMAND(ID_VIEW_UPERGRID, OnViewUpergrid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_UPERGRID, OnUpdateViewUpergrid)
	ON_COMMAND(ID_COLOR_INVERT, OnColorInvert)
	ON_UPDATE_COMMAND_UI(ID_COLOR_INVERT, OnUpdateColorInvert)
	ON_COMMAND(ID_ATTRACTOR_MESH, OnAttractorMesh)
	ON_UPDATE_COMMAND_UI(ID_ATTRACTOR_MESH, OnUpdateAttractorMesh)
	ON_COMMAND(ID_ATTRACTOR_POINTS, OnAttractorPoints)
	ON_UPDATE_COMMAND_UI(ID_ATTRACTOR_POINTS, OnUpdateAttractorPoints)
	ON_COMMAND(ID_ATTRACTOR_SOLID, OnAttractorSolid)
	ON_UPDATE_COMMAND_UI(ID_ATTRACTOR_SOLID, OnUpdateAttractorSolid)
	ON_UPDATE_COMMAND_UI(ID_ACTIONS_BIVARIATE, OnUpdateActionsBivariate)
	ON_COMMAND(ID_MISC_STATISTICS, OnMiscStatistics)
	ON_UPDATE_COMMAND_UI(ID_MISC_STATISTICS, OnUpdateMiscStatistics)
	ON_COMMAND(ID_ACTIONS_OPTIONS, OnActionsOptions)
	ON_COMMAND(ID_VIEW_ORTHOGRAPHIC, OnViewOrthographic)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ORTHOGRAPHIC, OnUpdateViewOrthographic)
	ON_COMMAND(ID_VIEW_PERSPECTIVE, OnViewPerspective)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PERSPECTIVE, OnUpdateViewPerspective)
	ON_COMMAND(ID_MISC_ANIMATE, OnMiscAnimate)
	ON_UPDATE_COMMAND_UI(ID_MISC_ANIMATE, OnUpdateMiscAnimate)
	ON_WM_TIMER()
	ON_COMMAND(ID_FRACTAL_DATASET, OnFractalDataset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBivariateView construction/destruction
unsigned char threeto8[8] = 
{
	0, 0111>>1, 0222>>1, 0333>>1, 0444>>1, 0555>>1, 0666>>1, 0377
};

unsigned char twoto8[4] = 
{
	0, 0x55, 0xaa, 0xff
};

unsigned char oneto8[2] = 
{
	0, 255
};

static int defaultOverride[13] = 
{
	0, 3, 24, 27, 64, 67, 88, 173, 181, 236, 247, 164, 91
};

static PALETTEENTRY defaultPalEntry[20] = 
{
	{ 0,   0,   0,    0 },
	{ 0x80,0,   0,    0 },
	{ 0,   0x80,0,    0 },
	{ 0x80,0x80,0,    0 },
	{ 0,   0,   0x80, 0 },
	{ 0x80,0,   0x80, 0 },
	{ 0,   0x80,0x80, 0 },
	{ 0xC0,0xC0,0xC0, 0 },

	{ 192, 220, 192,  0 },
	{ 166, 202, 240,  0 },
	{ 255, 251, 240,  0 },
	{ 160, 160, 164,  0 },

	{ 0x80,0x80,0x80, 0 },
	{ 0xFF,0,   0,    0 },
	{ 0,   0xFF,0,    0 },
	{ 0xFF,0xFF,0,    0 },
	{ 0,   0,   0xFF, 0 },
	{ 0xFF,0,   0xFF, 0 },
	{ 0,   0xFF,0xFF, 0 },
	{ 0xFF,0xFF,0xFF, 0 }
};

CBivariateView::CBivariateView()
{
	anim=ifsReady=stat=inv=DataMPrz1=DataMPrz0=DataMesh=inv = false;
	proj=Axis=DataPoints=true;
	m_pOldPalette = NULL;
	ifs.SetColorType(HMAP);
	ifs.SetRGBColor(0.1f,0.1f,0.2f);

}

CBivariateView::~CBivariateView()
{
}

BOOL CBivariateView::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBivariateView drawing

void CBivariateView::OnDraw(CDC* pDC)
{
	
	wglMakeCurrent(pDC->GetSafeHdc(), m_hrc);
	glClearColor((float)fabs(inv-.0f),(float)fabs(inv-.0f),(float)fabs(inv-.0f),1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	DrawScene();
	glPopMatrix();
	glFinish();
	SwapBuffers(pDC->m_hDC);
	wglMakeCurrent(NULL,  NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CBivariateView diagnostics

#ifdef _DEBUG
void CBivariateView::AssertValid() const
{
	CView::AssertValid();
}

void CBivariateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBivariateDoc* CBivariateView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBivariateDoc)));
	return (CBivariateDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBivariateView message handlers

BOOL CBivariateView::OnEraseBkgnd(CDC* pDC) 
{
	pDC;
	return true;
}

int CBivariateView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetupGL();
	
	return 0;
}

void CBivariateView::OnDestroy() 
{
	HGLRC	hrc;

	hrc = ::wglGetCurrentContext();

    ::wglMakeCurrent(NULL,  NULL);

    if (m_hrc)
        ::wglDeleteContext(m_hrc);

    if (m_pOldPalette)
        GetDC()->SelectPalette(m_pOldPalette, FALSE);

	CView::OnDestroy();
	
	
}

void CBivariateView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CView::OnPrepareDC(pDC, pInfo);
}


/////////////////////////////////////////////////////////////////////////////
// GL helper functions
BOOL CBivariateView::bSetupPixelFormat(CDC *pDC)
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
		1,													// version number
		PFD_DRAW_TO_WINDOW		|	// support window
		  PFD_SUPPORT_OPENGL	|	// support OpenGL
		  PFD_DOUBLEBUFFER,			// double buffered
		PFD_TYPE_RGBA,				// RGBA type
		24,                         // 24-bit color depth
		0, 0, 0, 0, 0, 0,           // color bits ignored
		0,                          // no alpha buffer
		0,                          // shift bit ignored
		0,                          // no accumulation buffer
		0, 0, 0, 0,                 // accum bits ignored
		32,                         // 32-bit z-buffer
		0,                          // no stencil buffer
		0,                          // no auxiliary buffer
		PFD_MAIN_PLANE,				// main layer
		0,                          // reserved
		0, 0, 0                     // layer masks ignored
	};
	int pixelformat;

	if ( (pixelformat = ChoosePixelFormat(pDC->GetSafeHdc(), &pfd)) == 0 )
	{
		MessageBox("ChoosePixelFormat failed");
		return FALSE;
	}

	if (SetPixelFormat(pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		MessageBox("SetPixelFormat failed");
		return FALSE;
	}

	return TRUE;
}

unsigned char CBivariateView::ComponentFromIndex(int i, UINT nbits, UINT shift)
{
	unsigned char val;

	val = (unsigned char) (i >> shift);
	switch (nbits)
	{

	case 1:
		val &= 0x1;
		return oneto8[val];
	case 2:
		val &= 0x3;
		return twoto8[val];
	case 3:
		val &= 0x7;
		return threeto8[val];

	default:
		return 0;
	}
}


void CBivariateView::CreateRGBPalette(CDC *pDC)
{
	PIXELFORMATDESCRIPTOR pfd;
	LOGPALETTE *pPal;
	int n, i;

	n = ::GetPixelFormat(pDC->GetSafeHdc());
	::DescribePixelFormat(pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	if (pfd.dwFlags & PFD_NEED_PALETTE)
	{
		n = 1 << pfd.cColorBits;
		pPal = (PLOGPALETTE) new char[sizeof(LOGPALETTE) + n * sizeof(PALETTEENTRY)];

		ASSERT(pPal != NULL);

		pPal->palVersion = 0x300;
		pPal->palNumEntries = (unsigned short) n;
		for (i=0; i<n; i++)
		{
			pPal->palPalEntry[i].peRed =
					ComponentFromIndex(i, pfd.cRedBits, pfd.cRedShift);
			pPal->palPalEntry[i].peGreen =
					ComponentFromIndex(i, pfd.cGreenBits, pfd.cGreenShift);
			pPal->palPalEntry[i].peBlue =
					ComponentFromIndex(i, pfd.cBlueBits, pfd.cBlueShift);
			pPal->palPalEntry[i].peFlags = 0;
		}

		/* fix up the palette to include the default GDI palette */
		if ((pfd.cColorBits == 8)                           &&
			(pfd.cRedBits   == 3) && (pfd.cRedShift   == 0) &&
			(pfd.cGreenBits == 3) && (pfd.cGreenShift == 3) &&
			(pfd.cBlueBits  == 2) && (pfd.cBlueShift  == 6)
		   )
		{
			for (i = 1 ; i <= 12 ; i++)
				pPal->palPalEntry[defaultOverride[i]] = defaultPalEntry[i];
		}

		m_cPalette.CreatePalette(pPal);
		delete pPal;

		m_pOldPalette = pDC->SelectPalette(&m_cPalette, FALSE);
		pDC->RealizePalette();
	}
}

void CBivariateView::SetupGL()
{
	PIXELFORMATDESCRIPTOR pfd;
	int         n;

	CDC *pDC = GetDC();

	ASSERT(pDC != NULL);

	if (!bSetupPixelFormat(pDC))
		return;

	n = ::GetPixelFormat(pDC->GetSafeHdc());
	::DescribePixelFormat(pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	CreateRGBPalette(pDC);

	m_hrc = wglCreateContext(pDC->GetSafeHdc());
	wglMakeCurrent(pDC->GetSafeHdc(), m_hrc);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(2.0);

//	glEnable(GL_LIGHTING);
//	glEnable(GL_LINE_SMOOTH);
	ViewScene();
}

void CBivariateView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType,cx,cy);
	ViewScene();
}

void CBivariateView::ViewScene(void)
{
	wglMakeCurrent(GetDC()->GetSafeHdc(), m_hrc);

	glMatrixMode(GL_PROJECTION);
	CRect client;
	GetClientRect(client);
	glViewport(0, 0, client.right,client.bottom);
	glLoadIdentity();
	if(proj)
	{
		gluPerspective(45.0f,(float)client.right/(float)client.bottom,1.0f, 20.0f);
		glTranslatef(-1.0f,-1.0f,-3.0f);
		glRotatef(-60.0f,1.0f,.0f,.0f);
		glRotatef(30.0f,.0f,.0f,1.0f);
	}
	else
		glOrtho(0.0f,(float)client.right/128.0f,(float)client.bottom/128.0f,0.0f,-1.0f,1.0f);
 	glMatrixMode(GL_MODELVIEW);

	wglMakeCurrent(NULL,  NULL);
}

void CBivariateView::DrawScene(void)
{
	if (anim)
	{
		static GLfloat  wAngleZ = 0.0f;
		glTranslatef(2.00f,2.00f,0.00f);
		glRotatef(wAngleZ++,0.00f, 0.00f,1.00f);
		glTranslatef(-2.00f,-2.00f,0.00f);
	}

	if (Axis)
	{
		glPushAttrib(GL_LINE_BIT);
		glLineWidth(2.0f);
		glEnable(GL_LINE_SMOOTH);
		glBegin(GL_LINES);
			glColor3f(1.0f,0.0f,0.0f);glVertex3f(0.0f,0.0f,0.0f);glVertex3f(10.0f,0.0f,0.0f);
			glColor3f(0.0f,1.0f,0.0f);glVertex3f(0.0f,0.0f,0.0f);glVertex3f(0.0f,10.0f,0.0f);
			glColor3f(0.0f,0.0f,1.0f);glVertex3f(0.0f,0.0f,0.0f);glVertex3f(0.0f,0.0f,10.0f);
		glEnd();
		glPopAttrib();
	}

	if (DataMesh) 
		GetDocument()->data2.GL_RenderMesh((float)fabs(inv-1.0f),(float)fabs(inv-1.0f),(float)fabs(inv-1.0f));
	if (DataMPrz0)
		GetDocument()->data2.GL_RenderMeshProjection((float)fabs(inv-.2f),(float)fabs(inv-.3f),(float)fabs(inv-.4f));
	if (DataMPrz1)
		GetDocument()->data2.GL_RenderMeshProjection((float)fabs(inv-.4f),(float)fabs(inv-.3f),(float)fabs(inv-.2f),1.0f);
	if (DataPoints)
		GetDocument()->data2.GL_RenderPoints(1.0f,0.0f,0.0f);
	if (ifsReady)
		ifs.GL_Render();
}

void CBivariateView::OnActionBivariate() 
{
	double *a=new double[GetDocument()->data2.GetSize()];
	for(unsigned int i=0;i<GetDocument()->data2.GetSize();i++)	a[i]=0.5f;
	ifs.Interpolate(BIVARIATE,GetDocument()->data2,a);
	ifsReady=!ifsReady;
	Invalidate();	
}

void CBivariateView::OnUpdateActionsBivariate(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(ifsReady);}
void CBivariateView::OnActionsDet()	
	{ifs.SetAlgorithm(DETERMINISTIC);Invalidate();}
void CBivariateView::OnActionsRnd()
	{ifs.SetAlgorithm(RNDITERATIONS);Invalidate();}
void CBivariateView::OnUpdateActionsDet(CCmdUI* pCmdUI)
	{pCmdUI->SetRadio(ifs.GetAlgorithm()==DETERMINISTIC);}
void CBivariateView::OnUpdateActionsRnd(CCmdUI* pCmdUI)
	{pCmdUI->SetRadio(ifs.GetAlgorithm()==RNDITERATIONS);}
void CBivariateView::OnAttractorMesh() 
	{ifs.SetRenderType(MESH);Invalidate();}
void CBivariateView::OnUpdateAttractorMesh(CCmdUI* pCmdUI) 
	{pCmdUI->SetRadio(ifs.GetRenderType()==MESH);}

void CBivariateView::OnAttractorPoints() 
	{ifs.SetRenderType(CLOUD);Invalidate();}
void CBivariateView::OnUpdateAttractorPoints(CCmdUI* pCmdUI) 
	{pCmdUI->SetRadio(ifs.GetRenderType()==CLOUD);}

void CBivariateView::OnAttractorSolid() 
	{ifs.SetRenderType(SOLID);Invalidate();}
void CBivariateView::OnUpdateAttractorSolid(CCmdUI* pCmdUI) 
	{pCmdUI->SetRadio(ifs.GetRenderType()==SOLID);}

void CBivariateView::OnViewAxis() 
	{Axis = !Axis;Invalidate(!Axis);}
void CBivariateView::OnUpdateViewAxis(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(Axis);}
void CBivariateView::OnViewDatamesh()
	{DataMesh = !DataMesh;Invalidate(!DataMesh);}
void CBivariateView::OnUpdateViewDatamesh(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(DataMesh);}
void CBivariateView::OnViewDatapoints()
	{DataPoints = !DataPoints;Invalidate(!DataPoints);}
void CBivariateView::OnUpdateViewDatapoints(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(DataPoints);}
void CBivariateView::OnViewLowergrid() 
	{DataMPrz0 = !DataMPrz0;Invalidate(!DataMPrz0);}
void CBivariateView::OnUpdateViewLowergrid(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(DataMPrz0);}
void CBivariateView::OnViewUpergrid() 
	{DataMPrz1 = !DataMPrz1;Invalidate(!DataMPrz1);}
void CBivariateView::OnUpdateViewUpergrid(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(DataMPrz1);}
void CBivariateView::OnColorInvert() 
	{inv = !inv;Invalidate();}
void CBivariateView::OnUpdateColorInvert(CCmdUI* pCmdUI) 
	{pCmdUI->SetCheck(inv);}


void CBivariateView::OnMiscStatistics() 
	{stat=!stat;}
void CBivariateView::OnUpdateMiscStatistics(CCmdUI* pCmdUI) 
	{pCmdUI->Enable(!anim);pCmdUI->SetCheck(stat);}
void CBivariateView::OnViewOrthographic() 
	{proj=false;ViewScene();Invalidate();}
void CBivariateView::OnUpdateViewOrthographic(CCmdUI* pCmdUI) 
	{pCmdUI->Enable(!anim);pCmdUI->SetRadio(!proj);}
void CBivariateView::OnViewPerspective() 
	{proj=true;ViewScene();Invalidate();}
void CBivariateView::OnUpdateViewPerspective(CCmdUI* pCmdUI) 
	{pCmdUI->Enable(!anim);pCmdUI->SetRadio(proj);}

void CBivariateView::OnUpdateMiscAnimate(CCmdUI* pCmdUI) 
	{pCmdUI->Enable(proj&&!stat);pCmdUI->SetCheck(anim);}

void CBivariateView::OnActionsOptions() 
{
	DLGalgoptions dlg;

	ifs.GetIterations(dlg.m_detiter,dlg.m_rnditer);
	if (dlg.DoModal()==IDOK)
	{
		ifs.SetIterations(dlg.m_detiter,dlg.m_rnditer);
		Invalidate();
	}
}

void CBivariateView::OnMiscAnimate() 
{
	anim=!anim;
	if (anim)	SetTimer(13,40,NULL);
	else		KillTimer(13);
}

void CBivariateView::OnTimer(UINT nIDEvent) 
{
	static BOOL     bBusy = FALSE;
	static int		msec=40;
	
	if(nIDEvent==13)
	{
		if(bBusy){
			KillTimer(13);msec+=5;SetTimer(13,msec,NULL);
			return;
		}
		else{
			KillTimer(13);msec-=2;SetTimer(13,msec,NULL);
			bBusy = TRUE;OnDraw(GetDC());bBusy = FALSE;
		}
	}

}

void CBivariateView::OnFractalDataset() 
{
	QueryPSet3D Dlg(&(GetDocument()->data2));
	Dlg.DoModal();
	double *a=new double[GetDocument()->data2.GetSize()];
	for(unsigned int i=0;i<GetDocument()->data2.GetSize();i++)
		a[i]=0.5f;
	ifs.Interpolate(BIVARIATE,GetDocument()->data2,a);
	Invalidate();
}
