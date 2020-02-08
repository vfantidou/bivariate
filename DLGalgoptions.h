#if !defined(AFX_DLGALGOPTIONS_H__2EB14C4E_100F_4CD2_9095_54744CC2DEF5__INCLUDED_)
#define AFX_DLGALGOPTIONS_H__2EB14C4E_100F_4CD2_9095_54744CC2DEF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGalgoptions.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLGalgoptions dialog

class DLGalgoptions : public CDialog
{
// Construction
public:
	DLGalgoptions(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DLGalgoptions)
	enum { IDD = IDD_ALGOPTIONS };
	UINT	m_detiter;
	UINT	m_rnditer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLGalgoptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLGalgoptions)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGALGOPTIONS_H__2EB14C4E_100F_4CD2_9095_54744CC2DEF5__INCLUDED_)
