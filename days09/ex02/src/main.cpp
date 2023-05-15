#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <iostream>
#include <list>

using namespace std;
using std::vector;
using std::cout; using std::endl;

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	//return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

void printList(std::list<int> myList, string str) {

	cout << str << " ";
	std::list<int>::iterator ref; 

	if (myList.size() < 100)
		ref = myList.end();
	else  {
		ref = myList.begin();
		std::advance(ref, 5);
	}

	for (std::list<int>::iterator it = myList.begin(); it != ref; ++it) {
		std::cout << *it << ' ';
	}
	std::cout << '\n';

}

template<typename T>
void printVector(const vector<T> &vec, std::string str) {
	std::vector<int>::const_iterator ref; 

	if (vec.size() < 100)
		ref = vec.end();
	else  {
		ref = vec.begin();
		std::advance(ref, 5);
	}
	std::cout << str << ": ";
	for (typename vector<T>::const_iterator it = vec.begin(); it != ref; ++it) {
		cout << *it << " ";
	}
	std::cout << " [....]" << std::endl;
}



void merge(list<int>& left, list<int>& right, list<int>& result) {
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.pop_front();
		} else {
			result.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty()) {
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty()) {
		result.push_back(right.front());
		right.pop_front();
	}
}

void merge_sort_list(list<int>& l) {
	if (l.size() <= 1) {
		return;
	}
	list<int> left, right, result;
	int middle = l.size() / 2;
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		if (distance(l.begin(), it) < middle) {
			left.push_back(*it);
		} else {
			right.push_back(*it);
		}
	}
	merge_sort_list(left);
	merge_sort_list(right);
	merge(left, right, l);
}

template<typename T>
void mergeSort(vector<T> &vec, int left, int right) {
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(vec, left, mid);
	mergeSort(vec, mid + 1, right);
	std::inplace_merge(vec.begin() + left, vec.begin() + mid + 1, vec.begin() + right + 1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		return 2;
	{
		vector<int> vec1;
		list<int>	list1;
		size_t size;	
		for(int i = 1; i < ac; ++i) {
			vec1.push_back(atoi(av[i]));
		}
		for (int i = 1; i < ac; i++) {
			list1.push_back(atoi(av[i]));
		}

		 // Start the timer



		printVector(vec1, "before");	
		size = vec1.size();
		clock_t startTime = clock();
		mergeSort(vec1, 0, vec1.size() - 1);	
		clock_t endTime = clock();
    	double elapsedSeconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    //	double elapsedMicroseconds = elapsedSeconds * 1000000;
		printVector(vec1, "after");
		std::cout << "Time to process a range of " << size << " elements with std::[..] : " << elapsedSeconds  << " us" << std::endl;	
	
		size = list1.size();
		startTime = clock();
		merge_sort_list(list1);
		endTime = clock();
		elapsedSeconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << size << " elements with std::[..] : " << elapsedSeconds << " us" << std::endl;

	}
	return EXIT_SUCCESS;
}