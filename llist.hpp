#pragma once

#include <cstddef>
#include <iostream>
#include <optional>

template<typename T> // the type of the data stored in the list
class SingleLinkedList {
private:
    // an element for the linked list. contains some data and a pointer to the next element
    struct Node {
	T data;
	Node* next;
    };

    // the beginning of the list
    Node* head = nullptr;

    // the end of the list
    Node* tail = nullptr;

    // the number of elements in the list
    size_t num_items = 0;
    
public:
    // pre: a list and some data to put in the list
    // post: insert that data at the beginning of the list
    void push_front(T data) {
	Node* newnode = new Node;
	newnode->data = data;
	if (head) {
	    newnode->next = head;
	    head = newnode;
	} else {
	    head = newnode;
	    tail = newnode;
	}
	num_items++;
    }

    // pre: a list and some data to put in the list
    // post: insert that data at the end of the list
    void push_back(T data) {
	Node* newnode = new Node;
	newnode->data = data;
	newnode->next = nullptr;
	
	if (tail) { // if there is at least one element (hence, there's a tail)
	    tail->next = newnode;
	    tail = newnode;
	} else { // if there are no elements in the list
	    head = newnode;
	    tail = newnode;
	}
	num_items++;
    }

    // pre: a list
    // post: if the list has elements, remove and return the first element. otherwise, return nothing
    std::optional<T> pop_front() {
	if (head) { // if the list is not empty (has head element)
	    if (!head->next) { // if the list has only one item (head)
		T return_value = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;

		num_items--;
		return return_value;
	    } else { // if the list has multiple items
		Node* tmp = head->next;
		T return_value = head->data;
		delete head;
		head = tmp;

		num_items--;
		return return_value;
	    }
	} else { // return nothing if list is empty
	    return std::nullopt;
	}
    }

    // pre: a list
    // post: if the list has elements, remove and return the last element. otherwise, return nothing
    std::optional<T> pop_back() {
	T return_value;
	
	if (head) { // if list has a head element (not empty)
	    Node* tmp = head;

	    if (!tmp->next) { // if there's only one element in the list, pop and return
		return_value = head->data;
		tail = nullptr;
		delete head;
		head = nullptr;

		num_items--;
		return return_value;
	    } else { // if there's multiple elements, iterate through the list and pop last
		while (tmp->next->next)
		    tmp = tmp->next;
	
		tail = tmp;
		return_value = tmp->next->data;
		delete tmp->next;
		tmp->next = nullptr;

		num_items--;
		return return_value;
	    }
	} else { // return nothing if list is empty
	    return std::nullopt;
	}
    }

    // pre: a list
    // post: if the list has elements, return the first element and keep it in the list. otherwise, return nothing.
    std::optional<T> front() {
	if (head)
	    return head->data;
	else
	    return std::nullopt;
    }

    // pre: a list
    // post: if the list has elements, return the last element and keep it in the list. otherwise, return nothing.
    std::optional<T> back() {
	if (tail)
	    return tail->data;
	else
	    return std::nullopt;
    }

    // pre: a list
    // post: clear all elements from the list. the resulting list should have head and tail as nullptr, and the number of items as 0
    void empty() {
	Node* tmp = head;
	while (tmp->next) {
	    Node* nextnode = tmp->next;
	    delete tmp;
	    tmp = nextnode;
	}

	num_items = 0;
	head = nullptr;
	tail = nullptr;
    }

    // pre: a list, an index in that list, and an item to add to the list
    // post: insert the given item into the list at the given index. check for errors
    void insert(const size_t index, const T& item) {
	if (index == 0) { // add to front of the list
	    push_front(item);
	} else if (index == num_items) { // add to end of the list
	    push_back(item);
	} else if (index > 0 && index < num_items) { // add to the middle of the list
	    Node* tmp = head;
	    Node* newnode = new Node;
	    newnode->data = item;
	
	    for(int i = 0; i < index - 1; i++)
		tmp = tmp->next;

	    newnode->next = tmp->next;
	    tmp->next = newnode;

	    num_items++;
	} else { // invalid index
	    std::cout << "Error: index out of bounds\n";
	}
	return;
    }

    // pre: a list and an index in that list
    // post: remove the item in the list at the given index. check for errors
    bool remove(size_t index) {
	if (index == 0) { // remove the head of the list
	    pop_front();
	} else if (index == num_items) { // remove the tail of the list
	    pop_back();
	} else if (index > 0 && index < num_items) { // remove from the middle of the list
	    Node* tmp = head;

	    for (int i = 0; i < index - 1; i++)
		tmp = tmp->next;

	    Node* nextnode = tmp->next->next;
	    delete tmp->next;
	    tmp->next = nextnode;

	    num_items--;
	} else { // invalid index
	    std::cout << "Error: index out of bounds\n";
	    return false;
	}

	return true;
    }

    // pre: a list and an item
    // post: iterate through the list and return the first index whose value matches the given item. if no item in the list matches the given item, return the size of the list
    size_t find(const T& item) {
	Node* tmp = head;
	size_t index = 0;
	
	while (true) {
	    if (tmp->data == item) {
		return index;
	    }

	    if(tmp->next) {
		tmp = tmp->next;
		index++;
	    } else {
		break;
	    }
	}

	return num_items;
    }

    // pre: a list
    // post: print all values in the list to stdout
    void print_list() {
	Node* tmp = head;
	while (tmp) {
	    if (tmp->next)
		std::cout << tmp->data << " --> ";
	    else
		std::cout << tmp->data << std::endl;
	    tmp = tmp->next;
	}
    }
};
