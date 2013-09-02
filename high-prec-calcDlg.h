
// high-prec-calcDlg.h : 헤더 파일
//

#pragma once


// ChighpreccalcDlg 대화 상자
class ChighpreccalcDlg : public CDialogEx
{
// 생성입니다.
public:
	ChighpreccalcDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HIGHPRECCALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

