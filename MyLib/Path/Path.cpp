#include "stdafx.h"
#include "Path.h"

std::tstring MyLib::Path::append(const std::tstring& src, const std::tstring& appendpath) {
	return MyLib::Path::append(src, appendpath.c_str());
}

std::tstring MyLib::Path::append(const std::tstring& src, const TCHAR* appendpath) {
	if(	(appendpath == NULL) ||
		(_tcslen(appendpath) == 0)	) {
		return src;
	}
	std::tstring src_copy(src);
	if((*(src_copy.rbegin())) != _T('\\'))	src_copy += _T('\\');
	return src_copy.append(appendpath);
}

std::tstring MyLib::Path::removeExtention(const std::tstring& src) {
	std::tstring::size_type index = src.find_last_of(_T("."));
	return ((index != std::tstring::npos) ? src.substr(0, index) : src);
}
std::tstring MyLib::Path::renameExtention(const std::tstring& src, const std::tstring& extention) {
	return MyLib::Path::renameExtention(src, extention.c_str());
}
std::tstring MyLib::Path::renameExtention(const std::tstring& src, const TCHAR* extention) {
	std::tstring::size_type srcExtentionIndex = src.find_last_of(_T("."));
	if(srcExtentionIndex == std::tstring::npos) {
		return src;
	}
	std::tstring removed = removeExtention(src);
	size_t extentionLength = ((extention != NULL) ? _tcslen(extention) : 0);
	if(extentionLength == 0) {
		return removed;
	}
	if(extention[0] != _T('.')) {
		removed += _T('.');
	}
	return removed.append(extention);
}

std::tstring MyLib::Path::filename(const TCHAR* path) {
	return MyLib::Path::filename(std::tstring(path));
}
std::tstring MyLib::Path::filename(const std::tstring& path) {
	std::tstring::size_type pos = path.find_last_of(_T('\\'), 0);
	if(pos == std::tstring::npos) {
		return std::tstring();
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
std::wstring MyLib::Path::W::filename(const wchar_t* path) {
	return MyLib::Path::W::filename(std::wstring(path));
}
std::wstring MyLib::Path::W::filename(const std::wstring& path) {
	std::wstring::size_type pos = path.find_last_of('\\', 0);
	if(pos == std::wstring::npos) {
		return std::wstring();
	}
	return path.substr(pos);
}
