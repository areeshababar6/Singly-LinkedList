#include<iostream>
using namespace std;

struct Node {
	int data;
	Node *link;

	void count_of_nodes(Node *);
	void print_list(Node *);
	Node* insert_list(Node *, int);            // inserting data at the end of the list
	int insert_data_array(int, int, int);
	int insert_array(int, int, int, int, int);//insert data at the end of the array
	Node* insert_at_beg(Node *, int);     //Insert the node at the begining of the list
	int insert_array_beg(int, int, int);
	void insert_btw_list(Node*, int, int);
	void insert_btw_array(int, int, int, int, int);
	Node* delete_first_list(Node*);
	int delete_last_list(Node*);
	void delete_certain_pos(Node **, int);
	Node *delete_entire_list(Node*);
	Node *reverse_list(Node* );
};
void count_of_nodes(Node *head)
{
	int count = 0;
	if (head == NULL)
		cout << "List is empty";
	Node *ptr = NULL;
	ptr = head;
	while (ptr != NULL) {
		count++;
		ptr = ptr->link;
	}
	cout << count << endl;

}

void print_list(Node *head)
{
	if (head == NULL)
		cout << "List is Empty" << endl;
	Node *ptr = NULL;
	ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->link;
	}
}

Node* insert_list(Node *head, int data)
{
	Node *ptr, *temp;
	ptr = head;
	temp = (Node *)malloc(sizeof(Node));
	temp->data = data;                        // creating the node with these 3 steps     
	temp->link = NULL;

	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}

	ptr->link = temp;
	return temp;
}

int insert_data_array(int a[], int freepos, int data) //if array is not full
{
	a[freepos] = data;
	freepos++;
	return freepos;     //maintaining the index of the empty slot in freepos variable
}

int insert_array(int a[], int b[], int n, int freepos, int data) // if array is full
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	b[freepos] = data;
	freepos++;
	return freepos;     //maintaining the index of the empty slot in freepos variable
}

Node *insert_at_beg(Node *head, int d)       // Method 2    void insert_at_beg(Node **head, int d)
{
	Node* ptr;
	ptr = (Node *)malloc(sizeof(Node));
	ptr->data = d;
	ptr->link = NULL;
	ptr->link = head;                            //ptr->link = *head;
	head = ptr;                                  //*head = ptr;
	return head;
}

int insert_array_beg(int arr[], int n, int data)          // insert the data at the starting of the array
{
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[0] = data;
	return n + 1;
}

