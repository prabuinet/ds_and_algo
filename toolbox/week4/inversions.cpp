#include <iostream>
#include <vector>

using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

vector<int> Merge(const vector<int> &B, const vector<int> &C, long long &inv) {
    vector<int> R(0);

    int i = 0;
    int j = 0;

    /*
    for(int i = 0; i < B.size(); i++) {
	for(int j = 0; j < C.size(); j++) {
	    if(B[i] > C[j]) {
		inv++;
	    }
	}
    }*/
    
    while(true) {

	if(i == B.size() || j == C.size())
	    break;
	
	if(B[i] <= C[j]) {
	    R.push_back(B[i]);
	    i++;
	} else {
	    R.push_back(C[j]);
	    j++;
	    inv += (B.size() - i);
	}
    }

    while(j < C.size()) {
	R.push_back(C[j++]);
    }

    while(i < B.size()) {
	R.push_back(B[i++]);
    }

    return R;
}

vector<int> MergeSort(const vector<int> &A, long long &inv) {
    int size = A.size();
    if(A.size() == 1)
	return A;
    
    int mid = size / 2;

    vector<int>::const_iterator first = A.begin();
    vector<int>::const_iterator last = A.begin() + mid;
    vector<int> B(first, last);
    first = A.begin() + mid;
    last = A.end();
    vector<int> C(first, last);

    vector<int> BR = MergeSort(B, inv);
    vector<int> CR = MergeSort(C, inv);
    vector<int> R = Merge(BR, CR, inv);
    return R;
}


int main() {
  int n;
  
  std::cin >> n;

  vector<int> a(n);
  
  for (size_t i = 0; i < a.size(); i++) {
      std::cin >> a[i];
  }

  long long inv = 0;
  
  vector<int> R = MergeSort(a, inv);
  cout << inv << endl;
  
  //vector<int> b(a.size());
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
