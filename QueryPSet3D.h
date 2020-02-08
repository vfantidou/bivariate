#if !defined(AFX_QUERYPSET3D_H__F201386E_7CAC_4AE1_8898_8A528B8EA4C3__INCLUDED_)
#define AFX_QUERYPSET3D_H__F201386E_7CAC_4AE1_8898_8A528B8EA4C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryPSet3D.h : header file
//
#include "Point.h"

/////////////////////////////////////////////////////////////////////////////
// QueryPSet3D dialog

class QueryPSet3D : public CDialog
{
private:
	int DataSetImage(void);
	int SelectionUpdate(double value);
	int SelectionChanged(void);
	void AddPoint2List(const Point_3d &p,int nSel = -1);
// Construction
public:
	QueryPSet3D(DataSet_3d *pset,CWnd* pParent = NULL);
	DataSet_3d *_pset;
// Dialog Data
	//{{AFX_DATA(QueryPSet3D)
	enum { IDD = IDD_PSET3D };
	CEdit	_zedit;
	CStatic		_preview;
	CSliderCtrl	_zslide;
	CTabCtrl	_gltab;
	CButton		_ButtonSet;
	CListBox	_plist;
	double		_z;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(QueryPSet3D)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(QueryPSet3D)
	afx_msg void OnSet();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangePlist();
	afx_msg void OnOptions();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYPSET3D_H__F201386E_7CAC_4AE1_8898_8A528B8EA4C3__INCLUDED_)
