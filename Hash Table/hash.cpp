#include <iostream>
#include <string>

	struct item{
		std::string name;
		int age;
		item* next;
	};

class Hash{
public:

	Hash();
	~Hash();
	void insert(std::string name_input, int age_input);
	void print_all();
	int hashfun(std::string key);
	void print_item(std::string& str, int a);
	item* search(std::string key);
	void printindex(int index);
	item* Hash::returnindex(int index);
	friend std::ostream& Hash::operator<<(std::ostream& stream, const item* it);

private:


	static const int table_size = 10;

	item* HashTable[table_size];

};


int main(){

	Hash mytable;

	//std::cout << "Key:" << mytable.hashfun("Matija") << std::endl;
	mytable.insert("Matija", 20);
	mytable.insert("Ana", 24);
	mytable.insert("Karlo", 45);
	mytable.insert("Amber", 27);
	mytable.insert("Karlo", 19);
	mytable.insert("Jozo", 17);
	mytable.insert("Paul", 99);
	//mytable.insert("Matija", 14);
	//mytable.print_all();
	mytable.print_all();
	return 0;
}

Hash::Hash()
{

	for(int i=0; i<table_size; i++)
	{
		HashTable[i]=NULL;
	}

}

Hash::~Hash()
{

}

int Hash::hashfun(std::string key)
{
	int index=0;
	for(int i=0; i<key.length(); i++)
	{
		index+=(int)key[i];
	}
	return index%table_size;
}

void Hash::insert(std::string name_input, int age_input)
{
	int index = hashfun(name_input);
	if(HashTable[index]==NULL)
	{
		HashTable[index]= new item;
		HashTable[index]->name=name_input;
		HashTable[index]->age=age_input;
		HashTable[index]->next=NULL;
	}
	else
	{
		item* current = HashTable[index];
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next = new item;
		current->next->name=name_input;
		current->next->age=age_input;
		current->next->next=NULL;
	}
}

void Hash::print_all()
{
	item *current;
	for(int i=0; i<table_size; i++)
	{
		if(HashTable[i]!=NULL)
		{
			current=HashTable[i];
			std::cout << "Bucket #" << i << ": " << current;
			//print_item(current->name, current->age);
			while(current->next!=NULL)
			{
				current=current->next;
				std::cout << ", " << current;
			}
			std::cout << std::endl;
		}
		else
			std::cout << "Bucket #" << i << " is empty." << std::endl;
	}
}

void Hash::print_item(std::string& str, int a)
{
	for(int i=0; i<str.length(); i++)
	{
		std::cout << str[i];
	}
	std::cout << " " << a;
}

std::ostream& operator<<(std::ostream& stream, const item* it)
{
	stream << it->name; 
	stream << " " << it->age;
	return stream;
}

item* Hash::search(std::string key)
{
	int index=hashfun(key);
	if(HashTable[index]!=NULL)
	{
		item* current = HashTable[index];
		while(current->next!=NULL)
		{
			if(key==current->name)
				return current;
			else
				current=current->next;
		}
	}
	return NULL;
}

void Hash::printindex(int index)
{
	std::cout << HashTable[index]->name << " " << HashTable[index]->age; 
}

item* Hash::returnindex(int index)
{
	return HashTable[index];
}