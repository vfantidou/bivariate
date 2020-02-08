// IFS.h: interface for the CIFS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IFS_H__36AC33BA_6E05_4E10_8358_37BEDBF56A31__INCLUDED_)
#define AFX_IFS_H__36AC33BA_6E05_4E10_8358_37BEDBF56A31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "InterpAffine_4d.h"

typedef enum {CONTR,AFF2D,AFF3D,AFF4D,GRID2D,GRID3D,IAFF2D,IAFF4D,INL2D} CNTRENUM;
typedef enum {INTERP,BIVARIATE} INTERPENUM;

typedef enum {NONE,RNDITERATIONS,DETERMINISTIC} ALGORITHM;
typedef enum {	CLOUD=GL_POINTS,
				MESH=GL_LINE_LOOP,
				SOLID=GL_POLYGON,
				SOLID3=GL_TRIANGLES,
				SOLID4=GL_QUADS} RENDERENUM;
typedef enum {MONO,HMAP,LIGHT}	COLORENUM;

typedef Varray < CContraction * > CntrMap;

class Attractor_3d
{
	friend class CIFS;

private:
	PointArray_3d	vertices;
	uint			iterations;
	uint			setsize;
	int				ready;

public:

	Attractor_3d();
	~Attractor_3d();

	uint Attract(PointArray_3d &set,const CntrMap &w,uint iterations);
	uint Attract(PointArray_3d &set,const CntrMap &w,uint n,uint m,uint iterations);

	void GL_Render_3DColor(int GL_Flags,float r,float g,float b);
	void GL_Render_2DColor(int GL_Flags,float r,float g,float b);
	void GL_Render_3DMono (int GL_Flags,float r,float g,float b);
	void GL_Render_2DMono (int GL_Flags,float r,float g,float b);
};


class CIFS  
	{
	private:
//Ifs Data
		CntrMap			_cntr;		//the contraction Map
		PointArray_3d	_initset;	//the initial set
		Attractor_3d	_attr3d;	//the 3d attractor	
//Ifs Settings
		ALGORITHM		_algorithm;
		uint			_rndIter,_detIter;
//Ifs Render Settings
		Point_3d		_color;
		RENDERENUM		_rType;
		COLORENUM		_cType;
//Ifs dirty bit
		bool			_settings_changed;
		
	public:
		CIFS();
		virtual ~CIFS();
		void Invalidate(void) {_settings_changed = true;}
		void Validate(void)	  {_settings_changed = false;}
		
		//settings functions.
		//attractor
		void SetInit(PointArray_3d &set)
		{_initset.Set(&set,set.getSize());Invalidate();_attr3d.ready=false;}
		void SetIterations(uint detIter = 1,uint rndIter = 1000)
		{_detIter=detIter;_rndIter=rndIter;Invalidate();_attr3d.ready=false;}
		//misceleneus
		void SetRGBColor(double r=0.0f,double g=0.0f,double b=0.0f){_color.set(r,g,b);Invalidate();}
		void SetColorType(COLORENUM cType = MONO)	{_cType=cType;Invalidate();}
		void SetRenderType(RENDERENUM rType = MESH)	{_rType=rType;Invalidate();}
		void SetAlgorithm(ALGORITHM algorthm = NONE){_algorithm=algorthm;Invalidate();}
		
		void GetRGBColor(double &r,double &g,double &b)const{_color.get(r,g,b);}
		void GetIterations(uint &detIter,uint &rndIter)const{detIter=_detIter;rndIter=_rndIter;}
		COLORENUM  GetColorType(void)const	{return _cType;}
		RENDERENUM GetRenderType(void)const	{return _rType;}
		ALGORITHM  GetAlgorithm(void)const	{return _algorithm;}
		//destruction function
		void Clear(int keepbuffers=1);
		bool isClean(void) {return !_settings_changed;}
									
		//creation function
		int Interpolate(INTERPENUM itype,const DataSet_3d &PSet,const double *scales);
//		int Interpolate(INTERPENUM itype,const DataSet_2d &PSet,const double *scales){return 0;};
		//render functions
		int GL_Render(void)
		{
			if (_algorithm==DETERMINISTIC) return Deterministic();
			if (_algorithm==RNDITERATIONS) return RndIterations();
			return 0;
		}
		int Deterministic();
		int RndIterations();


	public:

/*		CDialog *BindDlgParameters(CWnd* pParent=NULL)				{return 0;};
		CDialog *BindDlgInterpolationParameters(CWnd* pParent=NULL)	{return 0;};
		CDialog *BindDlgOptions(CWnd* pParent=NULL)					{return 0;}; */
	};

#endif // !defined(AFX_IFS_H__36AC33BA_6E05_4E10_8358_37BEDBF56A31__INCLUDED_)
