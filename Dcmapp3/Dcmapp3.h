
// Dcmapp3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDcmapp3App:
// �йش����ʵ�֣������ Dcmapp3.cpp
//

class CDcmapp3App : public CWinApp
{
public:
	CDcmapp3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDcmapp3App theApp;