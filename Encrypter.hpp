#pragma once

#include <iostream>

class EncryptSimple {
private:
    const std::string _Alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    const std::string _Conversion { "AXCZQBYIJGWEHNDFOPRTLVSUMK" };
public:
    std::string decrypt(const std::string& s) const {
        std::string return_value { };
        int length = s.length();
        for(int i = 0; i < length; i ++) {
            size_t c = _Conversion.find(s[i]);
            return_value += c != std::string::npos ? _Alphabet[c] : s[i];
        }
        return return_value;
    }
    std::string encrypt(const std::string & s) const {
        std::string return_value { };
        int length = s.length();
        for(int i = 0; i < length; i ++) {
            size_t c = _Alphabet.find(s[i]);
            return_value += c != std::string::npos ? _Conversion[c] : s[i];
        }
        return return_value;
    }
};