#pragma once

#include <wincrypt.h>

namespace MyLib {
namespace Crypto {

class CCryptoProvider {
public:
	CCryptoProvider() : m_CryptoProvider(NULL) {
	}
	explicit CCryptoProvider(HCRYPTPROV cryptoProvider) : m_CryptoProvider(cryptoProvider) {
	}
	~CCryptoProvider() {
		this->release();
	}
public:
	void attach(HCRYPTPROV cryptoProvider) {
		this->release();
		m_CryptoProvider = cryptoProvider;
	}
	void release() {
		if(m_CryptoProvider != NULL) {
			::CryptReleaseContext(m_CryptoProvider, 0);
			m_CryptoProvider = NULL;
		}
	}
	operator HCRYPTPROV() {
		return m_CryptoProvider;
	}
	operator HCRYPTPROV*() {
		return &m_CryptoProvider;
	}
private:
	HCRYPTPROV m_CryptoProvider;
};

}
}