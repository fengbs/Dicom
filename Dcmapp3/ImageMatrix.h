#pragma once
#include "DCMHeaders.h"
#include <string>
class ImageMatrix
{
private:
	CString patientid;
	CString patientname;
	Uint16 mRows;
	Uint16 mColumns;
	//����Դָ��
	Uint16 *mPixData16;
	Uint8 *mPixData8;
	double mWindowCenter;
	double mWindowWidth;
	int mPixLength;
	bool kind;
public:
	ImageMatrix(void);
	ImageMatrix(DcmDataset *dataset);
	~ImageMatrix(void);
	CString getname(){
		return patientname;
	}
	CString getid(){
		return patientid;
	}
	Uint16 getRows();
	Uint16 getColumns();
	double getWinCenter();
	double getWinWidth();
	static std::string get_patientname(const std::string &);//get a file's patient name
	//�õ�[row,column]����pixel data
	//get pixel data of the position
	Uint8 getUint8Pixel(int row, int column);
	Uint16 getUint16Pixel(int row, int column);
	void setUint16Pixel(int row, int column, Uint16 pixelValue);
	//�õ�����ָ��
	Uint8* getUint8Data();
	Uint16* getUint16Data();
	CString mContentTime;
	CString mTestInfo;
	Uint8 mIndex;
	Float64 pixelSpacing;//ÿ������֮���ʵ�ʾ��� ��λ�Ǻ���
	Float64 sliceThickness;//��Ƭ���
	Float32 PWICoe;//һ��PWIϵ��
};
