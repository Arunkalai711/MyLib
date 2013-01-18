#include "ApplicationInfo.h"

#include <Windows.h>

std::wstring MyLib::App::modulefilename() {
	wchar_t filename[1024] = {0};
	::GetModuleFileNameW(NULL, filename, _countof(filename));
	return std::wstring(filename);
}

std::wstring MyLib::App::modulepath() {
	std::wstring filename = MyLib::App::modulefilename();
	return filename.substr(0, filename.find_last_of(L"\\"));
}
