// Point.h: interface for the Point_2d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT_H__1E8AC8D7_7556_4678_9D55_8AF45CE34C09__INCLUDED_)
#define AFX_POINT_H__1E8AC8D7_7556_4678_9D55_8AF45CE34C09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <math.h>
#include "Varray.h"
#include "gl\gl.h"
#include "gl\glu.h"

class Point_2d;
class Point_3d;

class Point_2d  
{
public:
	double x,y;
	Point_2d(double xx=0.000f,double yy=0.000f)
		{x=xx;y=yy;};
	Point_2d(const Point_2d & p)
		{x=p.x;y=p.y;};
	Point_2d(const Point_3d & p);
	~Point_2d(){};
	void set(double xx=0.000f,double yy=0.000f)	{x=xx;y=yy;};
	void get(double &xx,double &yy)				{xx=x;yy=y;};
	Point_2d &operator=(const Point_2d &P)
		{x=P.x;y=P.y;return *this;};
	Point_2d &operator+=(const Point_2d &P)
		{x+=P.x;y+=P.y;return *this;};
	Point_2d operator+(const Point_2d &P)const
		{return Point_2d(x+P.x,y+P.y);};
	Point_2d &operator-=(const Point_2d &P)
		{x-=P.x;y-=P.y;return *this;};
	Point_2d operator-(const Point_2d &P)const
		{return Point_2d(x-P.x,y-P.y);};
	Point_2d &operator*=(double scalar)
		{x*=scalar;y*=scalar;return *this;};
	Point_2d operator*(double scalar)const
		{return Point_2d(x*scalar,y*scalar);};
	Point_2d &operator/=(double scalar)
		{x/=scalar;y/=scalar;return *this;};
	Point_2d operator/(double scalar)const
		{return Point_2d(x/scalar,y/scalar);};
	Point_2d &operator*=(const Point_2d &scalar)//dot
		{x*=scalar.x;y*=scalar.y;return *this;};
	Point_2d &operator/=(const Point_2d &scalar)//dot
		{x/=scalar.x;y/=scalar.y;return *this;};
	double operator*(Point_2d p)const
		{return x*p.x+y*p.y;};
	double norm1(void)
		{return x+y;};
	double norm2(void)
		{return sqrt(x*x+y*y);};
	double colapse(char axis = 'y')const;
	Point_3d raise(char axis = 'z',double q=0.000f)const;
	
	void GL2D(void){glVertex2d(x,y);}
	void GL2D(float r,float g,float b){glColor3f(r,g,b);glVertex2d(x,y);}

};

class Point_3d  
{
public:
	double x,y,z;
	Point_3d(double xx=0.000f,double yy=0.000f,double zz=0.000f)
			{x=xx;y=yy;z=zz;};
	Point_3d(const Point_3d & p)
		{x=p.x;y=p.y;z=p.z;};
	Point_3d(const Point_2d & p)
		{x=p.x;y=p.y;z=0.000f;};
	~Point_3d(){};
	void set(double xx=0.000f,double yy=0.000f,double zz=0.000f){x=xx;y=yy;z=zz;};
	void get(double &xx,double &yy,double &zz)	const			{xx=x;yy=y;zz=z;};

	Point_3d &operator=(const Point_3d &P)
		{x=P.x;y=P.y;z=P.z;return *this;};
	Point_3d &operator+=(const Point_3d &P)
		{x+=P.x;y+=P.y;z+=P.z;return *this;};
	Point_3d operator+(const Point_3d &P) const
		{return Point_3d(x+P.x,y+P.y,z+P.z);};
	Point_3d &operator-=(const Point_3d &P)
		{x-=P.x;y-=P.y;z-=P.z;return *this;};
	Point_3d operator-(const Point_3d &P) const
		{return Point_3d(x-P.x,y-P.y,z-P.z);};
	Point_3d &operator*=(double scalar)
		{x*=scalar;y*=scalar;z*=scalar;return *this;};
	Point_3d operator*(double scalar) const
		{return Point_3d(x*scalar,y*scalar,z*scalar);};
	Point_3d &operator/=(double scalar)
		{x/=scalar;y/=scalar;z/=scalar;return *this;};
	Point_3d operator/(double scalar) const
		{return Point_3d(x/scalar,y/scalar,z/scalar);};
	Point_3d &operator*=(const Point_3d &scalar)//dot
		{x*=scalar.x;y*=scalar.y;z*=scalar.z;return *this;};
	Point_3d &operator/=(const Point_3d &scalar)//dot
		{x/=scalar.x;y/=scalar.y;z/=scalar.z;return *this;};
	double operator*(Point_3d p)const
		{return x*p.x+y*p.y+z*p.z;};
	double norm1(void)
		{return x+y+z;};
	double norm2(void)
		{return sqrt(x*x+y*y+z*z);};

