#pragma once

#include <wincrypt.h>

namespace MyLib {
namespace Crypto {

class CCryptoKey {
public:
	CCryptoKey() : m_CryptoKey(NULL) {
	}
	explicit CCryptoKey(HCRYPTKEY cryptoKey) : m_CryptoKey(cryptoKey) {
	}
	~CCryptoKey() {
		this->release();
	}
public:
	void attach(HCRYPTKEY cryptoKey) {
		this->release();
		m_CryptoKey = cryptoKey;
	}
	void release() {
		if(m_CryptoKey != NULL) {
			::CryptDestroyKey(m_CryptoKey);
			m_CryptoKey = NULL;
		}
	}
	operator HCRYPTKEY() {
		return m_CryptoKey;
	}
	operator HCRYPTKEY*() {
		return &m_CryptoKey;
	}
private:
	HCRYPTKEY m_CryptoKey;
};

}
}