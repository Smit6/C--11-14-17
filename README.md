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


#### Move Semantics
- Save time by moving instead of copying
  ```
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = move(v1);
  ```
- Save time by moving data in and out of functions
  ```
  void foo(vector<int> v) {
    // do something with v
  }

  int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    foo(move(v));
  }
  ```
- If the source object is an 'rvalue', its data can be moved into the target instead of being copied. It is similar to moving files between folders instead of copying them.
- lvalue vs. rvalue
  - Simple world
    - lvalue: Originally, a lvalue can appear on the left of an assignment.
    - rvalue: Any object that is not an lvalue.
  - C++ world
      ```
      x = 2; // x is an lvalue; 2 is an rvalue
      x = func(); // func() is an rvalue
      ```
    - lvalue
      - A lvalue represents a named memory location
      - It has a name and it is addressable in memory
      - We can take its address via the & operator
      - x is an lvalue
      - x and &x is legal
    - rvalue
      - Anything else is an rvalue
      - 2 is an rvalue      // 2 has no name and it is not addressable
      - func() is an rvalue // return value from function call has no name
                            // &func() is illegal
    - lvalue and rvalues can behave differently when passed as function arguments
    - lvalue passed by value
      ```
      void func(int);

      int x = 2;  // x is lvalue
      func(x);    // The value of x is copied into the function argument
      ```
    - rvalues can also be passed by value
      ```
      void func(int);

      func(2);    // 2 is rvalue
                  // 2 is copied into the function argument
      ```
    - lvalue passed by address
      ```
      void func(int*);

      int x = 2;  // x is lvalue
      func(&x);   // x is passed by address
      ```
    - rvalue cannot be passed by address
    - lvalues can be passed by reference
      ```
      void func(int&);

      int x = 2;  // x is lvalue
      func(x);    // x is passed by reference
      ```
    - rvalues cannot be passed by reference
    - Passing rvalue by const reference is allowed
      ```
      void func(const int&);

      func(2);    // 2 is rvalue
                  // 2 is passed by const reference
      ```
    - Pass by move - In C++11, the argument can be moved if
      - obj is an rvalue
      - type is movable
      - True for all c++ library types
      - objects will be copied if
        - obj is an lvalue
        - type is not movable
    - Rvalue reference
      - C++11 has the concept of rvalue reference
      - Syntactic device which indicates that a function argument must be movable
      - An rvalue reference has '&&' after the type
        ```
        void func(int&&);
        
        func(2);    // 2 is rvalue
        
        int y{2};

        func(y);    // y is lvalue
                    // Error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
        ```
    - Moving a function call argument
      - The passed object will be moved into the argument if
        - The object is an rvalue
        - and its type is movable
      - Otherwise, the call does not compile
      - This allows us to overload functions to behave differently depending on whether the passed object is an lvalue or an rvalue
- std::move
  - If we want to pass an lvalue to a function which takes an rvalue reference, we have to cast it to rvalue
  - std::move is a function which casts its argument to rvalue
    ```
    int y{2};
    func(std::move(y)); // y is cast to rvalue
    ```
- This moves y's data into the function argument x
- This should only be done if y's data is expendable
  - After calling func(), y's data may empty or unusable
  - If we want to use y again, we must re-assign its data
- Argument type Summary
  - lvalue
    - pass an lvalue
    - function has a copy of the passed object's data
    - or we can pass a moveable rvalue
    - the function now owns the passed object's data
  - lvalue reference
    - we can pass an lvalue, but not rvalue
    - the function can modify the passed object's data through the reference
  - const lvalue reference
    - we can pass an lvalue or rvalue
    - the function cannot modify the passed object's data through the reference
  - rvalue reference
    - We can pass a removable rvalue, but not an lvalue
    - The function now owns the passed object's data


    
