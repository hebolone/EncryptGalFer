#pragma once

class Vigenere {
private:
    const std::string _Alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    const int _Length = _Alphabet.length();
public:
    std::string encrypt(const std::string & s, const std::string & key) const {
        std::string return_value { };
        int length = s.length();
        int key_counter = 0;
        for(int i = 0; i < length; i ++) {
            size_t column_index = _Alphabet.find(s[i]);
            if(column_index != std::string::npos) {
                char key_char = key[(key_counter ++) % key.length()];
                size_t row_index = _Alphabet.find(key_char);
                char result = _Alphabet[(column_index + row_index) % _Length];
                return_value += result;
            } else {
                return_value += s[i];
            }
        }
        return return_value;
    }
    std::string decrypt(const std::string & s, const std::string & key) const {
        std::string return_value { };
        int length = s.length();
        int key_counter = 0;
        for(int i = 0; i < length; i ++) {
            char key_char = key[key_counter % key.length()];
            size_t row_index = _Alphabet.find(key_char);
            if(_Alphabet.find(s[i]) != std::string::npos) {
                key_counter++;
                size_t intersection = (_Length - row_index + _Alphabet.find(s[i])) % _Length;
                return_value += _Alphabet[intersection];
            } else {
                return_value += s[i];
            }
        }
        return return_value;
    }
};