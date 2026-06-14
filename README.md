# sorting-algorithms-time-comparison-analysis
Implementation and performance analysis of multiple sorting algorithms (Selection, Insertion, Merge, Quick, Heap, Counting) with experimental runtime comparison and Big-O theoretical evaluation.
In this assignment, you are to implement the sorting algorithms listed below and give a 
table indicating the execution time for the different sorts (on various array sizes). 
You need to submit the following: 
1- Your source code. 
2- A text file containing the following: 
a. The table below. 
b. The graphs (2 graphs for each sort). 
For each algorithm you have to submit two graphs for the execution time, one using the 
big-oh function know for the sort in the worst case, and the other graph using the actual 
running times you get by using the function (clock) as explained below. Use 
experiment#1 values to draw the second graph for each sort. Use Excel to draw the 
graphs. 
The arrays’ values must be randomly generated integers using the function rand(); 
f(n) in the table is the theoretical execution time (worst case) for each algorithm, for 
example, selection sort is O(n2), so f(n)= n2 for selection sort. 
Don’t forget to notice and compare the results.
Conclusions:  
Compare both graphs for each sort. For example, does Selection Sort execution time 
show the same quadratic behavior in graph2 (using your experiment results) as in 
graph1 (using the calculated big O)? Ask the same question for all other sorts. 
Below is a sample code showing the main function in a program that calls Merge Sort to 
sort a randomly generated array of integers. The code uses the above functions to 
calculate the time taken by the Merge Sort function in seconds. Note that the ArraySize 
is set as a constant in order to try different array sizes easily (or you can make it a user 
input). 
Note: Merge Sort implementation is not given because it is a part of the assignment. 
