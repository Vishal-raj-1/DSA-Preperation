/*
Question:- We are given three towers one is source, one is helper other is destination. We have to shift all the disks from source to destination using helper tower.
There are some conditions which are:-
1. We can't put larger disk on smaller one.
2. We can take only one disk at a time.
3. We can take help of helper tower to shift disks.
link :- (https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/)
*/

/*
Approach:-
1. If there is only one disk then simply shift it at destination from source.
2. Otherwise, Put all the disks at helper tower except the last one and move last disk to destonation.
3. Atlast move remaining n-1 disks from helper to destination.
*/
#include<iostream>
using namespace std;

void towerOfHanoi(int n,int source,int destination,int helper)
{
    //If only one disk then move disk and return
    if(n == 1)
    {
        cout << "move disk 1 From " << source << " To " << destination << "\n";
        return;
    }
    
    //Move Top n-1 disks from source to helper
    towerOfHanoi(n-1,source,helper,destination);
    
    //Move last disk From Source to Destination
    cout << "move disk " << n << " From " << source << " To " << destination << "\n";
    
    //Move n-1 disks from helper to destination
    towerOfHanoi(n-1,helper,destination,source);
}

int main(){
    int n; 
    cout << "Enter a number : ";
    cin >> n;
    towerOfHanoi(n,1,2,3);
    return 0;
}