/*
 Question:- You are given a string containing lowercase , uppercase characters and numerals . You have to find all the permutations of the given string 
 after changing uppercase and lowercase letters in the string.
 link - https://leetcode.com/problems/to-lower-case/

Approach:-
1. Base case:- Whenever input string gets empty we get a permutaion in output string.
2. Now, we will have two outputs when the character is alphabet based on our decisions (either add an uppercase character or lowercase character in output).
3. But in case of numerals we will have only one output.
3. Now, we have to recursively call the fxn with output1 and output2 in case of alphabet and with single output in case of numerals.
*/

#include<iostream>
#include<string>
using namespace std;

void LetterCaseChange(string input,string output)
{
    if(input == "")
    {
        cout << output << "\n";
        return;
    }
    
    if(isdigit(input[0]))
    {
        output += input[0];
        input.erase(input.begin());
        LetterCaseChange(input,output);
        return;
    }
    
    string op1 = output;
    string op2 = output;
    op1 += tolower(input[0]);
    op2 += toupper(input[0]);
    
    input.erase(input.begin());
    
    LetterCaseChange(input,op1);
    LetterCaseChange(input,op2);
}

int main()
{
    string input,output = "";
    
    cout << "Enter string for Finding it's Permutations ";
    cin >> input;
    
    cout << "Letter Case Change of " << input << " are\n";
  
    LetterCaseChange(input,output);
}
