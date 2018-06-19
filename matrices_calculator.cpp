//this is a school project for making a matrices calculator with C++ 2013.
// it could be done better with classes 
/*
Input:
1-Symbol of the process required i.e. + - * ^(raise power to int) T(transpose) D(determinant) 
2-Matrix or two with maximum size 100*100, float values.
Example:

Input:
[3 6 3.3;6 4 8;3 1 2]
+  
[3 6 4;1 0 3;2 0 4]

Output:
[6 12 7.3;7 4 11;5 1 6]

In case of any mathematic error print ERROR
*/
#include <iostream>
#include "string"
#include <stdlib.h>
#include <sstream>
#include <math.h>
using namespace std;
//function to read the input as one string and parse it into 2D array.
void mat      (float a[100][100],int &m,int &n);

//add two matrices, function requires sizes of both mats x(m*n) , y(k*l). Print output in the required form
void add      (float x[100][100],int m,int n, float y [100][100],int k,int l );

//subtract two matrices, function requires sizes of both mats x(m*n) , y(k*l). Print output in the required form
void sub      (float x[100][100],int m,int n, float y [100][100],int k,int l );

//multiply two matrices, function requires sizes of both mats x(m*n) , y(k*l). Print output in the required form
void multiply (float x[100][100],int m,int n, float y [100][100],int k,int l );

//raise matrix x(m*n) to the power 'exponent'. Print output in the required form
void power    (float x[100][100],int m,int n,int exponent);

//Transpose mat x(m*n). Print output in the required form
void transpose(float x[100][100],int m,int n);

//calculate determinant of mat a(n*n). Return the output
float determ (float a[100][100],int n);

