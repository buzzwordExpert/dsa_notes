#include <bits/stdc++.h>

using namespace std;


void explainPair(){
	pair<int, int> p = {1, 3};

	cout << p.first << " " << p.second;

	pair<int, pair<int, int>> k = {1, {3, 4}};

	cout << p.first << " " << p.second.second << " " p.second.first;

	pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1}};

	cout << arr[1].second;
}

void explainVector() {
	vector<int> v;

	v.push_back(1);
	v.emplace_black(2); // faster than push_back
	
	vector<pair<int, int>> vec;

	vec.push_back({1,2});
	vec.emplace_back(1,2);

	vector<int> v1(5, 100); // array of size 5 with each entry containing 100
	
	vector<int> v2(5); // array of size 5 with each entry containing garbage value
	
	vector<int> v3(5,20);
	vector<int> v4(v3); // copy of v3


	vector<int>::iterator it = v.begin();

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *(it) << endl;
	}

	for (auto it = v.begin(); it != v.end(); it++){
		cout << *(it) << endl;
	}
	
	for (auto it : v) {
		cout << it << endl;
	}

	// erase
	// {10, 20, 12, 23, 35}
	v.erase(v.begin() + 2, v.begin() + 4); // {10, 20, 35} [start, end)
	
	// insert function
	
	vector<int>v(2, 100); // {100, 100}
	v.insert(v.begin(), 300); // {300, 100, 100}
	v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}
	
	vector<int> copy(2, 50); // {50. 50}
	v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}
	
	// {10, 20}
	cout << v.size(); // 2
	
	// {10, 20}
	v.pop_back(); // {10}
	
	// v1 -> {10, 20}
	// v2 -> {30, 40}
	v1.swap(v2); // v1 -> {30, 40}, v2 -> {10, 20}
	
	v.clear(); //erases the entire vector
	

	cout << v.empty(); // gives boolean value
}

void explainList() {

	list<int> ls;
	ls.push_back(2); // {2}
	ls.emplace_back(4); // {2, 4}
	
	ls.push_front(5); // {5, 2, 4}
	// cheaper than insert of vector in context of time complexity
	// lists work on doubly linked list and vectors work on single linked list
	ls.emplace_front(6); // {6, 5, 2, 4}
	
	// begin, end, clear, insert, size, swap same as vector

}

void explainDeque(){
	deque<int> dq;
	dq.push_back(1); // {1}
	dq.emplace_back(2); // {1, 2}
	dq.push_front(4); // {4, 1, 2}
	dq.emplace_front(3); // {3, 4, 1, 2}
	
	dq.pop_back(); // {3, 4, 1}
	dq.pop_front(); // {4, 1}
	
	dq.back();
	dq.front();
	
	// begin, end, clear, insert, size, swap same as vector
}

void explainStack(){
	
	// LILO principle -- last in last out
	stack<int> st;
	st.push(1);
	st.push(2); // {2, 1}
	st.emplace(5); // {5, 2, 1}
	
	cout << st.top(); // prints 5 "can not access the stack with index (invalid operation)"
	
	st.pop(); // {2, 1}
	
	cout << st.size(); // 2
	
	cout << st.empty(); // boolean value
	
	stack<int> st1, st2;
	st1.swap(st2);

}

void explainQueue(){
	
	// FIFO principle - first in first out
	queue<int> q;
	q.push(1);
	q.push(2);
	q.emplace(4);
	
	q.back() += 5; // adds 5 to the last element
	
	cout << q.back();
	cout << q.front();
	// can access by index aswell
	
	q.pop();

	// size, swap, empty same as stack
}

void explainPQ() {
	priority_queue<int>pq;
	// a tree in maintained in this
	pq.push(5); // {5}
	pq.push(2); // {5, 2}
	pq.emplace(10); // {10, 5, 2}

	cout << pq.top(); // prints 10
	
	pq.pop(); // {5, 2}
	
	// size, swap, empty function same as others
	
	// Minimum heap
	priority_queue<int, vector<int>, greater<int>> pq_1;
	pq_1.push(5); // {5}
	pq_1.push(2); // {2, 5}
	pq_1.emplace(10); // {2, 5, 10}
	
	cout << pq.top(); // prints 2

}


