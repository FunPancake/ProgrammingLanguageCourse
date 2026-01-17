#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

enum TokenType { KEYWORD, IDENTIFIER, NUMBER, SYMBOL, OPERATOR, UNKNOWN, RELATIONAL, EMOTION };


struct Token {
    string value;
    TokenType type;
};

// array for the tokens
string keywords[] = {
    "int", "float", "double", "char", "bool",
    "if", "else", "while", "for", "do", "switch", "case",
    "break", "continue", "return", "void", "const", "static",
    "struct", "class", "public", "private", "protected", "enum",
    "typedef", "sizeof", "try", "catch", "throw", "namespace"
};
string symbols[] = {
    "(", ")", "{", "}", "[", "]", ";", ",", ".", ":", "?"
};
string operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=",
    "!", "++", "--", "+=", "-=", "*=", "/=", "%=", "&&", "||", "&", "|", "^", "~", "<<", ">>"
};

// addtional arrays for tokens
string relational[] = {
    "something to add", "relational operators"
};

string emotion[] = {
    "emotions like emojis"
};

string placeholder[] = {
    "placeholder"
};

bool existsInArray(const string arr[], int size, const string &str) {
    for (int i = 0; i < size; i++)
        if (arr[i] == str) return true;
    return false;
}

TokenType classify(const string &str) {
    if (existsInArray(keywords, sizeof(keywords)/sizeof(keywords[0]), str)) return KEYWORD;
    if (existsInArray(symbols, sizeof(symbols)/sizeof(symbols[0]), str)) return SYMBOL;
    if (existsInArray(operators, sizeof(operators)/sizeof(operators[0]), str)) return OPERATOR;

    // add if existInArray for 3 new reference

    if (!str.empty() && isdigit(str[0])) return NUMBER;
    if (!str.empty() && (isalpha(str[0]) || str[0] == '_')) return IDENTIFIER;
    return UNKNOWN;
}

vector<Token> tokenize(const string &code) {
    vector<Token> tokens;
    string temp;
    
    for (size_t i = 0; i < code.size(); i++) {
        char ch = code[i];
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            temp = "";
            while (i < code.size() && (isdigit(code[i]) || code[i] == '.')) temp += code[i++];
            i--;
            tokens.push_back({temp, NUMBER});
        }
        else if (isalpha(ch) || ch == '_') {
            temp = "";
            while (i < code.size() && (isalnum(code[i]) || code[i] == '_')) temp += code[i++];
            i--;
            tokens.push_back({temp, classify(temp)});
        }
        else {
            temp = ch;
            if (i + 1 < code.size()) {
                string twoChar = temp + code[i + 1];
                if (existsInArray(operators, sizeof(operators)/sizeof(operators[0]), twoChar)) {
                    temp = twoChar;
                    i++;
                }
            }
            tokens.push_back({temp, classify(temp)});
        }
    }
    return tokens;
}

//output
void printTokens(const vector<Token> &tokens) {
    cout << left << setw(15) << "Token" << "|" << "Type" << endl;
    cout << string(25, '-') << endl;
    for (auto &t : tokens) {
        cout << left << setw(15) << t.value << "|    ";
        switch (t.type) {
            case KEYWORD: cout << "KEYWORD"; break;
            case IDENTIFIER: cout << "IDENTIFIER"; break;
            case NUMBER: cout << "NUMBER"; break;
            case SYMBOL: cout << "SYMBOL"; break;
            case OPERATOR: cout << "OPERATOR"; break;

            // add case for 3 new reference 

            default: cout << "UNKNOWN"; break;
        }
        cout << endl;
    }
}

int main() {
    string filename;
    cout << "Enter filename to tokenize: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << endl;
        return 1;
    }

    string code, line;
    while (getline(file, line)) {
        code += line + "\n";
    }
    file.close();

    vector<Token> tokens = tokenize(code);
    printTokens(tokens);
    
    cin.get();
    return 0;
}
