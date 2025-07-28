#include <iostream>
#include <memory>
#include <format>

#include "Encrypter.hpp"
#include "Vigenere.hpp"

int main() {
    //std::unique_ptr<std::string> author = std::make_unique<std::string>("world");
    //std::cout << "Hello, " << *author << std::endl;
    //std::cout << std::format("Hello, {}", *author) << std::endl;

    std::unique_ptr<EncryptSimple> encrypter = std::make_unique<EncryptSimple>();
    const std::string original { "GFTAVFDOX" };
    std::string converted = original;
    int times = 10;

    // for(int i = 0; i < times; i ++) {
    //     std::string in = converted;
    //     converted = encrypter->decrypt(in);
    //     std::cout << std::format("{} -{} -> {}", i + 1, in, converted) << std::endl;
    // }
    
    // std::cout << std::format("Original: {}, converted: {} (run {} times)", original, converted, times) << std::endl;

    //  Vigenere
    std::unique_ptr<Vigenere> vigenere = std::make_unique<Vigenere>();
    std::string source { "LA SOLITUDINE DEI NUMERI PRIMI" };
    std::cout << std::format("Original: {}, converted: {}", source, vigenere->encrypt(source, "TRE")) << std::endl;

    std::string source_encrypted { "ER WHCMMLHBEI WVM GLQXIM IIMFZ" };
    std::cout << std::format("Original: {}, converted: {}", source_encrypted, vigenere->decrypt(source_encrypted, "TRE")) << std::endl;


    return 0;
}