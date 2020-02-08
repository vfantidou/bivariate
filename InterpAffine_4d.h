// InterpAffine_4d.h: interface for the InterpAffine_4d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERPAFFINE_4D_H__CE4ED514_C0B3_49F0_BAA6_03991D0EF732__INCLUDED_)
#define AFX_INTERPAFFINE_4D_H__CE4ED514_C0B3_49F0_BAA6_03991D0EF732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "Contraction.h"

class InterpAffine_4d : public CContraction   
{
public:
	InterpAffine_4d(double a=1.000,double b=0.000,double c=1.000,
					double d=0.000,double e=0.000,double f=0.000,
					double g=0.000,double s=1.000,double k=0.000);
	virtual ~InterpAffine_4d();
	virtual Point_2d operator()(Point_2d &P) const;
	//contract a 3dimensional point
	virtual Point_3d operator()(Point_3d &P) const;
	//setup contraction from parameters
	virtual void SetUp_fromParameters(void *parameters);
	//setup contraction from combination of 2 contractions 
	virtual void SetUp_fromCombination(const CContraction *w1,const CContraction *w2);
	//get the energy of contraction
	virtual double GetEnergy(void) const;
	//setup contraction from interpolation data set (x,y,f(x,y))
	void SetUp_fromDataSet(	
	/*P0,0*/	const Point_3d &P00,
	/*PN,0*/	const Point_3d &PN0,
	/*P0,M*/	const Point_3d &P0M,
	/*PN,M*/	const Point_3d &PNM,
	/*Pi,j*/	const Point_3d &Pij,
	/*Pi+1,j*/	const Point_3d &Pippj,
	/*Pi,j+1*/	const Point_3d &Pijpp,
	/*Pi+1,j+1*/const Point_3d &Pippjpp,
	/*scale s*/	double scale	= 1.000);
protected:
	double _a,          _b;	//[a  0  0  0] [x]  [b]
	double _c,          _d;	//[0  c  0  0]*[y] +[d]
	/*hidden variable*/		//[ad cb ac 0] [xy] [bd]
	double _e,_f,_g,_s, _k;	//[e  f  g  s] [z]  [k]
	//s vertical scale factor, a free parameter.
	
};

#endif // !defined(AFX_INTERPAFFINE_4D_H__CE4ED514_C0B3_49F0_BAA6_03991D0EF732__INCLUDED_)
