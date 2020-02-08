// QueryPSet3D.cpp : implementation file
//

#include "stdafx.h"
#include "bivariate.h"
#include "QueryPSet3D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// QueryPSet3D dialog


QueryPSet3D::QueryPSet3D(DataSet_3d *pset,CWnd* pParent /*=NULL*/)
	: CDialog(QueryPSet3D::IDD, pParent)
{
	_pset = pset;
	//{{AFX_DATA_INIT(QueryPSet3D)
	_z = 0.0;
	//}}AFX_DATA_INIT
}


void QueryPSet3D::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(QueryPSet3D)
	DDX_Control(pDX, IDC_EDIT_Z, _zedit);
	DDX_Control(pDX, IDC_VIEW3D, _preview);
	DDX_Control(pDX, IDC_ZHEIGHT, _zslide);
	DDX_Control(pDX, IDC_GLOPTIONS, _gltab);
	DDX_Control(pDX, IDC_SET, _ButtonSet);
	DDX_Control(pDX, IDC_PLIST, _plist);
	DDX_Text(pDX, IDC_EDIT_Z, _z);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(QueryPSet3D, CDialog)
	//{{AFX_MSG_MAP(QueryPSet3D)
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_LBN_SELCHANGE(IDC_PLIST, OnSelchangePlist)
	ON_BN_CLICKED(IDC_OPTIONS, OnOptions)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// QueryPSet3D message handlers



BOOL QueryPSet3D::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

//INITLISTBOX:
	_zslide.SetParent(this);
//INITSLIDER:
	DataSetImage();
//INITTAB:
	TC_ITEM tci;
	tci.mask=TCIF_TEXT;
	tci.iImage=-1;
	tci.pszText="Perspective Solid";
	_gltab.InsertItem(0,&tci );
	tci.pszText="Perspective Grid";
	_gltab.InsertItem(1,&tci );
	tci.pszText="HeightMap";
	_gltab.InsertItem(2,&tci );


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void QueryPSet3D::OnSet() 
{
	if (UpdateData() != TRUE)	return;
	SelectionUpdate(_z);
}

void QueryPSet3D::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	
	_z = _zslide.GetPos()/(double)1000;
//	if (UpdateData() != TRUE)	return;
//	SelectionUpdate(_z);
	for (int i=0;i<_plist.GetCount();i++)
		if (_plist.GetSel(i)>0)
		{
			(*_pset)[i].z = _z;
			_plist.DeleteString(i);
			AddPoint2List((*_pset)[i],i);
			_plist.SetSel(i);
		}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void QueryPSet3D::OnSelchangePlist() 
{
	SelectionChanged();
}

void QueryPSet3D::OnOptions() 
{
/*	QueryPSet3D_Options	dlg;
	dlg._fv = _fv;
	dlg._fh = _fh;
	dlg._rv = _rv;
	dlg._rh = _rh;
	if (dlg.DoModal()==IDOK)
	{
		_fv = dlg._fv;
		_fh = dlg._fh;
		_rv = dlg._rv;
		_rh = dlg._rh;

		_plist.ResetContent();
		_pset->resize(newsize);
		for(pos=0,curh=0.000,i=0;i<_fh;i++,curh+=strideh)
			for(curv=0.000,j=0;j<_fv;j++,curv+=stridev,pos++)
			{
				(*_pset)[pos]=Point_3d(curh,curv);
				AddPoint2List((*_pset)[pos]);
			}
	}
	
*/
}

void QueryPSet3D::AddPoint2List(const Point_3d &p,int nSel)
{
	// Add new point to the listbox.
	CString str;
	str.Format(_T("(%12.6f,%12.6f,%12.6f)"), p.x,p.y,p.z);
	if (nSel == -1)	_plist.AddString(str);
	else			_plist.InsertString(nSel, str);

}

int QueryPSet3D::SelectionChanged()
{
	if (_plist.GetSelCount()>0)
	{
		_zslide.EnableWindow();
		_ButtonSet.EnableWindow();
		_z = (*_pset)[_plist.GetCaretIndex()].z;
		_zslide.SetPos((int)(_z*1000));
		UpdateData(FALSE);
	}
	else
	{
		_zslide.EnableWindow(FALSE);
		_ButtonSet.EnableWindow(FALSE);
	}
	return _plist.GetSelCount();
}

int QueryPSet3D::SelectionUpdate(double value)
{
	for (int i=0;i<_plist.GetCount();i++)
		if (_plist.GetSel(i)>0)
		{
			(*_pset)[i].z = value;
			_plist.DeleteString(i);
			AddPoint2List((*_pset)[i],i);
		}
	_ButtonSet.EnableWindow(FALSE);
	return _plist.GetSelCount();
}

int QueryPSet3D::DataSetImage()
{
	_plist.ResetContent();
	//copy points from PointSet to list box
	for(unsigned int i=0;i<_pset->GetSize();i++)
			AddPoint2List((*_pset)[i]);
	_zslide.EnableWindow(FALSE);
	_zslide.SetRange((int)(_pset->_min.z*1000),(int)(_pset->_max.z*1000));
	_ButtonSet.EnableWindow(FALSE);
	return _plist.GetCount();
}


