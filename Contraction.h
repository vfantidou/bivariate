// Contraction.h: interface for the CContraction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTRACTION_H__40562357_D014_4692_826E_9F07E06A324B__INCLUDED_)
#define AFX_CONTRACTION_H__40562357_D014_4692_826E_9F07E06A324B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point.h"
#include "Function.h"

class CContraction : public CFunction
{
public:
	CContraction(){};
	virtual ~CContraction(){};
	//contract a 2dimensional point
	virtual Point_2d operator()(Point_2d &P) const =0;
	//contract a 3dimensional point
	virtual Point_3d operator()(Point_3d &P) const =0;
	//contract a 3dimensional point Set
	virtual void operator()(Point_3d *set,unsigned int setsize)
		{for(register unsigned int i=0;i<setsize;(*this)(set[i++]));}
	//contract a 2dimensional point Set
	virtual void operator()(Point_2d *set,unsigned int setsize)
		{for(register unsigned int i=0;i<setsize;(*this)(set[i++]));}

	//setup contraction from parameters
	virtual void SetUp_fromParameters(void *parameters)=0;
	//setup contraction from combination of 2 contractions 
	virtual void SetUp_fromCombination(const CContraction *w1,const CContraction *w2)=0;
	//get the energy of contraction
	virtual double GetEnergy(void) const=0;
	//create a dlg to manipulate parameters from.
//	virtual QueryContraction *BindDlg(CWnd* pParent = NULL);

};

#endif // !defined(AFX_CONTRACTION_H__40562357_D014_4692_826E_9F07E06A324B__INCLUDED_)
