#pragma once

#include <list>
#include <string>

namespace MyLib {
namespace File {

class CFileEnumrator {
public:
	typedef std::list<std::wstring> FileList;

public:
	explicit CFileEnumrator(const wchar_t* target);
	explicit CFileEnumrator(const std::wstring& target);
	~CFileEnumrator();

private:
	void enumrate(const wchar_t* target);

public:
	FileList filelist() const {
		return m_list;
	};

private:
	FileList m_list;
};

}
}