	Point_2d colapse(char axis = 'z')const;

	void GL3D(void)		{glVertex3d(x,y,z);}
	void GL2D(void)		{glVertex2d(x,y);}
	void GL2D(double nz){glVertex3d(x,y,nz);}

	void GL3D_ZCLR(float r=0.0f,float g=0.0f,float b=0.0f)
		{glColor3d(r+z,g+z,b+z);glVertex3d(x,y,z);}
	void GL2D_ZCLR(float r=0.0f,float g=0.0f,float b=0.0f)
		{glColor3d(r+z,g+z,b+z);glVertex2d(x,y);}
	void GL2D_ZCLR(double nz,float r=0.0f,float g=0.0f,float b=0.0f)
		{glColor3d(r+z,g+z,b+z);glVertex3d(x,y,nz);}

	void GL3D_XYZCLR(float r=0.0f,float g=0.0f,float b=0.0f)
		{glColor3d(r+x,g+y,b+z);glVertex3d(x,y,z);}
	void GL2D_XYZCLR(float r=0.0f,float g=0.0f,float b=0.0f)
		{glColor3d(r+x,g+y,b+z);glVertex2d(x,y);}
	void GL2D_XYZCLR(double nz,float r=0.0f,float g=0.0f,float b=0.0f)
		{glColor3d(r+x,g+y,b+z);glVertex3d(x,y,nz);}


};

inline double Point_2d::colapse(char axis)const
{switch (axis){case 'x': return y;	case 'y': default: return x;};}

inline Point_3d Point_2d::raise(char axis,double q)const
{
	switch (axis)
	{
		case 'x': return Point_3d(q,x,y);
		case 'y': return Point_3d(x,q,y);
		case 'z':default: return Point_3d(x,y,q);
	};
}
inline	Point_2d Point_3d::colapse(char axis)const
{
	switch (axis)
	{
		case 'x': return Point_2d(y,z);
		case 'y': return Point_2d(x,z);
		case 'z':default: return Point_2d(x,y);
	};
}

inline double dist1(double p1,double p2){return fabs(p1-p2);}
inline double dist2(double p1,double p2){return dist1(p1,p2);}
inline double dist1(const Point_2d &p1,const Point_2d &p2){return fabs(p1.x-p2.x)+fabs(p1.y-p2.y);}
inline double dist2(const Point_2d &p1,const Point_2d &p2){return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));}
inline double dist1(const Point_3d &p1,const Point_3d &p2){return fabs(p1.x-p2.x)+fabs(p1.y-p2.y)+fabs(p1.z-p2.z);}
inline double dist2(const Point_3d &p1,const Point_3d &p2){return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));}

inline double det(const Point_2d &p1,const Point_2d &p2,const Point_2d &p3)
{
	return (p1.y+p3.y)*(p3.x-p1.x)-(p1.y+p2.y)*(p2.x-p1.x)-(p2.y+p3.y)*(p3.x-p2.x);
}

inline double det(const Point_3d &p1,const Point_3d &p2,const Point_3d &p3,const Point_3d &p4)
{
	return 	(p2.x-p1.x)*((p3.y-p1.y)*(p3.z-p1.z)-(p4.y-p1.y)*(p4.z-p1.z))-
			(p3.x-p1.x)*((p2.y-p1.y)*(p2.z-p1.z)-(p4.y-p1.y)*(p4.z-p1.z))+
			(p4.x-p1.x)*((p2.y-p1.y)*(p2.z-p1.z)-(p3.y-p1.y)*(p3.z-p1.z));
}

inline int comp(const void *p1,const void *p2)
{
	if		( *((double *)p1)>*((double *)p2))	return -1;
	else if ( *((double *)p1)<*((double *)p2))	return  1;
	else				return  0;
}

