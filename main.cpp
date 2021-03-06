#include <iostream>
#include <time.h>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"
#include <string>

using namespace std;

//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand((unsigned int) seed);
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 90 + 5;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;		
	}
	
	//--- Specific insert functionality that should be tested:
	std::cout << "*** TESTING INSERT WITHOUT SWAPUPS ***" << std::endl;
	// insert without any swap_ups needed
		// <INSERT TEST(S) HERE>
    for (int i = 0 ; i < 5; i++) {
        random_num = 5-i; // will always be smaller than previous nodes
        string text = word;
        text += std::to_string(i+1);
        std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
        hp.insert(text_item{text, random_num});
        temp = hp.top();
        std::cout << "Top of heap is: " << temp << std::endl;
    }
		
    std::cout << "*** TESTING INSERT WITH MULTIPLE SWAPUPS ***" << std::endl;
	// insert with a swap_up / multiple swap_ups
		// <INSERT TEST(S) HERE>
    for (int i = 0 ; i < 5; i++) {
        random_num = (i+1)*100; // will always be larger than previous nodes
        string text = word;
        text += std::to_string(i+1);
        std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
        hp.insert(text_item{text, random_num});
        temp = hp.top();
        std::cout << "Top of heap is: " << temp << std::endl;
    }
}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
	
	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	while (hp.size() > 1) { // will do both left and right childs at some point
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		temp = hp.top();
		std::cout << "Top of heap is now: " << temp << std::endl;	
	}
    
    //--- Specific insert functionality that should be tested:
    
    // remove_max works when swap_down with left child
    // <INSERT TEST(S) HERE> // completed above in the while loop
    std::cout << "*** TESTING DELETEMAX WHEN SWAP DOWN LEFT ***" << std::endl;
    
    string text = "word1";
    int num1 = 10;
    std::cout << "adding " << text << ",  with number " << num1 << " to heap" << std::endl;
    hp.insert(text_item{text, num1});
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    
    
    string text2 = "left1";
    int num2 = 6;
    std::cout << "adding " << text2 << ",  with number " << num2 << " to heap" << std::endl;
    hp.insert(text_item{text, num2});
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    
    string text3 = "right1";
    int num3 = 3;
    std::cout << "adding " << text3 << ",  with number " << num3 << " to heap" << std::endl;
    hp.insert(text_item{text, num3});
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    
    string text4 = "min1";
    int num4 = 5;
    std::cout << "adding " << text3 << ",  with number " << num4 << " to heap" << std::endl;
    hp.insert(text_item{text, num4});
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    
    temp = hp.delete_max();
    std::cout << "Item returned from heap delete: "<< temp << std::endl;
    temp = hp.top();
    std::cout << "Top of heap is now: " << temp << std::endl;
    
    // remove_max workd when swap_down with right child
     std::cout << "*** TESTING DELETEMAX WHEN SWAP DOWN RIGHT ***" << std::endl;
    // <INSERT TEST(S) HERE> // completed above in the while loop
    string text5 = "min2";
    int num5 = 2;
    std::cout << "adding " << text5 << ",  with number " << num5 << " to heap" << std::endl;
    hp.insert(text_item{text, num5});
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    
    temp = hp.delete_max();
    std::cout << "Item returned from heap delete: "<< temp << std::endl;
    temp = hp.top();
    std::cout << "Top of heap is now: " << temp << std::endl;
    
    // remove_max on an empty heap (should throw exception similar to top())
    // <INSERT TEST(S) HERE>
    std::cout << "*** TESTING DELETEMAX BY DELETING ALL VALUES BUT 1***" << std::endl;
    while (hp.size() > 1) { // will do both left and right childs at some point
        temp = hp.delete_max();
        std::cout << "Item returned from heap delete: "<< temp << std::endl;
        temp = hp.top();
        std::cout << "Top of heap is now: " << temp << std::endl;
    }
    
    std::cout << "*** TESTING DELETEMAX ON HEAP OF SIZE 1***" << std::endl;
    temp = hp.delete_max();
    std::cout << "Item returned from heap delete: "<< temp << std::endl;
    try{
        temp = hp.top();
        std::cout << "ERROR: Top of heap is now: " << temp << std::endl;
    }catch(std::logic_error){
        std::cout << "Heap is now empty" << std::endl;
    }
    
    std::cout << "*** TESTING DELETEMAX ON EMPTY HEAP***" << std::endl;
    try{
        temp = hp.delete_max();
        std::cout << "ERROR: Item returned from heap delete: "<< temp << std::endl;
    }catch(std::logic_error){
        std::cout << "Exception thrown, heap is empty" << std::endl;
    }
}

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
    // for testing purposes
	//std::cout << "Current tree under testing: " << endl;
	//tree.display();
	//std::cout << endl;

	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
	//--- Specific word_frequency functionality that should be tested:
	long int seed = long(time(0));    // seed for random number generator
	srand((unsigned int)seed);

	// can search through both left and right subtrees if not found at current node
	if (tree.size() > 1) {
		string to_find = tree.get_root()->data.word;
		int num_times = tree.word_frequency(to_find);
		std::cout << "Test to find the root node frequency." << endl;
		std::cout << "Found: " << to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	if (tree.size() > 1) {
		string_bst::node_t * currNode = tree.get_root();
		while (currNode->left) {
			currNode = currNode->left;
		}
		string to_find = currNode->data.word;
		int num_times = tree.word_frequency(to_find);
		std::cout << "Test to find the frequency of the leftmost node in the tree." << endl;
		std::cout << "Found: " << to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	if (tree.size() > 1) {
		string_bst::node_t * currNode = tree.get_root();
		while (currNode->right) {
			currNode = currNode->right;
		}
		string to_find = currNode->data.word;
		int num_times = tree.word_frequency(to_find);
		std::cout << "Test to find the frequency of the rightmost node in the tree." << endl;
		std::cout << "Found: " << to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	if (tree.size() > 1) {
		string_bst::node_t * currNode = tree.get_root();
		while (currNode->right && currNode->left) {
			if (rand() % 2 == 1) {
				currNode = currNode->right;
			}
			else {
				currNode = currNode->left;
			}
		}
		while (currNode->right) {
			currNode = currNode->right;
		}
		while (currNode->left) {
			currNode = currNode->left;
		}
		string to_find = currNode->data.word;
		int num_times = tree.word_frequency(to_find);
		std::cout << "Test to find the frequency of the a random leaf node in the tree." << endl;
		std::cout << "Found: " << to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	// returns 0 if word is not found
		// <INSERT TEST(S) HERE>
	if (tree.size() > 1) {
		string to_find = "notAWord";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Test for nonexistent word, should return 0." << endl;
		std::cout << "Found: " << to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}
}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	
	//--- Add your code to print out the 5 most frequent words below:
	if (hp.size() > 1) {
        
        text_item::text_item * tempStore = new text_item::text_item[5];
        int i;
        for(i=0; i<5; i++){
            if(hp.empty()){
                break;
            }
            
            std::cout << hp.top() << std::endl;
            tempStore[i] = hp.delete_max();
        }
        
        for(int k=0; k<i; k++){
            hp.insert(tempStore[k]);
        }
        
        delete [] tempStore;
    }
}

void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
		
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>
    
    if (hp.size() > 1) {
        
        text_item::text_item * tempStore = new text_item::text_item[hp.size()];
        int i;
        int numFound = 0;
        for(i=0; i<hp.size(); i++){
            if(hp.empty() || numFound == 5){
                break;
            }
            
            text_item::text_item curr = hp.top();
            if(curr.word.length()>=num_letters){
                std::cout << curr << std::endl;
                numFound++;
            }
            
            tempStore[i] = hp.delete_max();
        }
        
        for(int k=0; k<i; k++){
            hp.insert(tempStore[k]);
        }
        
        delete [] tempStore;
    }
}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;
		
	//--- Add code to print out the 5 most common words
	//--- that start with the letter <starts_with_letter>

    if (hp.size() > 1) {
        
        text_item::text_item * tempStore = new text_item::text_item[hp.size()];
        int i;
        int numFound = 0;
        for(i=0; i<hp.size(); i++){
            if(hp.empty() || numFound == 5){
                break;
            }
            
            text_item::text_item curr = hp.top();
            if(curr.word.front() == starts_with_letter){
                std::cout << curr << std::endl;
                numFound++;
            }
            
            tempStore[i] = hp.delete_max();
        }
        
        for(int k=0; k<i; k++){
            hp.insert(tempStore[k]);
        }
        
        delete [] tempStore;
    }
}

void heap_tester() {	
	text_item temp;
	int heap_size = 20; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;
		
	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;	
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 6); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'c'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {
	
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
    
    // create a bst from an input file.
    load_bst(argv[1], tree);
    //load_bst("/Users/Cynnifer/Documents/UBC/Year 3/2017 Winter/CPSC 221/cs221/proj2/proj2/sample1.txt", tree);
    //load_bst("C:/Users/Yuqing/Documents/CS221/cs221_proj2/sample1.txt", tree);
	
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);
}
