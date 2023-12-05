#include <iostream>
#include <limits>
#include <vector>
using std::cin, std::cout, std::string, std::vector;

/* CURRENT TASK:

    REFACTORING:
        Change the user input order to:
        1. Welcome Screen
        2. Question of about methods:
            - Arithmetics
            - Translation to Numerical System with base N
        if Arithmetics:
            Question: INT OR FLOAT?
            -> Input asked: I/F
            Question: OPERATOR (+ - * / P)
            -> Input asked:
            2 Numbers: ?
            MATH-STUFF...
            Question: Repeat?
            if yes: -> STEP 2
        if Translation:
            -> Input asked:
            System with Base to: ?
            -> Input asked:
            Decimal number to convert: ?
            MATH-STUFF...
            Question: Repeat?
            if yes: -> STEP 2
*/

// outputs
string t_welcome = "Hi there, buddy! We're doing maths and stuff!";
string t_sum = "The sum is: ";
string t_dif = "The difference is: ";
string t_product = "The product is: ";
string t_quo = "The quotient is: ";
string t_power = " to the power of ";
string t_datatype_output_int = " (INTEGER)";
string t_datatype_output_double = " (FLOAT)";
string t_numbers_wrong = "Please only use whole numbers!\n";
string t_datatype_wrong = "Please only use 'F' or 'I'! \n";

string filler = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

// inputs
string t_input_operation_kind = "Choose the kind of operation you wanna do:\n(1) ARITHMETICS\n(2) TRANSLATION of a dec to another base\noperation: ";
string t_input_operator = "Choose your operator: (+, -, /, * or p)\noperator: ";
string t_input_numbers_int = "Now type in your two numbers (only whole numbers!)\n";
string t_input_numbers_float = "Now type in your two numbers!\n";
string t_input_numbers_1 = "Number 1: ";
string t_input_numbers_2 = "Number 2: ";
string t_choice_wrong = "Please use: (+, -, /, * or p)\n";
string t_exit_question = "\nPress 'Y' to repeat!";
string t_end = "\nGood bye!";
string t_input_datatype = "Calculations with [INT:I] or [FLOAT:F]?\ndata_type: ";

int x, y;
double a, b;

vector<int> dec_to_baseX;

int sum(int x, int y);
int dif(int x, int y);
int quo(int x, int y);
int product(int x, int y);

double sum(double a, double b);
double dif(double a, double b);
double quo(double a, double b);
double product(double a, double b);
double power(double a, double b);

void dec_to_base_X_numeral_system(int y, int x);

