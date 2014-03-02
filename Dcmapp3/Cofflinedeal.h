#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <algorithm>
#include <utility>

// Cofflinedeal �Ի���

class Cofflinedeal : public CDialogEx
{
	DECLARE_DYNAMIC(Cofflinedeal)

public:
	Cofflinedeal(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cofflinedeal();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	HANDLE handle_cal_control;
	void exec_once(){
		static bool flag = false;
		if(flag)return;
		flag = true;
		cal_mutex = CreateMutex(NULL, false, L"calmutex");
	}
	static bool is_cal_ing;
	static HANDLE cal_mutex;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton8();
	CProgressCtrl ProcessCtrl;
	static DWORD WINAPI  controlprocess(LPVOID lpParameter);
	CStatic ShowProcessStatusTxt;
};
