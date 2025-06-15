#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

std::string aes256EncryptCBC(const std::string& plaintext, const std::string& key, const std::string& iv);
std::string aes256DecryptCBC(const std::string& ciphertext, const std::string& key, const std::string& iv);

#endif
