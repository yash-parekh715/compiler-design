#include <iostream>
#include <cctype> // for std::isdigit and std::isspace
using namespace std;

// Global variables for lexer
const char* input;  // Pointer to the input string
char currentChar;   // Current character in the input

// Function to advance to the next character
void advance() {
    currentChar = *++input;
}

// Function to skip whitespace
void skipWhitespace() {
    while (isspace(currentChar)) {
        advance();
    }
}

// Function to get a number from the input
double getNumber() {
    double result = 0;
    while (isdigit(currentChar)) {
        result = result * 10 + (currentChar - '0');
        advance();
    }
    if (currentChar == '.') {
        advance();
        double factor = 0.1;
        while (isdigit(currentChar)) {
            result += (currentChar - '0') * factor;
            factor *= 0.1;
            advance();
        }
    }
    return result;
}

// Forward declarations of parsing functions
double expr();
double term();
double factor();

// Function to parse an expression
double expr() {
    double result = term();
    while (currentChar == '+' || currentChar == '-') {
        char op = currentChar;
        advance();
        if (op == '+') {
            result += term();
        } else if (op == '-') {
            result -= term();
        }
    }
    return result;
}

// Function to parse a term
double term() {
    double result = factor();
    while (currentChar == '*' || currentChar == '/') {
        char op = currentChar;
        advance();
        if (op == '*') {
            result *= factor();
        } else if (op == '/') {
            result /= factor();
        }
    }
    return result;
}

// Function to parse a factor
double factor() {
    double result;
    if (isdigit(currentChar)) {
        result = getNumber();
    } else if (currentChar == '(') {
        advance();
        result = expr();
        if (currentChar == ')') {
            advance();
        } else {
            cerr << "Error: Missing closing parenthesis" << endl;
            exit(1);
        }
    } else {
        cerr << "Error: Unexpected character" << endl;
        exit(1);
    }
    return result;
}

int main() {
    cout << "Enter an arithmetic expression: ";
    string line;
    getline(cin, line);

    input = line.c_str();  // Initialize the global input pointer
    currentChar = *input;  // Set the current character

    skipWhitespace();
    double result = expr();
    skipWhitespace();
    
    if (currentChar != '\0') {
        cerr << "Error: Unexpected character at end of input" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}