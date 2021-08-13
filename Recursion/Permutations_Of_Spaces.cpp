//Question :- (https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0).

/*
Approach:-
1. Base case:- Whenever input string gets empty we get a permutaion in output string.
2. Now, we will have two outputs everytime based on our decisions (either add a character with space or add it without space).
3. Now, we have to recursively call the fxn with output1 and output2.
*/

#include <iostream>
#include <string>
using namespace std;

void permutationsOfSpaces(string input, string output)
{
    if (input == "")
    {
        cout << output << "\n";
        return;
    }

    string op1 = output + " " + input[0];
    string op2 = output + input[0];

    input.erase(input.begin() + 0);

    permutationsOfSpaces(input, op1);
    permutationsOfSpaces(input, op2);
}

int main()
{
    string input, output = "";

    cout << "Enter string for Finding it's Permutations ";
    cin >> input;

    cout << "Permutations Of Spaces " << input << " are\n";

    output += input[0];
    input.erase(input.begin() + 0);

    permutationsOfSpaces(input, output);
}
