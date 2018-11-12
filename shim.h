#ifndef __COPENSSL_SHIM_H__
#define __COPENSSL_SHIM_H__

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <openssl/ripemd.h>
#include <openssl/pkcs12.h>
#include <openssl/x509v3.h>

// Initialize OpenSSL
static inline void OpenSSL_SSL_init(void) {

	SSL_library_init();
	SSL_load_error_strings();
	OPENSSL_config(NULL);
	OPENSSL_add_all_algorithms_conf();
}

// This is a wrapper function to get client SSL_METHOD based on OpenSSL version.
static inline const SSL_METHOD *OpenSSL_client_method(void) {

        #if (OPENSSL_VERSION_NUMBER < 0x10100000L)
                return SSLv23_client_method();
        #else
                return TLS_client_method();
        #endif
}

static inline long OpenSSL_SSL_CTX_set_mode(SSL_CTX *context, long mode) {
        return SSL_CTX_set_mode(context, mode);
}

static inline long OpenSSL_SSL_CTX_set_options(SSL_CTX *context) {
        return SSL_CTX_set_options(context, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION);
}

#endif
