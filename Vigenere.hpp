#pragma once

#include <algorithm>

class Vigenere {
private:
    const std::string _Alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    const int _Length = _Alphabet.length();
public:
    std::string encrypt(const std::string & source, const std::string & key) const {
        std::string s { source };
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });

        std::string k { key };
        std::transform(k.begin(), k.end(), k.begin(), [](unsigned char c) { return std::toupper(c); });
        
        std::string return_value { };
        int length = s.length();
        int key_counter = 0;
        for(int i = 0; i < length; i ++) {
            size_t column_index = _Alphabet.find(s[i]);
            if(column_index != std::string::npos) {
                char key_char = k[(key_counter ++) % k.length()];
                size_t row_index = _Alphabet.find(key_char);
                char result = _Alphabet[(column_index + row_index) % _Length];
                return_value += result;
            } else {
                return_value += s[i];
            }
        }
        return return_value;
    }
    std::string decrypt(const std::string & source, const std::string & key) const {
        std::string s { source };
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });

        std::string k { key };
        std::transform(k.begin(), k.end(), k.begin(), [](unsigned char c) { return std::toupper(c); });
        
        std::string return_value { };
        int length = s.length();
        int key_counter = 0;
        for(int i = 0; i < length; i ++) {
            char key_char = k[key_counter % k.length()];
            size_t row_index = _Alphabet.find(key_char);
            size_t search_char = _Alphabet.find(s[i]);
            if(search_char != std::string::npos) {
                key_counter++;
                size_t intersection = (_Length - row_index + search_char) % _Length;
                return_value += _Alphabet[intersection];
            } else {
                return_value += s[i];
            }
        }
        return return_value;
    }
};