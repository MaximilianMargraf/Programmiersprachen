#ifndef LIST_HPP
#define LIST_HPP

#include <cassert>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <initializer_list>

template <class T>
class List;

template <class T>
struct ListNode {
	// value of this node, with standard constructor of T
	T value = T();
	// pointer to previous and next object in list
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
};

template <class T>
struct ListIterator{
	using Self = ListIterator<T>;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using difference_type = ptrdiff_t;
	using iterator_category = std::bidirectional_iterator_tag;

	// return value of pointer with deref.
	T& operator*() const{ 
		return node->value;
	}

	// return pointer to iterator content
	T* operator->() const{
		T* t = &node->value;
		return t;
	}

	// increase to next iterator and give old position back
	ListIterator<T>& operator++(){
		if(node->next != nullptr){
			node = node->next;
			return *this;
		}
		else{
			return *this;
		}
	}

	// increase to next position but give old position back
	ListIterator<T> operator++(int){
		ListIterator<T> a;
		a.node = node;
		node = node->next;
		return a;
	}

	bool operator==(ListIterator<T> const& x) const{
		if(node != nullptr && x.node != nullptr){
			if(**this == *x){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if(node==nullptr && x.node == nullptr){
				return true;
			}
			else{
				return false;
			}
		}
	}

	bool operator!=(ListIterator<T> const& x) const{
		if(**this != *x){
			return true;
		}
		else{
			return false;
		}
	}

	ListIterator<T> next() const{
		if(nullptr != node){
			return ListIterator{node->next};
		}
		else{
			return ListIterator{nullptr};
		}
	}

	// pointer to current node
	ListNode<T>* node = nullptr;
};

template <class T>
class List{
	public:
		using value_type = T;
		using pointer = T*;
		using const_pointer = T const*;
		using reference = T&;
		using const_reference = T const&;
		using iterator = ListIterator<T>;

		// default constructor for empty list
		List(){
			size_ = sizeof(T);
			first_ = nullptr;
			last_ = nullptr;
		}

		// constructor which takes a set of CSV data
		List(std::initializer_list<T> ini_list){
			size_ = sizeof(T);
			first_ = nullptr;
			last_ = nullptr;
			for(auto a : ini_list){
				push_back(a);
			}
		}

		~List(){clear();}

		ListIterator<T> begin(){
			ListIterator<T> a;
			a.node = first_;
			return a;
		}

		ListIterator<T> end(){
			ListIterator<T> a;
			a.node = nullptr;
			return a;
		}

		void clear(){
			ListNode<T>* a = first_;
			while(a != nullptr){
				a = a->next;
				pop_front();
			}
		}

		// add element at the front of the list
		void push_front(T const& element){
			// create pointer to new ListNode
			ListNode<T>* a;
			a = new ListNode<T>();
			a->value = element;

			// if there are no other elements
			if(empty()){
				first_ = a;
				last_ = a;
			}
			// if there are other elements
			else{
				first_->prev = a;
				a->next = first_;
				first_ = a;
			}
		}

		void push_back(T const& element){
			// create pointer to new ListNode
			ListNode<T>* a;
			a = new ListNode<T>();
			a->value = element;

			// if there are no other elements
			if(empty()){
				first_ = a;
				last_ = a;
			}
			// if there are other elements
			else{
				last_->next = a;
				a->prev = last_;
				last_ = a;
			}
		}

		void pop_front(){
			// the list has at least 2 entries
			if(first_ != last_){
				ListNode<T>* a = first_->next;
				a->prev = nullptr;
				delete first_;
				first_ = a;
			}
			// 1 entry remaining
			else if(first_ == last_ && last_ != nullptr){
				first_ = nullptr;
				delete last_;
				last_ = nullptr;
			}
		}

		void pop_back(){
			// the list has at least 2 entries
			if(first_ != last_){
				ListNode<T>* a = last_->prev;
				a->next = nullptr;
				delete last_;
				last_ = a;
			}
			// 1 entry remaining
			else if(first_ == last_ && last_ != nullptr){
				last_ = nullptr;
				delete first_;
				first_ = nullptr;
			}
		}

		T& front(){
			assert(!empty());
			return first_->value;
		}

		T& back(){
			assert(!empty());
			return last_->value;
		}

		// check if list is empty
		bool empty() const{
			if(first_ == nullptr && last_ == nullptr){
			return true;
			}
			else{
				return false;
			}
		}

		std::size_t size() const{
			ListNode<T>* a = first_;
			unsigned int c = 0;
			while(a != nullptr){
				c += 1;
				a = a->next;
			}
			a = nullptr;
			delete a;
			return c;
		}

	private:
		std::size_t size_;
		ListNode<T>* first_;
		ListNode<T>* last_;
};

#endif //LIST_HPP