void insert_btw_list(Node *head, int data, int pos)
{
	Node *ptr = head;
	Node *ptr2 = (Node *)malloc(sizeof(Node));
	ptr2->data = data;
	ptr2->link = NULL;

	pos--;
	while (pos != 1)
	{
		ptr = ptr->link;
		pos--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
}

void insert_btw_array(int arr[], int arr2[], int n, int data, int pos)
{
	int index = pos - 1;   //index are the particular position where the data is added.
	for (int i = 0; i <= index - 1; i++)
	{
		arr2[i] = arr[i];    //this loop is working before the index value.
	}
	arr2[index] = data;   // add the desired data in array 2 index.

	for (int i = index + 1, j = index; i < n + 1, j < n; i++, j++)
	{
		arr2[i] = arr[j];  // this loop is adding rest of the element from array1 to the array2.
		// this arr2 is printing 
	}
}

Node* delete_first_list(Node* head)
{
	if (head == NULL)
	{
		cout << "List is already Empty!" << endl;
	}
	else {
		Node *temp = head;
		head = head->link;
		free(temp);
	}
	return head;
}

Node* delete_last_list(Node * head)  //void using single pointer
{
	if (head == NULL)
	{
		cout << "List is already Empty!" << endl;
	}
	else if (head->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		/*	Node *temp = head;
			while (temp->link->link != NULL)                //using single pointer
			{
				temp = temp->link;
			}
			free(temp->link);
			temp->link = NULL;*/

			//using double pointers
		Node *temp = head;
		Node *temp2 = head;

		while (temp->link != NULL);
		{
			temp2 = temp;
			temp = temp->link;
		}
		temp2->link = NULL;
		free(temp);
		temp = NULL;
	}
	return head;
}

int delete_start_array(int arr[], int n)
{
	if (n == 0)
	{
		cout << "Array is Empty!" << endl;
		return n;
	}
	for (int i = 0; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
		return n - 1;
	}
}

void delete_certain_pos(Node **head, int pos)
{
	Node *current = *head;
	Node *perivous = *head;

	if (*head == NULL)
	{
		cout << "List is Empty!" << endl;
	}
	else if (pos == 1)
	{
		*head = current->link;
		free(current);
		current = NULL;
	}
	else
	{
		while (pos != 1)
		{
			perivous = current;
			current = current->link;
			pos--;
		}
		perivous->link = current->link;
		free(current);
		current = NULL;
	}
}

Node *delete_entire_list(Node *head)
{
	Node *temp = head;
	
	while (temp != NULL)
	{
		temp = temp->link;
		free(head);
		head = temp;
	}
	return head;
}

Node *reverse_list(Node *head)
{
	Node *prev = NULL;
	Node *next = NULL;

	while (head != NULL)
	{
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}
int main()
{
	Node *head, *ptr;            //*cur
	head = (Node *)malloc(sizeof(Node));
	head->data = 45;
	head->link = NULL;

	ptr = (Node *)malloc(sizeof(Node));
	ptr->data = 60;
	ptr->link = NULL;
	head->link = ptr;

	cout << "Inserting node at the begining of the list" << endl;
	/*
		int data = 3;
		head = insert_at_beg(head, data);                 //insert_at_beg(&head ,data);  ------>method 2
		ptr = head;

		cout << "Adding the node at the begining of the list " << endl;
		while (ptr != NULL)
		{
			cout << ptr->data << endl;
			ptr = ptr->link;
		}

		cout << "Print how many no of Nodes in list" << endl;

	/*cur = (Node *)malloc(sizeof(Node));
	cur->data = 50;
	cur->link = NULL;
	head->link = cur;

	cur = (Node *)malloc(sizeof(Node));
	cur->data = 55;
	cur->link = NULL;

	head->link->link = cur;

	cout << "Print No-of-Node" << endl;
	count_of_nodes(head);
	*/

	cout << "Iserting node at the end of the list" << endl;
	/*cout << "Inserting the node at the end" << endl;
	insert_list(head, 60);*/


	cout << "Printing the data of the list " << endl;
	/*cout << "Printing Data" << endl;
	print_list(head);
	*/

	cout << "Inserting Data using Array VS Linked List" << endl;
	/*
	Node *ptr = head;

	ptr = insert_list(ptr, 5);
	ptr = insert_list(ptr, 6);
	ptr = insert_list(ptr, 7);

	ptr = head;

	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->link;
	}

	Insertion at the end of the array
	there are 2 ways to insert a value in array
	  1- If array s not full            //Time Complexity: O(1)

	int a[10];
	int n, freepos;
	cout << "Enter the no of elemets:";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the value of array " << i + 1 <<"   ";
		cin >> a[i];
	}
		freepos = n;
		freepos = insert_data_array(a, freepos, 30);

		cout << "DISPLAYING THE OUTPUT OF THE ARRAY" << endl << endl << endl;

	for ( int i = 0; i <freepos; i++)
	{
		cout << "The output of array:  " << i + 1 << " ";
		cout << a[i] << endl;
	}

	   2- If array is full               //Time Complexity: O(n)
	/*int a[3];
	int n, freepos;
	cout << "Enter the no of elemets:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the value of array " << i + 1 << "   ";
		cin >> a[i];
	}

	cout << "DISPLAYING THE OUTPUT OF THE ARRAY" << endl << endl << endl;

	int size = sizeof(a) / sizeof(a[0]);
	freepos = n;
	if (n == size)
	{
		int b[size+2];
		freepos = insert_array(a, b, size, freepos, 34);
		for (int i = 0; i < freepos; i++)
		{
			cout << "The output of array:  " << i + 1 << " ";
			cout << b[i] << endl;
		}
	}*/

	cout << "Inserting Data at the begining of the array" << endl;
	/*
		int arr[10], data = 10, i, n;
		cout << "Enter the no of elements:" << endl;
		cin >> n;

		cout << "Enter the element:" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		n = insert_array_beg(arr, n, data);     //Time Complexity = O(n);

		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << endl;
		}
		*/

	cout << "Inserting node at the between of the list" << endl;
	/*	insert_list(head, 4);
	insert_list(head, 6);

	int data = 5, position = 6;
	insert_btw_list(head, data, position);
	ptr = head;

	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->link;
	}*/

	cout << "Inserting data at the between of the array" << endl;
	/*int pos = 5, data = 11;
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
		//size=10(means size of array)
	int* arr2 = new int[size + 1];
					 //arr2 =>means increase the size of array from the perivous array (10+1)

	insert_btw_array(arr, arr2, size, data, pos);
	for (int i = 0; i < size + 1; i++)
	{
		cout << arr2[i] << endl;  //from above arr2 is printed .
	}
	delete[] arr2;                    // Time complexity:O(n)
*/

	cout << "Deleting the node at the start of the List " << endl;
	//head = delete_first_list(head);
	//ptr = head;
	//while (ptr != NULL)
	//{                                             //Time Complexity=O(n)
	//	cout << ptr->data << endl;
	//	ptr = ptr->link;
	//}

	cout << "Deleting node at the last of the List" << endl;
	//delete_last_list(head);   //=> using for single pointer
	//head = delete_last_list(head);
	//ptr = head;
	//while (ptr != NULL) {                                    //Time Complexity=O(n)
	//	cout << ptr->data << endl;
	//	ptr = ptr->link;
	//}

	cout << "Deleting data at the last of the array" << endl;
	//int arr[] = { 2,4,6,8,12,13,14,15,17 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	////int* arr2 = new int[size + 1];
	//size = size - 1;
	//for (int i = 0; i < size; i++)
	//{
	//	cout << arr[i] << endl;                ////Time Complexity=O(1)
	//}

	cout << "Deleting data at the start of the array" << endl;
	//int arr[8], n;
	//cout << "Enter the no in the array!" << endl;
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> arr[i] ;         //Time Complexity=O(n)
	//}
	//n = delete_start_array(arr, n);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << endl;
	//}

	cout << "Deleting data at certain position in List" << endl;
	/*int pos = 2;
	delete_certain_pos(&head, pos);
	ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->link;
	}*/

	cout << "Deleting entire List" << endl;
	/*head = delete_entire_list(head);
	if (head == NULL)
	{
		cout << "List id Deleted successfully!" << endl;
	}*/

	cout << "Reverse the List" << endl;
	head = reverse_list(head);
	ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->link;
	}

	return 0;

}
