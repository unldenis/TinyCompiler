#include <iostream>
#include <string>


#include "lexer.h"
#include "token.h"


int main() {

	std::string input = "+-A*/";
	lexer lexer(input);

	token token = *lexer.getToken();
	while(token.type != TokenType::END_OF_FILE) {
		std::cout << token.type << std::endl;
		token = *(lexer.getToken());
	}
	return 0;
}