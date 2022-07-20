#include "Sorted_list.h"

// Name: Manik Debnath
// Student ID.: 2021124913

Node::Node( int e, Node*n ):

element( e ),
next_node( n ) {
	
// empty constructor
}


int Node::retrieve() const {
	
	return element;
}


Node*Node::next() const {

	return next_node;
}

// Sorted_single_list Class Member functions


Sorted_single_list::Sorted_single_list():
list_head( nullptr ),
list_tail(nullptr),

list_size(0){
	
// empty constructor
}

Sorted_single_list::~Sorted_single_list() {
    while ( !empty() ) {
		    pop_front();
		}
}

bool Sorted_single_list::empty() const {
	return ( list_head == nullptr );
}

Node*Sorted_single_list::head() const {
	return list_head;
}

Node*Sorted_single_list::tail() const {
	return list_head;
}


int Sorted_single_list::front() const {
	
	return head()->retrieve();
}

 
bool Sorted_single_list::display() const {
	if ( empty() ) {
          cout<<"This list is empty"<<endl;
          return false;
    }
	Node*ptr=head();
	while(ptr!=nullptr) {
		cout<<ptr->retrieve()<<" -> ";
		ptr = ptr->next();
	}
	cout<<"end"<<endl;
	return true;
}

int Sorted_single_list::size() const {
	int node_count = 0;
    for ( Node *ptr = list_head; ptr != nullptr; ptr = ptr->next() ) 
            ++node_count;
	return node_count;
}

void Sorted_single_list::swap( Sorted_single_list&list ) {
	std::swap( list_head, list.list_head );
	std::swap( list_tail, list.list_tail );
	std::swap( list_size, list.list_size );
}

void Sorted_single_list::push_front( int n ) {
    list_head = new Node( n, list_head );
}

int Sorted_single_list::pop_front() {
    if ( empty() ) {
          cout<<"This list is empty"<<endl;
          return 0;
    }

    int e = front();
    Node*ptr = list_head;
    list_head = list_head->next();
    delete ptr;
    return e;
}

int Sorted_single_list::count( int n ) const {
    int node_count = 0;

    for ( Node *ptr = list_head; ptr != nullptr; ptr = ptr->next() ) {
        if ( ptr->retrieve() == n ) {
            ++node_count;
        }
    }

    return node_count;
}

int Sorted_single_list::destroy() {
	while ( !empty() ) {
		    pop_front();
		}
}

int Sorted_single_list::olderase( int n ) {
	if ( empty() ) {
          cout<<"This list is empty"<<endl;
          return 0;
    }
    int node_count = 0;
    Node *tempptr, *ptr, *pre;
    for(ptr = head(), pre=nullptr;ptr != nullptr;){
    	if(ptr->retrieve()==n){
    		tempptr=ptr;
    		list_head=ptr=ptr->next();
    		delete tempptr;
    		++node_count;
		}
		else {
			pre=ptr;
			ptr=ptr->next();
			break;
		}
	}		
    while ( ptr != nullptr ) {
        
        if ( ptr->retrieve()==n) {
        	tempptr=ptr;
        	pre->next_node=ptr->next();
            ptr = ptr->next();
            delete tempptr;
            ++node_count;
        }
        else {
        	pre=ptr;
            ptr = ptr->next();
		}
    }
	cout<<"Delete "<<node_count<<" numbers."<<endl;
    return node_count;
}

int Sorted_single_list::erase( int n ){
	if ( empty() ) {
          cout<<"This list is empty"<<endl;
          return 0;
    }
    int node_count = 0;
    Node*tempptr, *ptr, *pre;
    for(ptr = head(), pre=nullptr;ptr != nullptr;){
    	if(ptr->retrieve()==n){
    		tempptr=ptr;
    		if(pre==nullptr)
    			list_head=ptr=ptr->next();
    		else 
    			pre->next_node=ptr = ptr->next();
    		delete tempptr;
    		++node_count;
		}
		else {
        	pre=ptr;
            ptr = ptr->next();
		}
	}
	cout<<"Delete "<<node_count<<" numbers."<<endl;
    return node_count;
}

Sorted_single_list::Sorted_single_list
( Sorted_single_list const & sorted_single_list ):list_head( nullptr ) {
	if(sorted_single_list.empty()) return;
	push_front(sorted_single_list.front());
	
	for(Node *original = sorted_single_list.head()->next(), *copy = head();
		original!=nullptr;
		original = original->next(), copy = copy->next()){
			copy->next_node = new Node( original->retrieve(), nullptr );
	}
}

Sorted_single_list &Sorted_single_list::operator = ( Sorted_single_list const &rhs ){
	if ( this == &rhs ) {
        return *this;
    }
	if(rhs.empty()) {
		destroy();
		return *this;
	}
	if ( empty() ) {
        list_head = new Node( rhs.front() );
    } else {
        head()->element = rhs.front();
    }

    Node *this_node = list_head,
         *rhs_node  = rhs.head()->next();

    while ( rhs_node != 0 ) {
        if ( this_node->next() == 0 ) {
            this_node->next_node = new Node( rhs_node->retrieve() );
            this_node = this_node->next();
        } else {
            this_node->next();
            this_node->element = rhs_node->retrieve();
        }

        rhs_node = rhs_node->next();
    }
}

bool Sorted_single_list::insert(int n, int l){
	if(l > size() || l <0)
		return false;
	Node *w = head();
	while(l){
		w = w->next(); 
		--l;
	}
	Node *temp = new Node();
	temp->element = n;
	temp->next_node = w->next();
	w->next_node = temp;
	return true;
}  


int Sorted_single_list::remove( int n ){
	if ( empty() ) {
          cout<<"This list is empty"<<endl;
          return 0;
    }
    int node_count = 0;
    Node *tempptr, *ptr, *pre;
    for(ptr = head(), pre=nullptr;ptr != nullptr;){
    	if(ptr->retrieve()==n){
    		tempptr=ptr;
    		if(pre==nullptr)
    			list_head=ptr=ptr->next();
    		else 
    			pre->next_node=ptr = ptr->next();
    		delete tempptr;
    		++node_count;
		}
		else {
        	pre=ptr;
            ptr = ptr->next();
		}
	}
	cout<<"Delete "<<node_count<<" numbers."<<endl;
    return node_count;
}
