#pragma once


// dialog1 对话框

class dialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(dialog1)

public:
	dialog1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    int x;
    int y;
};
