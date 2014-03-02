#pragma once
#include "afxcmn.h"
#include "DCMPatientInfo.h"
#include "Patient_information.h"
#include "ADOConn.h"
#include "common.h"
#include <memory>
// Conlinedeal �Ի���

class Conlinedeal : public CDialogEx
{
	DECLARE_DYNAMIC(Conlinedeal)

public:
	Conlinedeal(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Conlinedeal();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	int patient_id, show_index;
	CString patient_name, patient_dir;
	std::shared_ptr <DCMPatientInfo> patient_info;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl person_inf;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
