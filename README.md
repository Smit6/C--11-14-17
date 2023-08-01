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


