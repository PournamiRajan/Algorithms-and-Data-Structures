/*
 * WordVector.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: pournami
 */

#include <vector>
#include <string>
#include <cstring>
#include "WordVector.h"

using namespace std;
/**
 * Default constructor. Calling constructor of Timed container
 */
WordVector::WordVector()
{
	TimedContainer();
}
/**
* Destructor.
*/
WordVector::~WordVector() {}

/**
 * Getter.
 * @return the frequency count.
 */
int WordVector::get_count(const string text) const
{
	int pos = WordVector::find(text, 0, size()-1); // Calling find function of WordVector class (binary search)
	if(pos > -1) return (*(begin() +pos)).get_count(); // If present return count else return 0
	else return 0;
}

/**
 * Insert a new word into the sorted vector,
 * or increment the count of an existing word.
 * Time this operation.
 * @param text the text of the word to insert or increment.
 */
void WordVector::insert(const string text)
{
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); // start insert time

	vector<Word>::iterator iter = WordVector::search(text); // Calling Wordvector search

	if(iter != end())
	{
		(*iter).increment_count();
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // end insert time if item present
		TimedContainer::increment_elapsed_time(start, end); // total insert time if item present
		return;
	}

	vector<Word>::iterator iterator = begin();
	Word new_obj(text);

	while(iterator != end())
	{
		if(strcmp((*iterator).get_text().c_str(),text.c_str()) > 0) break;
		++iterator;
	}
	if (iterator != end()) vector<Word>::insert(iterator,new_obj);
	else push_back(new_obj);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // end insert time
	TimedContainer::increment_elapsed_time(start, end); // total insert time
}

/**
 * Search the vector for a word entry with the given text.
 * Time this operation.
 * @param text the text of the word to find.
 * @return an iterator pointing to the word entry if found,
 *         or data.end() if not.
 */
vector<Word>::iterator WordVector::search(const string text)
{
	std::chrono::steady_clock::time_point start_search = std::chrono::steady_clock::now(); // start search time

	int position = WordVector::find(text, 0, size()-1); // Calling Wordvector find
	vector<Word>::iterator pos = position > -1 ?  begin() + position : end();

	std::chrono::steady_clock::time_point end_search = std::chrono::steady_clock::now(); // end search time
	TimedContainer::increment_elapsed_time(start_search, end_search);
	return pos;
}

/**
 * Helper function that performs a binary search of the sorted vector.
 * @param text the text of the target word.
 * @param low the lower index of the subrange to search.
 * @param high the upper index of the subrange to search.
 */
int WordVector::find(const string text, int low, int high) const
{
    if(low > high) return -1;
	int mid = (low + high)/2;
    if (strcmp(at(mid).get_text().c_str(),text.c_str()) == 0) return mid;
    else if (strcmp(at(mid).get_text().c_str(),text.c_str()) > 0) return WordVector::find(text,low, mid -1);
    else return WordVector::find(text,mid + 1, high);
    return -1;
}
