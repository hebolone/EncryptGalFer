#include <memory>
#include <format>
#include <print>

#include "Encrypter.hpp"
#include "Vigenere.hpp"

enum class TOperation { Encrypt, Decrypt };

std::string Test01(TOperation, const std::string &, const std::string &, int);

std::string Test02(TOperation, const std::string &, const std::string &, int);

int main() {
    //  Simple
    std::string source_simple_01 { "GFTAVFDOX" };
	const std::string conversion_table { "AXCZQBYIJGWEHNDFOPRTLVSUMK" };
    std::println("{} -> {}", source_simple_01, Test01(TOperation::Decrypt, source_simple_01 , conversion_table , 10));
    
    //  Vigenere
	const auto vig = std::make_unique<Vigenere>();
    
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

	std::println("{} (key: {}) -> {}", source_vig_02, key_vig_02, Test02(TOperation::Decrypt, source_vig_02, key_vig_02 , 3));

    return 0;
}

std::string Test01(TOperation operation, const std::string & source, const std::string & converter, int iterations = 1) {
	EncryptSimple sim { converter };
	std::string current { source };

	for(int i = 0; i < iterations; i ++) {
		switch(operation) {
			case TOperation::Encrypt:
				current = sim.encrypt(current);
				break;
			case TOperation::Decrypt:
				current = sim.decrypt(current);
				break;
		}
	}

	return current;
}

std::string Test02(TOperation operation, const std::string & source, const std::string & key, int iterations = 1) {
	Vigenere vig { };
	std::string current { source };

	for(int i = 0; i < iterations; i ++) {
		switch(operation) {
			case TOperation::Encrypt:
				current = vig.encrypt(current, key);
				break;
			case TOperation::Decrypt:
				current = vig.decrypt(current, key);
				break;
		}
	}

	return current;
}