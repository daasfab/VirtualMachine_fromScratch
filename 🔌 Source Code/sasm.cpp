#include <iostream>
#include <fstream>
#include "sasm_lexer.h"

typedef uint32_t i32;

using namespace std;

// Function prototypes
vector<i32> compileToInstructions(strings s); // Convert lexemes to instructions
bool isInteger(string s);                     // Check if string is an integer
i32 mapToNumber(string s);                    // Map operation to a number

int main(int argc, char *argv[]) {
    // Check for correct command-line arguments
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <sasm-filename>" << endl;
        exit(1);
    }

    // Open input file
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.is_open()) {
        cout << "Error: could not open [" << argv[1] << "]" << endl;
        exit(1);
    }

    // Read entire file contents
    string line;
    string contents;
    while (getline(infile, line)) {
        contents += line + "\n";
    }
    infile.close();

    // Tokenize file contents
    Lexer lexer;
    strings lexemes = lexer.lex(contents);

    // Compile tokens into binary instructions
    vector<i32> instructions = compileToInstructions(lexemes);

    // Write instructions to a binary file
    ofstream ofile;
    ofile.open("out.bin", ios::binary);
    for (i32 i = 0; i < instructions.size(); i++) {
        ofile.write(reinterpret_cast<char *>(&instructions[i]), sizeof(i32));
    }
    ofile.close();
    return 0;
}

// Convert lexemes to binary instructions
vector<i32> compileToInstructions(strings s) {
    vector<i32> instructions;
    for (i32 i = 0; i < s.size(); i++) {
        if (isInteger(s[i])) {
            instructions.push_back(stoi(s[i])); // Add integer to instructions
        } else {
            i32 instruction = mapToNumber(s[i]); // Map operation to number
            if (instruction != -1) {
                instructions.push_back(instruction);
            } else {
                cout << "Error: Invalid instruction [" << s[i] << "]" << endl;
            }
        }
    }
    return instructions;
}

// Check if a string represents an integer
bool isInteger(string s) {
    for (i32 i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

// Map string operations to unique instruction numbers
i32 mapToNumber(string s) {
    if (s == "+") {
        return 0x40000001;
    } else if (s == "-") {
        return 0x40000002;
    } else if (s == "*") {
        return 0x40000003;
    } else if (s == "/") {
        return 0x40000004;
    }
    return -1; // Invalid operation
}
