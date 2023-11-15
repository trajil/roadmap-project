#include<iostream>
using  std::cin, std::cout, std::string;

/* Problem 1 (Aritmetic Operators)
		"Write a C++ program that asks the user to enter two integers. The program should then calculate and output the sum, difference, product and quotient 
        (as a floating point number) of these numbers. Use `cin` for input and `cout` for the output."
*/


int main()
{
    string t_welcome = "Hi there, buddy! We're doing maths and stuff! Enter your two numbers: \n", t_sum="The sum is: ",t_dif="\nThe difference is: ",t_product="\nThe product is: ",t_quo="\nThe quotient is: ";

    double x, y;


    cout << t_welcome;
    cin >> x >> y;

    double sum= x + y, dif= x - y, product= x * y, quo= x / y;
    cout << t_sum << sum << t_dif << dif << t_product << product << t_quo << quo ;

    return 0;

}
