// bivariate.h : main header file for the BIVARIATE application
//

#if !defined(AFX_BIVARIATE_H__FA891034_FBB4_4FA2_A08A_26BEB875C6E4__INCLUDED_)
#define AFX_BIVARIATE_H__FA891034_FBB4_4FA2_A08A_26BEB875C6E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBivariateApp:
// See bivariate.cpp for the implementation of this class
//

class CBivariateApp : public CWinApp
{
public:
	CBivariateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBivariateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBivariateApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIVARIATE_H__FA891034_FBB4_4FA2_A08A_26BEB875C6E4__INCLUDED_)
