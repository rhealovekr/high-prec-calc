
// high-pre-calcDlg.h : ��� ����
//

#pragma once


// ChighprecalcDlg ��ȭ ����
class ChighprecalcDlg : public CDialogEx
{
// �����Դϴ�.
public:
	ChighprecalcDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HIGHPRECALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRadioButtonClicked();
	afx_msg void OnEnUpdateEdit1();
	BOOL ValidateNumber(CString number);
	void UpdateExp();
	int m_nRadioSelected;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	BOOL ValidateDot(CString number);
};

