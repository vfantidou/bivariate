// bivariateView.h : interface of the CBivariateView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIVARIATEVIEW_H__A3711C95_81DF_4BD0_BF09_62C5CF76FFBC__INCLUDED_)
#define AFX_BIVARIATEVIEW_H__A3711C95_81DF_4BD0_BF09_62C5CF76FFBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "bivariateDoc.h"
#include "IFS.h"


class CBivariateView : public CView
{
protected: // create from serialization only
	CBivariateView();
	DECLARE_DYNCREATE(CBivariateView)

// Attributes
public:
	CBivariateDoc* GetDocument();
	CPalette    m_cPalette;
	CPalette    *m_pOldPalette;

	HGLRC       m_hrc;

	CIFS		ifs;

	BOOL		ifsReady,anim;
	BOOL		proj,stat,inv,DataPoints,DataMesh,DataMPrz0,DataMPrz1,Axis;

private:
	void SetupGL(void);
	void CreateRGBPalette(CDC *pDC);
	BOOL bSetupPixelFormat(CDC *pDC);
	unsigned char ComponentFromIndex(int i, UINT nbits, UINT shift);
	void DrawScene(void);
	void ViewScene(void);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBivariateView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBivariateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBivariateView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnActionBivariate();
	afx_msg void OnActionsDet();
	afx_msg void OnUpdateActionsDet(CCmdUI* pCmdUI);
	afx_msg void OnActionsRnd();
	afx_msg void OnUpdateActionsRnd(CCmdUI* pCmdUI);
	afx_msg void OnViewAxis();
	afx_msg void OnUpdateViewAxis(CCmdUI* pCmdUI);
	afx_msg void OnViewDatamesh();
	afx_msg void OnUpdateViewDatamesh(CCmdUI* pCmdUI);
	afx_msg void OnViewDatapoints();
	afx_msg void OnUpdateViewDatapoints(CCmdUI* pCmdUI);
	afx_msg void OnViewLowergrid();
	afx_msg void OnUpdateViewLowergrid(CCmdUI* pCmdUI);
	afx_msg void OnViewUpergrid();
	afx_msg void OnUpdateViewUpergrid(CCmdUI* pCmdUI);
	afx_msg void OnColorInvert();
	afx_msg void OnUpdateColorInvert(CCmdUI* pCmdUI);
	afx_msg void OnAttractorMesh();
	afx_msg void OnUpdateAttractorMesh(CCmdUI* pCmdUI);
	afx_msg void OnAttractorPoints();
	afx_msg void OnUpdateAttractorPoints(CCmdUI* pCmdUI);
	afx_msg void OnAttractorSolid();
	afx_msg void OnUpdateAttractorSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateActionsBivariate(CCmdUI* pCmdUI);
	afx_msg void OnMiscStatistics();
	afx_msg void OnUpdateMiscStatistics(CCmdUI* pCmdUI);
	afx_msg void OnActionsOptions();
	afx_msg void OnViewOrthographic();
	afx_msg void OnUpdateViewOrthographic(CCmdUI* pCmdUI);
	afx_msg void OnViewPerspective();
	afx_msg void OnUpdateViewPerspective(CCmdUI* pCmdUI);
	afx_msg void OnMiscAnimate();
	afx_msg void OnUpdateMiscAnimate(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFractalDataset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in bivariateView.cpp
inline CBivariateDoc* CBivariateView::GetDocument()
   { return (CBivariateDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIVARIATEVIEW_H__A3711C95_81DF_4BD0_BF09_62C5CF76FFBC__INCLUDED_)
