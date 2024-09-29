#include "Dictionary.h"
#include <algorithm>
#include <list>
#include <iostream>
#include <cctype>
using namespace std;

class DictionaryImpl
{
public:
	DictionaryImpl(int max);
	~DictionaryImpl();
	void insert(string word);
	void lookup(string letters, void callback(string)) const;
	std::string wordConvert(std::string s) const;

private:
	int maxBuckets;
	std::list<std::string>* hashtable;

	unsigned int hasher(std::string s) const;
	bool isAnagram(std::string s, std::string input) const;
};

//Constructors
Dictionary::Dictionary(int maxBuckets) {
	m_impl = new DictionaryImpl(maxBuckets);
}

DictionaryImpl::DictionaryImpl(int max) {
	maxBuckets = max;
	hashtable = new std::list<std::string>[maxBuckets];
}


//DictionaryImpl implementations
void DictionaryImpl::insert(string word) {
	word = wordConvert(word);

	std::list<std::string>* bucket = &hashtable[hasher(word)];
	bucket->push_back(word);
}

void DictionaryImpl::lookup(string letters, void callback(string)) const {
	letters = wordConvert(letters);
	std::list<std::string>* bucket = &hashtable[hasher(letters)];

	for (std::list<std::string>::iterator it = bucket->begin(); it != bucket->end(); it++) {
		if (isAnagram(*it,letters))
			callback(*it);
	}
}

DictionaryImpl::~DictionaryImpl() {
	delete[] hashtable;
}

//Dictionary Implementations
Dictionary::~Dictionary()
{
	delete m_impl;
}

void Dictionary::insert(string word)
{
	m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
	m_impl->lookup(letters, callback);
}

//Custom functions
bool DictionaryImpl::isAnagram(std::string listitem,std::string input) const{
	std::sort(listitem.begin(), listitem.end());
	std::sort(input.begin(), input.end());
	if (listitem == input)
		return true;
	else
		return false;
}

std::string DictionaryImpl::wordConvert(std::string s) const {
	for (int i = 0; i < s.size();i++) {
		if (!isalpha(s[i])) {
			s.erase(i,1);
			i--;
		}
		else if (isupper(s[i]))
			s[i]=tolower(s[i]);
	}
	return s;
}

unsigned int DictionaryImpl::hasher(std::string s) const {
	//In order to ensure anagrams are always in the same bucket
	sort(s.begin(), s.end());

	//Hash function from cs lecture
	unsigned int h = 2166136261U;
	for (char c : s) {
		h += c;
		h *= 16777619;
	}

	return h % maxBuckets;
}