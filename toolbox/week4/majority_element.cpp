#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here

  int mid = (right - left) / 2 + left;
  
  int maj_left = get_majority_element(a, left, mid);
  int maj_right = get_majority_element(a, mid, right);


  int lc = 0;
  int rc = 0;

  for(int i = left; i < right; i++) {
      if(a[i] == maj_left)
	  lc++;
      if(a[i] == maj_right)
	  rc++;
  }

  int n = right - left;
  
  if(lc > n / 2)
      return maj_left;

  if(rc > n / 2)
      return maj_right;
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
