// dialog2.cpp: 实现文件
//

#include "stdafx.h"
#include "1.h"
#include "dialog2.h"
#include "afxdialogex.h"


// dialog2 对话框

IMPLEMENT_DYNAMIC(dialog2, CDialogEx)

dialog2::dialog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
    , x(0)
    , y(0)
    , r(0)
    , g(0)
    , b(0)
{

}

dialog2::~dialog2()
{
}

void dialog2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT2, x);
    DDX_Text(pDX, IDC_EDIT3, y);
    DDX_Text(pDX, IDC_EDIT4, r);
    DDX_Text(pDX, IDC_EDIT5, g);
    DDX_Text(pDX, IDC_EDIT6, b);
}


BEGIN_MESSAGE_MAP(dialog2, CDialogEx)
END_MESSAGE_MAP()


// dialog2 消息处理程序
