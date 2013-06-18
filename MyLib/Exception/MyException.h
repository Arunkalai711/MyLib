#pragma once

#include <exception>
#include <string>

namespace MyLib {

namespace Exception {

#define	RAISE_MYEXCEPTION(message)										\
	{																	\
		MyLib::Exception::CMyException e(__FILE__, __LINE__, message);	\
		throw e;														\
	}

class CMyException : public std::exception {
public:
	CMyException(const char* szFilePath, int nLine, const char* szMessage);
	virtual	~CMyException();
	virtual const char* what() const {return m_what.c_str();};
private:
	std::string m_what;
};

}
}
