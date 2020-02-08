// bivariateDoc.h : interface of the CBivariateDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIVARIATEDOC_H__9DDD6FA6_D3B4_4A22_9DC1_2C5945327A40__INCLUDED_)
#define AFX_BIVARIATEDOC_H__9DDD6FA6_D3B4_4A22_9DC1_2C5945327A40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Point.h"

class CBivariateDoc : public CDocument
{
protected: // create from serialization only
	CBivariateDoc();
	DECLARE_DYNCREATE(CBivariateDoc)

// Attributes
public:
	DataSet_3d data1,data2;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBivariateDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBivariateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBivariateDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIVARIATEDOC_H__9DDD6FA6_D3B4_4A22_9DC1_2C5945327A40__INCLUDED_)
