#pragma once

#include <Windows.h>
#include <tchar.h>
#include <list>
#include <string>
#include "../tstring/tstring.h"

namespace MyLib {
namespace File {

class CFileEnumrator {
public:
	typedef std::list<std::tstring> FileList;

public:
	explicit CFileEnumrator(const TCHAR* target);
	explicit CFileEnumrator(const std::tstring& target);
	~CFileEnumrator();

private:
	void enumrate(const TCHAR* target);

public:
	FileList filelist() const {
		return m_list;
	};

private:
	FileList m_list;
};

}
}