inline int compXY(const void *p1,const void *p2)
{
	if		(((Point_2d *)p1)->x>((Point_2d *)p2)->x)	return -1;
	else if (((Point_2d *)p1)->x<((Point_2d *)p2)->x)	return  1;
	else if (((Point_2d *)p1)->y>((Point_2d *)p2)->y)	return -1;
	else if (((Point_2d *)p1)->y<((Point_2d *)p2)->y)	return  1;
	else				return  0;
}

inline int compYX(const void *p1,const void *p2)
{
	if		(((Point_2d *)p1)->y>((Point_2d *)p2)->y)	return -1;
	else if (((Point_2d *)p1)->y<((Point_2d *)p2)->y)	return  1;
	else if (((Point_2d *)p1)->x>((Point_2d *)p2)->x)	return -1;
	else if (((Point_2d *)p1)->x<((Point_2d *)p2)->x)	return  1;
	else				return  0;
}

inline int compXYZ(const void *p1,const void *p2)
{
	if		(((Point_3d *)p1)->x>((Point_3d *)p2)->x)	return -1;
	else if (((Point_3d *)p1)->x<((Point_3d *)p2)->x)	return  1;
	else if (((Point_3d *)p1)->y>((Point_3d *)p2)->y)	return -1;
	else if (((Point_3d *)p1)->y<((Point_3d *)p2)->y)	return  1;
	else if (((Point_3d *)p1)->z>((Point_3d *)p2)->z)	return -1;
	else if (((Point_3d *)p1)->z<((Point_3d *)p2)->z)	return  1;
	else				return  0;

}
inline int compXZY(const void *p1,const void *p2)
{
	if		(((Point_3d *)p1)->x>((Point_3d *)p2)->x)	return -1;
	else if (((Point_3d *)p1)->x<((Point_3d *)p2)->x)	return  1;
	else if (((Point_3d *)p1)->z>((Point_3d *)p2)->z)	return -1;
	else if (((Point_3d *)p1)->z<((Point_3d *)p2)->z)	return  1;
	else if (((Point_3d *)p1)->y>((Point_3d *)p2)->y)	return -1;
	else if (((Point_3d *)p1)->y<((Point_3d *)p2)->y)	return  1;
	else				return  0;

}

inline int compYZX(const void *p1,const void *p2)
{
	if		(((Point_3d *)p1)->y>((Point_3d *)p2)->y)	return -1;
	else if (((Point_3d *)p1)->y<((Point_3d *)p2)->y)	return  1;
	else if (((Point_3d *)p1)->z>((Point_3d *)p2)->z)	return -1;
	else if (((Point_3d *)p1)->z<((Point_3d *)p2)->z)	return  1;
	else if (((Point_3d *)p1)->x>((Point_3d *)p2)->x)	return -1;
	else if (((Point_3d *)p1)->x<((Point_3d *)p2)->x)	return  1;
	else				return  0;
}
inline int compYXZ(const void *p1,const void *p2)
{
	if		(((Point_3d *)p1)->y>((Point_3d *)p2)->y)	return -1;
	else if (((Point_3d *)p1)->y<((Point_3d *)p2)->y)	return  1;
	else if (((Point_3d *)p1)->x>((Point_3d *)p2)->x)	return -1;
	else if (((Point_3d *)p1)->x<((Point_3d *)p2)->x)	return  1;
	else if (((Point_3d *)p1)->z>((Point_3d *)p2)->z)	return -1;
	else if (((Point_3d *)p1)->z<((Point_3d *)p2)->z)	return  1;
	else				return  0;
}
inline int compZYX(const void *p1,const void *p2)
{
	if		(((Point_3d *)p1)->z>((Point_3d *)p2)->z)	return -1;
	else if (((Point_3d *)p1)->z<((Point_3d *)p2)->z)	return  1;
	else if (((Point_3d *)p1)->y>((Point_3d *)p2)->y)	return -1;
	else if (((Point_3d *)p1)->y<((Point_3d *)p2)->y)	return  1;
	else if (((Point_3d *)p1)->x>((Point_3d *)p2)->x)	return -1;
	else if (((Point_3d *)p1)->x<((Point_3d *)p2)->x)	return  1;
	else				return  0;
}
inline int compZXY(const void *p1,const void *p2)
{
	if		(((Point_3d *)p1)->z>((Point_3d *)p2)->z)	return -1;
	else if (((Point_3d *)p1)->z<((Point_3d *)p2)->z)	return  1;
	else if (((Point_3d *)p1)->x>((Point_3d *)p2)->x)	return -1;
	else if (((Point_3d *)p1)->x<((Point_3d *)p2)->x)	return  1;
	else if (((Point_3d *)p1)->y>((Point_3d *)p2)->y)	return -1;
	else if (((Point_3d *)p1)->y<((Point_3d *)p2)->y)	return  1;
	else				return  0;
}

