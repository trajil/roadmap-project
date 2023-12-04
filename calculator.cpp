#include <iostream>
#include <limits>
#include <vector>
using std::cin, std::cout, std::string, std::vector;

/* CURRENT TASK:

    BONUS ROUND:
    Implement calculating to the power of and translating dec to bin;

*/

// OVERLOADED FUNCTIONS -> INTEGERS
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

// inputs
string t_input_operator = "First, enter the operator (+, -, /, * or p): ";
string t_input_numbers_i = "Now type in your two numbers (only whole numbers!)\n";
string t_input_numbers_f = "Now type in your two numbers! \n";
string t_input_numbers_dec = "Translate decimal [NUMB1] to system_with_base_n[NUMB2]! \n";
string t_input_numbers_1 = "Number 1: ";
string t_input_numbers_2 = "Number 2: ";
string t_choice_wrong = "Please use: (+, -, /, * or p)";
string t_exit_question = "\nPress 'Y' to repeat!";
string t_end = "\nGood bye!";
string t_input_datatype = "Calculations [INT:I] or [FLOAT:F], Translations [DEC:D]? ";

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

vector<int> dec_to_binary(int y, int x);

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
        case 'p':
            cout << a << t_power << b << " is: " << power(a, b) << t_datatype_output_double;
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

    else if (choice_datatype == 'D' || choice_datatype == 'd')
    {
        cout << t_input_numbers_dec << t_input_numbers_1;
        cin >> x;
        cout << t_input_numbers_2;
        cin >> y;
        dec_to_binary(x, y);
    }
    else
    {
        cout << t_datatype_wrong << std::endl;
    }
}

int main()
{

    char choice_datatype, exit;
    char choice_operator;
    string input;

    cout << t_welcome << std::endl;
    do
    {
        choice_operator = 0;
        cout << t_input_operator;
        getline(cin, input); // only way for the input to accept [ENTER]

        if (input.empty())
        {
            cout << "(input left empty)\n";
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
            cout << "\n VALUE 0\n";
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

vector<int> dec_to_binary(int y, int x)
{
    vector<int> binary_whole(0);
    int rest;

    // 'Y' is the integer, 'X' is the base_system (e.g. x=2 is binary system)
    if (y >= x)
    {
        for (int i = 1; y != 0; i++)
        {
            // binary_whole.resize(i);

            rest = y % x;
            y = (y - rest) / x;
            binary_whole.insert(binary_whole.begin(), rest);
        }
    }
    else
    {
        cout << "Too low integer entered!\n";
        return binary_whole;
    }

    cout << "\nYour number in the system with base: " << x << " is:\n";
    for (int i = 0; i < binary_whole.size(); i++)
    {
        cout << binary_whole[i];
    }

    return binary_whole;
}