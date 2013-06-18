#include "stdafx.h"
#include "Path.h"

bool MyLib::Path::isExsist(const std::tstring& path) {
	bool result = false;
	WIN32_FIND_DATA fd = {0};
	HANDLE find = ::FindFirstFile(path.c_str(), &fd);
	if(find != INVALID_HANDLE_VALUE) {
		result = true;
		::CloseHandle(find);
	}
	return result;
}
