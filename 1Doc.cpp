// 1Doc.cpp : CMy1Doc ���ʵ��
//

#include "stdafx.h"
#include "1.h"
//#pragma comment(lib, "msvcrtd.lib") 
#include "1Doc.h"
#include "dialog3.h"
#include "dialog4.h"
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
    ON_COMMAND(ID_IMAGEPROCESSING_MEDIANFILTERING, &CMy1Doc::OnImageprocessingMedianfiltering)
    ON_COMMAND(ID_IMAGEPROCESSING_GAUSSIANSMOTHING, &CMy1Doc::OnImageprocessingGaussiansmothing)
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
    LPCTSTR lpszFilter = "BMP Files (*.bmp)|*.bmp||";
    CFileDialog dlg(TRUE, NULL, NULL, OFN_NOCHANGEDIR, lpszFilter, NULL);//�����Ի���
    if (dlg.DoModal() != IDOK) return;//ȷ�϶Ի����Ƿ����ļ���ѡ����ģʽ
    if (pFileBuf != NULL)
    {
        CString ext = ".bmp";
        CString strBmpFile = dlg.GetFileTitle() + ext;
        SaveDIB(pFileBuf, strBmpFile);
    }
}

//void CMy1Doc::OnImageprocessingSavetonewbmpfile()
//{
//	if( pFileBuf != NULL )
//	{
//		CString strBmpFile = "2.bmp";
//		SaveDIB(pFileBuf, strBmpFile);
//	}
//}

void CMy1Doc::OnImageprocessingImageinterpolation()
{
    dialog3 dlg;
    dlg.DoModal();
    if (pFileBuf != NULL)
    {
        BITMAPFILEHEADER* pFileHeader = (BITMAPFILEHEADER*)pFileBuf;
        BITMAPINFOHEADER* pDIBInfo = (BITMAPINFOHEADER*)(pFileBuf + sizeof(BITMAPFILEHEADER));
        int oldWidth = pDIBInfo->biWidth;
        int oldHeight = pDIBInfo->biHeight;
        int newWidth = oldWidth * dlg.xFactor;//�����µĿ��
        int newHeight = oldHeight * dlg.yFactor;//�����µĳ���
        int method = dlg.combo1.GetCurSel();
        char* pNewFileBuf = ImageInterpolation(pFileBuf, newWidth, newHeight, method);
        SaveDIB(pNewFileBuf, "C:\\11.bmp");//�ļ�����Ӧ��Ҫ��������?������ĿҪ��û˵Ҫ����
        delete[] pFileBuf;
        pFileBuf = pNewFileBuf;
        UpdateAllViews(NULL);
    }
}
//void CMy1Doc::OnImageprocessingImageinterpolation()
//{
//	if( pFileBuf != NULL )
//	{
//		int newWidth  = 500;//�����µĿ��
//		int newHeight = 490;//�����µĳ���
//		char *pNewFileBuf = ImageInterpolation(pFileBuf,newWidth,newHeight,0);
//		SaveDIB(pNewFileBuf, "C:\\11.bmp");
//		delete [] pFileBuf;
//		pFileBuf = pNewFileBuf;
//		UpdateAllViews(NULL);
//	}
//}


void CMy1Doc::OnImageprocessingMedianfiltering()//��ֵ�˲�
{
    int  nImageHeight = GetImageHeight(pFileBuf);
    int  nBytesPerRow = GetWidthBytes(pFileBuf);
    for (int y = 0; y < nImageHeight; y++) {
        for (int x = 0; x < nBytesPerRow; x++) {
            PixelFilter(pFileBuf, x, y);
        }
    }
    //UpdateAllViews(NULL);
    // TODO: �ڴ���������������
}


void CMy1Doc::OnImageprocessingGaussiansmothing()
{
    dialog4 dlg;
    dlg.DoModal();
    int  nColorBits = GetColorBits(pFileBuf);
    int  nImageHeight = GetImageHeight(pFileBuf);
    int  nBytesPerRow = GetWidthBytes(pFileBuf);
    double standardDevitation = dlg.standard;
    BITMAPFILEHEADER* pBmpHead = (BITMAPFILEHEADER*)pFileBuf;
    long lFileSize = pBmpHead->bfSize;
    char* newpFileBuf = new char[lFileSize];
    memcpy(newpFileBuf, pFileBuf, lFileSize);
    BYTE temp;
    RGBQUAD rgb;
    bool bGray;
    for (int y = 0; y < nImageHeight; y++) {
        for (int x = 0; x < nBytesPerRow; x++) {
            temp = PixelSmoothing(pFileBuf, x, y, standardDevitation);
            GetPixel(pFileBuf, x, y, &rgb, &bGray);
            rgb.rgbReserved = temp;
            SetPixel(newpFileBuf, x, y, rgb);
        }
    }
    SaveDIB(newpFileBuf, "C:\\11.bmp");//�ļ�����Ӧ��Ҫ��������?������ĿҪ��û˵Ҫ����
    delete[] pFileBuf;
    pFileBuf = newpFileBuf;
    UpdateAllViews(NULL);
    // TODO: �ڴ���������������
}
