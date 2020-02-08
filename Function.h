// Function.h: interface for the CFunction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUNCTION_H__7A5C8BC2_ACC5_4E5A_8DAC_81BF6161585D__INCLUDED_)
#define AFX_FUNCTION_H__7A5C8BC2_ACC5_4E5A_8DAC_81BF6161585D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Point.h"
class CFunction  
{
public:
	CFunction(){};
	virtual ~CFunction(){};
	virtual double		operator()(double arg)	 const{return arg;};
	virtual Point_2d	operator()(Point_2d &arg)const{return arg;};
	virtual Point_3d	operator()(Point_3d &arg)const{return arg;};
};

#endif // !defined(AFX_FUNCTION_H__7A5C8BC2_ACC5_4E5A_8DAC_81BF6161585D__INCLUDED_)
