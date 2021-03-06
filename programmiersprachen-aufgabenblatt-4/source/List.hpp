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
		return &(node->value);
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

		// copy constructor
		List(List<T> const& a){
			ListNode<T>* n = a.first_;
			size_ = sizeof(T);

			first_ = nullptr;
			last_ = nullptr;

			while(n != nullptr){
				T t = n->value;
				push_back(t);
				n = n->next;
			}
			n = nullptr;
		}

		// move constructor
		List(List<T>&& rhs){
			first_ = rhs.first_;
			last_ = rhs.last_;
			rhs.first_ = nullptr;
			rhs.last_ = nullptr;
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
			a.node = last_;
			return a;
		}

		void clear(){
			ListNode<T>* a = first_;
			while(a != nullptr){
				a = a->next;
				pop_front();
			}
			a = nullptr;
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
				first_->next = nullptr;
				delete first_;
				first_ = a;
				a = nullptr;
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
				last_->prev = nullptr;
				delete last_;
				last_ = a;
				a = nullptr;
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
			return c;
		}

		bool operator==(List<T> const& rhs){
			if(size() != rhs.size()){
				return false;
			}

			else{
				bool eq = true;
				ListNode<T>* a = first_;
				ListNode<T>* b = rhs.first_;
				while(a != nullptr){
					if(a->value != b->value){
						eq = true;
					}
					a = a->next;
					b = b->next;
				}
				a = nullptr;
				b = nullptr;

				if(eq)
					return true;
				else
					return false;
			}
		}

		bool operator!=(List<T> const& rhs){
			if(size()!=rhs.size()){
				return true;
			}

			else{
				ListNode<T>* a = first_;
				ListNode<T>* b = rhs.first_;
				while(a != nullptr){
					if(a->value == b->value){
						return false;
					}
					a = a->next;
					b = b->next;
				}
				a = nullptr;
				b = nullptr;

				return true;
			}
		}

		List<T>& operator=(List<T>& lhs){
			// first: empy existing list
			clear();
			ListIterator<T> a = lhs.begin();
			while(a.node!=nullptr){
				push_back(a.node->value);
				a++;
			}
			return *this;
		}

		void reverse(){
			ListNode<T>* a = first_;
			ListNode<T>* tmp = nullptr;
			while(a!=nullptr){
				tmp = a->prev;
				a->prev = a->next;
				a->next = tmp;
				a = a->prev; 
			}
			tmp = first_;
			first_ = last_;
			last_ = tmp;
			tmp = nullptr;
			delete tmp;
		}

		ListIterator<T> insert(ListIterator<T>& it, T const& t){
			// construct new node at position with given value
			ListNode<T>* a;
			a = new ListNode<T>();
			a->value = t;
			a->prev = it.node->prev;
			a->next = it.node;

			it.node->prev->next = a;
			it.node->prev = a;

			ListIterator<T> iter;
			iter.node = a;
			return iter;
		}

		void print(){
			ListNode<T>* a = first_;
			std::cout<<"The list:\n";
			while(a!=nullptr){
				std::cout<<a->value<<"\n";
				a = a->next;
			}
		}

	private:
		std::size_t size_;
		ListNode<T>* first_;
		ListNode<T>* last_;
};

template <class T>
List<T>& reverse(List<T>& l){
	l.reverse();
	//List<T> rev{l};
	return l;
}

template<class T>
List<T> operator+(List<T>& lhs, List<T>& rhs){
			List<T> r{lhs};
			ListIterator<T> a = rhs.begin();

			while(a.node != nullptr){
				r.push_back(a.node->value);
				a++;
			}
			return r;
}

#endif //LIST_HPP