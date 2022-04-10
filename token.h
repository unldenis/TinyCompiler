#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "tokentype.h"

struct token {
	std::string* text;
	TokenType type;
	token() {
		text = nullptr;
		type = TokenType::BAD_TOKEN;
	}
};

#endif
