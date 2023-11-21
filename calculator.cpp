#include <iostream>
using std::cin, std::cout, std::string;

/* CURRENT TASK:

    Functions
    A. Define and call functions - Create reusable code blocks with specific tasks.
    Problem 1 (Operations to Functions)
        "Using the Control structure/C/Problem 1 refactor every arithmetic operation so it has a function. Do that only for the primitive type (int). Print the results to screen. Hard code the values in the functions"

*/

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
    string t_welcome_1 = "Hi there, buddy! We're doing maths and stuff! First: Enter your two numbers: \n";
    string t_sum = "The sum is: ";
    string t_dif = "The difference is: ";
    string t_product = "The product is: ";
    string t_quo = "The quotient is: ";
    string t_nunbers_wrong = "Please only use whole numbers!";

    // choices
    string t_choice = "Now select the type of arithmetic operation (+ - / or *) you want to use: ";
    string t_choice_wrong = "Please use: (+ - / or *)";
    string t_exit_question = "\nPress 'Y' to repeat!";
    string t_end = "\nGood bye!";

    int x, y;
    char choice_operator, exit;

    do
    {
        cout << t_welcome_1;
        cin >> x >> y;
        cout << t_choice;
        cin >> choice_operator;

        // double sum = x + y, dif = x - y, product = x * y, quo = x / y;

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
