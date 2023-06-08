#include<bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node* left;
  node* right;

  node(int d){
    this-> data=d;
    this-> left= NULL;
    this-> right= NULL;
  }

};

node* buildTree(node* root){

  cout<<"  Enter data: ";
  int data;
  cin >> data;
  root = new node(data);

  if( data == -1)
  return NULL;

  cout<<"\n Enter data for inserting in LEFT  of  "<<data<<endl;
  root -> left = buildTree( root -> left);
  cout<<"\n Enter data for inserting in RIGHT of "<<data<<endl;
  root -> right = buildTree( root -> right);

  return root;
}

void levelOrderTraversal(node* root)
{
  queue<node*> q;
  q.push( root );
  q.push(NULL); //sweprator fot root level

  while ( !q.empty() )
   {
    node* temp = q.front();
    q.pop();
    if(temp==NULL){
          //last level traversed :)
          cout<<endl;
          if( !q.empty())
          { //que still has some child nodes
              q.push(NULL);
          }
    }
    else{
      cout<< temp -> data <<" ";

          if( temp -> left)
          q.push( temp -> left );

           if( temp -> right)
           q.push( temp -> right );
        }
    }
}
//-------------inOrder------------
void travLNR(node* root)
{
   //baseCase
   if( root == NULL)
   return;

   travLNR( root->left );
   cout<< root-> data<< " ";
   travLNR( root-> right );
}



// cntr + shift + D for to replicate line

int main()
{
  node * root =NULL;

//tree creation
root =buildTree(root);
//levelOrderTraversal
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
cout<<"\n level order: \n\n";
levelOrderTraversal(root);
cout<<"\n inOrder -aka- LNR: \n\n";
travLNR(root); //inOrder

  return 0;
}