typedef  Varray< double >	ScalarArray;
typedef  Varray< Point_2d > PointArray_2d;
typedef  Varray< Point_3d > PointArray_3d;
typedef	 Varray< GLUquadricObj* > GL_Index;

class DataSet_3d
{
	friend class QueryPSet3D;
private:
	//data bounding box
	Point_3d _min;
	Point_3d _max;
	//data subdivision
	uint _sx,_sy,_sz;
	//data
	GL_Index	_glDataIndex;
	GL_Index	_glSelection;

public:
	PointArray_3d _data;
	DataSet_3d( uint sx = 1,uint sy = 1,uint sz = 1,
				const Point_3d &pmin = Point_3d(0.000f,0.000f,0.000f),
				const Point_3d &pmax = Point_3d(1.000f,1.000f,1.000f))
	:_data(sx*sy*sz),_glDataIndex(sx*sy*sz)
	{
		_sx = sx;_sy = sy;_sz = sz;
		_min = pmin;_max = pmax;
		//initialize dataset to an sx by sy by sz grid
		Init(_min,_max);
		//create quadrat objects
		for(uint i=0;i<_glDataIndex.getSize();i++)
			_glDataIndex[i] = gluNewQuadric();
	}
	~DataSet_3d()
	{
		for(uint i=0;i<_glDataIndex.getSize();i++)
			gluDeleteQuadric(_glDataIndex[i]);
	};

	//Sets Range per axis
	void SetRange(	double x_max = HUGE_VAL,double x_min = -HUGE_VAL,
					double y_max = HUGE_VAL,double y_min = -HUGE_VAL,
					double z_max = HUGE_VAL,double z_min = -HUGE_VAL)
	{
		if (x_max<HUGE_VAL) _max.x = x_max;
		if (x_min>-HUGE_VAL) _min.x = x_min;
		if (y_max<HUGE_VAL) _max.y = y_max;
		if (y_min>-HUGE_VAL) _min.y = y_min;
		if (z_max<HUGE_VAL) _max.z = z_max;
		if (z_min>-HUGE_VAL) _min.z = z_min;
	}
	//Sets Range 
	void SetRange(
				const Point_3d &pmin = Point_3d(-HUGE_VAL,-HUGE_VAL,-HUGE_VAL),
				const Point_3d &pmax = Point_3d(HUGE_VAL,HUGE_VAL,HUGE_VAL))
	{
		if (pmax.x<HUGE_VAL) _max.x = pmax.x;
		if (pmin.x>-HUGE_VAL) _min.x = pmin.x;
		if (pmax.y<HUGE_VAL) _max.y = pmax.y;
		if (pmin.y>-HUGE_VAL) _min.y = pmin.y;
		if (pmax.z<HUGE_VAL) _max.z = pmax.z;
		if (pmin.z>-HUGE_VAL) _min.z = pmin.z;
	}
	//Clamp axis to specified range;
	void Clamp(char axis = 'z',double min = 0.000f,double max = 0.000f)
	{
		Point_3d pmin = _min;
		Point_3d pmax = _max;
		switch(axis)
		{
			case 'x':pmin.x = min;pmax.x = max;break;
			case 'y':pmin.y = min;pmax.y = max;break;
			default: pmin.z = min;pmax.z = max;break;
		}
		Init(pmin,pmax);
	}

	//Initialize data set grid to range
	void Init(const Point_3d &pmin,const Point_3d &pmax)
	{
		uint k,i,j,pos;
		double stx = (pmax.x - pmin.y);if (_sx>1) stx /=(double)(_sx-1);
		double sty = (pmax.y - pmin.y);if (_sy>1) sty /=(double)(_sy-1);
		double stz = (pmax.z - pmin.y);if (_sz>1) stz /=(double)(_sz-1);
		Point_3d p;
		for (pos = 0,p.z = pmin.z,k=0; k<_sz; k++,p.z+=stz)
			for(p.y = pmin.y,i=0; i<_sy; i++,p.y+=sty)
				for(p.x = pmin.x,j=0; j<_sx; j++,p.x+=stx,pos++)
					_data[pos] = p;
	};