void explainSet() {
	
	// sorted and unique
	set<int>st;
	st.insert(1);
	st.emplace(2); // {1, 2}
	st.insert(2); // {1, 2}
	st.insert(4); // {1, 2, 4}
	st.insert(3); // {1, 2, 3, 4}
	
	// begin(), end(), size(), empty(), swap() are same as those above
	
	// {1,2,3,4,5}
	auto it = st.find(3); // gives an iterator pointing to 3
	auto it = st.find(6); // return st.end()
	
	st.erase(5); // erases 5. takes logarithmic time

	int cnt = st.count(1); // return 1 or 0, as set only takes unique values
	
	auto it = st.find(3);
	st.erase(it); // this approach takes constant time
	
	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1,it2); // after erase -- {1,4,5} [first,last)
	
	// lower_bound() and upper_bound() function works in the same way
	
	auto it = st.lower_bound(2);
	auto it = st.upper_bound(3);


}


void explainMultiSet() {

	// same as set except no uniqueness
	
	multiset<int> ms;
	ms.insert(1); // {1}
	ms.insert(1); // {1, 1}
	ms.insert(1); // {1, 1, 1}
	

	ms.erase(1); // all 1's erased
	
	int cnt = ms.count(1); 
	
	ms.erase(ms.find(1)); // only one 1 is erased
	
	ms.erase(ms.find(1), ms.find(1)+2); // erases two 1's
	
	//rest all functions are same

}

void explainUSet() {
	unordered_set<int> st;
	// lower_bound and upper_bound function
	// does not work, rest all functions are same
	// as above, it does not store in order
	// constant time complexity in most cases, linear complexity in worst case
}

void explainMap() {
	// equivalent to dictionaries in python
	// you will have a key value pair <key, value> which can take any data type
	// keys are unique and automatically sorted in ascending order

	map<int, int> mpp;
	map<pair<int,int>,int> mpp_2;

	mpp[1] = 2;
	mpp.emplace({3, 1});
	mpp.insert({2,4});

	mpp_2[{2, 3}] = 10;

	for(auto it : mpp) {
		cout << it.first << " " << it.second << endl; // [{1:2},{2:4},{3:1}] -> key value of 1 and 2 will be printed
	}

	cout << mpp[1]; // prints 2 (key value of 1)
	cout << mpp[5]; // does not exist that's why null or 0
	
	auto it = mpp.find(3); // gives the iterator to the key value pair of {3,1}
	cout << *(it).second; // prints the key value
	
	auto it = mpp.find(5); // points to mpp.end()
	
	auto it = mpp.lower_bound(2);
	auto it = mpp.upper_bound(3);
	
	// erase, swap, size, empty, are same as above
	
	// works in logn time
}

void explainMultiMap(){
	// everything same as map, but can store duplicate keys aswell
	// only mpp[key] cannot be used here

}

void explainUnorderedMap(){
	// same as set and unordered_set difference
	// most cases O(1) and worst case O(n)
}

bool comp(pair<int, int> p1, pair<int, int> p2){
	if(p1.second < p2.second) return true;
	if(p1.second > p2.second) return false;
	// only case left is when both the second element in same
	if (p1.first > p2.second) return true;
	return false;

void explainExtra() {
	
	sort(a, a + n); // will sort all the elements in range [a, a+n)
	sort(v.begin(),v.end()); // for vector
	
	sort(a+2, a+4); // will sort 2nd and 3rd position element
	
	sort(a, a+n, greater<int>); // for descending order
	
	pair<int, int> a[] = {1,2}, {2,1}, {4,1}};

	// sort it according to second element
	// if second element is same, then sort
	// it according to first element but in descending
	
	// implementing the comment with comparator logic 
	sort(a, a+n, comp);

	// {4, 1}, {2, 1}, {1, 2}
	
	int num = 7;
	int cnt = __builtin_popcount(); // counts the number of set bits in binary
	
	long long num = 167586578495;
	int cnt = __builtin_popcountll();

	string s = "123";

	// to find all the permutations of the string ( string has to be sorted beforehand )
	do {
		cout << s << endl;
	} while(next_permutation(s.begin(), s.end());
	
	int maxim_num = *max_element(a,a+n); // max_element() give the adress as the output, used * to get the element
	int minim_num = *min_element(a,a+n); // same as max_element()
	

}

int main(){
	

	return 0;
}
