**INTRODUCTION**

An Intal is a string of characters used to represent decimal numbers.
It consists of characters from '0' to '9' representing corresponding integer value.
The significance of the characters increases from right to left.
So for example "9984" represents the decimal value 9984.
This representation of numbers does not allow leading zeros such as "029" for 29.
However zero is represented as "0" (not to be confused with '0' which is a character. "0" is essentially {'0', '\0'}).


**WHATS THE DIFFERENCE?**

Normal integers and similar data types in C are stored in blocks of memory in its binary form.
However a string is stored as a contiguous memory for characters with a terminal null character. Hence the
Intals cannot be computed using normal C libraries as numbers, since at the memory level, the stored bits represent different data type.

In C each character occupies a single byte and a single integer occupies 4 bytes
Hence Intal allows storing monumental numbers with with a fraction of memory consumption.


**WHEN CAN THEY BE USED?**

Since Intals occupy less amount of memory, they can be used when a large amount of data needs to be stored.

C also has a maximum limit to the highest number that can be stored (2^64-1)
Even though its enough for most tasks however certain fields require even larger requirement.
Intals can be helpful in these situations. These fields include cosmology, cryptology and statistical mechanics to name a few.

Intals are even superior to scientific notation forms as scientific notations results in deminishing accuracy.

**DRAWBACKS**

Intal does not follow the normal rules of arithmetic as characters and strings cannot be computed upon in its raw nature and
requires specialized functions for any kind of arithmetic operation for Intal.
These functions are not available as standard functionsa and calls for manual work.

Also calculations on integers is very efficient since bits manipuations are used.
However complexity of calculations on Intal is more since control structures are used.

**APPROACH**

My approach to write functionalities for Intal is to think the basic algorithm that is behind the mathematical operation.
The algorithms can use basic mathematical operations on single digits and use these results to construct the final output.
Also after we have all the basic operations established, we can use these to build other operations.

*intal_add:*
The main idea is to iterate through both intals from right to left and add the digits by converting each characted to the corresponding digit by subtracting '0'. Now get their sum. Get the carry if the sum is greater than 9 and forward this carry to the next sum.

*intal_compare:*
We take advantage of intals being string here. Check which intal has greater length,as that intal will only be greater and return corresponding result. If the lenght is same iterate the intals from left to right and the intal which has a greater character('digit') first
is the greater intal.

*intal_diff:*
Initially we compare both the intals, if same return 0. Now perform difference for the remaining two cases separately. Iterate both the intals from right to left. If the digit of first intal is greater than of the second, subtract normally. Else iterate towards left till if get a position where first character is greater than second. While we are doing this, update the characters of first intal to add 9.
Subtract 1 from the position found and add 10 to the present character for which we were doing subtraction.

*intal_multiply:*
This is brute O(n2) approach of multiplying each digit with other and getting the solution.

*intal_mod:*
For this we add 0s to the number form which we want the mod, till the number is just less than the number being moded.
Now subtract them and do the mod of this number till we get the output smaller than the number which we are moding by.

intal_pow:
The idea is to apply divide and conquer algorithm of power to get the solution in O(logn) complexity.

*intal_gcd:*
Using the idea that gcd(a,b) = gcd(b, a mod b) till we get b as 0. Then a will be the answer. (Eucledian Algorithm).

*intal_fibonacci:*
Basic O(n) Dynamic programming approch by builing all Fibonacci series number till we get the number at the required position.

*intal_factorial:*
Basic O(n) approch of iterating from 1 to n, and multiplying each number to the previously initialized ans variable as 1.

*intal_bincoff:*
Used Dynamic programming on an array of size k and applying the property nCk = nC(k-1)+(n-1)C(k-1). We basically form each row
of Pascal's Triangle in each iteration.

*intal_max:*
Basic O(n) approach of comparing each adjacent elements and stroring a global max and updating it from the comparisons.

*intal_min:*
Basic O(n) approach of comparing each adjacent elements and stroring a global min and updating it from the comparisons.

*intal_search:*
Basic O(n) approach of comparing each element with the key. If found, return the position. If not found after
n comparisons, accepting that the key is not present and return -1.

*intal_binsearch:*
Basic O(logn) approch wherein we check if the middle element is the key or not. Else we recursively binary search over
the two halves on either side of the middel element.

*intal_sort:*
Applied the Quicksort with O(nlogn) complexity. The idea is to partition the array such the after partition an element is
in its sorted position, i.e. all elements to its left are less than it and all on the right are greater. Then recursively apply
Quicksort on the either side of the sorted element.

*coin_row_problem:*
The core idea is that the maximum sum can or cannot include a particular coin. If it is included then the maximum sum will
happen when we add this coin to the maximum sum not including it. Else if it not included, we just update it with previous maximum sum. Then return the maximum of all of these possible maximum sums.
This approach can be implemented using Dynamic Programming with O(n) complexity and O(n) memory space.

**OTHER FUNCTIONALITIES TO ADD**

1) A useful functionality that can be added to further improve the library will be division. 

First we can find the mod of the numbers to get the remainder and subtract it from the dividend. This will help reduce the work done next. Now we know this number is a multiple of the divisior(According to Remainder Theorem). So we can just use the long division method wherein we find what multiple of divisor equales the first part of dividend having same length as the divisior, finding the difference and extending it with the remaining digits of the dividend and repeating this process till we get zero.

2) Calculating rounded down square root can be done by iterating a varible from 1 and above till the square of the variable value
is less than the input number and returing this value. The square can be easily calculated using power function.


**MEMORY LEAKS REMOVAL**
A good memory leak detection tool for Windows is provided by https://github.com/bibhas2/Memd 
The library easily detects memory leaks in the program and gives line by line information regarding it.
A great alternative for Valgrind in Windows.




