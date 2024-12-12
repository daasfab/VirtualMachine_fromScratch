#include "sasm_lexer.h"

// Lexical analyzer function that takes a string and returns a list of tokens
strings Lexer::lex(std::strings s) {
    strings strlst;           // List to store tokens
    char lexeme[256];         // Buffer for the current lexeme
    int i = 0;                // Index for input string
    int j = 0;                // Index for the lexeme buffer
    State state = START;      // Current state of the lexer
    int done = 0;             // Flag to indicate completion (not used)
    int len = s.length();     // Length of the input string
    int balance = 0;          // Balance counter for group characters (e.g., brackets)

    // Main loop to process the input string
    while (i < len) {
        switch (state) {
        case START:
            // Handle initial state transitions based on character type
            if (my_isspace(s[i])) {
                state = SKIP;  // Skip whitespace
            } else if (isgroup(s[i])) {
                // Handle group characters (e.g., quotes, brackets)
                if (s[i] == '"') {
                    lexeme[j] = s[i];
                    j++;
                    i++;
                }
                state = READBLOCK;
            } else if (s[i] == '/' && s[i + 1] == '/') {
                // Handle comments starting with "//"
                i += 2;
                state = COMMENT;
            } else {
                state = READCHAR; // Read a regular character
            }
            break;

        case READCHAR:
            // Read characters to form a lexeme
            if (my_isspace(s[i])) {
                state = DUMP;  // End lexeme on whitespace
            } else if (s[i] == '\\') {
                // Skip escaped characters
                i += 2;
            } else if (isgroup(s[i])) {
                // Handle group characters
                if (s[i] == '"') {
                    lexeme[j] = s[i];
                    j++;
                    i++;
                }
                state = READBLOCK;
            } else if (isspecial(s[i])) {
                // Handle special characters
                if (j == 0) {
                    lexeme[j] = s[i];
                    j++;
                    i++;
                }
                state = DUMP;
            } else if (s[i] == '/' && s[i + 1] == '/') {
                // Start comment processing
                i += 2;
                state = COMMENT;
            } else {
                // Add regular character to lexeme
                lexeme[j] = s[i];
                j++;
                i++;
            }
            break;

        case READBLOCK:
            // Handle block constructs (e.g., strings, brackets)
            if (s[i] == beg_char && s[i] != '"') {
                balance++;    // Increment balance for nested groups
                lexeme[j] = s[i];
                j++;
                i++;
            } else if (s[i] == end_char) {
                balance--;    // Decrement balance for closing group
                lexeme[j] = s[i];
                j++;
                i++;
                if (balance <= 0) {
                    state = DUMP;
                }
            } else if (end_char == '"' && s[i] == '\\') {
                // Skip escaped characters inside strings (TODO: fix recording)
                i += 2;
            } else {
                lexeme[j] = s[i]; // Add character to lexeme
                j++;
                i++;
            }
            break;

        case SKIP:
            // Skip over whitespace
            if (my_isspace(s[i])) {
                i++;
            } else {
                state = READCHAR;
            }
            break;

        case DUMP:
            // Finalize the current lexeme and add it to the token list
            if (j > 0) {
                lexeme[j] = 0; // Null-terminate the lexeme
                strlst.push_back(lexeme);
                j = 0;
            }
            state = START; // Reset to start state
            break;

        case COMMENT:
            // Skip characters until the end of the line
            if (s[i] != '\n') {
                i++;
            } else {
                state = READCHAR;
            }
            break;

        case END:
            // End processing
            i = len;
            break;
        }
    }

    // Add any remaining lexeme to the token list
    if (j > 0) {
        lexeme[j] = 0;
        strlst.push_back(lexeme);
    }

    return strlst; // Return the list of tokens
}
