// 1Doc.h : CMy1Doc ��Ľӿ�
//


#pragma once


class CMy1Doc : public CDocument
{
protected: // �������л�����
	CMy1Doc();
	DECLARE_DYNCREATE(CMy1Doc)

// ����
public:
	char *pFileBuf;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMy1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnImageprocessingOpenbmpfile();
	afx_msg void OnImageprocessingSavetonewbmpfile();
	afx_msg void OnImageprocessingImageinterpolation();
};


