# C++ notes from basics to advance

## Basic topics

### [Call by - value, address, reference](call-by-value-address-reference)


## Cheatsheet

### Data Structure and Algorithms

#### Vector

  - Initialize vector with size.
    ```
    vector<int> grades(3);
    ```
  - Initialize vector with size and default value.
    ```
    vector<int> product(nums_size, 1);
    ```
  - Initialize vector of vector
    ```
    vector<vector<int>> memoization(rows, vector<int> (cols, 0));
    ```
  - Add to tail O(1)
    ```
    result.push_back({nums[l], nums[m], nums[r]});
    ```
  - Add to head O(N)
    ```
    v.insert(v.begin(), value);
    ```
  - Add to index O(N)
    ```
    v.insert(v.begin() + index, value);
    ```
  - Remove Tail O(1), NOTE: Does not return the last element.
    ```
    wishlist.pop_back();
    ```
  - Remove Head O(N)
    ```
    v.erase(v.begin());
    ```
  - Remove at index O(N)
    ```
    v.erase(v.begin()+index);
    ```
  - Clear
    ```
    v.clear();
    ```
  - Get head O(1)
    ```
    v.front();
    ```
  - Get back O(1)
    ```
    v.back();
    ```
  - Loop
    ```
    // Loop using index
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << endl;
    }
    
    // Loop using auto
    for(auto it = v.begin(); it!=v.end(); i++){
      cout << *it << endl; // dereference

    for(auto &elem: v) {
      elem *= 2; // modifies actual element
      cout << elem << endl; // without dereference
    }
    ```
  - Find an element
      ```
      std::vector<int> v(10, 1);
      v[2] = 13;
      if (std::find(v.begin(), v.end(), 13) != v.end()) {
        std::cout << "Found 13" << std::endl;
      } else {
        std::cout << "Not found 13" << std::endl;
      }
      ```
  - Sort
    ```
    sort(nums.begin(), nums.end());
    ```
  - Get max element
    ```
    *max_element(nums.begin(), nums.end());
    ```
  - Get min element
    ```
    *min_element(nums.begin(), nums.end());
    ```




#### Map
  -  Find
      ```
      if (difference.find(num) != difference.end()) {
        cout << "found" << endl;
      } else {
        cout << "Doesn't exist" << endl;
      }
      ```



#### Set
- Convert vector to a set
  ```
  set<string> word_set(wordDict.begin(), wordDict.end());
  ```
- Insert an element to set
  ```
  visited.insert(crs);
  ```
- Remove an element from set
  ```
  visited.erase(crs);
  ```
- Create a set from a vector
  ```
  set<int> numsSet(nums.begin(), nums.end());
  ```

#### Pair
- Create pair with make pair
  ```
  foo = std::make_pair (10,20);
  ```
- Create pair
  ```
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor
  ```

#### String
- Create string
  ```
  string result(ret.begin(), ret.end());
  ```
