#include <iostream>
using std::cin, std::cout, std::string;

/* CURRENT TASK:

 B. Parameters and return values Handling input parameters and returning results.
    Problem 1 (Aritmetic Operation functions Argument passing)
        "Using the Function/A/Problem 1 refactor the Aritmetic Functions for the type (int) and pass the arithmetic operands as arguments to the functions. Print result to standard output"
    Problem 2 (Aritmetic Operation functions returning results)
        "Using the Function/B/Problem 1 refactor the Aritmetic Functions to return the result insted of printing it in the function"
*/

// using one line with "return + variables" instead of two lines, one with the equation, the second with the return of the result -- less code
int sum(int x, int y)
{
    return x + y;
}

int dif(int x, int y)
{
    return x - y;
}

double quo(int x, int y)
{
    return x / y;
}

int product(int x, int y)
{
    return x * y;
}

int main()
{
    // fixed outputs
    string t_input_operator = "Hi there, buddy! We're doing maths and stuff! First, enter the operator (+,-,/ or *): ";
    string t_sum = "The sum is: ";
    string t_dif = "The difference is: ";
    string t_product = "The product is: ";
    string t_quo = "The quotient is: ";
    string t_nunbers_wrong = "Please only use whole numbers!\n";

    // choices
    string t_input_numbers = "Now put in your two numbers (only whole numbers!)\n";
    string t_input_numbers_1 = "Number 1: ";
    string t_input_numbers_2 = "Number 2: ";
    string t_choice_wrong = "Please use: (+ - / or *)";
    string t_exit_question = "\nPress 'Y' to repeat!";
    string t_end = "\nGood bye!";

    int x, y;
    char choice_operator, exit;

    do
    {
        cout << t_input_operator;
        cin >> choice_operator;
        cout << t_input_numbers << t_input_numbers_1;
        cin >> x;
        cout << t_input_numbers_2;
        cin >> y;

        switch (choice_operator)
        {
        case '+':
            cout << t_sum << sum(x, y);
            break;

        case '-':
            cout << t_dif << dif(x, y);
            break;

        case '/':
            cout << t_quo << quo(x, y);
            break;

        case '*':
            cout << t_product << product(x, y);
            break;

        default:
            cout << t_choice_wrong;
            break;
        }

        cout << t_exit_question;
        cin >> exit;
    } while (exit == 'Y' || exit == 'y');

    cout << t_end;

    return 0;
}
