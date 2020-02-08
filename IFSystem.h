// IFSystem.h: interface for the IFSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IFSYSTEM_H__CD731731_1DED_4ECE_8E22_C7F2BB0EFAB1__INCLUDED_)
#define AFX_IFSYSTEM_H__CD731731_1DED_4ECE_8E22_C7F2BB0EFAB1__INCLUDED_
#include "IFS.h"
#include "Point.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class GeneralIFS:public CIFS
{

public:
	GeneralIFS(){};
	virtual ~GeneralIFS(){};
};

class InterpIFS:public CIFS
{

DataSet_2d *PSet2d;
DataSet_3d *PSet3d;
ScalarArray	*scales;

public:
	InterpIFS()	{if (_cmap) delete _cmap; _cmap = new CContractionInterpMap();}
	virtual ~InterpIFS(){};
};

#endif // !defined(AFX_IFSYSTEM_H__CD731731_1DED_4ECE_8E22_C7F2BB0EFAB1__INCLUDED_)
