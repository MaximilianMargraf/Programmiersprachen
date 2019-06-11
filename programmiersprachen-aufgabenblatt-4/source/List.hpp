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
	T value = T ();
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

	/*T& operator*() const{
		return{};
	}

	T* operator->() const{
		return nullptr;
	}

	ListIterator<T>& operator++(){
		return {};
	}

	ListIterator<T> operator++(){
		return{};
	}

	bool operator==(ListIterator<T> const& x) const{
		return true;
	}

	bool operator!=(ListIterator<T> const& x) const{
		return false;
	}*/

	ListIterator<T> next() const{
		if(nullptr != node){
			return ListIterator{node->next};
		}
		else{
			return ListIterator{nullptr};
		}
	}

	// pointer to current node
	ListNode <T>* node = nullptr;
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
		}

		~List(){}

		ListIterator<T> begin(){}
		ListIterator<T> end(){}
		void clear(){}
		void push_front(T const& element){}
		void push_back(T const& element){}
		void pop_front(){}
		void pop_back(){}

		/*T& front(){
			assert(!empty());
			return T();
		}*/

		/*T& back(){
			assert(!empty())
			return T();
		}*/

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
			return std::distance(first_, last_);
		}

	private:
		std::size_t size_;
		ListNode<T>* first_;
		ListNode<T>* last_;
};

#endif //LIST_HPP