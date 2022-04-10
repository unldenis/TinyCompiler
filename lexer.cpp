#include "lexer.h"
#include <iostream>

lexer::lexer(std::string& input) : _source(input) , _currentChar('\0') , _currentPos(-1) {
    nextChar();
}


//  Process the next character.
void lexer::nextChar() {
    _currentPos++;
    if(_currentPos >= _source.length()) {
        _currentChar = '\0';	// EOF
    } else {
        _currentChar = _source[_currentPos];
    }
}

// Return the lookahead character.
char lexer::peek() {
    if(_currentPos + 1 >=  _source.length()) {
        return '\0';
    } else {
        return _source[_currentPos + 1];
    }
}

// Return the current character
char& lexer::getCurrentChar() {
    return _currentChar;
}

// Return the next token.
std::unique_ptr<token> lexer::getToken() {
    std::unique_ptr<token> t(new token()); 

    // Check the first character of this token to see if we can decide what it is.
    // If it is a multiple character operator (e.g., !=), number, identifier, or keyword then we will process the rest.
    switch(_currentChar) {
        case '+': {
            t->text = new std::string(1, _currentChar);
            t->type = TokenType::PLUS;
            break;
        }
        case '-': {
            t->text = new std::string(1, _currentChar);
            t->type = TokenType::MINUS;
            break;
        }
        case '*': {
            t->text = new std::string(1, _currentChar);
            t->type = TokenType::ASTERISK;
            break;
        }
        case '/': {
            t->text = new std::string(1, _currentChar);
            t->type = TokenType::SLASH;
            break;
        }
        case '\n': {
            t->text = new std::string(1, _currentChar);
            t->type = TokenType::NEWLINE;
            break;
        }
        case '\0': {
            t->text = new std::string(1, _currentChar);
            t->type = TokenType::END_OF_FILE;
            break;
        }
        default: {
 	        std::string badChar = std::string("Unknown token: ") + _currentChar;
            abort(badChar);
        }
    }

    nextChar();
    return t;
}


void lexer::abort(std::string message) {
    std::cout << "Lexing error. " + message << std::endl;
}


