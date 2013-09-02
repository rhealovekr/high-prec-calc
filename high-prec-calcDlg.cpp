
// high-prec-calcDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "high-prec-calc.h"
#include "high-prec-calcDlg.h"
#include "afxdialogex.h"
#include "mpirxx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ChighpreccalcDlg ��ȭ ����



ChighpreccalcDlg::ChighpreccalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChighpreccalcDlg::IDD, pParent)
	, m_nRadioSelected(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChighpreccalcDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Radio(pDX, IDC_RADIO1, m_nRadioSelected);

	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(ChighpreccalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &ChighpreccalcDlg::OnRadioButtonClicked)
	ON_BN_CLICKED(IDC_RADIO2, &ChighpreccalcDlg::OnRadioButtonClicked)
	ON_BN_CLICKED(IDC_RADIO3, &ChighpreccalcDlg::OnRadioButtonClicked)
	ON_BN_CLICKED(IDC_RADIO4, &ChighpreccalcDlg::OnRadioButtonClicked)
	ON_EN_CHANGE(IDC_EDIT1, &ChighpreccalcDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &ChighpreccalcDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &ChighpreccalcDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ChighpreccalcDlg �޽��� ó����
BOOL ChighpreccalcDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->wParam == VK_RETURN)
	{
		return TRUE;
	}
	if (pMsg->wParam == VK_F1)
	{
		CAboutDlg aboutDlg;
		aboutDlg.DoModal();
		return TRUE;
	}
	if (this->GetFocus() == GetDlgItem(IDC_EDIT3))
	{
		if (pMsg->message == WM_KEYDOWN && ::GetKeyState(VK_CONTROL) < 0)
		{
			switch (pMsg->wParam)
			{
			case 'Z':
				((CEdit*)GetDlgItem(IDC_EDIT3))->Undo();
				return TRUE;
			case 'X':
				((CEdit*)GetDlgItem(IDC_EDIT3))->Cut();
				return TRUE;
			case 'C':
				((CEdit*)GetDlgItem(IDC_EDIT3))->Copy();
				return TRUE;
			case 'V':
				((CEdit*)GetDlgItem(IDC_EDIT3))->Paste();
				return TRUE;
			case 'A':
				((CEdit*)GetDlgItem(IDC_EDIT3))->SetSel(0, -1);
				return TRUE;
			} 
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL ChighpreccalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T("A+B"));
	GetDlgItem(IDC_EDIT5)->SetWindowText(_T("128"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void ChighpreccalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void ChighpreccalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR ChighpreccalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void ChighpreccalcDlg::OnRadioButtonClicked()
{
	if (IsDlgButtonChecked(IDC_RADIO4))
	{
		GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	}

	UpdateExp();
}

void ChighpreccalcDlg::UpdateExp()
{
	CString input_a;
	CString input_b;
	GetDlgItem(IDC_EDIT1)->GetWindowText(input_a);
	GetDlgItem(IDC_EDIT2)->GetWindowText(input_b);
	if (ValidateNumber(input_a) && ValidateNumber(input_b))
	{

	}
	else
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Syntax Error"));
		return;
	}

	if (input_a.GetLength() == 0) input_a = _T("A");
	if (input_b.GetLength() == 0) input_b = _T("B");

	UpdateData(TRUE);

	//
	switch (m_nRadioSelected)
	{
	case 0:
	case 1:
	case 2:
		if (input_a.Find(_T(".")) > 0)
		{
			input_a = input_a.Left(input_a.Find(_T(".")));
		}
		if (input_b.Find(_T(".")) > 0)
		{
			input_b = input_b.Left(input_b.Find(_T(".")));
		}
		break;
	case 3:
		{
			// if dots more than two
			if (ValidateDot(input_a) == FALSE || ValidateDot(input_b) == FALSE)
			{
				GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Syntax Error"));
				return;
			}

			// division by zero
			if (input_b.GetAt(0) == _T('0'))
			{
				CString temp(input_b);
				temp.Remove(_T('.'));

				int n = temp.GetLength();
				if (n == temp.Remove(_T('0')))
				{
					GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Division by zero"));
					return;
				}
			}
		}
		break;
	default:
		break;
	}

	//
	CString op;
	switch (m_nRadioSelected)
	{
	case 0:
		op = _T("+");
		break;
	case 1:
		op = _T("-");
		break;
	case 2:
		op = _T("*");
		break;
	case 3:
		op = _T("/");
		break;
	default:
		break;
	}

	CString expression;
	expression.Format(_T("%s%s%s"), input_a, op, input_b);

	GetDlgItem(IDC_EDIT4)->SetWindowText(expression);
}

BOOL ChighpreccalcDlg::ValidateDot(CString number)
{
	int n = number.Remove(_T('.'));
	
	return n <= 1;
}

BOOL ChighpreccalcDlg::ValidateNumber(CString number)
{
	if (number.GetLength() == 0)
		return TRUE;

	// IsNumber
	CString temp(number);
	temp.Replace(_T("."), _T(""));

	if (temp.Find(_T("\\")) >= 0 ||
		temp.Find(_T("&")) >= 0)
		return FALSE;
	
	CComVariant v = temp;
	if (v.ChangeType(VT_R8) != S_OK)
	{
		// string is not number
		return FALSE;
	}

	//
	if (number.GetLength() > 1 && number.GetAt(0) == _T('0') && number.GetAt(1) != _T('.') ||
		number.GetAt(number.GetLength() - 1) == _T('-') ||
		number.GetAt(number.GetLength() - 1) == _T('+'))
		return FALSE;

	return TRUE;
}

void ChighpreccalcDlg::OnEnChangeEdit1()
{
	UpdateExp();
}


void ChighpreccalcDlg::OnEnChangeEdit2()
{
	UpdateExp();
}


void ChighpreccalcDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if (str.Compare(_T("Syntax Error")) == 0 ||
		str.Compare(_T("Division by zero")) == 0 ||
		str.Find(_T("A")) >= 0 ||
		str.Find(_T("B")) >= 0)
	{
		return;
	}

	CString input_a;
	CString input_b;
	GetDlgItem(IDC_EDIT1)->GetWindowText(input_a);
	GetDlgItem(IDC_EDIT2)->GetWindowText(input_b);

	switch (m_nRadioSelected)
	{
	case 0:
	case 1:
	case 2:
		{
			if (input_a.Find(_T(".")) > 0)
			{
				input_a = input_a.Left(input_a.Find(_T(".")));
			}
			if (input_b.Find(_T(".")) > 0)
			{
				input_b = input_b.Left(input_b.Find(_T(".")));
			}

			mpz_class a, b, c;
			a = ATL::CT2A(input_a.GetBuffer(0));
			b = ATL::CT2A(input_b.GetBuffer(0));
			switch (m_nRadioSelected)
			{
			case 0:
				c = a + b;
				break;
			case 1:
				c = a - b;
				break;
			case 2:
				c = a * b;
				break;
			default:
				break;
			}
			CString str(c.get_str().c_str());
			GetDlgItem(IDC_EDIT3)->SetWindowText(str);
		}
		break;
	case 3:
		{
			CString input_prec;
			GetDlgItem(IDC_EDIT5)->GetWindowText(input_prec);
			mpf_set_default_prec(atoi(ATL::CT2A(input_prec.GetBuffer(0))));
			
			mp_exp_t ex;
			mpf_class a, b, c;
			a = ATL::CT2A(input_a.GetBuffer(0));
			b = ATL::CT2A(input_b.GetBuffer(0));
			c = a / b;

			CString str(c.get_str(ex, 10).c_str());

			// exponent
			if (str.GetAt(0) == _T('-'))
				ex+=1;

			if (str.GetLength() != ex)
			{
				if (ex > 0)
				{
					if (ex > str.GetLength())
					{
						// x000...0
						for (int i = 1; i < ex; ++i)
						{
							str.Insert(str.GetLength(), _T('0'));
						}
					}
					else
					{
						str.Insert(ex, _T('.'));
					}
				}
				else
				{
					// 0.000...x
					for (int i = ex; i <= 0; ++i)
					{
						str.Insert(0, _T('0'));
					}
					str.Insert(1, _T('.'));
				}
			}
			GetDlgItem(IDC_EDIT3)->SetWindowText(str);
		}
		break;
	default:
		break;
	}
}
