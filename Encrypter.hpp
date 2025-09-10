#pragma once

#include <algorithm>
#include <utility>

class EncryptSimple {
private:
    const std::string Alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    std::string Conversion { };
public:
    explicit EncryptSimple(std::string  conversionTable) : Conversion(std::move(conversionTable)) { }
    [[nodiscard]] std::string decrypt(const std::string& source) const {
        std::string s;
        s.resize(source.length());
        std::ranges::transform(source, s.begin(), ::toupper);

        std::string return_value { };
        for(int i = 0; i < s.length(); i ++) {
            const size_t c = Conversion.find(s[i]);
            return_value += c != std::string::npos ? Alphabet[c] : s[i];
        }
        return return_value;
    }
    [[nodiscard]] std::string encrypt(const std::string & source) const {
        std::string s;
        s.resize(source.length());
        std::ranges::transform(source, s.begin(), ::toupper);

        std::string return_value { };
        for(int i = 0; i < s.length(); i ++) {
            const size_t c = Alphabet.find(s[i]);
            return_value += c != std::string::npos ? Conversion[c] : s[i];
        }
        return return_value;
    }
    void SetConversionTable(const std::string & conversion_table) {
        Conversion = conversion_table;
    }
};