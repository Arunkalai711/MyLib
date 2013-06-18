#include "stdafx.h"
#include "MyException.h"

using namespace MyLib::Exception;

CMyException::CMyException(const char* szFileName, int nLine, const char* szMessage):
	std::exception(), m_what() {
	std::ostringstream oss;
	oss << "[" << (const char*)(strrchr(szFileName, '\\') + 1) << ":" << nLine << "]" << szMessage;
	m_what = oss.str();
}
CMyException::~CMyException(){}
