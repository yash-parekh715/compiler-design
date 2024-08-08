#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

bool isKeyword(string s){
    set<string> keywords = {"int","return","if","else","while","for","class","public","private","virtual","void","const","static","namespace","template","using","try","catch","throw"};
    return keywords.find(s) != keywords.end();
}

bool isIdentifier(string s){
    if (s.empty() || isKeyword(s)) {
        return false;
    }
    if (!isalpha(s[0]) && s[0] != '_') {
        return false;
    }
    for (size_t i = 1; i < s.length(); ++i) {
        if (!isalnum(s[i]) && s[i] != '_') {
            return false;
        }
    }
    return true;
}

bool isStringLiteral(string s) {
    if (s.length() < 2 || s[0] != '"' || s[s.length() - 1] != '"') {
        return false;
    }
    return true;
}

bool isNumber(string s) {
    for (char ch:s){
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool isUnaryOperator(string s) {
    set<string> unary = {"++", "--"};
    return unary.find(s) != unary.end();
}

bool isArithmeticOperator(string s) {
    set<string> arithmetic = {"+", "-", "*", "/", "%"};
    return arithmetic.find(s) != arithmetic.end();
}

bool isAssignmentOperator(string s) {
    set<string> assignment = {"=", "+=", "-=", "*=", "/=", "%="};
    return assignment.find(s) != assignment.end();
}

bool isRelationalOperator(string s) {
    set<string> relational = {"==", "!=", "<", ">", "<=", ">="};
    return relational.find(s) != relational.end();
}

bool isLogicalOperator(string s) {
    set<string> logical = {"&&", "||", "!"};
    return logical.find(s) != logical.end();
}

bool isBitwiseOperator(string s) {
    set<string> bitwise = {"&", "|", "^", "<<", ">>", "~"};
    return bitwise.find(s) != bitwise.end();
}

bool isDelimiter(string s) {
    set<string> delimiter = {".","'",";",":",","};
    return delimiter.find(s) != delimiter.end();
}

bool isSpecialSymbol(string s) {
    set<string> symbol = {"!","@","#","$","%","^","&"};
    return symbol.find(s) != symbol.end();
}

bool isBracket(string s) {
    set<string> bracket = {"(", ")", "{", "}", "[", "]"};
    return bracket.find(s) != bracket.end();
}

int main(){
    string line;
    ifstream textfile("Example.txt");

    if(!textfile) {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    string input;
    while(textfile >> input){
        if (isKeyword(input)) cout << "< " << input << " : keyword >" << endl;
        else if (isIdentifier(input)) cout << "< " << input << " : identifier >" << endl;
        else if (isStringLiteral(input)) cout << "< " << input << " : string literal >" << endl;
        else if (isNumber(input)) cout << "< " << input << " : number >" << endl;
        else if (isUnaryOperator(input)) cout << "< " << input << " : unary operator >" << endl;
        else if (isArithmeticOperator(input)) cout << "< " << input << " : arithmetic operator >" << endl;
        else if (isAssignmentOperator(input)) cout << "< " << input << " : assignment operator >" << endl;
        else if (isRelationalOperator(input)) cout << "< " << input << " : relational operator >" << endl;
        else if (isLogicalOperator(input)) cout << "< " << input << " : logical operator >" << endl;
        else if (isBitwiseOperator(input)) cout << "< " << input << " : bitwise operator >" << endl;
        else if (isDelimiter(input)) cout << "< " << input << " : delimiter >" << endl;
        else if (isSpecialSymbol(input)) cout << "< " << input << " : special symbol >" << endl;
        else if (isBracket(input)) cout << "< " << input << " : bracket >" << endl;
        else cout << "< " << input << " : Other >" << endl;
    }
    
    textfile.close();
    return 0;
}




