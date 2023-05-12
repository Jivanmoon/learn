#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
 
using namespace std;
 
void vector_func(vector<int>& iv){
	auto iter = iv.begin();
	while (iter != iv.end()){
		if (*iter % 2){
			iter = iv.insert(iter, *iter);
			iter += 2;
		}
		else{
			iter = iv.erase(iter);
		}
	}
}
 
void list_func(list<int>& il){
	auto iter = il.begin();
	while (iter != il.end()){
		if (*iter % 2){
			iter = il.insert(iter, *iter);
			++iter;
			++iter;
		}
		else {
			iter = il.erase(iter);
		}
	}
}
 
void forward_list_func(forward_list<int>& ifl){
	auto prev = ifl.before_begin();
	auto curr = ifl.begin();
	while (curr != ifl.end()){
		if (*curr % 2){
			curr = ifl.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else{
			curr = ifl.erase_after(prev);
			prev = curr;
		}
	}
}
 
int main(){
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> ilist(vi.begin(), vi.end());
	forward_list<int> forward_ilist(vi.begin(), vi.end());
 
	vector_func(vi);
	for (auto i : vi){
		cout << i << " ";
	}
	cout << endl;
 
	list_func(ilist);
	for (auto i : ilist){
		cout << i << " ";
	}
	cout << endl;
 
	forward_list_func(forward_ilist);
	for (auto i : forward_ilist){
		cout << i << " ";
	}
	cout << endl;
}