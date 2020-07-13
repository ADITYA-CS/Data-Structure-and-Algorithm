<h1 align="center"> SORTING </h1>

## Table of contents
- Testing
  - [Input Format](#input-format)
  - [Output Format](#output-format)
  - [Test case](#test-case)
- Algorithm
  - [Heap sort](../Sorting/heap_sort.cpp)
  - [Merge sort](../Sorting/merge-sort.cpp)
  - [Quick sort](../Sorting/quick-sort.cpp)
- Problems
  - [Inversion - count](../Sorting/inversion-count.cpp)

### Input Format
- First line contain n which is number of numbers in the input list
- then, contains n number

### Output Format
- First line contain n which is number of numbers in the input list
- then, contains n number in sorted order

### Test case
- `testcase` folder contains `checker.cpp`, `generator.cpp` and test cases.
- `checker.cpp` checks whether given list of integers are in non-increasing order or not.
 - input format is same as [Output Format](#output-format) discussed above;
 - when everything is ok, it will not output anything, otherwise generates `cassert error`
- `generator.cpp` generates random list of integers.
 - takes 3 integers parameter.
    ```txt
      ./a.out n min max
      n = number of integer numbers to generate
      min and max specify the lower and upper bound of value of integer value
      use streaming to store input a file.
    ```
    `Example`
    ```bash
    ./a.out 100 1 99999 > testX.txt
    ```
  - Output format is same as [Input Format](#input-format) discussed above.
