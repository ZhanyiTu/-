#pragma once


// dialog4 对话框

class dialog4 : public CDialogEx
{
	DECLARE_DYNAMIC(dialog4)

public:
	dialog4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    double standard;
};
