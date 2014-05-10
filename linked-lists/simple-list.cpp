/**
 * a simple (non-oo) singly-linked list with basic functions add,
 * del, search
 * 
 * EAS
 */

#include <iostream>
using namespace std;

struct IntNode
{
    int x;
    IntNode *next;
};

IntNode* create_node (int val)
{
    IntNode *tmp = new IntNode;
    tmp->x = val;
    tmp->next = NULL;
    return tmp;
}

IntNode* add (IntNode *list, int val)
{
    IntNode *tmp = new IntNode;
    tmp->x = val;
    tmp->next = list;
    return tmp;
}

/**
 * deletes a node from a list, if it exists
 */
IntNode* del (IntNode *list, int val)
{
	// handle case where only one node exists
	if (list != NULL && list->next == NULL)
	{
		if (list->x == val)
		{
			delete list;
			list = NULL;
		}
	}
	else
	{
		IntNode *walker = list;
		// case where more than one node exists
		while (walker != NULL)
		{
			IntNode *next = walker->next;
			if (walker->next != NULL)
			{
				// they're trying to delete the head of list
				if (walker->x == val)
				{
					IntNode *todel = walker;
					list = walker = next;
					next = walker->next;
					delete todel;
					todel = NULL;
				}
				// trying to delete the middle of the list
				else if (walker->next->x == val)
				{
					IntNode *todel = walker->next;
					walker->next = walker->next->next;
					delete todel;
					todel = NULL;
				}
				// not found yet
				else
				{
					walker = next;
					next = next->next;
				}
			}
			else
			{
				// causes us to break out the loop
				walker = walker->next;
			}
		}
	}
	return list;
}

bool search (IntNode *list, int val)
{
    IntNode *p_list = list;
    while (p_list != NULL)
    {
        if (p_list->x == val)
            return true;
        p_list = p_list->next;
    }
    return false;
}

void print_list (IntNode *list)
{
    IntNode *p_list = list;
    while (p_list != NULL)
    {
        cout << p_list->x << endl;
        p_list = p_list->next;
    }
}

void clear_list (IntNode *list)
{
    IntNode *p_elem = list;
    if (list != NULL)
    {
    	clear_list(p_elem->next);
    	delete p_elem;
    }
}

int main (void)
{
    IntNode* list = NULL;
    int input = -1;

    cout << "let's add to the list..." << endl;
    cin >> input;
    while (input != -1)
    {
        list = add(list, input);
        cin >> input;
    }

    cout << "now let's search..." << endl;
    cin >> input;
    while (input != -1)
    {
        cout << search(list, input) << endl;
        cin >> input;
    }

    cout << "let's delete..." << endl;
    print_list(list);
    cout << endl;
    cin >> input;
    while (input != -1)
    {
    	list = del(list, input);
    	cout << endl;
    	if (list != NULL);
	    	print_list(list);
    	cout << endl;
    	cin >> input;
    }

    print_list (list);
    clear_list(list);
}
