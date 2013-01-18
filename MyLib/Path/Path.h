#pragma once

#include <string>

namespace MyLib {
namespace Path {

std::wstring append(const std::wstring& src, const std::wstring& appendpath);
std::wstring append(const std::wstring& src, const wchar_t* appendpath);

std::wstring filename(const std::wstring& path);
std::wstring filename(const wchar_t* path);
namespace A {
std::string filename(const std::string& path);
std::string filename(const char* path);
}

bool isExsist(const std::wstring& path);

}
}