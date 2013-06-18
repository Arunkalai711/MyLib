#pragma once

#include <string>
#include <fstream>
#include <sstream>

namespace std {

#ifdef UNICODE

	typedef std::wstring		tstring;
	typedef std::wifstream		tifstream;
	typedef std::wofstream		tofstream;
	typedef std::wfstream		tfstream;
	typedef std::wistringstream	tistringstream;
	typedef std::wostringstream	tostringstream;
	typedef std::wstringstream	tstringstream;

#else

	typedef std::string			tstring;
	typedef std::ifstream		tifstream;
	typedef std::ofstream		tofstream;
	typedef std::fstream		tfstream;
	typedef std::istringstream	tistringstream;
	typedef std::ostringstream	tostringstream;
	typedef std::stringstream	tstringstream;

#endif


}
