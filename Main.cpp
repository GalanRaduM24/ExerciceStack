﻿#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;

ifstream fin1("test1.txt");//suspect exists
ifstream fin2("test2.txt");//suspect does not exist


//Solution with complexity O(n)
void solutionOn(int n, int v[100][100])
{
    Stack<int> s, sj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s.push(v[i][j]);
            sj.push(v[j][i]);
        }
    }

    int cn = 0;
    int nr1 = 0, nr2 = 0, cnr1 = 0, cnr2 = 0;
    int vb = -1;
    int cnt = 0;
    
    while (cn != n * n)
    {
        if (s.pop() != 0)
            vb++;
        if (sj.pop() != 0)
            cnt++;
        cn++;
        if (cn % n == 0)
        {
            if (vb == -1)
            {
                nr1 = cn / n;
                cnr1++;
            }
            if (cnt == n - 1)
            {
                nr2 = cn / n;
                cnr2++;
            }
            vb = -1;
            cnt = 0;
        }
    }

    if (cnr1 == 1 && cnr2 != 0)
        cout << "suspect: " << nr1;
    else
        cout << "Did not participate";

}


//Solution with complexity O(n^2)
void solutionOn2(int n, int v[100][100]){
    Stack<int> s[1000], sj[1000];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i].push(v[i][j]);
            sj[i].push(v[j][i]);
        }
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
        int vb = -1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (s[i].pop() != 0)
                vb++;
            if (sj[i].pop() != 0)
                cnt++;
        }
        if (vb == -1 && cnt == n - 1)
        {
            cout << "suspect: " << i << endl;
            ok = true;
        }

    }

    if (!ok)
    {
        cout << "Did not participate";
    }
}

int main() {
    int n, a, v[100][100];

    //Test 1
    fin1 >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin1 >> v[i][j];
        }
    }
    solutionOn(n, v);
    cout << endl;
    solutionOn2(n, v);

    cout << endl;

    //Test 2
    fin2 >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin2 >> v[i][j];
        }
    }

    solutionOn(n, v);
    cout << endl;
    solutionOn2(n, v);

    /*Input from keyboard
    cout << "Ener size of matrix: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    */
   
    return 0;
}
