#pragma once

#include <algorithm>

class EncryptSimple {
private:
    const std::string _Alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    const std::string _Conversion { "AXCZQBYIJGWEHNDFOPRTLVSUMK" };
public:
    std::string decrypt(const std::string& source) const {
        std::string s;
        s.resize(source.length());
        std::ranges::transform(source, s.begin(), [](unsigned char c) { return std::toupper(c); });

        std::string return_value { };
        for(int i = 0; i < s.length(); i ++) {
            size_t c = _Conversion.find(s[i]);
            return_value += c != std::string::npos ? _Alphabet[c] : s[i];
        }
        return return_value;
    }
    std::string encrypt(const std::string & source) const {
        std::string s;
        s.resize(source.length());
        std::ranges::transform(source, s.begin(), [](unsigned char c) { return std::toupper(c); });

        std::string return_value { };
        for(int i = 0; i < s.length(); i ++) {
            size_t c = _Alphabet.find(s[i]);
            return_value += c != std::string::npos ? _Conversion[c] : s[i];
        }
        return return_value;
    }
};