#include <iostream>
using namespace std;

class CMyString
{
private:
	char* m_pData;
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);//必须使用常量引用传参
	~CMyString();
	CMyString& operator =(const CMyString& str);//第一个引用可以进行连续赋值，第二个引用防止连续调用赋值构造函数，影响程序执行效率
};

//初级
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

//高级
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

