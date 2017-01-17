//p7
//Cristian Silva
//upbeatfish

#ifndef BST_TREE
#define BST_TREE

#include <iostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class BST_tree
{
public:
    BST_tree(){m_root=NULL;};
    void rebalance(vector<string> boxes);
    int distance() {return distance(m_root, 0);};
    //find(string);
    void echo(string value);
    int balanced(){return balanced(m_root);};
    int size(){return size(m_root);};
    void dft();
    bool lookup(string value){return lookup(value,m_root);};
    bool insert(string value){return  insert(value, m_root);};
    void print(vector<string> &boxes){print(m_root, boxes);};
    void bft(vector<string> &boxes);
    void delete_subtree(){delete_subtree(m_root);};
private:

    
    class Node
    {
    public:
        Node (string value)
        {m_value = value;m_left = NULL;m_right = NULL;}
        
        string m_value;
        Node* m_left;
        Node* m_right;
        
       
    };
    //Node* cur_root;
    Node* m_root;
    int sum(int level, Node* cur_root);
    bool insert(string str, Node* &cur_value);
    bool lookup(string target, Node* cur_root);
    void dft(Node* cur_root);
    int balanced(Node* cur_root);
    void print(Node* cur_root, vector<string> &boxes);
    void rebalance(vector<string> boxes, int beginning, int finished);
    int distance(Node* cur_root, int avg);
    void delete_subtree(Node* cur_root);
    int size(Node* cur_root);
};



#endif
