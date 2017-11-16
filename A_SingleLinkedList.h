#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

template <typename Tmplt>

class A_SingleLinkedList {

private:

	//nodes within the list
	//nested class to discourage making (a) node(s) outside of a LinkedList
	struct Node {

		//constructor
		Node(Tmplt* const _data) {

			//assign this the _data passed
			myData = _data;

			//for now, assume this is the back of the LinkedList
			this->nextNode = 0;

		}

		//data contained within the node
		Tmplt myData;

		//the next node in the list
		Node* nextNode;


	};//END OF Node

	  // pointers to first and last nodes in the list
	Node *front, *back;

	//the number of elements in this list
	int listSize;

public:

	//public iterator class for our single linked list
	class A_SingleLinkedListIterator {

	private:

		//A_SingleLinkedList declared as friend to avoid wasting time accessing iterator objects
		//seen as benificial since iterator is essentially a helper class for A_SingleLinkedList
		friend class A_SingleLinkedList;

		Node *node;

	public:



	};//end of A_SingleLinkedListIterator

	/**
	Default constructor
	initializes front, back, and listSize to 0
	*/
	A_SingleLinkedList() {

		this->front = this->back = 0;

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
	const Tmplt* getfront() {

		//if the list is not empty, it's fine to return the front
		if (this->listSize > 0)
			return this->front;

		//if the list is currently empty, return 0
		return 0;

	}

	/**
	returns a constant pointer to the last pointer in this list
	*/
	const Tmplt* getback() {

		if (this->listSize > 0)
			return this->back;

		//if the list is currently empty, return 0
		return 0;

	}
	
	/**
	pushes this data into a new node, located at the front of the list
	*/
	void PushFront(Tmplt& const _newNode) {

		//the new front of the list
		Node *T_NewFront = new Node(_newNode);

		//if this is empty, this should be a new node which is both the front and the back of this list
		if (this->listSize == 0) {

			this->front = this->back = T_NewFront;

		}

		//if not, place the new node at the new front of the list, and have it pointing to the former front
		else {

			T_NewFront->nextNode = this->front;
			*this->front = T_NewFront;

		}

		//list got bigger
		++this->listSize;

		//test this
		//meant to avoid memory leak
		delete T_NewFront;

	}

	/**
	pushes this data into a new node, located at the back of the list
	*/
	void PushBack(Tmplt& const _newNode) {

		//the new front of the list
		Node *T_NewBack = new Node(_newNode);

		//if this is empty, this should be a new node which is both the front and the back of this list
		if (this->listSize == 0) {

			this->back = this->front = T_NewFront;

		}
		
		//if not, place the new node at the new back of the list, and have the former back pointing to it
		else {

			this->back->nextNode = T_NewBack;
			this->back = T_NewBack;

		}

		//list got bigger
		++this->listSize;

		//test this
		//meant to avoid memory leak
		delete T_NewFront;

	}

	/**
	used to remove the front most element from this list
	DO NOT check for an empty list before calling this method, it accounts for size 0
	*/
	void PopFront() {
		//if the list is not empty
		if (this->listSize > 0) {

			//if this list only has one element to begin with remove it
			//by making both front and back null
			if (this->front == this->back) {

				this->front = this->back = 0;

			}

			//this will fire if the list size is greater than 1
			else {

				//temporary pointer to hold the position of the old head of the list
				Node *T_OldHead = this->head;

				//moving the list's head pointer to it's new head
				this->head = this->head->nextNode;

				//deleting the pointer to the value to the old head of the list
				delete T_OldHead;

			}

			//either way, decrement the size of the list
			--this->listSize;

		}

	}

	/**
	used to remove the back most element from this list
	DO NOT check for an empty list before calling this method, it accounts for size 0
	*/
	void PopBack() {
		//if the list is not empty
		if (this->listSize > 0) {

			//if the list only has one element to begin with remove it
			//by making both the front and back null
			if (this->front == this->back) {

				this->front = this->back = 0;

			}

			//this will fire if the list size is greater than 1
			else {

				//holding the address of the old back of the list
				Node T_OldBack = this->back;
				//going to use our back pointer to traverse the list, to the node before it's old value
				this->back = this->head;
				while (this->back->nextNode != T_OldBack) 
					this->back = this->back->nextNode;

				//the new back is found, temp must be deleted
				delete T_OldBack;
				

			}

			//either way, decrement the size of the list
			--this->listSize;

		}

	}

};

#endif