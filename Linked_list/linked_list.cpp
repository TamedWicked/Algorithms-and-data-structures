#include <iostream>
#include <string>

template <class T>
class List{
private:
	template <class T>
	struct Node {
		T element;
		Node<T> *next;
		Node<T> *prev;
		int place=1;
	};

	Node<T> *head,*tail;

public:
	List()
	{
		head=NULL;
		tail=NULL;
	}
	//Make a new list element as a tail
	void CreateNode(T input_value)
	{
		Node<T> *temp = new Node<T>;
		temp->element=input_value;
		temp->next=NULL;
		temp->prev=tail;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{
			temp->place=(tail->place)+1;
			tail->next=temp;
			tail=temp;
		}
	}
	//Create a node with a given place in the list.
	void CreateNode(T input_value, int place_num)
	{
		Node<T> *previous=new Node<T>;
	    Node<T> *current=new Node<T>;
	    Node<T> *temp=new Node<T>;
	    current=head;
	    for(int i=1;i<place_num;i++)
	    {
	      previous=current;
	      current=current->next;
	    }
	    current->prev=temp;
	    temp->prev=previous;
	    temp->place=previous->place+1;
	    temp->element=input_value;
	    previous->next=temp;	
	    temp->next=current;
		
		for(int i=temp->place+1;i<tail->place+1;++i)
		{
			temp=temp->next;
			temp->place++;
		}
		tail->place++;
	}

	//Show the whole list from head to tail
	void ShowList()
	{
		Node<T> *temp = new Node<T>;
		Node<T> *temp2 = new Node<T>;
		temp=head;
		temp2=temp->prev;
		while(temp!=NULL)
		{
			std::cout << std::endl;
			std::cout << "Data #" << temp->place <<": " << temp->element;
			if(temp->prev!=NULL){std::cout <<"	Previous element: " << temp2->element;}
			temp=temp->next;

			if(temp!=NULL)temp2=temp->prev;
		}
		if(head==NULL){
			std::cout << "The list is empty." << std::endl;
		}
	}
	//Show specific Node given positive integer as an argument
	void ShowNode(int number)
	{

		if(head==NULL || number>tail->place){std::cout << "Input number invalid or list is empty." << std::endl; return;}

		if(number==tail->place){
			std::cout << "Data #" << tail->place <<": " << tail->element;
			return;}

		if(number>0 && head!=NULL)
		{
			Node<T> *temp = new Node<T>;
			temp=head;
			while(temp!=NULL)
			{
				if(temp->place==number){
					std::cout << "Data #" << temp->place <<": " << temp->element;
					break;}

				temp=temp->next;
			}
		}
	}

	void DeleteFirst()
	{
		
	}

	const T ListSize(){if(tail!=NULL)return tail->place; else return 0;}
	const T GetData(int number)
	{
		Node<T> *temp = new Node<T>;
		temp=head;
		if(head==NULL || number>tail->place || number<1)
			return NULL;
		
		if(number==tail->place)
			return tail->element;

		while(temp!=NULL)
		{
			if(temp->place==number)
				return temp->element;

			temp=temp->next;
		}
	}
};

int main(){
	List<int> lista;
	lista.CreateNode(4);
	lista.CreateNode(22);
	lista.CreateNode(6);
	lista.CreateNode(64);
	lista.CreateNode(88);
	lista.CreateNode(16);
	lista.CreateNode(5,3);
	lista.CreateNode(666,4);
	lista.CreateNode(222,2);
	lista.ShowList();
	//lista.DeleteFirst();
	std::cout << std::endl;
	lista.ShowList();
	return 0;
}