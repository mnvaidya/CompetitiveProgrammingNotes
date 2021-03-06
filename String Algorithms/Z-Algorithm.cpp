#include <bits/stdc++.h>
using namespace std;

// link for animation of this algorithm -->  http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm

// Function for searching the pattern in string with O(n) time complexity

vector<int> search(string pat, string txt)                  // returns the vector of indices at which the pattern is present   else returns -1 if the list is empty
        {
            string s= pat+'%'+txt;                         // concatenate pattern to the string, so that it will act as a prefix string for matching
				                                    // % is added because it is not present in either txt or pattern and it will indicate that this is the end of pattern that i have to search in txt

            int ptlen= pat.length();
            int n= s.length();
           
            vector<int>z(n);                 // z array of length equal to the string's length  .. 
				                               //z[i] will store the length of substring (which starts at i) which matches the prefix of the string
                                              //z[0] is meaningless as the substr starting from 0 to n-1 will always be equal to the prefix of that string

            int l=0; int r=0;                                  // rightmost segment match       (  l . . . . . r  )

            for(int i=ptlen+1; i<n; i++){                  // can start from 1 as well as ptlen + 1	because we have to find the pattern in the given txt which is after '%' part

                if(i<=r){                                               // if my current index lies completely inside the segment match   ie.   l . . . . i . . r
                    z[i]= z[i-l] ;                   		// z[i] will be atleast z[i-l] len    
                }

                while(i+z[i]<n and s[z[i]]==s[i+z[i]]) z[i]++;        // now we will check the possibility that whether it is possible that the next character (which is after that atleast len) matches with the corresponding prefix character or not  
                                                                    // s[ z[i] ]== s[ i+z[i] ] --- this line checks that next char matches or not, if it matches we increment that atleast len for z[i] until we find a mismatch 
                
                if(i+z[i]-1 > r) l=i, r=i+z[i]-1;                             // here we updates the l . . . . . r  range  (it gets updated only if the above while loop runs) 
                                                                         //otherwise the range remains same (means if the above while loop goes beyond the    r    then this updates it) 
                                                                         // i + z[i] -1   is to jst get the zerobased indexing bec r is also 0 based and if it is greater than the previous r, means we have to update the window or range  
            }
            
            vector<int> ans;                                        // to store the indices where the pattern has appeared
            for(int i=0; i<n; i++){
                if(z[i]==ptlen) ans.push_back(i-z[i]);                       // if the z[i] == patternlength , means we found a pattern at that position { i - z[ i ] } gives the 1-based indexing position
            }
            
            return ans;                         // returning that indices vector
        }

