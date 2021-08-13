/*
Question:- You have to find all the permutations of the given lowercase string after changing lowecase to uppercase letters in the string.
Link :- (https://leetcode.com/problems/letter-case-permutation/)

Approach:-
1. Base case:- Whenever input string gets empty we get a permutation in output string.
2. Now, we will have two outputs everytime based on our decisions (either add a character after converting it into uppercase or add it without converting into uppercase).
3. Now, we have to recursively call the fxn with output1 and output2.
*/

#include <iostream>
#include <string>
using namespace std;

void permutationsWithCaseChange(string input, string output)
{
    if (input == "")
    {
        cout << output << "\n";
        return;
    }

    string op1 = output + input[0];
    string op2 = output;
    op2 += toupper(input[0]);

    input.erase(input.begin());

    permutationsWithCaseChange(input, op1);
    permutationsWithCaseChange(input, op2);
}

int main()
{
    string input, output = "";

    cout << "Enter string for Finding it's Permutations ";
    cin >> input;

    cout << "Permutations With Case Changes of " << input << " are\n";

    permutationsWithCaseChange(input, output);
}
