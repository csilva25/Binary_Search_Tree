//p7
//Cristian Silva
//upbeatfish
#include <iostream>
#include <vector>
#include <string>
#include "bst_tree.h"
using namespace std;

int main()
{
    string input;
    string value;
    BST_tree tree;
    
    while (cin >> input)
    {
        if (input == "echo")
        {
            cin.ignore();
            getline(cin, value);
            tree.echo(value);
        }
        else if (input == "breadth")
        {
            vector<string> boxes;
            tree.bft(boxes);
            cout << "{";
            for (unsigned int i = 0; i < boxes.size(); i ++)
            {
                if (i != boxes.size() -1)
                {
                    cout << boxes[i] <<", ";
                }
                else
                {
                    cout << boxes[i];
                }
            }
            cout << "}" << endl;
        }
            else if (input == "print")
            {
                vector<string> boxes;
                tree.print(boxes);
                cout << "{";
                for (unsigned int i = 0; i < boxes.size(); i++)
                {
                    if (i != boxes.size() -1)
                    {
                        cout << boxes[i] << ", ";
                    }
                    else
                    {
                        cout << boxes[i];
                    }
                }
                cout << "}" << endl;
            }
                else if (input == "insert")
                {
                    cin.ignore();
                    getline(cin,value);
                  
                    if (tree.insert(value) == false)
                    {
                        cerr << "insert <"<< value <<"> failed. String already in tree." <<endl;
                    }
                   // cin.ignore();
            }
                else if (input == "find")
                {
                    cin.ignore();
                    getline(cin,value);
                    
                    if (tree.lookup(value) == true)
                    {
                        cout << "<" << value << "> is in tree." <<endl;
                    }
                    else
                    {
                        cout << "<" << value << "> is not in tree." << endl;
                    }
        }
                else if (input == "size")
                {
                    cout << tree.size() << endl;
                }
        else if (input == "distance")
        {
            //double dis = tree.size()/(double)tree.distance();
            cout << "Average distance of nodes to root = "<< (double)tree.distance()/tree.size() <<endl;
        }
        else if (input == "balanced")
        {
            if (tree.balanced() == -1)
            {
                cout << "Tree is not balanced." << endl;
            }
            else
            {
                cout << "Tree is balanced."<< endl;
            }
        }
        else if (input == "rebalance")
        {
            vector<string> boxes;
             tree.print(boxes);
            tree.rebalance(boxes);
           
        }
        else
        {
            while (cin.peek() != '\n')
            {
                cin.ignore();
            }
            cerr<<"Illegal command <" << input << ">." << endl;
        }
    }
}



