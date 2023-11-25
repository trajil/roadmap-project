#include <iostream>
#include <limits>
#include <vector>
using std::cin, std::cout, std::string, std::vector;

bool debug_mode = false;

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
vector<int> vector_reverse_with_length_and_print(vector<int> binary_whole, int vector_length, int base);

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
            cout << t_product << power(a, b) << t_datatype_output_double;
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

vector<int> dec_to_binary(int y, int x)
{
    vector<int> binary_whole(100);

    int vector_length;
    int integer = y;
    int i = 0;
    int base = x;
    int rest;

    if (integer >= base)
    {
        do
        {
            if (debug_mode)
            {
                cout << binary_whole[i];
            }
            rest = integer % base;

            binary_whole[i] = rest; // what is segmentation fault?
            integer = (integer - binary_whole[i]) / base;
            i++;

            if (debug_mode)
            {
                cout << "Current BINARY: ";
                cout << binary_whole[i];
                cout << std::endl;
            }
        } while (integer != 0);
    }
    else
    {
        cout << "Too low value entered!\n";
        return binary_whole;
    }
    vector_length = i;
    if (debug_mode)
    {
        cout << "@@@@@@@@@ TESTSTELLE VEKTOR EINGABE @@@@@@@@@@\n";
        cout << std::endl;
    }
    vector_reverse_with_length_and_print(binary_whole, vector_length, base);
    if (debug_mode)
    {
        cout << "\n@@@@@@@@@ TESTSTELLE VEKTOR AUSGABE @@@@@@@@@@\n";
        cout << std::endl;
    }
    return binary_whole;
}

vector<int> vector_reverse_with_length_and_print(vector<int> input_vector, int vector_length, int base)
{
    vector<int> calc_vector(100);

    calc_vector = input_vector;

    // Printing out in right direction
    cout << "\n binary number: \n";
    for (int i = 0; i < vector_length; i++)
    {
        cout << calc_vector[i];
    }

    // printing and assigning reverse direction
    cout << "\n binary number, new order: \n";
    for (int i = vector_length - 1, j = 0; j < vector_length; i--, j++)
    {
        calc_vector[j] = input_vector[i];

        cout << calc_vector[j];
    }

    return calc_vector;
}