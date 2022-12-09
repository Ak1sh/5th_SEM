

#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
	int key;

	Node **forward;
	Node(int, int);
};

Node::Node(int key, int level)
{
	this->key = key;


	forward = new Node*[level+1];


	memset(forward, 0, sizeof(Node*)*(level+1));
};


class SkipList
{
	int MAXLVL;
	float P;
	int level;
	Node *header;
	
public:
	SkipList(int MAXLVL, float P)
    {
	this->MAXLVL = MAXLVL;
	this->P = P;
	level = 0;
	header = new Node(-1, MAXLVL);
    }
    
	int randomLevel(){
	    float r = (float)rand()/RAND_MAX;
	     int lvl = 0;
	    while (r < P && lvl < MAXLVL)
	    {
	      	lvl++;
	       	r = (float)rand()/RAND_MAX;
	    }
	     return lvl;
	 }
	 
	Node* createNode(int key, int level){
	    Node *n = new Node(key, level);
	     return n;
	}
	void insertElement(int);
	void displayList();
	 void deleteElement(int);
    void searchElement(int);
    
};

void SkipList::insertElement(int key)
{
	Node *current = header;

	Node *update[MAXLVL+1];
	memset(update, 0, sizeof(Node*)*(MAXLVL+1));

	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] != NULL &&
			current->forward[i]->key < key)
			current = current->forward[i];
		update[i] = current;
	}

	current = current->forward[0];

	if (current == NULL || current->key != key)
	{

		int rlevel = randomLevel();

		if (rlevel > level)
		{
			for (int i=level+1;i<rlevel+1;i++)
				update[i] = header;

		
			level = rlevel;
		}

	
		Node* n = createNode(key, rlevel);

	
		for (int i=0;i<=rlevel;i++)
		{
			n->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = n;
		}
		cout << "Successfully Inserted key " << key << "\n";
	}
};

void SkipList::searchElement(int key)
{
    Node *current = header;
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] &&
               current->forward[i]->key < key)
            current = current->forward[i];
  
    }
    current = current->forward[0];
    if(current and current->key == key) 
        cout<<"Found key: "<<key<<"\n";
    else cout<<"Not Found \n";
};
void SkipList::displayList()
{
	cout<<"\n*****Skip List*****"<<"\n";
	for (int i=0;i<=level;i++)
	{
		Node *node = header->forward[i];
		cout << "Level " << i << ": ";
		while (node != NULL)
		{
			cout << node->key<<" ";
			node = node->forward[i];
		}
		cout << "\n";
	}
};

void SkipList::deleteElement(int key)
{
    Node *current = header;
    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] != NULL  &&
              current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if(current != NULL and current->key == key)
    {
        for(int i=0;i<=level;i++)
        {
            
            if(update[i]->forward[i] != current)
                break;
  
            update[i]->forward[i] = current->forward[i];
        }
        while(level>0 &&
              header->forward[level] == 0)
            level--;
         cout<<"Successfully deleted key "<<key<<"\n";
    }
};
int main()
{

	
	SkipList lst(3, 0.5);
	while(1){
	    int choice;
	    cout<<"1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit\n";
	    cout<<"Enter the choice :";
	cin>>choice;
	switch(choice){
	    case 1:
	    int temp;
	    cout<<"Enter the element to insert:";
	    cin>>temp;
	    lst.insertElement(temp);
	    break;
	    case 2:
	    lst.displayList();
	    break;
	    case 3:
	    int val;
	    cout<<"Enter the value to be searched:";
	    cin>>val;
	    lst.searchElement(val);
	    break;
	    case 4:
	    int del;
	    cout<<"Enter the element to delete:";
	    cin>>del;
	    lst.deleteElement(del);
	    break;
	    case 5:
	    exit(0);
	    break;
	    default:
	    cout<<"Enter the correct choice!";
	    break;
	}
	}
	

	
}
