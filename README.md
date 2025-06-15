# CryptoKeyLogger

**CryptoKeyLogger** is a powerful AES-256 CBC-mode based keylogger designed for cybersecurity monitoring, analysis, and research purposes. Unlike typical keyloggers, this tool ensures secure logging by encrypting every keystroke using military-grade cryptography, making it suitable for Red Team operations, forensic analysis, and controlled penetration testing.

---

## 🧠 Features

- 🛡️ **AES-256 Encryption (CBC Mode)** for secure keystroke logging
- 🧬 **Stealth Mode** – Hides the console window on execution
- 🧾 **Cross-compatible C++ Design**
- 🔒 **Logs stored in encrypted binary format**
- ⚡ **Lightweight and Efficient**

---

## 🧰 Tech Stack

| Component       | Usage                        |
|----------------|------------------------------|
| `C++`           | Core logic & keylogging      |
| `Crypto++`      | AES-256 encryption library   |
| `Windows API`   | Keystroke capture & stealth  |

---

## 📁 Project Structure

```

CryptoKeyLogger/
├── encryption.h          # AES-256 CBC Encrypt/Decrypt Headers
├── encryption.cpp        # Core AES logic using Crypto++
├── keylogger.cpp         # Main keylogging logic
├── keylog\_cbc\_encrypted.log  # Output log (encrypted)
├── README.md             # You’re reading it!

````

---

## ⚙️ Setup & Build Instructions

### 🔧 Prerequisites

- [Crypto++ Library](https://www.cryptopp.com/)
- C++ Compiler (g++, MSVC)

### 🛠️ Build with g++ (Linux/Windows with MinGW)
```bash
g++ keylogger.cpp encryption.cpp -lcryptopp -o CryptoKeyLogger.exe
````

### 🛠️ Build with MSVC (Visual Studio Command Prompt)

```cmd
cl keylogger.cpp encryption.cpp cryptlib.lib /EHsc
```

---

## 🚀 How to Run

1. Run the `CryptoKeyLogger.exe`
2. The logger will hide and begin capturing keystrokes
3. Encrypted output will be saved in `keylog_cbc_encrypted.log`

> 🔐 **NOTE**: The logger uses a hardcoded 32-byte AES key and 16-byte IV. You can customize them in `keylogger.cpp`.

---

## 🔓 Decrypting the Logs (Optional)

To convert encrypted logs back to readable text:

* Use `aes256DecryptCBC()` from `encryption.cpp` in a separate utility tool
* Supply the same AES key and IV

> 🧪 Decryption script available on request

---

## ⚠️ Legal Disclaimer

> This tool is intended for **educational, research, and authorized security testing only**. Unauthorized deployment or malicious use is strictly prohibited and punishable under cybersecurity laws. Use responsibly.

---

## 👨‍💻 Author

**Aditya Bhatt** <br/>
Cybersecurity Enthusiast | VAPT Specialist | InfoSec Writer <br/>

🔗 GitHub: [@AdityaBhatt3010](https://github.com/AdityaBhatt3010) <br/>
📝 Medium: [@adityabhatt3010](https://medium.com/@adityabhatt3010)

---

## 🧠 Inspiration

> *"Encrypt the inputs. Log the world. Secure the future."* 🧠🦇

---
