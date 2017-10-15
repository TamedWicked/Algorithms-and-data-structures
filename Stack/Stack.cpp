#include <iostream>

template <class T>
class Stack{
private:
	template <class T>
	struct Node{
	T element;
	Node<T> *prev;
	};

	Node<T> *tail;

public:

	Stack()
	{
		tail=NULL;
	}

	void Push(T input_value)
	{
		Node<T> *temp = new Node<T>;
		temp->element=input_value;
		temp->prev=tail;
		if(tail==NULL)
		{
			tail=temp;
			temp=NULL;
		}
		else
		{
			temp->prev=tail;
			tail=temp;
		}
	}

	void ShowStack()
	{
		if(tail==NULL){
			std::cout << "Stack is empty.	";
			return;}

		Node<T> *temp = new Node<T>;
		temp=tail;
		while(temp!=NULL)
		{
			std::cout << temp->element << std::endl;
			temp=temp->prev;
		}

	}

	const T Pop()
	{
		if(tail==NULL){
			std::cout << "Stack is empty.";
			return NULL;}

		Node<T> *temp = new Node<T>;
		T element_holder;
		temp=tail;
		temp=temp->prev;
		element_holder=tail->element;
		delete tail;
		tail=temp;
		return element_holder;

	}
};


int main(){
	Stack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	//stack.Push(5);
	stack.ShowStack();
	std::cout << std::endl;
	std::cout	<< stack.Pop();
	std::cout	<< stack.Pop();
	std::cout	<< stack.Pop();
	std::cout	<< stack.Pop() << std::endl;
	stack.Pop();
	
	std::cout << std::endl;
	Stack<char> letters;
	letters.Push('S');
	letters.Push('t');
	letters.Push('a');
	letters.Push('c');
	letters.Push('k');
	std::cout << std::endl;
	std::cout	<< letters.Pop()
				<< letters.Pop()
				<< letters.Pop()
				<< letters.Pop()
				<< letters.Pop() << std::endl;
	letters.Pop();
	return 0;
}