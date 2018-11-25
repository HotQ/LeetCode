# LeetCode

## Tips

1. **DON'T** use global variable in LeetCode **!**

## Algorithms
| #    | Title                                               | Difficulty | Languge  | Runtime | Time Complexity | Tag                         |
| ---: | :-------------------------------------------------- | :--------- | :------- | ------: | :-------------- | :-------------------------: |
| 1    | [Two Sum][1]                                        | Easy       | [C][1C]  | 90.07%  | ![][On2]        |                             |
|      |                                                     |            | [C][1C2] | 6.45%   | ![][Ologn]      |                             |
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
| 13   | [Roman to Integer][13]                              | Easy       | [C][13C] | 100.00% |                 |                             |
| 14   | [Longest Common Prefix][14]                         | Easy       | [C][14C] | 100.00% |                 |                             |
| 15   | [3Sum][15]                                          | Medium     | [C][15C] | 84.06%  |                 |                             |
| 94   | [Longest Common Prefix][94]                         | Medium     | [C][94C] | 100.00% |                 |                             |


[1]:    ./doc/001.md
[1C]:   ./src/prob/001.c
[1C2]:  ./src/prob/001_2.c
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
[13]:   ./doc/013.md
[13C]:  ./src/prob/013.c
[14]:   ./doc/014.md
[14C]:  ./src/prob/014.c
[15]:   ./doc/015.md
[15C]:  ./src/prob/015.c
[94]:   ./doc/094.md
[94C]:  ./src/prob/094.c


[Ominmn]: http://latex.codecogs.com/gif.latex?O(\min\(m,n\)) 
[Ologmn]: http://latex.codecogs.com/gif.latex?O(\log\(m,n\)) 
[Ologn]: http://latex.codecogs.com/gif.latex?O(\log\(n\)) 
[On2]: http://latex.codecogs.com/gif.latex?O(n^{2})  
[On]: http://latex.codecogs.com/gif.latex?O(n) 

[Mnch]: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/  
[10dp]: ./doc/010_dp.md
