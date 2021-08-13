// Question:- Sort the given array/vector using recursion.

/*
Approach:-
1. Base case:- If vector contains single element then it is already sorted.
2. Otherwise, Pop the last element of vector and store it in temp variable now call sort fxn in rest of the vector(which will sort the rest vector).
3. Now, only work is to push/insert the popped element in the vector back. So,in insert fxn, if vector is empty or the element is the greatest/ equal of the elements in the vector then push the element .
4. Otherwise, pop an element from vector and again check the condition through recursive call and atlast push the element back.
*/

void insert(vector<int> &v, int val)
{
    if (v.empty() || v.back() <= val)
    {
        v.push_back(val);
        return;
    }

    int temp = v.back();
    v.pop_back();

    insert(v, val);

    v.push_back(temp);
}

void sort(vector<int> &v)
{
    if (v.size() == 1)
        return;

    int val = v.back();
    v.pop_back();

    sort(v);

    insert(v, val);
}
