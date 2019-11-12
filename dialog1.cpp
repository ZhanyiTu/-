// dialog1.cpp: 实现文件
//

#include "stdafx.h"
#include "1.h"
#include "dialog1.h"
#include "afxdialogex.h"


// dialog1 对话框

IMPLEMENT_DYNAMIC(dialog1, CDialogEx)

dialog1::dialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
    , x(0)
    , y(0)
{

}

dialog1::~dialog1()
{
}

void dialog1::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, x);
    DDX_Text(pDX, IDC_EDIT2, y);
}


BEGIN_MESSAGE_MAP(dialog1, CDialogEx)
END_MESSAGE_MAP()


// dialog1 消息处理程序
