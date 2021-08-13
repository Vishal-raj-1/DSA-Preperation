/* Question:- Return the kth symbol in grammar. Grammar here is defined as :-
If n = 1 & k = 1 then there is 0 at that position . Here n - (nth row) and k - (kth column) .
If there is 0 at kth positon in the last row then there will be 01 at next row and if there is 1 at kth position in last row then it will be 10 in next row.
so, structure will be like this:-

            0
            0  1 
            0  1  1  0
            0  1  1  0  1  0  0  1 
            .
            .
            .
  Link :- (https://leetcode.com/problems/k-th-symbol-in-grammar/)
*/

/*
Approach:- 
1. Base case:- It is gven in the question that if n = 1 && k = 1 then return 0 at that position.
2. Let's take n = 4 so after observing 3rd and 4th row we can say that elements before mid of fourth row are sam as the 3rd row and elements after the mid in the 4th row 
are complement of the elements of 3rd row.
3. So , if k lies in left of mid then we will recursively call solve fxn with n-1 & k otherwise if it lies in right of middle the we will call solve fxn with n-1 & k-mid.
*/

int kthSymbolInGrammar(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;

    int mid = 1 << (n - 2); // which is 2^(n-1)/2 == 2^(n-2)

    if (k <= mid)
        return kthSymbolInGrammar(n - 1, k);
    else
        return !kthSymbolInGrammar(n - 1, k - mid);
}
