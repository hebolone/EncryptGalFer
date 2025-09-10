#include <memory>
#include <format>
#include <print>

#include "cxxopts.hpp"
#include "Encrypter.hpp"
#include "Vigenere.hpp"
#include "commandlineparser.cpp"




int main(const int argc, const char* argv[]) {
 //    //  Simple
 //    std::string ex_a_source { "GFTAVFDOX" };
	// const std::string conversion_table { "AXCZQBYIJGWEHNDFOPRTLVSUMK" };
	// std::println("Exercise A");
 //    std::println("{} -> {}", ex_a_source, LaunchSimple(TOperation::Decrypt, ex_a_source , conversion_table , 10));
 //
 //    //  Vigenere
	// const auto vig = std::make_unique<Vigenere>();
 //
	// // std::string test_vig_01 { "la solitudine dei numeri primi" };
	// // std::string key_vig_01 { "TRE" };
	// // std::string test_vig_encrypted = vig->encrypt(test_vig_01, key_vig_01);
	// // std::string test_vig_decrypted = vig->decrypt(test_vig_encrypted, key_vig_01);
 // //
 //     std::println();
 // //    std::println("Vigenere");
	// // std::println("{} (key: {}) -> {}", test_vig_01, key_vig_01, test_vig_encrypted);
	// // std::println("{} (key: {}) -> {}", test_vig_encrypted, key_vig_01, test_vig_decrypted);
 //
	// //	Exercise B
	// std::string ex_b_source { "stiamo tutti bene" };
	// std::string ex_b_key { "alfa" };
	// std::string ex_b_result = vig->encrypt(ex_b_source, ex_b_key);
	// std::println("Exercise B");
	// std::println("{} (key: {}) -> {}", ex_b_source, ex_b_key, ex_b_result);
	//
	// //	Exercise C
 //    std::println();
 //    std::println("Exercise C");
	//
	// std::string ex_c_source { "WDFNVUEIRZJ EFAQOJUHA" };
	// std::string ex_c_key { "BETA" };
 //
	// std::println("{} (key: {}) -> {}", ex_c_source, ex_c_key, LaunchVigenere(TOperation::Decrypt, ex_c_source, ex_c_key , 3));

	//--------------------------------------------------------------------------
	// cxxopts
	if(!parse(argc, argv)) {
		return 1;
	}

    return 0;
}
