#include <iostream>

template <class T>
	class Queue{
	private:
		template <class T>
		struct Node{
			T element;
			Node<T> *next;
		};

		Node<T> *head, *tail;

	public:
		Queue()
		{
			head=NULL;
			tail=NULL;
		}

		void CreateNode(T input_value)
		{
			Node<T> *temp = new Node<T>;
			temp->element=input_value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
		}

		void ShowQueue()
		{
			Node<T> *temp = new Node<T>;
			temp=head;
			if(head==NULL){std::cout << "Queue is empty." << std::endl; return;}
			while(temp!=NULL)
			{
				std::cout << temp->element << std::endl;
				temp=temp->next;
			}
		}

		void Pop()
		{
			Node<T> *temp = new Node<T>;
			temp=head;
			head=head->next;
			delete temp;
		}

	};

int main(){
	Queue<int> brojevi;
	brojevi.CreateNode(4);
	brojevi.CreateNode(16);
	brojevi.ShowQueue();
	brojevi.Pop();
	std::cout << std::endl;
	brojevi.ShowQueue();

	return 0;
}