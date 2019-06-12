#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
    T         value = T ();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T>
struct ListIterator {
    using Self              = ListIterator<T>;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using difference_type   = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    ListNode <T>* node = nullptr;

    //Aufgabe 4.5
    /* DESCRIPTION  operator*() */
    T&  operator*()  const {
  	    return node->value;
    }

    /* DESCRIPTION  operator->() */
    T* operator->() const {
  	    return &node->value;
    }

    /* ... */
    ListIterator<T>& operator++() {
  	    node = node->next;
        return *this;
    }

    /* ... */
    ListIterator<T> operator++(int) {
        ListIterator<T> nodereturn{*this};
        node = node->next;
        return nodereturn;
    } //POSTINCREMENT (signature distinguishes)

    /* ... */
    bool operator==(ListIterator<T> const& x) const {
  	    return node == x.node;
    }

    /* ... */
    bool operator!=(ListIterator<T> const& x) const {
  	    return node != x.node;
    }

    /* ... */
    ListIterator<T> next() const {
        if (nullptr != node) {
            return ListIterator{node->next};
        }
        else {
            return ListIterator{nullptr};
        }
    }
};

template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // not implemented yet
    // do not forget about the initialiser list !
  	/* ... */
    List() {
        size_ = 0;
        first_ = nullptr;
        last_  = nullptr;
        }
    
    List(List<T> const& rhs) {        //Aufgabe 4.8
        size_ = 0;
        first_ = nullptr;
        last_  = nullptr;
        if(rhs.empty()) {
        
        } else {
            ListIterator<T> check{rhs.first_};
            for (int i = 0; i < rhs.size_; ++i){
                push_back(*check);
                ++check;
            }
        }
    }

    //
    List(List<T> && rhs):
        first_(rhs.first_),
        last_(rhs.last_),
        size_(rhs.size_)
        {
            rhs.first_ = rhs.last_;
            rhs.first_ = nullptr;
            rhs.size_ = 0;
        }

    //Aufgabe4.9
    ListIterator<T> insert(ListIterator<T> const& x) {
        bool success = false;
        if(empty()) {
            push_back(0);
        } else {
            ListNode<T>* current = first_;
            ListNode<T>* previous;
            for (int i = 0; i < size_; ++i) {
                ListIterator<T> check{current};
                if (check == x) {
                    previous = current->prev;
                    ListNode<T>* newnode = new ListNode<T>;
                    newnode->value = *x;
                    newnode->next = current;
                    newnode->prev = previous;
                    current->prev = newnode;
                    if (current == first_) {
                        first_ = newnode;
                    }
                    ListIterator<T> result{newnode};
                    size_++;
                    return result;
                }
                current = current->next;
            }
        }
    }

    void reverse() {
        if (size_ <= 1) {

        } else {
            ListNode<T>* current = first_;
            ListNode<T>* mark = last_;
            for (int i = 0; i < size_; ++i) {
                ListNode<T>* placeholder = current->next;
                current->next = current->prev;
                current->prev = placeholder;
                current=current->prev;
            }
            last_= first_;
            first_ = mark;
        }
    }

    /* ... */
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)

  	/* ... */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* ... */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* ... */
    //TODO: Assignment operator (Aufgabe 4.12)

    //Aufgabe 4.7
    bool operator ==(List<T> const& rhs) {
        if (size_ != rhs.size_) {
            return false;
        }
        if (size_ == rhs.size_) {
            if (size_ == 0) {
                return true;
            }
        }
        ListIterator<T> check1f {first_};
        ListIterator<T> check2f {rhs.first_};
        ListIterator<T> check1l {last_};
        ListIterator<T> check2l {rhs.last_};
        bool test = true;
        bool loop = true;
        ListIterator<T> null {};

        while (loop) {
            if (check1f == check1l) {
                if (check2f != check2l) {
                    test = false;
                    loop = false;
                }
                if(check2f == check2l) {
                    loop = false;
                }
            }
            if (check2f == check2l) {
                if (check1f != check1l) {
                    test = false;
                    loop = false;
                }
                if (check1f == check1l) {
                    loop = false;
                }
            }
            if (*check1f != *check2f) {
                test = false;
               loop = false;
            }
            check1f++;
            check2f++;
            }
        return test;
    }
     

    bool operator !=(List<T> const& rhs){
      return !(*this==rhs);
    }
  	
    ~List() {
    }

  	/* Iterates over list and returns the first element */
    ListIterator<T> begin() {
    	if (empty()) {
            return ListIterator<T>{};
        } else {
            return ListIterator<T>{first_};
        }
    }

  	/* Iterates over list and returns the last element */
    ListIterator<T> end() {
    	if (empty()) {
            return ListIterator<T>{};
        }
  		else {
            return ListIterator<T>{last_};
        }
    }

    /* Removes the last element of the list as long as the list has more than 0 elements */
    void clear() {
  		while (size_ !=0 ){
        pop_back();
        }
    }
  
    /* Inserts a new element at the beginning of the list. 
     * The content of element is copied to the inserted element (L) */
    void push_front(T const& element) {
  		ListNode<T>* L = new ListNode<T>;
        L->value = element;
        if (size_ == 0) {
            L->prev = nullptr;
            L->next = nullptr;
            first_ = L;
            last_ = L;
            size_++;
        } else {
            L->next = first_;
            L->prev = first_->prev;
            first_->prev = L;
            first_= L;
            size_++;
        }
    }

    /* Inserts a new element at the end of the list.
     * The content of "element" is copied to the new element (L) */
    void push_back(T const& element) {
  		ListNode<T>* L = new ListNode<T>;
        L->value = element;
  		if (size_ == 0) {
            L->prev = nullptr;
            L->next = nullptr;
            first_ = L;
            last_ = L;
        } else {
            last_->next = L;
            L->prev = last_;
            L->next = nullptr;
            last_ = L;
        }
        ++size_;
    }

    /* Removes the first element in the list,
     * the removed element is destroyed */
    void pop_front() {
    	if (size_ == 0) {

        }
    	if (size_ == 1) {
            delete first_;
            first_ = nullptr;
            last_ = nullptr;
            size_--;
        } else {
            first_ = first_->next;
            delete first_->prev;
            first_->prev = nullptr;
            size_--;
        }
    }

    /* Removes the last element of the list,
     * the removed element is destroyed */
    void pop_back() {
        if (size_ == 0) {

        }
        if (size_ == 1) {
            delete last_;
            first_ = nullptr;
            last_ = nullptr;
            size_--;
        } else {
            last_ = last_->prev;
            delete last_->next;
            last_->next = nullptr;
            size_--;
        }
    }

    T& front() {
    	return first_->value;
    }

    T& back() {
    	return last_->value;
    }

    /* returns "true" if the container is empty, "false" otherwise */
    bool empty() const {
        return size_ == 0;
    }

    /* returns the number of elements in the container */
    std::size_t size() {
        return size_;
  }

  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

template <typename T>
    bool operator==(List<T> const& xs , List<T> const& ys){
      return xs.node == ys.node;
    }

/* ... */
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif // # define BUW_LIST_HPP