// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dcmapp3.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Dcmapp3Dlg.h"

// CLogin �Ի���

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin::IDD, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CLogin ��Ϣ�������


void CLogin::OnBnClickedOk()
{
	CString username, password;
	GetDlgItemText(IDC_EDIT1, username);
	GetDlgItemText(IDC_EDIT4, password);
	if(username == "test" && password == "test"){
		CDcmapp3Dlg::login_state = true;
		CDcmapp3Dlg::username = username;
		AfxMessageBox(L"��¼�ɹ�");
		OnOK();
	}
	else
		{
		AfxMessageBox(L"��¼ʧ��");	
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
