#include <iostream>
#include <string>

template <class T> class List{
	
	private:
		//One node of the list which contains one variable for data and a pointer to the next node
		template <class T> struct Node{
		T data;
		Node<T> *next;
	};
		//This pointers will point to first and last node and num_of_nodes will keep track of how many there are
		Node<T> *head, *tail;
		int num_of_nodes=0;

	public:
		//Pointing to NULL because we will be adding data after making an object
		List()
		{
			head=NULL;
			tail=NULL;
		}
		//This is essentially a push function, it will add a node to the end of the list 
		void CreateNode(T input_value)
		{
			Node<T> *temp = new Node<T>;
			temp->data=input_value;
			temp->next=NULL;

			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
				num_of_nodes++;
			}
			else
			{
				tail->next=temp;
				tail=temp;
				temp=NULL;
				num_of_nodes++;
			}
		}
		//Overloaded CreateNode so the place in the list can also be chosen
		void CreateNode(T input_value, int place)
		{
			if(place==1 && head!=NULL) //adding at the start of the list if the list is NOT empty
			{
				Node<T> *temp = new Node<T>;
				temp->data=input_value;
				temp->next=head;
				head=temp;
				temp=NULL;

			}
			else if(place>1 && place<=num_of_nodes+1) //place must be between 1 and number of nodes in the list
			{
				Node<T> *previous = new Node<T>;
				Node<T> *current = new Node<T>;
				Node<T> *temp = new Node<T>;
				temp->data=input_value;
				current=head;
				for(int i=0; i<place-1; i++)
				{
					previous=current;
					current=current->next;
				}
				temp->next=current;
				previous->next=temp;
				num_of_nodes++;
				temp=NULL;
			}
			else 	//if all above fails... well, it failed. Invalid input.
			{
				std::cout << "Invalid input." << std::endl;
				return;
			}

		}
		//Prints the whole list as a column
		void PrintList()
		{
			Node<T> *temp= new Node<T>;
			temp=head;
			if(head==NULL)
			{
				std::cout << "The list is empty." << std::endl;
			}
			else
			{
				int i=1;
				while(temp!=NULL)
				{
					std::cout << "Data #" << i++ <<": " << temp->data << std::endl;
					temp=temp->next;
				}
			}
		}
		//Returns size of the list 
		const int size()
		{
			return num_of_nodes;
		}
};



int main(){
	List<int> integers;
	integers.CreateNode(4);
	integers.CreateNode(5);
	integers.CreateNode(6,3);
	integers.CreateNode(7,3);
	integers.PrintList();
	std::cout << "The list has " << integers.size() << " elements." << std::endl;

	List<std::string> words;
	words.CreateNode("Hello");
	words.CreateNode("world");
	words.CreateNode("I can even fit sentences in here.", 2);
	words.PrintList();


	return 0;
}