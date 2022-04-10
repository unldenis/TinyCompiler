#pragma once

#include <string>
#include "token.h"
#include <memory>
#include <sstream>

class lexer {

public:

	lexer(std::string& input);

	//  Process the next character.
	void nextChar();

 	// Return the lookahead character.
    char peek();

    // Return the current character
	char& getCurrentChar();

	// Return the next token.
    std::unique_ptr<token> getToken();

	// Return theInvalid token found, print error message and exit.
	void abort(std::string message);
	
private:
	std::string& _source;
	char _currentChar;
	int _currentPos;
};