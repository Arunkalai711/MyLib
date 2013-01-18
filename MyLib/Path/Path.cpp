#include "Path.h"

std::wstring MyLib::Path::append(const std::wstring& src, const std::wstring& appendpath) {
	return MyLib::Path::append(src, appendpath.c_str());
}

std::wstring MyLib::Path::append(const std::wstring& src, const wchar_t* appendpath) {
	std::wstring src_copy(src);
	if((*(src_copy.rbegin())) != L'\\')	src_copy += L'\\';
	return src_copy.append(appendpath);
}

std::wstring MyLib::Path::filename(const wchar_t* path) {
	return MyLib::Path::filename(std::wstring(path));
}
std::wstring MyLib::Path::filename(const std::wstring& path) {
	std::wstring::size_type pos = path.find_last_of(L'\\', 0);
	if(pos == std::wstring::npos) {
		return std::wstring();
	}
	return path.substr(pos);
}
std::string MyLib::Path::A::filename(const char* path) {
	return MyLib::Path::A::filename(std::string(path));
}
std::string MyLib::Path::A::filename(const std::string& path) {
	std::string::size_type pos = path.find_last_of('\\', 0);
	if(pos == std::string::npos) {
		return std::string();
	}
	return path.substr(pos);
}
