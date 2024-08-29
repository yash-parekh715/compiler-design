#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

// A simple parser class
class Parser {
public:
    explicit Parser(const string& input)
        : input(input), pos(0) {}

    // Function to start parsing the input
    string parse() {
        string result = parseExpression();
        if (pos != input.length()) {
            throw runtime_error("Unexpected characters at end of input");
        }
        return result;
    }

private:
    // Function to parse an expression
    string parseExpression() {
        string result = parseTerm();
        while (true) {
            if (match('+')) {
                result += " + " + parseTerm();
            } else if (match('-')) {
                result += " - " + parseTerm();
            } else {
                break;
            }
        }
        return result;
    }

    // Function to parse a term
    string parseTerm() {
        return parseNumber();
    }

    // Function to parse a number
    string parseNumber() {
        string number;
        while (isdigit(peek())) {
            number += get();
        }
        if (number.empty()) {
            throw runtime_error("Expected a number");
        }
        return number;
    }

    // Peek at the next character without consuming it
    char peek() const {
        if (pos < input.length()) {
            return input[pos];
        }
        return '\0'; // End of input
    }

    // Get the next character and move the position forward
    char get() {
        if (pos < input.length()) {
            return input[pos++];
        }
        return '\0'; // End of input
    }

    // Match a specific character and move the position forward if it matches
    bool match(char expected) {
        if (peek() == expected) {
            get();
            return true;
        }
        return false;
    }

    const string& input;
    size_t pos;
};

int main() {
    try {
        // Define the input string to be parsed
        string input = "12+34-56";

        // Create a parser instance
        Parser parser(input);

        // Parse the input string and get the resulting derived string
        string result = parser.parse();

        // Print the derived string
        cout << "Derived string: " << result << std::endl;
    } catch (const std::exception& e) {
        // Handle any parsing errors
        cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}