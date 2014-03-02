// Cofflinedeal.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dcmapp3.h"
#include "Cofflinedeal.h"
#include "afxdialogex.h"


// Cofflinedeal �Ի���

bool Cofflinedeal::is_cal_ing = false;
HANDLE Cofflinedeal::cal_mutex = NULL;
IMPLEMENT_DYNAMIC(Cofflinedeal, CDialogEx)

Cofflinedeal::Cofflinedeal(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cofflinedeal::IDD, pParent)
{
 
}
DWORD WINAPI  Cofflinedeal::controlprocess(LPVOID lpParameter){
	std::pair <CStatic *, CProgressCtrl *> * pair = (std::pair <CStatic *,  CProgressCtrl *> *)(lpParameter);
	CProgressCtrl *Speed = pair -> second;
	CStatic * text = pair -> first;
	text -> SetWindowTextW(L"��ʼ����");
	for (int i = 0; i < 1000; i++)  
	{  
		Speed -> SetPos(i);
		if(i == 250)
			text -> SetWindowTextW(L"���ڼ���ADC");
		else
		if(i == 500)
			text -> SetWindowTextW(L"���ڼ���MTT");
		else
			if(i == 750)
				text -> SetWindowTextW(L"���ڼ�����");
		Sleep(10);
	}	  
	AfxMessageBox(L"�������");
	int result = WaitForSingleObject(cal_mutex, INFINITE);
	is_cal_ing = false;
	ReleaseMutex(cal_mutex);
	return 0;
}

Cofflinedeal::~Cofflinedeal()
{

}

void Cofflinedeal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, ProcessCtrl);
	DDX_Control(pDX, IDC_EDIT9, ShowProcessStatusTxt);
}


BEGIN_MESSAGE_MAP(Cofflinedeal, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON8, &Cofflinedeal::OnBnClickedButton8)
END_MESSAGE_MAP()


// Cofflinedeal ��Ϣ�������


BOOL Cofflinedeal::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ProcessCtrl.SetRange(0, 1000);
	ProcessCtrl.SetStep(1);
	exec_once();
	//ModifyStyle(0, WS_CHILD);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void Cofflinedeal::OnBnClickedButton8()
{
	int result = WaitForSingleObject(cal_mutex, INFINITE);
	if(is_cal_ing){
		AfxMessageBox(L"���ڼ���");
		ReleaseMutex(cal_mutex);
		return;
	}
	is_cal_ing = true;
	ReleaseMutex(cal_mutex);
	std::pair <CStatic *, CProgressCtrl *> * tmp_pair = new std::pair <CStatic *, CProgressCtrl *>;
	tmp_pair -> first = &ShowProcessStatusTxt;
	tmp_pair -> second = &ProcessCtrl;
	handle_cal_control = CreateThread(0,0, controlprocess,tmp_pair, 0,0); 
}