	Point_3d & operator[](int i) const {return _data[i];}
	Point_3d & map(uint i)const 
		{return _data[i];}
	Point_3d & map(uint i,uint j) const	
		{return _data[i*_sx+j];}
	Point_3d & map(uint k,uint i,uint j) const
		{return _data[(k*_sy+i)*_sx+j];}

	uint GetSize(void) const {return _data.getSize();}
	void GetDim(int &sx,int &sy,int &sz) const {sx=_sx;sy=_sy;sz=_sz;}

	//find closest point of set to point p within the epsilon disk
	//eukleidian distance,search O(n)
	int find(const Point_3d &p,double epsilon)const 
	{
		double distance,best = HUGE_VAL;
		int winner = -1;

		for(uint i=0;i<_data.getSize();i++)
			if ( ( distance=dist2(p,_data[i]) )<epsilon )
				if (distance<best){best = distance;winner = i;}
		return winner;
	}

	//find closest point of set to point p within the epsilon disk
	//ippodamian distance,search O(n)
	int ffind(const Point_3d &p,double epsilon)const
	{
		double distance,best = HUGE_VAL;
		int winner = -1;

		for(uint i=0;i<_data.getSize();i++)
			if ( ( distance=dist1(p,_data[i]) )<epsilon )
				if (distance<best){best = distance;winner = i;}
		return winner;
	}
	//Sort Data Set with quicksort, int XYZ order or other if specified
	void sort(int (*compfunc)(const void *,const void *) = compXYZ)
	{
		_data.Sort(compfunc);
	}

	void GL_RenderMesh(float r=1.0f,float g=1.0f,float b=1.0f)
	{
		uint k,i,j;
		glColor3f(r,g,b);
		//strips along x axis
		if (_sx>1)
			for (k=0;k<_sz;k++)
				for (i=0;i<_sy;i++)
				{glBegin(GL_LINE_STRIP);
					for(j=0;j<_sx;j++)map(k,i,j).GL3D();
		glEnd();}

		//strips along y axis
		if (_sy>1)
			for (k=0;k<_sz;k++)
				for (j=0;j<_sx;j++)
				{glBegin(GL_LINE_STRIP);
					for(i=0;i<_sy;i++)map(k,i,j).GL3D();
		glEnd();}

		//strips along z axis
		if (_sz>1)
			for(i=0;i<_sy;i++)
				for (j=0;j<_sx;j++)
				{glBegin(GL_LINE_STRIP);
				for (k=0;k<_sz;k++)map(k,i,j).GL3D();
		glEnd();}
	}

	void GL_RenderMeshProjection(float r=0.5f,float g=0.5f,float b=0.5f,double height=0.000f)
	{
		uint k,i,j;
		glColor3f(r,g,b);
		if (_sx>1)
			for (k=0;k<_sz;k++)
				for (i=0;i<_sy;i++)
				{glBegin(GL_LINE_STRIP);
					for(j=0;j<_sx;j++)map(k,i,j).GL2D(height);
		glEnd();}
		if (_sy>1)
			for (k=0;k<_sz;k++)
				for (j=0;j<_sx;j++)
				{glBegin(GL_LINE_STRIP);
					for(i=0;i<_sy;i++)map(k,i,j).GL2D(height);
		glEnd();}
		glBegin(GL_LINES);
		for(i=0;i<_data.getSize();i++)
		{
			_data[i].GL3D();
			_data[i].GL2D(height);
		}
		glEnd();

	}

	void GL_RenderPoints(float r=1.0f,float g=1.0f,float b=1.0f)
	{
		GLenum glStyle[4] = {GLU_FILL,GLU_LINE,GLU_SILHOUETTE,GLU_POINT};

		glColor3f(r,g,b);
		for (uint i=0;i<_data.getSize();i++)
		{
			glPushMatrix();
			glTranslated(_data[i].x,_data[i].y,_data[i].z);
			gluQuadricDrawStyle(_glDataIndex[i],glStyle[0]);
  			gluSphere(_glDataIndex[i],0.02,8,6);
			glPopMatrix();
		}
	}
};

