// 1View.h : CMy1View ��Ľӿ�
//


#pragma once


class CMy1View : public CView
{
protected: // �������л�����
	CMy1View();
	DECLARE_DYNCREATE(CMy1View)

// ����
public:
	CMy1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnImageprocessingDisplayfileheader();
	afx_msg void OnUpdateImageprocessingDisplayfileheader(CCmdUI *pCmdUI);
	afx_msg void OnImageprocessingReadpixelvalue();
	afx_msg void OnImageprocessingSetpixelvalue();
    afx_msg void OnPhoneapplicationHistogramequalization();
    afx_msg void OnPhoneapplicationMedianfiltering();
    afx_msg void OnPhoneapplicationGaussiansmoothing();
    afx_msg void OnPhoneapplication3stepprocess();
};

#ifndef _DEBUG  // 1View.cpp �еĵ��԰汾
inline CMy1Doc* CMy1View::GetDocument() const
   { return reinterpret_cast<CMy1Doc*>(m_pDocument); }
#endif

