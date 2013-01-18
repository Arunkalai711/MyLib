#include "Path.h"
#include <Windows.h>

bool MyLib::Path::isExsist(const std::wstring& path) {
	bool result = false;
	WIN32_FIND_DATAW fd = {0};
	HANDLE find = ::FindFirstFileW(path.c_str(), &fd);
	if(find != INVALID_HANDLE_VALUE) {
		result = true;
		::CloseHandle(find);
	}
	return result;
}
