# LeetCode

## Tips

1. **DON'T** use global variable in LeetCode **!**

## Algorithms
| #    | Title                                               | Difficulty | Languge  | Runtime | Time Complexity | Tag                         |
| ---: | :-------------------------------------------------- | :--------- | :------- | ------: | :-------------- | :-------------------------: |
| 1    | [Two Sum][1]                                        | Easy       | [C][1C]  | 90.07%  |                 |                             |
| 2    | [Add Two Numbers][2]                                | Medium     | [C][2C]  | 100.00% |                 |                             |
| 3    | [Longest Substring Without Repeating Characters][3] | Medium     | [C][3C]  | 100.00% |                 |                             |
| 4    | [Median of Two Sorted Arrays][4]                    | Hard       | [C][4C1] | 100.00% | ![][Ominmn]     |                             |
|      |                                                     |            | [C][4C2] | 100.00% | ![][Ologmn]     |                             |
| 5    | [Longest Palindromic Substring][5]                  | Medium     | [C][5C1] | 79.49%  | ![][On2]        |                             |
|      |                                                     |            | [C][5C2] | 93.66%  | ![][On]         | [Manacher][Mnch]            |
| 6    | [ZigZag Conversion][6]                              | Medium     | [C][6C]  | 100.00% |                 |                             |
| 7    | [Reverse Integer][7]                                | Easy       | [C][7C]  | 98.34%  |                 |                             |
| 8    | [String to Integer (atoi)][8]                       | Medium     | [C][8C]  | 100.00% |                 |                             |
| 9    | [Palindrome Number][9]                              | Easy       | [C][9C]  | 88.57%  |                 |                             |
| 10   | [Regular Expression Matching][10]                   | Hard       | [C][10C] | 100.00% |                 | [Dynamic Programming][10dp] |
| 11   | [Container With Most Water][11]                     | Medium     | [C][11C] | 100.00% |                 |                             |
| 12   | [Integer to Roman][12]                              | Medium     | [C][12C] | 100.00% |                 |                             |


[1]:    ./doc/001.md
[1C]:   ./src/prob/001.c
[2]:    ./doc/002.md
[2C]:   ./src/prob/002.c
[3]:    ./doc/003.md
[3C]:   ./src/prob/003.c
[4]:    ./doc/004.md
[4C1]:  ./src/prob/004_1.c 
[4C2]:  ./src/prob/004_2.c 
[5]:    ./doc/005.md
[5C1]:  ./src/prob/005_1.c 
[5C2]:  ./src/prob/005_2.c
[6]:    ./doc/006.md
[6C]:   ./src/prob/006.c
[7]:    ./doc/007.md
[7C]:   ./src/prob/007.c
[8]:    ./doc/008.md
[8C]:   ./src/prob/008.c
[9]:    ./doc/009.md
[9C]:   ./src/prob/009.c
[10]:   ./doc/010.md
[10C]:  ./src/prob/010.c
[11]:   ./doc/011.md
[11C]:  ./src/prob/011.c
[12]:   ./doc/012.md
[12C]:  ./src/prob/012.c


[Ominmn]: http://latex.codecogs.com/gif.latex?O(\min\(m,n\)) 
[Ologmn]: http://latex.codecogs.com/gif.latex?O(\log\(m,n\)) 
[On2]: http://latex.codecogs.com/gif.latex?O(n^{2})  
[On]: http://latex.codecogs.com/gif.latex?O(n) 

[Mnch]: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/  
[10dp]: ./doc/010_dp.md
