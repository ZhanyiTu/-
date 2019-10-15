// 1View.cpp : CMy1View ���ʵ��
//

#include "stdafx.h"
#include "1.h"

#include "1Doc.h"
#include "1View.h"
#include "..\\Common\\GlobalCommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_IMAGEPROCESSING_DISPLAYFILEHEADER, &CMy1View::OnImageprocessingDisplayfileheader)
	ON_UPDATE_COMMAND_UI(ID_IMAGEPROCESSING_DISPLAYFILEHEADER, &CMy1View::OnUpdateImageprocessingDisplayfileheader)
	ON_COMMAND(ID_IMAGEPROCESSING_READPIXELVALUE, &CMy1View::OnImageprocessingReadpixelvalue)
	ON_COMMAND(ID_IMAGEPROCESSING_SETPIXELVALUE, &CMy1View::OnImageprocessingSetpixelvalue)
END_MESSAGE_MAP()

// CMy1View ����/����

CMy1View::CMy1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy1View ����

void CMy1View::OnDraw(CDC *pDC)
{
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if( pDoc->pFileBuf != NULL )
	{
		DisplayImage(pDC, pDoc->pFileBuf, 50, 50, 0, 0, 0);
	}

}


// CMy1View ��ӡ

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy1View ���

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1View ��Ϣ�������

void CMy1View::OnImageprocessingDisplayfileheader()
{
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	if( pDoc->pFileBuf != NULL )
	{
		DisplayHeaderMessage(pDoc->pFileBuf);
	}
}

void CMy1View::OnUpdateImageprocessingDisplayfileheader(CCmdUI *pCmdUI)
{
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	pCmdUI->Enable(pDoc->pFileBuf != NULL);
}

void CMy1View::OnImageprocessingReadpixelvalue()
{
	int x = 100;
	int y = 100;
	RGBQUAD rgb;
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	if( pDoc->pFileBuf != NULL )
	{
		bool bGray;
		GetPixel(pDoc->pFileBuf, x, y, &rgb, &bGray);
		char buf[100];
		if( bGray )
			sprintf(buf, "(%d,%d) = %d", x, y, rgb.rgbReserved);
		else
			sprintf(buf, "(%d,%d) = (%d, %d, %d)", x, y, rgb.rgbRed, rgb.rgbGreen, rgb.rgbBlue);
		AfxMessageBox( buf );
	}
}

void CMy1View::OnImageprocessingSetpixelvalue()
{
	int x = 100;
	int y = 100;
	RGBQUAD rgb;
	rgb.rgbReserved = 255;
	rgb.rgbRed      = 255;
	rgb.rgbGreen    = 255;
	rgb.rgbBlue     = 255;
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	if( pDoc->pFileBuf != NULL )
	{
		SetPixel(pDoc->pFileBuf, x, y, rgb);
		ValidateRect(NULL);
	}
}