void control(char choice_operation_kind = '1')
{
    char choice_datatype, choice_operator;

    switch (choice_operation_kind)
    {
    case '1':
        cout << t_input_operator;
        cin >> choice_operator;
        break;

    case '2':
        cout << "Input decimal number: \n";
        cin >> y;
        cout << "Input numerical system base: \n";
        cin >> x;
        dec_to_baseX.clear();
        dec_to_base_X_numeral_system(y, x);
        cout << "\nYour number in the system with base_" << x << " is:\n";
        for (int i : dec_to_baseX)
        {
            cout << i;
        }
        return;
        break;

    default:
        break;
    }

    switch (choice_operator)
    {
    case '+':
        cout << t_input_datatype;
        cin >> choice_datatype;
        if (choice_datatype == 'F' || choice_datatype == 'f')
        {
            cout << t_input_numbers_float << t_input_numbers_1;
            cin >> a;
            cout << t_input_numbers_2;
            cin >> b;
            cout << t_sum << sum(a, b) << t_datatype_output_double;
        }
        else if (choice_datatype == 'I' || choice_datatype == 'i')
        {
            cout << t_input_numbers_int << t_input_numbers_1;
            cin >> x;
            cout << t_input_numbers_2;
            cin >> y;
            cout << t_sum << sum(x, y) << t_datatype_output_int;
        }
        break;

    case '-':
        cout << t_input_datatype;
        cin >> choice_datatype;
        if (choice_datatype == 'F' || choice_datatype == 'f')
        {
            cout << t_input_numbers_float << t_input_numbers_1;
            cin >> a;
            cout << t_input_numbers_2;
            cin >> b;
            cout << t_sum << dif(a, b) << t_datatype_output_double;
        }
        else if (choice_datatype == 'I' || choice_datatype == 'i')
        {
            cout << t_input_numbers_int << t_input_numbers_1;
            cin >> x;
            cout << t_input_numbers_2;
            cin >> y;
            cout << t_sum << dif(x, y) << t_datatype_output_int;
        }
        break;

    case '/':
        cout << t_input_numbers_float << t_input_numbers_1;
        cin >> a;
        cout << t_input_numbers_2;
        cin >> b;
        cout << t_sum << quo(a, b) << t_datatype_output_double;

        break;

    case '*':
        cout << t_input_datatype;
        cin >> choice_datatype;
        if (choice_datatype == 'F' || choice_datatype == 'f')
        {
            cout << t_input_numbers_float << t_input_numbers_1;
            cin >> a;
            cout << t_input_numbers_2;
            cin >> b;
            cout << t_sum << product(a, b) << t_datatype_output_double;
        }
        else if (choice_datatype == 'I' || choice_datatype == 'i')
        {
            cout << t_input_numbers_int << t_input_numbers_1;
            cin >> x;
            cout << t_input_numbers_2;
            cin >> y;
            cout << t_sum << product(x, y) << t_datatype_output_int;
        }
        break;
    case 'p':
        cout << "You chose the power function. Please input your number: ";
        cin >> a;
        cout << "To the power of: ";
        cin >> b;
        cout << a << t_power << b << " is: " << power(a, b) << t_datatype_output_double;
        break;

    default:
        cout << t_choice_wrong;
        break;
    }
}
int main()
{
    char choice_operation_kind, exit;

    cout << t_welcome << std::endl;

    do
    {
        cout << filler << t_input_operation_kind;
        cin >> choice_operation_kind;

        if (int i = choice_operation_kind; i == '1' || i == '2')
        {
            control(choice_operation_kind);
        }
        else
        {
            cout << "Please only use one of the options above!\n";
        }

        cout << t_exit_question;
        cin >> exit;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clearing cin
    } while (exit == 'Y' || exit == 'y');

    cout << t_end;

    return 0;
}

int sum(int x, int y)
{
    return x + y;
}

int dif(int x, int y)
{
    return x - y;
}

int quo(int x, int y)
{
    return x / y;
}

int product(int x, int y)
{
    return x * y;
}

double sum(double a, double b)
{
    return a + b;
}

double dif(double a, double b)
{
    return a - b;
}

double quo(double a, double b)
{
    return a / b;
}

double product(double a, double b)
{
    return a * b;
}

double power(double a, double b)
{
    if (b > 0)
    {
        int power = a;

        for (int i = 1; i < b; i++)
        {

            a *= power;
        }
    }
    else if (b == 0)
    {
        a = 1;
    }
    else
    {
        cout << "The exponent needs to be at least 0!\n";
        return 0;
    }
    return a;
}

void dec_to_base_X_numeral_system(int y, int x)
{
    // POSITIVE NUMBERS ONLY
    y = abs(y);
    x = abs(x);

    if (x < 2)
    {
        cout << "\n!!!Base too low!!!\n";
        return;
    }

    int rest;

    // 'Y' is the integer, 'X' is the base_system (e.g. x=2 is binary system)
    if (y >= x)
    {
        for (int i = 1; y != 0; i++)
        {
            rest = y % x;
            y = (y - rest) / x;
            dec_to_baseX.insert(dec_to_baseX.begin(), rest);
        }
    }
    else
    {
        dec_to_baseX.push_back(y);
    }
}