#pragma once
#include "DCMPatientInfo.h"
#include <memory>
#include "afxwin.h"

// Cshowperson �Ի���

class Cshowperson : public CDialogEx
{
	DECLARE_DYNAMIC(Cshowperson)

public:
	Cshowperson(CWnd* pParent = NULL);   // ��׼���캯��
	void setdata(std::shared_ptr <DCMPatientInfo> _patient_data, std::string _id){
		id = _id;
		patient_data = _patient_data;
	}
	virtual ~Cshowperson();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	std::shared_ptr <DCMPatientInfo> patient_data;
	std::string id;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	double pwivalue;
	double dwivalue;
	double mismatch;
	CStatic picdata;
	afx_msg void OnPaint();
};