class DataSet_2d
{
	//data bounding box
private:
	Point_2d _min;
	Point_2d _max;
	//data subdivision
	uint _sx,_sy;
	//data
	PointArray_2d _data;
public:
	DataSet_2d( uint sx = 1,uint sy = 1,
				const Point_2d &pmin = Point_2d(0,0),
				const Point_2d &pmax = Point_2d(1,1))
	:_data(sx*sy)
	{
		_sx = sx;_sy = sy;
		_min = pmin;_max = pmax;
		//initialize dataset to an sx by sy by sz grid
		Init(pmin,pmax);
	}
	~DataSet_2d(){};

	//Sets Range per axis
	void SetRange(	double x_max = HUGE_VAL,double x_min = -HUGE_VAL,
					double y_max = HUGE_VAL,double y_min = -HUGE_VAL)
	{
		if (x_max<HUGE_VAL) _max.x = x_max;
		if (x_min>-HUGE_VAL) _min.x = x_min;
		if (y_max<HUGE_VAL) _max.y = y_max;
		if (y_min>-HUGE_VAL) _min.y = y_min;
	}
	//Sets Range
	void SetRange(
				const Point_3d &pmin = Point_3d(-HUGE_VAL,-HUGE_VAL,-HUGE_VAL),
				const Point_3d &pmax = Point_3d(HUGE_VAL,HUGE_VAL,HUGE_VAL))
	{
		if (pmax.x<HUGE_VAL) _max.x = pmax.x;
		if (pmin.x>-HUGE_VAL) _min.x = pmin.x;
		if (pmax.y<HUGE_VAL) _max.y = pmax.y;
		if (pmin.y>-HUGE_VAL) _min.y = pmin.y;
	}

	//Clamp axis to specified range;
	void Clamp(char axis = 'y',double min = 0.000f,double max = 0.000f)
	{
		Point_2d pmin = _min;
		Point_2d pmax = _max;
		switch(axis)
		{
			case 'x':pmin.x = min;pmax.x = max;break;
			default:pmin.y = min;pmax.y = max;break;
		}
		Init(pmin,pmax);
	}

	
	//Initialize data set grid to range
	void Init(const Point_2d &pmin,const Point_2d &pmax)
	{
		uint i,j,pos;
		Point_2d step = (pmax - pmin);
		step /=Point_2d(_sx,_sy);
		Point_2d p;
		pos = 0;
			for(p.y = pmin.y,i=0; i<_sy; i++,p.y+=step.y)
				for(p.x = pmin.x,j=0; j<_sx; j++,p.x+=step.x)
					_data[pos++] = p;
	};

	Point_2d & operator[](int i) const{return _data[i];}
	Point_2d & map(uint i)const 
		{return _data[i];}
	Point_2d & map(uint i,uint j) const	
		{return _data[i*_sx+j];}
	uint GetSize(void) const {return _data.getSize();}
	void GetDim(int &sx,int &sy) const {sx=_sx;sy=_sy;}
	//find closest point of set to point p within the epsilon disk
	//eukleidian distance,search O(n)
	int find(const Point_2d &p,double epsilon)const 
	{
		double distance,best = HUGE_VAL;
		int winner = -1;

		for(uint i=0;i<_data.getSize();i++)
			if ( ( distance=dist2(p,_data[i]) )<epsilon )
				if (distance<best){best = distance;winner = i;}
		return winner;
	}

	//find closest point of set to point p within the epsilon disk
	//ippodamian distance,search O(n)
	int ffind(const Point_2d &p,double epsilon)const
	{
		double distance,best = HUGE_VAL;
		int winner = -1;

		for(uint i=0;i<_data.getSize();i++)
			if ( ( distance=dist1(p,_data[i]) )<epsilon )
				if (distance<best){best = distance;winner = i;}
		return winner;
	}
	//Sort Data Set with quicksort, int XY order or other if specified
	void sort(int (*compfunc)(const void *,const void *) = compXY)
	{
		_data.Sort(compfunc);
	}
};



#endif // !defined(AFX_POINT_H__1E8AC8D7_7556_4678_9D55_8AF45CE34C09__INCLUDED_)
