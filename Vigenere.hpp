#pragma once

#include <algorithm>

class Vigenere {
private:
    const std::string Alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    const size_t Length = Alphabet.length();
public:
    [[nodiscard]] std::string encrypt(const std::string & source, const std::string & key) const {
        std::string s;
        s.resize(source.length());
        std::ranges::transform(source, s.begin(), [](const unsigned char c) { return std::toupper(c); });

        std::string k;
        k.resize(key.length());
        std::ranges::transform(key, k.begin(), [](const unsigned char c) { return std::toupper(c); });
        
        std::string return_value { };
        const size_t length = s.length();
        int key_counter = 0;
        for(int i = 0; i < length; i ++) {
            if(const size_t column_index = Alphabet.find(s[i]); column_index != std::string::npos) {
                const char key_char = k[(key_counter ++) % k.length()];
                const size_t row_index = Alphabet.find(key_char);
                const char result = Alphabet[(column_index + row_index) % Length];
                return_value += result;
            } else {
                return_value += s[i];
            }
        }
        return return_value;
    }
    [[nodiscard]] std::string decrypt(const std::string & source, const std::string & key) const {
        std::string s;
        s.resize(source.length());
        std::ranges::transform(source, s.begin(), [](const unsigned char c) { return std::toupper(c); });

        std::string k;
        k.resize(key.length());
        std::ranges::transform(key, k.begin(), [](const unsigned char c) { return std::toupper(c); });
        
        std::string return_value { };
        const size_t length = s.length();
        int key_counter = 0;
        for(int i = 0; i < length; i ++) {
            const char key_char = k[key_counter % k.length()];
            const size_t row_index = Alphabet.find(key_char);
            if(const size_t search_char = Alphabet.find(s[i]); search_char != std::string::npos) {
                key_counter++;
                const size_t intersection = (Length - row_index + search_char) % Length;
                return_value += Alphabet[intersection];
            } else {
                return_value += s[i];
            }
        }
        return return_value;
    }
};