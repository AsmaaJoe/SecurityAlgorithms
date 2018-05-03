//Inverse Permutation Box contest on codeforces http://codeforces.com/group/KkzeMzmDoa/contest/216520/problem/B
//part of the DES encryption algorithm 
/*
Input:
The input consists of 2 lines. The first line contains a number S that represents the size of the permutation box which also represents the size of its input and output. The second line contains S numbers in decimal format that represent the values inside the permutation box which represent the order of the bits in the output with respect to the order of the bits in the input.

Output:
In case the given permutation box is reversible, output a single line containing the values in the inverse permutation box as described in the statement. In case the given permutation box is irreversible, output a single line containing "IMPOSSIBLE" without the quotes.

Example:
Input:
16
8 4 16 12 7 3 15 11 6 2 14 10 5 1 13 9

Output:
14 10 6 2 13 9 5 1 16 12 8 4 15 11 7 3
*/


#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <limits>
#include <math.h>
#include <stdlib.h>
using namespace std;

vector<int> ip(vector<int> table, int osize);

int main()
{
int s;
cin>>s;
cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

std::string line;
getline(std::cin, line);
std::istringstream iss(line);
std::vector<int> table,inverse;
int x;

while ( iss >> x ) table.push_back( x );

    if (s>table.size())
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=0; i<table.size(); i++)
    {
        /*if(table[i]>osize)
        {
        cout<<"IMPOSSIBLE";
        return 0;
        }*/
        for(int k=i+1; k<table.size(); k++)
        {
        if(table[i]==table[k])
        {
        cout<<"IMPOSSIBLE";
        return 0;
        }
        }
    }
inverse=ip(table,s);
for (int l=0; l<s; l++)
    cout<<inverse[l]<<" ";

return 0;
}

vector<int> ip(vector<int> table, int osize)
{

    vector<int> inverse(osize);
    for(int i=0; i<osize; i++)
    {
        inverse[table[i]-1]=i+1;
    }
    return inverse;
}

