//S Box contest on codeforces http://codeforces.com/group/KkzeMzmDoa/contest/216520/problem/C
//part of the DES encryption algorithm 
/*
Input:
The input consists of a single line which contains 12 Hex characters that represent the 48-bit input to the S-Boxes.

Output:
The output should consist of a single line which contains 8 Hex characters that represent the 32-bit output of the S-Boxes.

Example:
Input:
57FB0266F918

Output:
C93D3AB5
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> toBinary(long long num);
//Transforms decimal numbers into their binary sequence
vector<int> toBinary(int num);
//Overwrite of the previous function to include small decimal numbers 
//stored in 'int' data type 

void toDigits(vector<int> &b, int s);
//Adds the zeros to the left of the binary number if needed
//i.e. (6)decimal = 0110'b not 110'b 

long long toLongDecimal(vector<int> i);
//Transforms the binary sequence-stored in 'vector<int>' container to their corresponding
//huge decimal number and store it in 'long long' data type 
int toDecimal(vector<int> i);
//Overwrite of the previous function to produce small decimal numbers 
//stored in 'int' data type 
void sBoxSub(vector<int> binary_plain, vector<int> &sBoxcipher);

int sbox[8][64] ={ { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
                    0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
                    4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
                    15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 },
                  { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
                    3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
                    0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
                    13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 },
                  { 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
                    13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
                    13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
                    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 },
                  { 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
                    13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
                    10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
                    3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 },
                  { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
                    14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
                    4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
                    11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 },
                  { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
                    10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
                    9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
                    4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 },
                  { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
                    13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
                    1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
                    6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 },
                  { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
                    1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
                    7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
                    2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 }
                };

int main()
{
    long long input=0;
    cin>>hex>>input;
    vector<int> binary_plain(toBinary(input));
    toDigits(binary_plain,48);
    vector<int>cipher;
    sBoxSub(binary_plain,cipher);
    int output=toDecimal(cipher);
    cout<<hex<<uppercase<<output;
    return 0;
}
vector<int> toBinary(long long num)
{
    int rem;
    vector<int> out_binary;
    if (num <= 1)
    {
        out_binary.push_back(num);
        return out_binary;
    }
    rem = num % 2;
    out_binary=toBinary(num / 2);
    out_binary.push_back(rem);
}
vector<int> toBinary(int num)
{
    int rem;
    vector<int> out_binary;
    if (num <= 1)
    {
        out_binary.push_back(num);
        return out_binary;
    }
    rem = num % 2;
    out_binary=toBinary(num / 2);
    out_binary.push_back(rem);
}
void toDigits(vector<int> &b, int s)
{
    int f=s-b.size();
    if(f>=1)
    {
        for(int i=0; i<f; i++)
            b.insert(b.begin(),0);
    }
}
long long toLongDecimal(vector<int> i)
{
    int s=i.size();
    long long sum=0;
    for(int j=0; j<s; j++)
    {
        sum+=(i[j]*pow(2,s-1-j));
    }
    return sum;
}
int toDecimal(vector<int> i)
{
    int s=i.size();
    int sum=0;
    for(int j=0; j<s; j++)
    {
        sum+=(i[j]*pow(2,s-1-j));
    }
    return sum;
}
void sBoxSub(vector<int> binary_plain, vector<int> &sBoxcipher)
{
    vector<vector<int>> index(8,vector<int>(6));
    for(int i=0; i<8; i++)
    {
        for(int j=0;j<6; j++)
        {
            index[i][j]=binary_plain[i*6+j];
        }
    }
    vector<int> row(2),column(4);
    for(int l=0; l<8; l++)
    {
        row[0]=index[l][0];
        row[1]=index[l][5];
        column[0]=index[l][1];
        column[1]=index[l][2];
        column[2]=index[l][3];
        column[3]=index[l][4];
        int t=toDecimal(row)*16+toDecimal(column);
        t=sbox[l][t];
        vector<int> partofs;
        partofs=toBinary(t);
        toDigits(partofs,4);
        sBoxcipher.insert(sBoxcipher.end(),partofs.begin(),partofs.end());
    }
}



