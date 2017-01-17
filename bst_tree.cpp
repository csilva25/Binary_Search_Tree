//p7
//Cristian Silva
//upbeatfish
#include <iostream>
#include <cmath>
#include <queue>
#include "bst_tree.h"
using namespace std;

/*BST_tree::BST_tree()
{
    m_root = NULL;
}
*/

void BST_tree::echo(string value)
{
    cout << value << endl;
}

/*
 
bool BST_tree::insert(string value)
{
    return insert( value, m_root);
    
}
*/
bool BST_tree::insert(string value, Node* &cur_root)
{
    if (cur_root == NULL)
    {
        cur_root = new Node (value);
        return true;
    }
    else if (value ==  cur_root -> m_value)
    {
        return false;
    }
    else if (cur_root -> m_value > value)
    {
      return  insert(value , cur_root -> m_left);
      
    }
    else
    {
      return  insert(value, cur_root -> m_right);
        
    }
   
    
}
/*
void BST_tree::delete_subtree()
{
     delete_subtree(m_root);
}
*/
void BST_tree::delete_subtree(Node* cur_root)
{
    if (cur_root != NULL)
    {
        delete_subtree(cur_root -> m_left);
        delete_subtree(cur_root -> m_right);
        delete cur_root;
    }
}

int BST_tree::sum(int value, BST_tree::Node *cur_root)
{
    return value + sum(value + 1, cur_root -> m_left) + sum(value + 1, cur_root -> m_right);
}
/*
int BST_tree::distance();
{
    return distance(m_root, 0);
}
*/
int BST_tree::distance(Node* cur_root, int avg)
{
    if (cur_root == NULL)
    {
        return 0;
    }
  
        return avg + distance(cur_root -> m_left, avg + 1) + distance(cur_root -> m_right, avg + 1);

    
    
    
   // return cur_root == NULL ?  0 : avg + distance(cur_root -> m_left, avg + 1) + distance(cur_root -> m_right, avg + 1);
  
}
/*
bool BST_tree::lookup(string value)
{
    return lookup(value , m_root);
}
*/
bool BST_tree::lookup(string value, Node* cur_root)
{
    if (cur_root == NULL)
    {
        return false;
    }
    else if (value == cur_root -> m_value)
    {
        return true;
    }
    else if (value < cur_root->m_value)
    {
        return lookup(value, cur_root->m_left);
    }
        else
        {
            return lookup(value , cur_root -> m_right);
        }
    
}

void BST_tree::dft()
{
    dft(m_root);
}

void BST_tree::dft(Node* cur_root)
{
    if (cur_root != NULL)
    {
        dft (cur_root -> m_left);
        cout << cur_root -> m_value << endl;
        dft(cur_root -> m_right);
    }
}

/*
int BST_tree::size()
{
   return size (m_root);
}
 */
int BST_tree::size(Node* cur_root)
{
    return cur_root == NULL ? 0 : size(cur_root -> m_left) + 1 + size(cur_root -> m_right);
}

/*
int BST_tree::balanced()
{
    return balanced(m_root);
}
*/
int BST_tree::balanced(Node* cur_root)
{
    
   
    if  (cur_root == NULL)
    {
        return 0;
    }
   
    else
    {
        int left = balanced(cur_root -> m_left);
        int right = balanced(cur_root -> m_right);
    
        if (abs(left - right) > 1 || left == -1 || right == -1)
        {
            return -1;
        }
        else
        {
            return left > right ? left + 1 : right + 1;
 //return the largest of my children's subtree plus one (plus one  because we count cur_node in the height);
        }
    }
}

void BST_tree::rebalance(vector<string> boxes)
{
    
     m_root = NULL;
    delete_subtree();
    rebalance(boxes , 0 , boxes.size() -1);
}

void BST_tree::rebalance(vector<string> boxes, int beginning, int finished)
{
    if (finished == beginning)
    {
        insert(boxes[beginning]);
        return;
    }
    else if (beginning > finished)
    {
        return;
    }
    else
    {
        int index = (finished - beginning)/ 2 + beginning;
        insert(boxes[index]);
        rebalance(boxes, beginning, index - 1);
        rebalance(boxes, index + 1, finished);
    }
}
/*
void BST_tree::print(vector<string> &boxes)
{
    return print(cur_root, boxes);
}
*/

void BST_tree::print(Node* cur_root, vector<string> &boxes)
{
    if (cur_root == NULL)
    {
        return;
    }
    else
    {
        print(cur_root -> m_left, boxes);
        boxes.push_back(cur_root -> m_value);
        print(cur_root -> m_right, boxes);
    }
  
}


void BST_tree::bft(vector<string> &boxes)
{
    if (m_root == NULL)
    {
        return;
    }
    else
    {
        queue<Node*> Node_Q;
        Node_Q.push(m_root);
        while (Node_Q.empty() != true)
        {
            Node* temp = Node_Q.front();
            Node_Q.pop();
         if (temp -> m_left != NULL)
         {
             Node_Q.push(temp -> m_left);
         }
         if (temp -> m_right != NULL)
         {
             Node_Q.push(temp -> m_right);
         }
         boxes.push_back(temp -> m_value);
        }
    }
}
 

/*


if (cur_root == NULL)
{return 0}
int left = balanced (cur_root ->m_left),
int right = balanced (cur_root ->m_right),
if (left == -1 || right == -1 )
{
    return -1,
}
if height of left differs from height of right by more than 1
reutn -1,
else
return max(left,right) +1
*/
