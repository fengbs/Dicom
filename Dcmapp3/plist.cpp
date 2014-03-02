// plist.h : Cplist ���ʵ��



// Cplist ʵ��

// ���������� 2013��10��24��, 17:50

#include "stdafx.h"
#include "plist.h"
IMPLEMENT_DYNAMIC(Cplist, CRecordset)

Cplist::Cplist(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_pid = "";
	m_pname = "";
	m_pdir = "";
	m_pwicount = 0;
	m_dwicount = 0;
	m_modifytime;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cplist::GetDefaultConnect()
{
	return _T("DSN=attacker;Description=attacker;UID=sa;PWD=kobe31413;APP=Microsoft\x00ae Visual Studio\x00ae 2012;WSID=ATTACKER-PC;DATABASE=attacker;QuotedId=No;");
}

CString Cplist::GetDefaultSQL()
{
	return _T("[dbo].[plist]");
}

void Cplist::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[pid]"), m_pid);
	RFX_Text(pFX, _T("[pname]"), m_pname);
	RFX_Text(pFX, _T("[pdir]"), m_pdir);
	RFX_Long(pFX, _T("[pwicount]"), m_pwicount);
	RFX_Long(pFX, _T("[dwicount]"), m_dwicount);
	RFX_Date(pFX, _T("[modifytime]"), m_modifytime);

}
/////////////////////////////////////////////////////////////////////////////
// Cplist ���

#ifdef _DEBUG
void Cplist::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cplist::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


