// Cshowperson.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dcmapp3.h"
#include "Cshowperson.h"
#include "afxdialogex.h"
#include "common.h"

// Cshowperson �Ի���

IMPLEMENT_DYNAMIC(Cshowperson, CDialogEx)

Cshowperson::Cshowperson(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cshowperson::IDD, pParent)
	, pwivalue(0)
	, dwivalue(0)
	, mismatch(0)
{

}

Cshowperson::~Cshowperson()
{
}

void Cshowperson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT100, pwivalue);
	DDX_Text(pDX, IDC_EDIT102, dwivalue);
	DDX_Text(pDX, IDC_EDIT101, mismatch);
	DDX_Control(pDX, IDC_PIC_STATIC, picdata);
}


BEGIN_MESSAGE_MAP(Cshowperson, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &Cshowperson::OnNMDblclkList1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Cshowperson ��Ϣ�������


BOOL Cshowperson::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(string_to_lpsctr("����" + id));
	pwivalue = patient_data -> getPWIVolumn();
	dwivalue = patient_data -> getDWIVolumn();
	mismatch = pwivalue / dwivalue;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void Cshowperson::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	Cshowperson p;
	p.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void Cshowperson::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CImage img;
	img.Load(L"dicom.png");
	CRect rect;
	picdata.GetClientRect(&rect);
	CDC * pdc = picdata.GetDC();
	SetStretchBltMode(pdc -> m_hDC, STRETCH_HALFTONE);
	int width = img.GetWidth();
	int height = img.GetHeight();
	if(height <= rect.Height() && width <= rect.Width()){
		CRect rect1 = CRect(rect.TopLeft(), CSize(width, height));
		img.StretchBlt(pdc -> m_hDC, rect1, SRCCOPY);
	}
	else{
		float xscale = (float)rect.Width() / (float)width;
		float yscale = (float)rect.Height() / height;
		float scaleindex = (xscale < yscale) ? xscale: yscale;
		CRect rect1 = CRect(rect.TopLeft(), CSize(rect.Width(), rect.Height()));
		img.StretchBlt(pdc -> m_hDC, rect1, SRCCOPY);
	}
	ReleaseDC(pdc);
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
