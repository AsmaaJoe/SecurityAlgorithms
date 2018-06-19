// Hill cipher for contest http://codeforces.com/group/KkzeMzmDoa/contest/216311/problem/A on codeforces 


//you can find cipher explained here http://crypto.interactive-maths.com/hill-cipher.html 
/*	Input:
The input consists of 3 lines. The first line contains the length of the key L(0 < L ≤ 104) L is guaranteed to be a perfect square. The second line contains L numbers X(0 ≤ X ≤ 109) which represent the key. You can use these numbers to form the key matrix of Hill Cipher. The last line contains the plaintext to encrypt. It is a single string that consists of at most 100 characters. Each character is a capital English alphabetical character.

	Output:
You should print the result of Hill Cipher encryption of the plain text using the key described above. The output should be a string of size that is bigger than or equal to the size of the plaintext(since you might need to append Xs while encrypting) and that consists only of capital English alphabetical letters.

Example:
input:
	4
	7 8 11 11
	SHORT
output:
	APADFU
*/
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

//function to map letters into numbers i.e A->0 B->1.........
int* substitute_char_with_integers(string a);

//split the plaintext into small matrices
void split(int partial[100][100], int *total, int p_size, int start, int sqrt_size, int &e);

//multiply matrices c(m,l)=x(m,n)*y(k,l) 
void multiply(int x[100][100],int m,int n, int y[100][100],int k,int l,int c[100][100]);

//print output in the desired shape
void print(int c[100][100],int k, int l);

// constant to declare the alphabet. To be used in mapping the char into integers and vice versa.
char alpha[26];

int main()
	{
	//initiate variable 'alpha' with the alphabet  
	for(int i=0; i<26; i++)
		{
			alpha[i]=65+i;
		}
	int n;
	cin>>n;
	n=sqrt(n);
	int key[100][100];
	long long t=0;
	for(int i=0; i<n; i++)
		{
		for(int j=0; j<n; j++)
		    {cin>>t; key[i][j]=t%26;}
		}
	string p;
	cin>>p;
	int p_size=p.size(), e;
	int *pp=substitute_char_with_integers(p);
	int cipher[100][100];
	int partial[100][100];
	for(int i=0; i<p_size; i+=e)
	{
		split(partial, pp, p_size, i, n*n, e);
		//partial*key>>new int *cipher
		if(e==n)
		{	multiply(key,n,n, partial,e,1, cipher);
			print(cipher,n,1);
		}
		else if(e==n*n)
		{
			multiply(key,n,n, partial,n,n, cipher);
			print(cipher,n,n);
		}
	}


	return 0;
}
int* substitute_char_with_integers(string aa)
{
    int *x=new int[aa.size()];
    for(unsigned int i=0; i<aa.size(); i++)
    {
        for(int j=0; j<26; j++)
        {
            if(alpha[j]==aa[i])
            {x[i]=j;   break;}
        }
    }
    return x;
}
// we take a n*n from plain or n*1 or
void split(int partial[100][100], int *total, int p_size, int start, int sqrt_size, int &e)
{
    int s=sqrt(sqrt_size);
    if (sqrt_size<=(p_size-start))
    {
        for(int m=0; m<s; m++)
        {
            for(int n=0; n<s; n++)
            {
             partial[n][m]=total[m*s+n+start];
            }
        }
        e=sqrt_size;
    }
    else if (s<=(p_size-start))
    {
        for(int m=0; m<s; m++)
        {
         partial[m][0]=total[m+start];
        }
        e=s;
    }
    else
    {
        for(int m=0; m<s; m++)
        {
        if(m+start<p_size)
         partial[m][0]=total[m+start];
        else partial[m][0]=23;
        }
        e=s;
    }
}
void multiply(int x[100][100],int m,int n, int y[100][100],int k,int l, int ci[100][100])
{
        int c;
        for(int i=0 ;i<m ;i++)
        {
            for(int j =0 ;j<l ;j++)
            {
                c =0;
                for(int h=0;h<n;h++)
                {
                c=c+x[i][h]*y[h][j];
                }
                ci[i][j]=c%26;
            }
        }
}
void print(int c[100][100],int k, int l)
{
for(int i=0; i<l; i++)
	for(int j=0; j<k; j++)
	{
		for(int d=0; d<26; d++)
		    if(d==(c[j][i]))
		        {cout<<alpha[d];break;}

	}
}





