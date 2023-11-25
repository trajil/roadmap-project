#include <iostream>
#include <limits>
#include <vector>

using std::cin, std::cout, std::string, std::vector;

// foreward_declaration functions
vector<int> dec_to_binary(int y);
vector<int> vector_reverse_with_length_and_print(vector<int> binary_whole, int vector_length);

int counter, x, y;
int vector_length;

int main()
{
    cout << "Your number: ";
    cin >> y;
    dec_to_binary(y);

    return 0;
}

vector<int> dec_to_binary(int y)
{
    cout << std::endl;
    cout << "@@@@@@@@@@@@@@@@@@@\n";
    vector<int> binary_whole(100);

    int integer = y;
    int i = 0;
    int base = 2;
    int rest;

    if (integer >= base)
    {
        do
        {
            // cout << binary_whole[i];
            rest = integer % 2;
            // cout << "RESTWERT: " << rest; // what is segmentation fault?
            binary_whole[i] = rest;
            integer = (integer - binary_whole[i]) / 2;
            i++;

            // cout << "Current BINARY: ";
            // cout << binary_whole[i];
            // cout << std::endl;
        } while (integer != 0);
    }
    else
    {
        cout << "Too low value entered!\n";
        return binary_whole;
    }
    vector_length = i;
    cout << "@@@@@@@@@ TESTSTELLE VEKTOR EINGABE @@@@@@@@@@\n";
    cout << std::endl;
    vector_reverse_with_length_and_print(binary_whole, vector_length);
    cout << "\n@@@@@@@@@ TESTSTELLE VEKTOR AUSGABE @@@@@@@@@@\n";
    cout << std::endl;


    return binary_whole;
}

vector<int> vector_reverse_with_length_and_print(vector<int> input_vector, int vector_length)
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