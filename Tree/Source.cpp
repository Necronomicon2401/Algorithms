#include <iostream>
#include <queue>

using namespace std;


struct Tree {
	int data = NULL;
	Tree* left = NULL;
	Tree* right = NULL;
};

struct Tree* addNode(int x, Tree* tree) {
	if (tree == NULL) { 
		tree = new Tree; 
		tree->data = x;   
		tree->left = NULL;
		tree->right = NULL; 
	}
	else  if (x < tree->data)   
		tree->left = addNode(x, tree->left);
	else    
		tree->right = addNode(x, tree->right);
	return(tree);
}

void createTreeFromArray(Tree* &tree, int array[], int n)
{
	for (int i = 0; i < n; i++) {
		tree = addNode(array[i], tree);
	}
}


void treePrint(Tree* tree) {
	if (tree != NULL) { 
		cout << tree->data << " "; 
		treePrint(tree->left); 
		treePrint(tree->right); 
	}
}

bool search(Tree* tree, int x) {
	if (tree != NULL) {
		if (x == tree->data) {
			return true;
		}
		else if (x > tree->data) search(tree->right, x);
		else if (x < tree->data) search(tree->left, x);
	}
	return false;
}

void straightPrint(Tree* tree)
{
	if (tree == NULL)   
	{
		return;
	}
	cout << tree->data << " ";
	straightPrint(tree->left);
	straightPrint(tree->right);
}

void centralPrint(Tree* tree)
{
	if (tree == NULL)   
	{
		return;
	}
	centralPrint(tree->left);
	cout << tree->data << " ";
	centralPrint(tree->right);
}

void backPrint(Tree* tree)
{
	if (tree == NULL)  
	{
		return;
	}
	backPrint(tree->left);
	backPrint(tree->right);
	cout << tree->data << " ";
}

void widthPrint(Tree* tree) {
	if (tree == NULL)
	{
		return;
	}
	queue<Tree*> q; 
	q.push(tree); 

	while (!q.empty()) 
	{
		Tree* temp = q.front();
		q.pop(); 
		cout << temp->data << " "; 

		if (temp->left != NULL)
			q.push(temp->left);  

		if (temp->right != NULL)
			q.push(temp->right);  
	}
}

int height(Tree* tree) {
	int h = 0;
	if (tree == NULL)
	{
		return h;
	}
	return 1 + max(height(tree->left), height(tree->right));
}


int main()
{
	const int n = 5;
	int a[n];
	a[0] = 3;
	a[1] = 2;
	a[2] = 4;
	a[3] = 1;
	a[4] = 5;
	struct Tree *tree;
	tree = NULL;
	createTreeFromArray(tree, a, n);
	cout << "Tree : ";
	treePrint(tree);
	cout << endl;
	cout << "Straight print : ";
	straightPrint(tree);
	cout << endl;
	cout << "Central print : ";
	centralPrint(tree);
	cout << endl;
	cout << "Back print : ";
	backPrint(tree);
	cout << endl;
	cout << "Width print : ";
	widthPrint(tree);
	cout << endl;
	cout << "Height of tree : ";
	cout << height(tree);
	cout << endl;
	system("pause");
	return 0;
}