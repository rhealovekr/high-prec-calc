
// high-pre-calc.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// ChighprecalcApp:
// �� Ŭ������ ������ ���ؼ��� high-pre-calc.cpp�� �����Ͻʽÿ�.
//

class ChighprecalcApp : public CWinApp
{
public:
	ChighprecalcApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern ChighprecalcApp theApp;