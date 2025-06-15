#include "encryption.h"
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

std::string aes256EncryptCBC(const std::string& plaintext, const std::string& key, const std::string& iv) {
    std::string ciphertext;

    CBC_Mode<AES>::Encryption encryption;
    encryption.SetKeyWithIV(reinterpret_cast<const byte*>(key.data()), key.size(),
                            reinterpret_cast<const byte*>(iv.data()));

    StringSource ss(plaintext, true,
        new StreamTransformationFilter(encryption,
            new StringSink(ciphertext)
        )
    );
    return ciphertext;
}

std::string aes256DecryptCBC(const std::string& ciphertext, const std::string& key, const std::string& iv) {
    std::string decrypted;

    CBC_Mode<AES>::Decryption decryption;
    decryption.SetKeyWithIV(reinterpret_cast<const byte*>(key.data()), key.size(),
                            reinterpret_cast<const byte*>(iv.data()));

    StringSource ss(ciphertext, true,
        new StreamTransformationFilter(decryption,
            new StringSink(decrypted)
        )
    );
    return decrypted;
}
