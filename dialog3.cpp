// dialog3.cpp: 实现文件
//

#include "stdafx.h"
#include "1.h"
#include "dialog3.h"
#include "afxdialogex.h"


// dialog3 对话框

IMPLEMENT_DYNAMIC(dialog3, CDialogEx)

dialog3::dialog3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
    , xFactor(0)
    , yFactor(0)
{

}

dialog3::~dialog3()
{
}

void dialog3::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT2, xFactor);
    DDX_Text(pDX, IDC_EDIT2, xFactor);
    DDX_Text(pDX, IDC_EDIT1, yFactor);
    DDX_Control(pDX, IDC_COMBO1, combo1);
}


BEGIN_MESSAGE_MAP(dialog3, CDialogEx)
END_MESSAGE_MAP()


// dialog3 消息处理程序


BOOL dialog3::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  在此添加额外的初始化
    combo1.AddString(_T("最邻近法"));
    combo1.AddString(_T("双线性插值法"));
    combo1.SetCurSel(0);
    return TRUE;  // return TRUE unless you set the focus to a control
                  // 异常: OCX 属性页应返回 FALSE
}
