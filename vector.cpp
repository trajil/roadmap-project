#include <iostream>
#include <limits>
#include <vector>

using std::cin, std::cout, std::string, std::vector;

// foreward_declaration functions
vector<int> dec_to_binary(int x);
vector<int> vector_reverse(int x);

// variables
vector<int> testitestmann(1000);
int counter, x, y, element;

int main()
{
    // cout << "Set the vector_length: ";
    // cin >> x;
    cout << "Set Y: ";
    cin >> y;
    cout << std::endl;
    dec_to_binary(y);
    // vector_reverse(x - 1);

    return 0;
}

vector<int> dec_to_binary(int y)
{
    cout << std::endl;
    cout << "@@@@@@@@@@@@@@@@@@@\n";
    vector<int> binary_whole(1000);

    int integer = y;
    int i = 0;
    int base = 2;
    int rest;
    int vector_length;

    if (integer >= base)
    {
        do
        {
            //cout << binary_whole[i];
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
    // reversing VECTOR
    for (int i = vector_length, j = 0; i >= 0; i--, j++)
    {

        testitestmann[i] = j;
    }

    // printing whole Vector out: Values N to 0
    cout << "\n Whole vector: ";
    for (int i = 0; i <= vector_length; i++)
    {
        cout << testitestmann[i];
    }
    cout << std::endl;
    cout << "@@@@@@@@@@@@@@@@@@@\n";

    return binary_whole;
}

vector<int> vector_reverse(int x)
{
    cout << "@@@@@@@@@@@@@@@@@@@\n";
    // filling VECTOR UP, counting every step
    for (int i = 0; i <= x; i++)
    {
        cout << " Position: " << i << std::endl;
        testitestmann[i] = i;
        cout << "VALUE: ";
        cout << testitestmann[i] << std::endl;
        counter = i;
    }

    // printing whole Vector out: Values 0 to N
    cout << "\n Whole vector: ";
    for (int i = 0; i <= counter; i++)
    {
        cout << testitestmann[i];
    }
    cout << std::endl;

    // reversing VECTOR, counting every step
    for (int i = counter, j = 0; i >= 0; i--, j++)
    {
        cout << " Position " << i << std::endl;
        testitestmann[i] = j;
        cout << "VALUE: ";
        cout << testitestmann[i] << std::endl;
    }

    // printing whole Vector out: Values N to 0
    cout << "\n Whole vector: ";
    for (int i = 0; i <= counter; i++)
    {
        cout << testitestmann[i];
    }
    cout << std::endl;
    cout << "@@@@@@@@@@@@@@@@@@@\n";

    return testitestmann;
}