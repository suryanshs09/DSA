# 0/1 knapsack problem performance analysis

## Recursive approach

| Testcase | Result | Time taken |
| --- | --- | --- |
| 1 | passed | 0 ms |
| 2 | passed | 0 ms |
| 3 | passed | 13985 ms |
| 4 | failed | |
| 5 | failed | |
| 6 | failed | |

### Time complexity:
O(2^n) here, n is the size of input array
### Space complexity:
O(n) for recursive call stack 
### Reason for failure:
The time complexity of recursive approach is O(2^n) and in Testcase 4, n=50. Knowing it took 13985 ms for n=20 in Testcase 3, we have:
- The approx time for computing Testcase 4 with n=50 is 15016279408640 ms i.e. 476.163096 years
- The approx time for computing Testcase 5 with n=80 is 16123607241926754959360 ms i.e. 527907157.33 years
- The approx time for computing Testcase 6 with n=100 is 16906827587310589008265871360 ms i.e. 539659361.47 years
#### Hence, it is not a good approach for even slightly large values of n.

## Memoized approach

| Testcase | Result | Time taken |
| --- | --- | --- |
| 1 | passed | 0 ms |
| 2 | passed | 0 ms |
| 3 | passed | 0 ms |
| 4 | passed | 997 ms |
| 5 | passed | 3025 ms |
| 6 | passed | 6979 ms |

### Time complexity: 
O(n\*w) here, n is size of input array and w is total capacity
### Space complexity: 
O(n\*w) + O(n) here, O(n\*w) for storing the dp table of n\*w size and O(n) for recursive call stack 

## Top-down/Tabular approach

| Testcase | Result | Time taken |
| --- | --- | --- |
| 1 | passed | 0 ms |
| 2 | passed | 0 ms |
| 3 | passed | 0 ms |
| 4 | passed | 997 ms |
| 5 | passed | 2000 ms |
| 6 | passed | 7973 ms |

### Time complexity:
O(n\*w) here, n is size of input array and w is total capacity
### Space complexity:
O(n\*w) here, O(n\*w) for storing the dp table of n\*w size
#### Hence, top-down dp is the best approach for solving 0/1 knapsack problem. 

