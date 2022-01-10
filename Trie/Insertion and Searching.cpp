
		              // TRIE //

//uses::       auto complete,         spell checkers ,       longest prefix matching 
//string search in O(L) time where L is length of string to be searched


// Program for first insert words into trie and then search for them if present or not 

#include <bits/stdc++.h>
using namespace std;

const int size=26;         		 // max size of lowercase letters

struct node{                             // structure of the node
    bool end;                                  // denoting the end of word
    node* arr[size]; 		             // each node will have this array of size 26
};


node* getNode(){     		           // creating a new node
    node* newnode= new node;
    newnode->end= false;
    for(int i=0; i<size; i++){
        newnode->arr[i]=NULL;  		    // this newly created node will have 26 other nodes attached to it (all currently set to NULL)
    }
    return newnode;
}


void insert(string s, node* root){                // inserting a string into the trie
    node* temp= root;     	             // create a temporary node, so not to bring any change in root

    for(int i=0; i<s.length(); i++){
        int index= s[i]-'a';
        
        // if this node is not present, create a new one
        if(temp->arr[index]==NULL) temp->arr[index]=getNode();

        temp=temp->arr[index];        	 // traverse forward to insert each character of the string
    }
    temp->end=true;         		  // mark the end of word
}


bool search(string s, node* root){                      // searching whether string    s    is present in trie or not
    node* temp=root;

    for(int i=0; i<s.length(); i++){
        int index=s[i]-'a';

        if(temp->arr[index]==NULL) return false;	  //if not exists that node, that word doesnot exist 
        
        temp=temp->arr[index];
    }

    return temp->end;           			 // return whether the last node is a end of the searching word or not
}

int main(){

    node* root= getNode();     		  // creating the root node (must)

    int n , code;
    string st;
 
    while(1)
                {
		cin>>code;
 
		if(code == 1)                                // code - 1 means to insert a string into trie
		{
			cout<<"Enter string to insert\n";
			cin>>st;
			insert(st, root);    			 // inserting the string into trie
		}
		else
		if(code == 2)                              // code - 2 means searching the string in trie
		{
			cout<<"Enter string to search\n";
			cin>>st;
			cout<<search(st, root)<<endl;  		  //searching for that string in trie
		}
		else
		break;
	}

    return 0;
}