#include <iostream>
using namespace std;

class CMyString
{
private:
	char* m_pData;
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);//����ʹ�ó������ô���
	~CMyString();
	CMyString& operator =(const CMyString& str);//��һ�����ÿ��Խ���������ֵ���ڶ������÷�ֹ�������ø�ֵ���캯����Ӱ�����ִ��Ч��
};

//����
CMyString& CMyString::operator =(const CMyString& str)
{
	if (this == &str)
	{
		return *this;
	}
	delete[]m_pData;
	m_pData = nullptr;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

//�߼�
CMyString& CMyString::operator =(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

