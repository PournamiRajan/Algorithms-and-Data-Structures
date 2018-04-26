/*
 * WordMap.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: pournami
 */
#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
/**
 * Default constructor.
 */
WordMap::WordMap() {
	TimedContainer();
}
/**
 * Destructor.
 */
WordMap::~WordMap() {}

/**
 * Getter.
 * @return the frequency count.
 */
int WordMap::get_count(const string text) const
{
	map<string, Word>::const_iterator iter = map<string, Word>::find(text);
	if(iter != end()) return iter->second.get_count();
	else return 0;

}
/**
 * Insert a new word into the map,
 * or increment the count of an existing word.
 * Time this operation.
 * @param text the text of the word to insert or increment.
 */
void WordMap::insert(const string text)
{
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); // start insert time

	map<string,Word>::iterator iter = WordMap::search(text);
	Word new_obj(text);
	if(iter != end())
	{
		iter->second.increment_count();
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // end insert time if item present
		TimedContainer::increment_elapsed_time(start, end); // total insert time if item present
		return;
	}
	map<string, Word>::insert( std::pair<const string, Word>(text,new_obj));

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // end insert time
	TimedContainer::increment_elapsed_time(start, end); // total insert time
}
/**
 * Search the map for a word entry with the given text.
 * Time this operation.
 * @param text the text of the word to find.
 * @return an iterator pointing to the word entry if found,
 *         or end() if not.
 */
map<string, Word>::iterator WordMap::search(const string text)
{
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); // start search time

	map<string, Word>::iterator iter = map<string, Word>::find(text);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // end search time
	TimedContainer::increment_elapsed_time(start, end);
	return iter;
}
