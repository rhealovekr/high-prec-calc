
// high-prec-calc.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// ChighpreccalcApp:
// �� Ŭ������ ������ ���ؼ��� high-prec-calc.cpp�� �����Ͻʽÿ�.
//

class ChighpreccalcApp : public CWinApp
{
public:
	ChighpreccalcApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern ChighpreccalcApp theApp;
