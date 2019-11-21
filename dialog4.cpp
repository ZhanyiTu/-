// dialog4.cpp: 实现文件
//

#include "stdafx.h"
#include "1.h"
#include "dialog4.h"
#include "afxdialogex.h"


// dialog4 对话框

IMPLEMENT_DYNAMIC(dialog4, CDialogEx)

dialog4::dialog4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
    , standard(0)
{

}

dialog4::~dialog4()
{
}

void dialog4::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, standard);
}


BEGIN_MESSAGE_MAP(dialog4, CDialogEx)
END_MESSAGE_MAP()


// dialog4 消息处理程序
