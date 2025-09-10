#include <iostream>

enum class TOperation { Encrypt, Decrypt };

std::string LaunchSimple(const TOperation operation, const std::string & source, const std::string & converter, const int iterations = 1) {
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

std::string LaunchVigenere(const TOperation operation, const std::string & source, const std::string & key, const int iterations = 1) {
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

bool parse (const int argc, const char* argv[]) {
	const std::unique_ptr<cxxopts::Options> allocated(new cxxopts::Options(argv[0], " - example command line options"));
	auto& options = *allocated;
	options
	  .positional_help("[optional args]")
	  .show_positional_help();

	options.set_width(70).set_tab_expansion().allow_unrecognised_options().add_options()
		("v,version", "Version")
		("a,algorithm", "Algorithm to use [simple,vigenere]", cxxopts::value<std::string>()->default_value("simple"))
		("t,text", "Text to encrypt/decrypt", cxxopts::value<std::string>())
		("k,key", "Key", cxxopts::value<std::string>()->default_value(""))
		("i,iterations", "Iterations", cxxopts::value<int>()->default_value("1"))
		("o,operation", "Operation [encrypt,decrypt]", cxxopts::value<std::string>()->default_value("encrypt"))
		("h,help", "Print help")
	;

	const auto result = options.parse(argc, argv);
	if (result.count("v")) {
		std::println("Version 0.1");
		return true;
	}

	if(result.count("h") || !result.count("t")) {
		std::cout << options.help();
		return true;
	}

	std::string algorithm { };
	algorithm = result["algorithm"].as<std::string>();
	auto origin = result["text"].as<std::string>();
	const int iterations = result["iterations"].as<int>();
	const std::string operation = result["operation"].as<std::string>();

	const TOperation operation_chosen = operation == "encrypt" ? TOperation::Encrypt : TOperation::Decrypt;
	std::string product { };

	if(algorithm == "simple") {
		const std::string conversion_table = result["key"].as<std::string>();
		product = LaunchSimple(operation_chosen, origin, conversion_table, iterations);
	} else if(algorithm == "vigenere") {
		const std::string key = result["key"].as<std::string>();
		product = LaunchVigenere(operation_chosen, origin, key, iterations);
	}
	std::println("{} : {}", origin, product);

	return true;
}

