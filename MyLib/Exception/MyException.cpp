#include "MyException.h"

#include <sstream>

using namespace MyLib::Exception;

CMyException::CMyException(const char* szFileName, int nLine, const char* szMessage):
	std::exception(), m_what() {
	std::ostringstream oss;
	oss << L"[" << (const char*)(strrchr(szFileName, '\\') + 1) << L":" << nLine << L"]" << szMessage;
	m_what = oss.str();
}
CMyException::~CMyException(){}
