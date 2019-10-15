// 1Doc.cpp : CMy1Doc ���ʵ��
//

#include "stdafx.h"
#include "1.h"

#include "1Doc.h"
#include "..\\Common\\GlobalCommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1Doc

IMPLEMENT_DYNCREATE(CMy1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1Doc, CDocument)
	ON_COMMAND(ID_IMAGEPROCESSING_OPENBMPFILE, &CMy1Doc::OnImageprocessingOpenbmpfile)
	ON_COMMAND(ID_IMAGEPROCESSING_SAVETONEWBMPFILE, &CMy1Doc::OnImageprocessingSavetonewbmpfile)
	ON_COMMAND(ID_IMAGEPROCESSING_IMAGEINTERPOLATION, &CMy1Doc::OnImageprocessingImageinterpolation)
END_MESSAGE_MAP()


// CMy1Doc ����/����

CMy1Doc::CMy1Doc()
{
	// TODO: �ڴ����һ���Թ������
	pFileBuf = NULL;

}

CMy1Doc::~CMy1Doc()
{
}

BOOL CMy1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy1Doc ���л�

void CMy1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMy1Doc ���

#ifdef _DEBUG
void CMy1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy1Doc ����

void CMy1Doc::OnImageprocessingOpenbmpfile()
{
	LPCTSTR lpszFilter = "BMP Files (*.bmp)|*.bmp||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_NOCHANGEDIR,lpszFilter,NULL);
	if( dlg.DoModal() != IDOK ) return;
	if( pFileBuf != NULL )
	{
		delete [] pFileBuf;
	}
	pFileBuf = OpenBMPfile( dlg.GetPathName() );
	UpdateAllViews(NULL);
}

void CMy1Doc::OnImageprocessingSavetonewbmpfile()
{
	if( pFileBuf != NULL )
	{
		CString strBmpFile = "2.bmp";
		SaveDIB(pFileBuf, strBmpFile);
	}
}

void CMy1Doc::OnImageprocessingImageinterpolation()
{
	if( pFileBuf != NULL )
	{
		int newWidth  = 500;
		int newHeight = 490;
		char *pNewFileBuf = ImageInterpolation(pFileBuf,newWidth,newHeight,0);
		SaveDIB(pNewFileBuf, "C:\\11.bmp");
		delete [] pFileBuf;
		pFileBuf = pNewFileBuf;
		UpdateAllViews(NULL);
	}
}
