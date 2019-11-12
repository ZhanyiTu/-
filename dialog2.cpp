// dialog2.cpp: 实现文件
//

#include "pch.h"
#include "1.h"
#include "dialog2.h"
#include "afxdialogex.h"


// dialog2 对话框

IMPLEMENT_DYNAMIC(dialog2, CDialogEx)

dialog2::dialog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

dialog2::~dialog2()
{
}

void dialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(dialog2, CDialogEx)
END_MESSAGE_MAP()


// dialog2 消息处理程序
