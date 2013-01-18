#include "FileEnumrator.h"
#include <Windows.h>

MyLib::File::CFileEnumrator::CFileEnumrator(const wchar_t* target) : m_list() {
	this->enumrate(target);
}
MyLib::File::CFileEnumrator::CFileEnumrator(const std::wstring& target) : m_list() {
	this->enumrate(target.c_str());
}

MyLib::File::CFileEnumrator::~CFileEnumrator() {
}

void MyLib::File::CFileEnumrator::enumrate(const wchar_t* target) {
	// ファイル検索ループ
	WIN32_FIND_DATAW finddata = {0};
	HANDLE find = ::FindFirstFileW(target, &finddata);
	if(find != INVALID_HANDLE_VALUE) {
		do {
			// ".", ".." は無視
			if(	(wcscmp(finddata.cFileName, L".") != 0) ||
				(wcscmp(finddata.cFileName, L"..") != 0)	) {
				// リストへ追加
				m_list.push_back(std::wstring(finddata.cFileName));
			}
		} while (	::FindNextFileW(find, &finddata) ||
					(::GetLastError() == ERROR_MORE_DATA)	);
		::FindClose(find);
	}
}
