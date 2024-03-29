// 1View.cpp : CMy1View 类的实现
//

#include "stdafx.h"
#include "1.h"
#include "dialog1.h"
#include "dialog2.h"
#include "1Doc.h"
#include "1View.h"
#include "..\\Common\\GlobalCommon.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
//#pragma comment(lib, "winsock.lib") 
using namespace cv;
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
Mat src;


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
    ON_COMMAND(ID_PHONEAPPLICATION_HISTOGRAMEQUALIZATION, &CMy1View::OnPhoneapplicationHistogramequalization)
    ON_COMMAND(ID_PHONEAPPLICATION_MEDIANFILTERING, &CMy1View::OnPhoneapplicationMedianfiltering)
    ON_COMMAND(ID_PHONEAPPLICATION_GAUSSIANSMOOTHING, &CMy1View::OnPhoneapplicationGaussiansmoothing)
    ON_COMMAND(ID_PHONEAPPLICATION_OPENIMAGE, &CMy1View::OnPhoneapplicationOpenimage)
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
    dialog1 dlg;
    int x, y;
    dlg.DoModal();
    x = dlg.x;
    y = dlg.y;
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
    dialog2 dlg;
    int x, y;
    dlg.DoModal();
    x = dlg.x;
    y = dlg.y;
	RGBQUAD rgb;
	rgb.rgbReserved = dlg.reserved;
	rgb.rgbRed      = dlg.r;
	rgb.rgbGreen    = dlg.g;
	rgb.rgbBlue     = dlg.b;
	CMy1Doc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	if( pDoc->pFileBuf != NULL )
	{
		SetPixel(pDoc->pFileBuf, x, y, rgb);
		ValidateRect(NULL);
	}
}


void CMy1View::OnPhoneapplicationHistogramequalization()
{
    Mat src_gray, dst;
    vector<Mat> channels;
    //src = imread("3 input.bmp");
    /*LPCTSTR lpszFilter = "BMP Files (*.bmp)|*.bmp||";
    CFileDialog dlg(TRUE, NULL, NULL, OFN_NOCHANGEDIR, lpszFilter, NULL);
    if (dlg.DoModal() != IDOK) return;
    src = imread(dlg.GetPathName().GetBuffer(0));*/
    //imshow("原图像", src);
    split(src, channels);
    Mat imageBlueChannel = channels.at(0);
    Mat imageGreenChannel = channels.at(1);
    Mat imageRedChannel = channels.at(2);
    equalizeHist(imageBlueChannel, imageBlueChannel);
    equalizeHist(imageGreenChannel, imageGreenChannel);
    equalizeHist(imageRedChannel, imageRedChannel);
    merge(channels, dst);
    //cvtColor(src, src_gray, COLOR_BGR2GRAY);
    //直方图均衡化
    //equalizeHist(src_gray, dst);
    imshow("效果图", dst);
    src = dst;
    waitKey(0);

    //cv::Mat img = cv::imread("C:\\Users\\admin\\Desktop\\code\\mfcdemo\\mfcdemo\\lena256.bmp");//载入一张图片

    //cv::imshow("测试图片", img);//显示图片 窗口名为“测试图片”

    //cv::waitKey(0);//等待任意键（暂停）
    // TODO: 在此添加命令处理程序代码
}


void CMy1View::OnPhoneapplicationMedianfiltering()
{
    // TODO: 在此添加命令处理程序代码
    // load image   
    //LPCTSTR lpszFilter = "BMP Files (*.bmp)|*.bmp||";
    //CFileDialog dlg(TRUE, NULL, NULL, OFN_NOCHANGEDIR, lpszFilter, NULL);
    //if (dlg.DoModal() != IDOK) return;
    ////Mat image = imread("C:\\Users\\admin\\Desktop\\code\\mfcdemo\\mfcdemo\\lena256.bmp", 1);
    //Mat src = imread(dlg.GetPathName().GetBuffer(0), 1);

    

    // display result  
    //cv::imshow("原图像", src);

    //median filte  
    Mat result;
    cv::medianBlur(src, result, 7);

    //display result  
    cv::imshow("效果图", result);
    src = result;
    cv::waitKey();
}


void CMy1View::OnPhoneapplicationGaussiansmoothing()
{
    // [1] src读入图片
    // TODO: 在此添加命令处理程序代码
    // load image   
    //LPCTSTR lpszFilter = "BMP Files (*.bmp)|*.bmp||";
    //CFileDialog dlg(TRUE, NULL, NULL, OFN_NOCHANGEDIR, lpszFilter, NULL);
    //if (dlg.DoModal() != IDOK) return;
    ////Mat image = imread("C:\\Users\\admin\\Desktop\\code\\mfcdemo\\mfcdemo\\lena256.bmp", 1);
    //Mat src = imread(dlg.GetPathName().GetBuffer(0), 1);
    //cv::Mat src = cv::imread("C:\\Users\\admin\\Desktop\\code\\mfcdemo\\mfcdemo\\lena256.bmp");
    // [2] dst目标图片
    cv::Mat dst;
    // [3] 高斯滤波  sigma越大越平越模糊
    cv::GaussianBlur(src, dst, cv::Size(5, 5), 3, 3);
    // [4] 窗体显示
    //cv::imshow("src", src);
    cv::imshow("dst", dst);
    src = dst;
    cv::waitKey(0);
    cv::destroyAllWindows();
}




void CMy1View::OnPhoneapplicationOpenimage()
{
    LPCTSTR lpszFilter = "BMP Files (*.bmp)|*.bmp||";
    CFileDialog dlg(TRUE, NULL, NULL, OFN_NOCHANGEDIR, lpszFilter, NULL);
    if (dlg.DoModal() != IDOK) return;
    src = imread(dlg.GetPathName().GetBuffer(0), 1);
    imshow("原图像", src);
    // TODO: 在此添加命令处理程序代码
}
