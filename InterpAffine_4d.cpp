// InterpAffine_4d.cpp: implementation of the InterpAffine_4d class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InterpAffine_4d.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

InterpAffine_4d::InterpAffine_4d(double a,double b,double c,
								 double d,double e,double f,
								 double g,double s,double k)
{_a=a;_b=b;_c=c;_d=d;_f=f;_g=g;_e=e;_s=s;_k=k;}

InterpAffine_4d::~InterpAffine_4d()
{}

Point_2d InterpAffine_4d::operator()(register Point_2d &P) const
{
	P.x*=_a;
	P.x+=_b;
	P.y*=_c;
	P.y+=_d;
	return P;
}
Point_3d InterpAffine_4d::operator()(register Point_3d &P) const
{
	P.z*=_s;
	P.z+=_e * P.x + _f * P.y + _g * P.x*P.y + _k;
	P.x*=_a;
	P.x+=_b;
	P.y*=_c;
	P.y+=_d;
	return P;
}

//setup contraction from parameters
void InterpAffine_4d::SetUp_fromParameters(void *parameters)
{
	_a=((double *)parameters)[0];
	_b=((double *)parameters)[1];
	_c=((double *)parameters)[2];
	_d=((double *)parameters)[3];
	_e=((double *)parameters)[4];
	_f=((double *)parameters)[5];
	_g=((double *)parameters)[6];
	_s=((double *)parameters)[7];
	_k=((double *)parameters)[8];
}
//setup contraction from combination of 2 contractions 
void InterpAffine_4d::SetUp_fromCombination(const CContraction *w1,const CContraction *w2)
{
	InterpAffine_4d *c1 = (InterpAffine_4d *)w1;
	InterpAffine_4d *c2 = (InterpAffine_4d *)w2;
	_a= c2->_a*c1->_a;
	_b= c2->_a*c1->_b + c2->_b;
	_c= c2->_c*c1->_c;
	_d= c2->_c*c1->_d + c2->_d;
	_e= (c2->_e + c2->_g*c1->_d)*c1->_a + c2->_s*c1->_e;
	_f= (c2->_f + c2->_g*c1->_b)*c1->_c + c2->_s*c1->_f;
	_g= c2->_g*c1->_a*c1->_c + c2->_s*c1->_g;
	_s= c2->_s*c1->_s;
	_k= c2->_e*c1->_b + c2->_f*c1->_d + c2->_g*c1->_b*c1->_d + c2->_s*c1->_k;  
}
//setup contraction from interpolation data set (x,y,f(x,y))
void InterpAffine_4d::SetUp_fromDataSet(	
				const Point_3d &P00,const Point_3d &PN0,
				const Point_3d &P0M,const Point_3d &PNM,
				const Point_3d &Pij,const Point_3d &Pippj,
				const Point_3d &Pijpp,const Point_3d &Pippjpp,
				double scale)
{
	double dX = P00.x - PNM.x;
	double dY = P00.y - PNM.y;
	_a= (Pij.x - Pippjpp.x)/dX;
	_b= (Pippjpp.x*P00.x - Pij.x*PNM.x)/dX;
	_c= (Pij.y - Pippjpp.y)/dY;
	_d= (Pippjpp.y*P00.y - Pij.y*PNM.y)/dY;
	_s= scale;
	_g= ((Pij.z-Pijpp.z-Pippj.z+Pippjpp.z)-_s*(P00.z-P0M.z-PN0.z+PNM.z))/
			(P00.x*P00.y-P0M.x*P0M.y-PN0.x*PN0.y+PNM.x*PNM.y);
	_e= (Pij.z-Pippj.z-_s*(P00.z-PN0.z)-_g*(P00.x*P00.y-PN0.x*PN0.y))/dX;
	_f= (Pij.z-Pijpp.z-_s*(P00.z-P0M.z)-_g*(P00.x*P00.y-P0M.x*P0M.y))/dY;
	_k= Pippjpp.z - _e*PNM.x - _f*PNM.y -_s*PNM.z - _g*PNM.x*PNM.y;
}
//get the energy of contraction
double InterpAffine_4d::GetEnergy(void) const
{
	return (_a*_c)*(_a*_c)*_s;
}
