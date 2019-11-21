#pragma once


// dialog2 对话框

class dialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(dialog2)

public:
	dialog2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    int x;
    int y;
    int r;
    int g;
    int b;
    int reserved;
};
