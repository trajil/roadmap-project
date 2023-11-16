#include<iostream>
using  std::cin, std::cout, std::string;

/* CURRENT TASK:

    "Using the Control structures/B/Problem 1 project and add repetability to the project. Choose the right loop to give the user as many arithmetic operations as he/she wishes. 
    All the code should be in the loop. Write a few sentances to elaborate your loop choice"

*/


int main()
{
    //fixed outputs
    string t_welcome_1 = "Hi there, buddy! We're doing maths and stuff! First: Enter your two numbers: \n";
    string t_sum="The sum is: ";
    string t_dif="The difference is: ";
    string t_product="The product is: ";
    string t_quo="The quotient is: ";
    string t_nunbers_wrong = "Please only use whole numbers!";

     
    //choices
    string t_choice = "Now select the type of arithmetic operation (+ - / or *) you want to use: "; 
    string t_choice_wrong = "Please use: (+ - / or *)";
    string t_exit_question = "\nPress 'Y' to repeat!";
    string t_end = "\nGood bye!";



    double x, y;
    char choice_operator, exit = 'Y';

    /* I chose the "while" loop because the other loops would not be the right choice:
            - the "for" loop is for repetetive tasks with a known ending;
            - the "do while" loop is for pre-tasks before the main loop - not needed in this case;
    */
    while( exit == 'y' || exit == 'Y')
    {
        cout << t_welcome_1; cin >> x >> y; cout << t_choice; cin >> choice_operator;

        double sum= x + y, dif= x - y, product= x * y, quo= x / y;


        switch(choice_operator)
        {
            case '+': 
                cout << t_sum << sum;
                break;

            case '-':
                cout << t_dif << dif;
                break;

            case '/':
                cout << t_quo << quo;
                break;

            case '*':
                cout << t_product << product;
                break;

            default:
                cout << t_choice_wrong;
                break;
        }

    cout << t_exit_question; cin >> exit;
    }

    cout << t_end ;

    return 0;

}
