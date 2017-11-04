#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

template <typename Tmplt>

class A_SingleLinkedList {

public:

	/**
	Default constructor
	initializes start, end, and listSize to 0
	*/
	A_SingleLinkedList() {

		this->start = this->end = 0;

		this->listSize = 0;

	}

	/**
	destructor calls the Clear method
	*/
	~A_SingleLinkedList() {

		// =D

	}

	/**
	returns true if the list is not empty
	*/
	bool IsEmpty() {

		if (this->listSize == 0) return true;

		//if we've gotten to this line, it's acceptable to return false
		return false;

	}

	/**
	returns the size of this list
	*/
	const int getSize() {

		return this->listSize;

	}

	/**
	returns a constant pointer to the first pointer in this list
	*/
	const Tmplt* getStart() {

		//if the list is not empty, it's fine to return the start
		if (this->listSize > 0)
			return this->start;

		//if the list is currently empty, return 0
		return 0;

	}

	/**
	returns a constant pointer to the last pointer in this list
	*/
	const Tmplt* getEnd() {

		if (this->listSize > 0)
			return this->end;

		//if the list is currently empty, return 0
		return 0;

	}
	
	/**
	pushes this data into a new node, located at the front of the list
	*/
	void PushFront(Tmplt& const _newNode) {

		//if this is empty, this should be a new node which is both the start and the end of this list
		if (this->listSize == 0) {



		}

		//if not, place the new node at the new start of the list, and have it pointing to the former start

	}

private:

	//nodes within the list
	//nested class to discourage making (a) node(s) outside of a LinkedList
	struct Node {

		//constructor
		Node(Tmplt* const _data) {

			//assign this the _data passed
			myData = _data;

			//for now, assume this is the end of the LinkedList
			this->nextNode = 0;

		}

		//data contained within the node
		Tmplt myData;

		//the next node in the list
		Node* nextNode;


	};//END OF Node

	// pointers to first and last nodes in the list
	Node *start, *end;

	//the number of elements in this list
	int listSize;

};

#endif