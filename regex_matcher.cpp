#include <iostream>

using namespace std;

bool match(const char *regex, const char *text);

bool match_prefix(const char *regex, const char *text);

bool match_star(const char c, const char *regex, const char *text);

int main() {

    string regex;
    getline(cin, regex);

    string text;
    getline(cin, text);

    cout << match(regex.c_str(), text.c_str()) << "\n";
    return 0;
}

/*
    c    matches any literal character c
    .    matches any single character
    ^    matches the beginning of the input string
    $    matches the end of the input string
    *    matches zero or more occurrences of the previous character
 */

// search for regex anywhere in text
bool match(const char *regex, const char *text) {
    if (regex[0] == '^')
        return match_prefix(regex + 1, text);

    do {    // must look even if string is empty
        if (match_prefix(regex, text))
            return true;
    } while (*text++ != '\0');

    return false;
}

// search for regexp at beginning of text
bool match_prefix(const char *regex, const char *text) {
    if (regex[0] == '\0')
        return true;

    if (regex[0] == '$' && regex[1] == '\0')
        return *text == '\0';

    if (regex[1] == '*')
        return match_star(regex[0], regex + 2, text);

    if (*text != '\0' && (regex[0] == '.' || regex[0] == *text))
        return match_prefix(regex + 1, text + 1);

    return false;
}

// match_star: search for c*regexp at beginning of text
bool match_star(const char c, const char *regex, const char *text) {
    // greedy
    // 	for (t = text; *t != '\0' && (*t == c || c == '.'); t++)
    do {    // * matches zero or more instances
        if (match_prefix(regex, text))
            return true;
    } while (*text != '\0' && (*text++ == c || c == '.'));

    return false;
}
