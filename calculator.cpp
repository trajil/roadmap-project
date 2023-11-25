#include <iostream>
#include <limits>
#include <vector>
using std::cin, std::cout, std::string, std::vector;

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

int sum(int x, int y);
int dif(int x, int y);
int quo(int x, int y);
int product(int x, int y);

double sum(double a, double b);
double dif(double a, double b);
double quo(double a, double b);
double product(double a, double b);
double power(double a, double b);

/*
    dec is divided by 2. MODULO
    remainder is taken straight to binary_string
    continued until dec == 0


    dec 98 = bin   1 1 0 0 0 1 0

    98 %2 = 49 | 0
    49 %2 = 24 | 1
    24 %2 = 12 | 0
    12 %2 = 6 | 0
    6 %2 = 3 | 0
    3 %2 = 1 | 1
    1 %2 = 0 | 1
*/

vector<int> dec_to_binary(int x)
{
    int binary_it = 0;
    vector<int> binary_whole(0);
    int counter = 0;
    do
    {
        binary_it = x % 2;
        binary_whole[] = binary_it;
        x = x / 2 - binary_it;
        counter++;
    } while (x != 0);

    

    return binary_whole;
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

    else if (choice_datatype == 'B' || choice_datatype == 'B')
    {
    }
    else
    {
        cout << t_datatype_wrong << std::endl;
    }
}

int main()
{
    // cin >> a >> b;
    // cout << a << " to the power of " << b << std::endl << power(a, b) << std::endl;

    // cin >> x;
    // cout << a << " to the power of " << b << std::endl << power(a, b) << std::endl;

    char choice_datatype, exit;
    char choice_operator;
    string input;

    cout << t_welcome << std::endl;
    do
    {
        choice_operator = 0;
        cout << t_input_operator;
        getline(cin, input);

        if (input.empty())
        {
            cout << "CHECK 1\n";
        }
        else
        {
            for (int i = 0; i < input.length(); i++) // Getting the last digit of the string to char -by Victor
            {
                choice_operator = input[i];
            }
        }

        cout << t_input_datatype;
        cin >> choice_datatype;

        char i = choice_operator;

        if (i == 0) // how can I accept an empty input? (solved)
        {
            cout << "\nVALUE 0\n";
            control();
        }

        else
        {
            control(choice_operator, choice_datatype);
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
        cout << "To the power of "
             << "1" << std::endl;
        cout << "A is now: " << a << std::endl;

        for (int i = 1; i < b; i++)
        {
            cout << "To the power of " << i + 1 << std::endl;
            a *= power;
            cout << "A is now: " << a << std::endl;
        }
    }
    else if (b == 0)
    {
        cout << "To the power of "
             << "0" << std::endl;
        a = 1;
    }
    else
    {
        cout << "The exponent needs to be at least 0!\n";
    }
    return a;
}