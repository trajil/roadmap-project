#include<iostream>
using  std::cin, std::cout, std::string;

/* CURRENT TASK:

"Using the Basic/A/Problem 1 project make a control structure using if statements and logical operators. 
The structure should give the user a choice between the available arithmetic operations. The choice should be the sign of the operation"

    

*/


int main()
{
    //fixed outputs
    string t_welcome_1 = "Hi there, buddy! We're doing maths and stuff! First: Enter your two numbers: \n";
    string t_sum="The sum is: ";
    string t_dif="\nThe difference is: ";
    string t_product="\nThe product is: ";
    string t_quo="\nThe quotient is: ";
    string t_nunbers_wrong = "Please only use whole numbers!";

     
    //choices
    string t_choice = "Now select the type of arithmetic operation (+ - / or *) you want to use: "; 
    string t_choice_wrong = "Please use: (+ - / or *)";



    double x, y;
    char choice_operator;
    

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

    return 0;

}
