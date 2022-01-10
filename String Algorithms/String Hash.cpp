#include <bits/stdc++.h>
using namespace std;


//function for calculating the hash of string

long long int gethash(string key){               // calculating the hash of key
    long long int hash=0;                               // will contain the hash         
    long long int p= 31;                               // should be greater than the alphabets used in the string 
    long long int p_power= 1;

    for(char ch: key){
        hash= (hash+(ch-'a' + 1)*p_power) % 1000000007;
        p_power = (p_power*p) % 1000000007;
    }

    return hash;                   //returns hashvalue
}
