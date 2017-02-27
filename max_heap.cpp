/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly deletes
		// and maintains the heap-order property
		// required for a max-heap
		
		// returning something so it compiles:
        
        // top item should be biggest
        text_item returnVal = data[0];
        
        // move last item to top
        data[0] = data[numItems-1];
        numItems--; //one less item now
        
        // reorder to preserve rep invariant
        swap_down(0);
        
		return returnVal;
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
		
	// Fix this so it correctly swaps
    int s = i;
    int left = i*2+1;
    int right = left+1;
    
    // if left node still exists and left is greater than current
    // save index
    if((left < numItems) && (data[left].freq > data[s].freq)){
        s = left;
    }
    
    // if right node still exists and right is greater than current
    // save index
    if((right < numItems) && (data[right].freq > data[s].freq)){
        s = right;
    }
    
    // if there is something to swap, swap
    if( s!=i){
        text_item temp = data[i];
        data[i] = data[s];
        data[s] = temp;
        
        // continue swapping
        swap_down(s);
    }
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly inserts
		// and maintains the heap-order property
		// required for a max-heap
        
        // add the item
		data[numItems++] = item;
        
        // reorder to preserve rep invariant
        swap_up(numItems-1);
	}
}

void max_heap::swap_up(int i) {
	// ADD CODE HERE
		
	// Fix this so it correctly swaps
    
    if(i==0){
        return;
    }
    
    int parent = (i-1)/2;
    
    // if current is greater than parent, need to swap
    if(data[i].freq > data[parent].freq){
        text_item temp = data[i];
        data[i] = data[parent];
        data[parent] = temp;
        
        // continue swapping if needed
        swap_up(parent);
    }
}
