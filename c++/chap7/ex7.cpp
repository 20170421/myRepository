#include "../../../std_lib_facilities.h"

const char number = 8;
const char quit = 'q';
const char print = ';';

class Variable {
public:
    string name;
    double value;
};

Vector<Variable> var_table;

double get_value(string s)
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: 정의되지 않은 변수", s);
}

void set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name == s) {
            v,value = d;
            return;
        }
    error("set: 정의되지 않은 변수", s);
}

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token();
    Token(char ch);    // make a Token from a char 
    Token(char ch, double val);     // make a Token from a char and a double
};

Token::Token()
{
    
}

Token::Token(char ch)
{
    kind = ch; value = 0;
}

Token::Token(char ch, double val)
{
    kind = ch; value = val;
}

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);    // c를 찾을 때까지 c를 포함한 문자열 버리기
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
{
    full = false; buffer = 0;    // no Token in buffer
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:
    case quit:
    case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!': case '%':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token(number ,val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    // 우선 버퍼를 본다
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // 이제 입력을 찾음
    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

int factorial(int n) 
{
    int ret = 1;
    for (int i=0; i<n; ++i) {
        ret *= (i+1);
    }
    return ret;
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '{':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return d;
        }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with !
double prefix()
{
    double left = primary();
    Token t = ts.get();
    switch (t.kind) {
    case '!':
        {
            int n = narrow_cast<int>(left);
            return factorial(n);
        }
    default:
        ts.putback(t);
        return left;
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = prefix();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '!':
            {
                int n = narrow_cast<int>(left);
                return factorial(n);
            }
        case '*':
            left *= prefix();
            t = ts.get();
            break;
        case '/':
            {    
                double d = prefix();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {
                double d = primary();
                if (d == 0) error("divided by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

bool is_declared(string var)
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var)) error(var, "가 재정의됨");
    var_table.push_back(Variable(var, val));
    return val;
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name) error("선언에는 이름이 필요함");
    string var_name = t,name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("선언에서 =가 빠짐 : ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    const string prompt = "> "; // 표현식 입력을 요구하는 프롬프트
    const string result = "= "; // 결과 출력을 알리는 지시자
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << "\n";
        }
        catch (exception& e) {
            cerr << e.what() << "\n";
            clean_up_mess();
        }
    }
}

int main()
{
    try
    {
        calculate();
        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << "\n";
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n"; 
        keep_window_open("~~");
        return 2;
    }
}
//------------------------------------------------------------------------------
