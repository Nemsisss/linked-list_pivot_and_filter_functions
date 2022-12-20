#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct isOdd{
    bool operator()(int x){
        return (x%2!=0); //returns true if odd
    }
};

struct isEven{
    bool operator()(int x){
        return (x%2==0); //returns true if even
    }
};

//less than 0
struct lessThan{
     bool operator()(int x){
        return (x<0);
    }
};

//greater than or equal to 0
struct greaterThan{
     bool operator()(int x){
        return (x>=0);
    }
};


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    int pivot=8;

    //Test out your linked list code
    Node* smaller;
    Node* larger;
    llpivot(head, smaller, larger, pivot);
    cout<<endl;
    cout<<"The list Smaller than "<<pivot<< " contains: ";
    print(smaller);
    cout<<"The list Larger than "<<pivot<< " contains: ";
    print (larger);
    cout<<"Head contains: ";
    print(head);
    cout<<endl;

    head = readList(argv[1]); 
    isOdd f1;
    Node* newHead= llfilter(head, f1);
    cout<<"The list of even numbers: "<<endl;
    print(newHead);
    cout<<endl;

    head = readList(argv[1]);
    isEven f2;
    Node* newHead2= llfilter(head, f2);
    cout<<"The list of odd numbers: "<<endl;
    print(newHead2);
    cout<<endl;

    head = readList(argv[1]);
    lessThan f3;
    Node* newHead3= llfilter(head, f3);
    cout<<"The list of numbers greater than or equal to 0: "<<endl;
    print(newHead3);
    cout<<endl;

    head = readList(argv[1]);
    greaterThan f4;
    Node* newHead4= llfilter(head, f4);
    cout<<"The list of numbers less than 0: "<<endl;
    print(newHead4);
    cout<<endl;
     
     dealloc(smaller);
     dealloc(larger);
     dealloc(newHead);
     dealloc(newHead2);
     dealloc(newHead3);
     dealloc (newHead4);
    
    return 0;

}
