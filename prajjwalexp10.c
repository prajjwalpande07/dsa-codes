#include<stdio.h>
#include<conio.h>


struct node
{
 struct node* left;
 int data;
 struct node* right;
};
static int count=0;

struct node* newnode(int num)
{
 struct node* temp;
 temp=(struct node*)malloc(sizeof(struct node*));
 temp->data=num;
 temp->left=temp->right=NULL;
 return temp;
}

void preorder(struct node* root)
{
 if(root!=NULL)
 {
 printf("%d\t",root->data);
 preorder(root->left);
 preorder(root->right);
 }
}

void inorder(struct node* root)
{

 if(root!=NULL)
 {
 inorder(root->left);
 printf("%d\t",root->data);
 inorder(root->right);
 }
}

void postorder(struct node* root)
{
 if(root!=NULL)
 {
 postorder(root->left);
 postorder(root->right);
 printf("%d\t",root->data);
 }
}

struct node* ins_node(struct node* root,int num)
{
  struct node* temp=NULL;
  if(root==NULL)
  {
   root=newnode(num);
  }
  else
      {
       temp=root;
       while(temp!=NULL)
	      {
	       if(num<temp->data)
		{
		 if(temp->left==NULL)
		 {
		 temp->left=newnode(num);
		 break;
		 }
		 temp= temp->left;
		}
	       else
	       {
		 if(temp->right==NULL)
		 {
		  temp->right=newnode(num);
		  break;
		 }
		temp= temp->right;
	       }

	      }

      }
      return root;

}
int count_node(struct node *root)
{
  if(root!=NULL)
  {
  count++;
  count_node(root->left);
  count_node(root->right);
  }
  return(count);
}
void freenode(struct node *root)
{
  if(root!=NULL)
  {
    freenode(root->left);
    freenode(root->right);
    free(root);
  }
 }
 struct node *search(struct node *root,int val)
 { if(root==NULL)
      return(NULL);
   if(val==root->data)
      return(root);
   if(val<root->data)
   return search(root->left,val);
   else
   return search(root->right,val);
 }


void main()
{
 struct node* temp=NULL, *root=NULL;
 int num,choice,i,val;
 clrscr();
 while(1)
 {
  printf("\nMENU::\n1.INSERT_NODE\n2.DISPLAY\n3.COUNT NODES\n4.SEARCH\n5.EXIT\n");
  printf("Enter your choice::\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	  printf("Enter the data for the node::\n");
	  scanf("%d",&num);
	  root=ins_node(root,num);
	  break;
   case 2:
	  if(root!=NULL)
	  {
	  printf("PRE-ORDER TRAVERSAL::\n");
	  preorder(root);
	  printf("\nIN-ORDER TRAVERSAL::\n");
	  inorder(root);
	  printf("\nPOST-ORDER TRAVERSAL::\n");
	  postorder(root);
	  }
	  else
	  {
	  printf("Unable to Display::\n");
	  }
	  break;

  case 3:
	i=count_node(root);
	printf("\n Number of nodes=%d",i);
	break;
  case 4:
	 printf(" Enter value to be search\n ");
	 scanf("%d",&val);
	 temp=search(root,val);
	 if(temp!=NULL)
	 printf("Element found\n");
	 else
	 printf("Element not found\n");
	 break;
  case 5:
	 freenode(root);
	 exit(0);
	 break;

  }
 }
 getch();
}