int main()
{
    float a[100][100];
    int m=0,n=0;
    mat (a,m,n);
    float b[100][100];
    int k=0, l=0;
    string  Q;
    getline(cin,Q);
    switch (Q[0])
    {
    case '+':
        {
            mat (b,k,l);
            add(a,m,n,b,k,l);
            break;
        }
    case '-':
        {
            mat (b,k,l);
            sub(a,m,n,b,k,l);
            break;
        }
    case '*':
        {
            mat (b,k,l);
            multiply(a,m,n,b,k,l);
            break;
        }
    case '^':
        {
            int g;
            cin>>g;
            power(a,m,n,g);
            break;
        }
    case 'T':
        {
            transpose(a,m,n);
            break;
        }
    case 'D':
        {
            if(m!=n)
                {
                   cout<<"ERROR";
                    exit(0);
                }
          cout<<determ(a,m);

            break;
        }
    }

    return 0;
}
//need m,n,k,l real dimensions
// CHECKED
// every fn has it's mathematic check i.e. matrix dimensions are verified 
void mat (float a[100][100],int &m,int &n)
{
    string str;
    getline(cin,str);
    int t=str.length();
    if(str[0]!='[')
    {
        cout<<"ERROR";
        exit (0);
    }
    if(str[t-1]!=']')
    {
        cout<<"ERROR";
        exit (0);
    }
    int num[100];
    for (int e=0;e<100;e++)
    {
        num[e]=0;
    }
    string x[100];
    int p=str.find(";");int p2;
    int h=0;
    if(p==-1)
    {
        x[0]=str.substr(1,t-2);m=1;
        while (h!=-1)
        {
            h=x[0].find(" ",h+1);
            n++;
        }
    }
    else
    {
        x[0]=str.substr(1,p-1);
        for(int k=0;k<p;k++)
            if(x[k]==" ")
                num[0]+=1;
        for(int i=1;i<100;i++)
        {
            p2=str.find(";",p+1);
            if(p2==-1)
            {
                x[i]=str.substr(p+1,t-2-p);
                m=i+1;break;
            }
            else
            {
                x[i]=str.substr(p+1,p2-p-1);
                p=p2;
            }
        }

        for (int f=0;f<m;f++)
        {
            int z=0;
            while (z!=-1)
            {
                z=x[f].find(" ",z+1);
                num[f]++;
            }
        }
        int flag=1;
        for(int r=1;r<m;r++)
        {
            if(num[0]!= num[r])
            {
                flag=0;
                break;
            }
        }
        if (flag==0)
        {
            cout<<"ERROR";
            exit (0);
        }
        else n=num[0];
    }
// have correct x[m],m,n  v = atof(s.c_str());
    string s;
    for (int i=0;i<m;i++)
    {
        int w=x[i].find(" ");int w2;
        for(int j=0;j<n;j++)
        {
            w2=x[i].find(" ",w+1);
            if(j==0)
            {
                s=x[i].substr(0,w);
                a[i][j]=atof(s.c_str());
            }
            else if (j==n-1)
            {
                        s=x[i].substr(w+1,x[i].length()-1-w);
                        a[i][j]=atof(s.c_str());
            }
            else
                {
                    s=x[i].substr(w+1,w2-w);
                    a[i][j]=atof(s.c_str());
                    w=w2;
                }
        }
    }
}
void add (float x[100][100],int m,int n, float y [100][100],int k,int l )
{
    if (m!=k||n!=l)
    {
        cout<<"ERROR";
        exit(0);
    }
        cout<<"[";
        float sum=0;
        for(int i=0 ;i<m ;i++)
        {
            for(int j =0 ;j<n ;j++)
            {
                sum=x[i][j]+y[i][j];
                if(j<n-1)
                    cout<<sum<<" ";
                else if (j==n-1)
                    cout<<sum;
            }
 //CHECKED
            if(i!=m-1)
            cout<<";";

        }
        cout<<"]";
}
void sub (float x[100][100],int m,int n, float y [100][100],int k,int l )
{
    if (m!=k||n!=l)
    {
        cout<<"ERROR";
        exit(0);
    }
        cout<<"[";
        float sub=0;
        for(int i=0 ;i<m ;i++)
        {
            for(int j =0 ;j<n ;j++)
            {
                sub=x[i][j]-y[i][j];
                if(j<n-1)
                    cout<<sub<<" ";
                else if (j==n-1)
                    cout<<sub;
            }
 //CHECKED
            if(i!=m-1)
            cout<<";";

        }
        cout<<"]";
}
void multiply(float x[100][100],int m,int n, float y[100][100],int k,int l)
{
    if(n!=k)
    {
        cout<<"ERROR";
        exit(0);
    }

        cout<<"[";
        float c;
        for(int i=0 ;i<m ;i++)
        {
            for(int j =0 ;j<l ;j++)
            {
                c =0;
                for(int h=0;h<n;h++)
                {
                c=c+x[i][h]*y[h][j];
                }

                if(j<l-1)
                    cout<<c<<" ";
                else if (j==l-1)
                    cout<<c;
            }
 //CHECKED
            if(i!=m-1)
            cout<<";";

        }
        cout<<"]";
}
void power (float x[100][100],int m,int n,int e)
{
     if(m!=n)
    {
       cout<<"ERROR";
        exit(0);
    }
     if(e<0)
    {
        cout<<"ERROR";
        exit(0);
    }
    float y[100][100];
    for(int i =0;i<100;i++)
    {
        for (int j=0;j<100;j++)
        {
          y[i][j] =( i == j );
        }
    }
    float c[100][100];
    for (int d=0;d<e;d++)
    {
        for(int i=0 ;i<m ;i++)
        {
            for(int j =0 ;j<n ;j++)
            {
                c[i][j]=0;
                for(int h=0;h<n;h++)
                {
                c[i][j]+=y[i][h]*x[h][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                y[i][j]=c[i][j];
            }
        }
    }
        cout<<"[";
        for(int i=0 ;i<m ;i++)
        {
            for(int j =0 ;j<n ;j++)
            {
                if(j<n-1)
                    cout<<y[i][j]<<" ";
                else if (j==n-1)
                    cout<<y[i][j];
            }
 //CHECKED
            if(i!=m-1)
            cout<<";";
        }
        cout<<"]";
}
void transpose (float x[100][100],int m,int n)
{

    cout<<"[";
        for(int i=0 ;i<n ;i++)
        {
            for(int j =0 ;j<m ;j++)
            {
                if(j<m-1)
                    cout<<x[j][i]<<" ";
                else if (j==m-1)
                    cout<<x[j][i];
            }
 //CHECKED
            if(i!=n-1)
            cout<<";";

        }
        cout<<"]";
}
float determ (float a[100][100],int n)
{
      float det=0; int  p, h, k, i, j;
      float temp[100][100];
      if(n==1)
        {
            return a[0][0];
        }
      else if(n==2)
        {
            det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
            return det;
        }
      else
        {
            for(p=0;p<n;p++)
            {
                h = 0;
                k = 0;
// fill 'temp' (the smaller determ)
                for(i=1;i<n;i++)
                 {
                    for( j=0;j<n;j++)
                     {
                        if(j==p)
                         {
                            continue;
                         }
                         temp[h][k] = a[i][j];
                         k++;
                         if(k==n-1)
                         {
                            h++;
                            k = 0;
                         }
                     }
                 }
              det=det+a[0][p]*pow(-1,p)*determ(temp,n-1);
            }
        return det;
      }
}
