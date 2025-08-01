#include <iostream>
#include <memory>
#include <format>
#include <print>

#include "Encrypter.hpp"
#include "Vigenere.hpp"

std::string Test_Simple_01(const std::string & source, int iterations) {
    std::unique_ptr<EncryptSimple> sim = std::make_unique<EncryptSimple>();
    std::string current { source };

    for(int i = 0; i < iterations; i ++) {
        current = sim->decrypt(current);
    }

    return current;
}

int main() {
    
    //  Simple
    std::string source_simple_01 { "GFTAVFDOX" };
    std::println("{} -> {}", source_simple_01, Test_Simple_01(source_simple_01, 10));
    
    //  Vigenere
	std::unique_ptr<Vigenere> vig = std::make_unique<Vigenere>();
    
	std::string source_vig_01 { "la solitudine dei numeri primi" };
	std::string key_vig_01 { "TRE" };
	std::string encrypted = vig->encrypt(source_vig_01, key_vig_01);
	std::string decrypted = vig->decrypt(encrypted, key_vig_01);
    
    std::println();
    std::println("Vigenere");
	std::println("{} (key: {}) -> {}", source_vig_01, key_vig_01, encrypted);
	std::println("{} (key: {}) -> {}", encrypted, key_vig_01, decrypted);
	
	//--------------------------------------------------------------------------
    std::println();
    std::println("Vigenere 3 times");
	
	std::string source_vig_02 { "WDFNVUEIRZJ EFAQOJUHA" };
	std::string key_vig_02 { "BETA" };
	std::string current { source_vig_02 };
	
	for(int i = 0; i < 3; i ++) {
	    current = vig->decrypt(current, key_vig_02);
	}
	
    std::println("{} (key: {}) -> {}", source_vig_02, key_vig_02, current);

    return 0;
}