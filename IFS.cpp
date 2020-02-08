// IFS.cpp: implementation of the CIFS class.
//
//////////////////////////////////////////////////////////////////////

#include <time.h>
#include "stdafx.h"
#include "IFS.h"
#include "InterpAffine_4d.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define EPSILON 0.001f
Attractor_3d::Attractor_3d()
{
	ready = false;
	iterations = 0;
	setsize = 0;
}

Attractor_3d::~Attractor_3d(){}

uint Attractor_3d::Attract(PointArray_3d &set,const register CntrMap &w,uint iterations)
{
	setsize = set.getSize();
	//calculate total size needed
	uint vsize=setsize;
	for (uint i=0;i<iterations;i++,vsize*=w.getSize());
	if (!vsize)	return 0;
	vertices.resize(vsize);
	//copy initset to vertices buffer
	memcpy(&vertices,&set,sizeof(Point_3d)*setsize);
	//attract...
	{
		register Point_3d *s = &vertices,*t;
		register uint i,level,
			wsize = w.getSize(),
			psize = setsize,
			tsize = setsize*wsize;
			
		
		for (level=iterations;level;level--,psize=tsize,tsize*=wsize)
		{
			for (t=s+(tsize-psize),i = wsize-1;i>0;i--,t-=psize)
			{
				memcpy(t,s,psize*sizeof(Point_3d));
				(*w[i])(t,psize);			//TODO in parallel
			}
			(*w[0])(s,psize);
		}
	}
	ready = true;
	return vsize;
}


uint Attractor_3d::Attract(PointArray_3d &set,const register CntrMap &w,uint n,uint m,uint iterations)
{
	setsize = set.getSize();
	//calculate total size needed
	uint i,j,vsize=setsize;
	for (i=0;i<iterations;i++,vsize*=w.getSize());
	if (!vsize)	return 0;
	vertices.resize(vsize);
	//copy initset to vertices buffer
	memcpy(&vertices,&set,sizeof(Point_3d)*setsize);
	//attract...
	{
		register Point_3d *s = &vertices,*t;
		register uint level,
				wsize = w.getSize(),
				psize = setsize,
				tsize = setsize*wsize;
			
		
		for (level=iterations;level;level--,psize=tsize,tsize*=wsize)
			for (t=s+(tsize-psize),i = wsize-1;t>=s;i--,t-=psize)
				for(j=0;j<psize;j++)
				{
					Point_3d p1(s[j]),p2(s[j]);
					bool	u = dist1(s[j].y,set[2].y)<EPSILON,
							d = dist1(s[j].y,set[0].y)<EPSILON,
							r = dist1(s[j].x,set[2].x)<EPSILON,
							l = dist1(s[j].x,set[0].x)<EPSILON;

					(*w[i])(p1);t[j]=p1;

					if ((!(u||d||r||l))||(u&&l)||(d&&l)||(u&&r)||(d&&r)) continue;

					if		(u&&(i/n<m-1))	{p2.y=set[0].y;(*w[i+n])(p2);}
					else if (d&&(i/n>0))	{p2.y=set[2].y;(*w[i-n])(p2);}
					else if (r&&(i%n<n-1))	{p2.x=set[0].x;(*w[i+1])(p2);}
					else if (l&&(i%n>0))	{p2.x=set[2].x;(*w[i-1])(p2);}
					else continue;

					t[j].z=p2.z;t[j].z/=2.000f;
				}
	}
	ready = true;
	return vsize;
}

void Attractor_3d::GL_Render_3DColor(int GL_Flags,float r,float g,float b)
{
	if (ready)
	{
		bool solid = (GL_Flags == GL_POLYGON);
		if (solid)
		{
			if (setsize == 1) GL_Flags = GL_POINTS;
			else if (setsize==2) GL_Flags = GL_LINES;
			else if (setsize==3) GL_Flags = GL_TRIANGLES;
			else if (setsize==4) GL_Flags = GL_QUADS;
		}

		register uint i,j;

		if (solid&&(setsize>4))
		{
			glBegin(GL_Flags);
			for(j=0;j<vertices.getSize();j++) vertices[j].GL3D_ZCLR(r,g,b);
			glEnd();
		}
		else
		{
			for(j=0;j<vertices.getSize();)
			{
				glBegin(GL_Flags);
				for(i=0;i<setsize;i++,j++)	vertices[j].GL3D_ZCLR(r,g,b);
				glEnd();
			}
		}
	}
}

void Attractor_3d::GL_Render_3DMono(int GL_Flags,float r,float g,float b)
{
	if (ready)
	{
		glColor3f(r,g,b);

		bool solid = (GL_Flags == GL_POLYGON);
		if (solid)
		{
			if (setsize == 1) GL_Flags = GL_POINTS;
			else if (setsize==2) GL_Flags = GL_LINES;
			else if (setsize==3) GL_Flags = GL_TRIANGLES;
			else if (setsize==4) GL_Flags = GL_QUADS;
		}

		register uint i,j;

		if ((solid)&&(setsize>4))
		{
			glBegin(GL_Flags);
			for(j=0;j<vertices.getSize();j++) vertices[j].GL3D();
			glEnd();
		}
		else
		{
			for(j=0;j<vertices.getSize();)
			{
				glBegin(GL_Flags);
				for(i=0;i<setsize;i++,j++)	vertices[j].GL3D();
				glEnd();
			}
		}
	}
}

