// ShowCalProcess.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dcmapp3.h"
#include "ShowCalProcess.h"
#include "afxdialogex.h"
#include "Patient_information.h"
#include "common.h"
// CShowCalProcess �Ի���

IMPLEMENT_DYNAMIC(CShowCalProcess, CDialogEx)
std::string CShowCalProcess::id = "";
std::string CShowCalProcess::name = "";
std::vector <Patient_information> CShowCalProcess::res;
CShowCalProcess::CShowCalProcess(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowCalProcess::IDD, pParent)
{

}

CShowCalProcess::~CShowCalProcess()
{
}

void CShowCalProcess::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, ProcessCtrl);
	DDX_Control(pDX, IDC_EDIT4, doing);
	DDX_Control(pDX, IDC_BUTTON1, cancel_button);
}


BEGIN_MESSAGE_MAP(CShowCalProcess, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CShowCalProcess::OnBnClickedButton1)
END_MESSAGE_MAP()


// CShowCalProcess ��Ϣ�������
struct threaddata{
	CStatic * text;
	CProgressCtrl * speed;
	CShowCalProcess * reverse_ptr;
};

BOOL CShowCalProcess::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	finished = false;
	threaddata * tmp = new threaddata();
	tmp -> text = & doing;
	tmp -> speed = &ProcessCtrl;
	tmp -> reverse_ptr = this;
	handle = CreateThread(0, 0, getonlinedata, tmp, 0, 0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
DWORD WINAPI  CShowCalProcess::getonlinedata(LPVOID lpParameter){

		//here to get data...
		threaddata * tmp = (threaddata *)(lpParameter);
		CProgressCtrl *Speed = tmp -> speed;
		CStatic * text = tmp -> text;
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
		res.clear();
		std::shared_ptr <ADOConn> getcon = ADOConn::sharedSingleton();
		bool search_flag = true;
		res = getcon -> search_both(id, name);
		std::sort(res.begin(), res.end(), cmp);
		if(res.size() == 0){
			AfxMessageBox(L"�Ҳ�����������");
		}
		tmp -> reverse_ptr -> cancel_button.SetWindowTextW(L"���");
		tmp -> reverse_ptr -> finished = true;
		return 0;
	}



void CShowCalProcess::OnBnClickedButton1()
{
	if(finished){
		OnOK();
	}
	else{
		TerminateThread(handle, 1);
		OnCancel();
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
