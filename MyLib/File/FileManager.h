#pragma once

#include <string>
#include <Windows.h>

namespace MyLib
{
	namespace File
	{
		class CFileManager
		{
		public:
			static const int OM_Read		= 0x00000001;
			static const int OM_Write		= 0x00000002;
			static const int OM_ReadWrite	= (OM_Read | OM_Write);
		public:
			CFileManager();
			explicit CFileManager(const wchar_t* strFileName);
			explicit CFileManager(unsigned int nOpenMode);
			CFileManager(const wchar_t* strFileName, unsigned int nOpenMode);
			virtual ~CFileManager();

		public:
			void Open(){Open(m_FileName, m_OpenMode);};
			void Open(const wchar_t* strFileName){Open(strFileName, m_OpenMode);};
			void Open(unsigned int nOpenMode){Open(m_FileName, nOpenMode);};
			void Open(const std::wstring& strFileName, unsigned int nOpenMode){Open(strFileName.c_str(), nOpenMode);};
			void Open(const wchar_t* strFileName, unsigned int nOpenMode);
			void Close();

			void SetFileName(const wchar_t* strFileName);
			void SetOpenMode(int nOpenMode);

			bool IsOpen(){return (m_File != INVALID_HANDLE_VALUE);};
			HANDLE GetHandle(){return m_File;};
			std::wstring GetFileName(){return m_FileName;};
		private:
			HANDLE m_File;
			std::wstring m_FileName;
			unsigned int m_OpenMode;
		};
	};
};
// ---------- End Of File --------------------------------------------------- //
