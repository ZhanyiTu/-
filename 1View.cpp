// 1View.cpp : CMy1View 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_IMAGEPROCESSING_DISPLAYFILEHEADER, &CMy1View::OnImageprocessingDisplayfileheader)
	ON_UPDATE_COMMAND_UI(ID_IMAGEPROCESSING_DISPLAYFILEHEADER, &CMy1View::OnUpdateImageprocessingDisplayfileheader)
	ON_COMMAND(ID_IMAGEPROCESSING_READPIXELVALUE, &CMy1View::OnImageprocessingReadpixelvalue)
	ON_COMMAND(ID_IMAGEPROCESSING_SETPIXELVALUE, &CMy1View::OnImageprocessingSetpixelvalue)
END_MESSAGE_MAP()

// CMy1View 构造/析构

CMy1View::CMy1View()
{
	// TODO: 在此处添加构造代码

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy1View 绘制

void CMy1View::OnDraw(CDC *pDC)
{
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if( pDoc->pFileBuf != NULL )
	{
		DisplayImage(pDC, pDoc->pFileBuf, 50, 50, 0, 0, 0);
	}

}


// CMy1View 打印

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy1View 诊断

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1View 消息处理程序

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
