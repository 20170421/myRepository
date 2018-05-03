#include "../../../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    Token::Token(int k, string s): kind(k), str(s) { }
    int kind;  // 0:verb 1:noun 2: conj.
    string str;
}

//------------------------------------------------------------------------------

Token get() {
    string input;
    cin >> input;

    vector<string> v_list = { "rules", "fly", "swim" };
    vector<stirng> n_list = { "birds", "fish", "C++" };
    vector<string> conj_list = { "and", "or", "but" };

    for (string v : v_list) {
        if (input == v)
            return Token(0, input);
    }
    for (string n : n_list) {
        if (input == n)
            return Token(1, input);
    }
    for (string c : conj_list) {
        if (input == c)
            return Token(2, input);
    }
    error("Not implemented");
}

//------------------------------------------------------------------------------

bool noun() {
    Token t = get();
    if (t.kind == 1) 
        return true;
    else 
        return false;
}

//------------------------------------------------------------------------------

bool verb() {
    Token t = get();
    if (t.kind == 0)
        return true;
    else
        return false;
}

//------------------------------------------------------------------------------

bool conjunction() {
    Token t = get();
    if (t.kind == 2)
        return true;
    else
        return false;
}

//------------------------------------------------------------------------------

bool sentence() {
    bool correct = noun();
    Token t = get();

    while (true) {
        switch (t.kind) {
        case 0:
        case 1:
        case 2:
        default:
            
        }
    }
}

//------------------------------------------------------------------------------

int main() {
    cout << "문장을 입력하시오\n >> ";
    if (sentence())
        cout << "맞는 문장입니다.\n";
    else   
        cout << "틀린 문장입니다.\n";
}


// Sentence:
//     Noun Verb
//     Sentence Conjuncion Sentence

// Conjuncion:
//     "and"
//     "or"
//     "but"

// Noun:
//     "the" Noun
//     "birds"
//     "fish"
//     "C++"

// Verb:
//     "rules"
//     "fly"
//     "swim"