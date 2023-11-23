#include <iostream>
using std::cin, std::cout, std::string;

/* CURRENT TASK:
D. Argument default values
    Problem 1 (Primitive calculator function)
        "Using the Function/C/Problem 1 create a function which to hold the control function. 
        The function should take thee choice variable as an argument. 
        Also if no argument is passed the calculator function should default to the sum operation"
*/

// OVERLOADED FUNCTIONS -> INTEGERS
// outputs
string t_welcome = "Hi there, buddy! We're doing maths and stuff!";
string t_sum = "The sum is: ";
string t_dif = "The difference is: ";
string t_product = "The product is: ";
string t_quo = "The quotient is: ";
string t_datatype_output_int = " (INTEGER)";
string t_datatype_output_double = " (FLOAT)";
string t_numbers_wrong = "Please only use whole numbers!\n";
string t_datatype_wrong = "Please only use 'F' or 'I'! \n";

// inputs
string t_input_operator = "First, enter the operator (+,-,/ or *): ";
string t_input_numbers_i = "Now type in your two numbers (only whole numbers!)\n";
string t_input_numbers_f = "Now type in your two numbers! \n";
string t_input_numbers_1 = "Number 1: ";
string t_input_numbers_2 = "Number 2: ";
string t_choice_wrong = "Please use: (+ - / or *)";
string t_exit_question = "\nPress 'Y' to repeat!";
string t_end = "\nGood bye!";
string t_input_datatype = "Do you want to use INT (Enter 'I') or FLOAT (Enter 'F') values? ";

int x, y;
double a, b;

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

void control(char choice_operator = '+', char choice_datatype = 'I')
{
    // FLOAT VALUES
    if (choice_datatype == 'F' || choice_datatype == 'f')
    {
        cout << t_input_numbers_f << t_input_numbers_1;
        cin >> a;
        cout << t_input_numbers_2;
        cin >> b;
        switch (choice_operator)
        {
        case '+':
            cout << t_sum << sum(a, b) << t_datatype_output_double;
            break;

        case '-':
            cout << t_dif << dif(a, b) << t_datatype_output_double;
            break;

        case '/':
            cout << t_quo << quo(a, b) << t_datatype_output_double;
            break;

        case '*':
            cout << t_product << product(a, b) << t_datatype_output_double;
            break;

        default:
            cout << t_choice_wrong;
            break;
        }
    }

    // INT VALUES
    else if (choice_datatype == 'I' || choice_datatype == 'i')
    {
        cout << t_input_numbers_i << t_input_numbers_1;
        cin >> x;
        cout << t_input_numbers_2;
        cin >> y;
        switch (choice_operator)
        {
        case '+':
            cout << t_sum << sum(x, y) << t_datatype_output_int;
            break;

        case '-':
            cout << t_dif << dif(x, y) << t_datatype_output_int;
            break;

        case '/':
            cout << t_quo << quo(x, y) << t_datatype_output_int;
            break;

        case '*':
            cout << t_product << product(x, y) << t_datatype_output_int;
            break;

        default:
            cout << t_choice_wrong;
            break;
        }
    }
    else
    {
        cout << t_datatype_wrong << std::endl;
    }
}

int main()
{

    char choice_operator, choice_datatype, exit;
    string input;

    cout << t_welcome << std::endl;
    do
    {
        cout << t_input_operator;
        getline(cin, input);
        cout << t_input_datatype;
        cin >> choice_datatype;

        char i = choice_operator;

        if (i == '+' || i == '-' || i == '/' || i == '*') // how can I accept an empty input?
        {
            control(choice_operator, choice_datatype);
        }
        else
        {
            control();
        }

        cout << t_exit_question;
        cin >> exit;
    } while (exit == 'Y' || exit == 'y');

    cout << t_end;

    return 0;
}