void Attractor_3d::GL_Render_2DColor(int GL_Flags,float r,float g,float b)
{
	if (ready)
	{
		bool solid = (GL_Flags == GL_POLYGON);
		if (solid)
		{
			if (setsize == 1) GL_Flags = GL_POINTS;
			else if (setsize==2) GL_Flags = GL_LINES;
			else if (setsize==3) GL_Flags = GL_TRIANGLES;
			else if (setsize==4) GL_Flags = GL_QUADS;
		}

		register uint i,j;

		if ((solid)&&(setsize>4))
		{
			glBegin(GL_Flags);
			for(j=0;j<vertices.getSize();j++) vertices[j].GL2D_ZCLR(r,g,b);
			glEnd();
		}
		else
		{
			for(j=0;j<vertices.getSize();)
			{
				glBegin(GL_Flags);
				for(i=0;i<setsize;i++,j++)	vertices[j].GL2D_ZCLR(r,g,b);
				glEnd();
			}
		}
	}
}

void Attractor_3d::GL_Render_2DMono(int GL_Flags,float r,float g,float b)
{
	if (ready)
	{
		bool solid = (GL_Flags == GL_POLYGON);
		glColor3f(r,g,b);
		if (solid)
		{
			if (setsize == 1) GL_Flags = GL_POINTS;
			else if (setsize==2) GL_Flags = GL_LINES;
			else if (setsize==3) GL_Flags = GL_TRIANGLES;
			else if (setsize==4) GL_Flags = GL_QUADS;
		}

		register uint i,j;

		if ((solid)&&(setsize>4))
		{
			glBegin(GL_Flags);
			for(j=0;j<vertices.getSize();j++) vertices[j].GL2D();
			glEnd();
		}
		else
		{
			for(j=0;j<vertices.getSize();)
			{
				glBegin(GL_Flags);
				for(i=0;i<setsize;i++,j++)	vertices[j].GL2D();
				glEnd();
			}
		}
	}
}


CIFS::CIFS()
{
	SetIterations();
	SetAlgorithm();
	SetRenderType();
	SetRGBColor();
	SetColorType();
}

CIFS::~CIFS()
{
	Clear(false);
}

void CIFS::Clear(int keepbuffer)
{
	for(uint i=0;i<_cntr.getSize();delete _cntr[i++]);
	_cntr.Delall(keepbuffer);
	_initset.Delall(keepbuffer);
	_attr3d.vertices.Delall(keepbuffer);
	_attr3d.ready=false;
	Invalidate();
}

int  CIFS::Interpolate(INTERPENUM itype,const DataSet_3d &PSet,const double *scales)
{
	int sx,sy,sz;
	PSet.GetDim(sx,sy,sz);
	if (sz==1)//data set is valid
	{
		Clear();
		switch (itype)
		{
		case BIVARIATE:{
			for(int l=0,i=0;i<sy-1;i++)
				for(int j=0;j<sx-1;j++,l++)
				{
					InterpAffine_4d *w = new InterpAffine_4d; 
					w->SetUp_fromDataSet
					(	PSet.map(0,0),		PSet.map(0,sx-1),
						PSet.map(sy-1,0),	PSet.map(sy-1,sx-1),
						PSet.map(i,j),		PSet.map(i,j+1),
						PSet.map(i+1,j),	PSet.map(i+1,j+1),scales[l]	);
					_cntr.Add(w);
				}
			PointArray_3d set(4);
			set[0] = PSet.map(0,0);
			set[1] = PSet.map(0,sx-1);
			set[2] = PSet.map(sy-1,sx-1);
			set[3] = PSet.map(sy-1,0);
			SetInit(set);
			return 1;
		}
		default:return 0;
		}
	}
	return 0;
};

int CIFS::RndIterations()
{
	register Point_3d p = _initset[0];
	register uint wsize = _cntr.getSize();
	glBegin(GL_POINTS);
		for(register uint i=0;i<_rndIter;i++)
			(*_cntr[rand()%wsize])(p).GL3D_ZCLR();
	glEnd();
	return _rndIter;
}

int CIFS::Deterministic()
{
	double r,g,b;
	_color.get(r,g,b);

	if (!_attr3d.ready)	_attr3d.Attract(_initset,_cntr,2,2,_detIter);

	switch(_cType)
	{
	case LIGHT:
	case HMAP:_attr3d.GL_Render_3DColor(_rType,(float)r,(float)g,(float)b);break;
	case MONO:default:_attr3d.GL_Render_3DMono(_rType,(float)r,(float)g,(float)b);break;
	}

	return _attr3d.vertices.getSize();
}


