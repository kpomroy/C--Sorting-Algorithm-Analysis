# CS 124 Project 4

For this project, you will sort the 1000 objects from your data set. You will modify each sorting algorithm to collect data. You will analyze the results from the different sorting algorithms.

## Implement
You should have your 1000+ objects stored in a vector, initially unsorted.
Use these five sorting algorithms:
1. Bubble Sort
2. Choose either Selection Sort or Insertion Sort
3. Choose either Merge Sort or Quick Sort
4. Heap Sort
5. Two-sort: sort by any algorithm (except Bubble Sort), then sort on a different field using a stable sorting algorithm (again, except Bubble Sort).
   * Hint for implementing two-sort: for the second stable algorithm, make a copy of the stable sorting function and take out the template part. That way you will be able to call a getter on your custom-type objects to compare a second field of your class.

Modify each sorting algorithm to record the number of reads. This is the number of times you use a Comparable object. This could be using it to store somewhere else, using it to compare to another object, etc. Temporary Comparable objects count towards the reads. 
* Example code:
  ```cpp
  if (vec[i] > vec[i+1]) // This counts as two reads, which should
      // be counted whether the if statements evaluates to true or false.
  Comparable temp = vec[i]; // This is one read.
  smaller.push_back(vec[i]); // This is one read.
  ```
Modify each sorting algorithm to record the number of writes. This is the number of times you assign into a Comparable object. This could be to store a temporary Comparable, to overwrite an item in a Comparable vector, to push_back onto a Comparable vector, etc.
* Example code:
  ```cpp
  Comparable temp = vec[i]; // This is one write (and one read).
  smaller.push_back(vec[i]); // This is one write (and one read).
  vec[i] = vec[i+1]; // This is one write (and one read).
  ```
Use a loop to record the number of reads and writes needed to sort a vector of size 100, 200, 300, 400, 500, 600, 700, 800, 900, and 1000.
* Hint: start with 1000 and then use the resize method to make it smaller. 

Each of the five sorting algorithms should be given identical unsorted vectors to begin with. 
* If your data is naturally sorted by the attribute you use to overload your operators, change how you overload your operators.

## Extra Credit
To earn up to 10 extra credit points (at the grader’s discretion), you can get more thorough results. This can include, but is not limited to:
* Setting timers to record how long it takes you to sort the objects with each algorithm.
* Performing the same experiment, except double the size of the data set each time (instead of having it grow linearly).
* Using more sorting algorithms.

Note that if you add this logic to your code but do not analyze it in your report, it will not count towards extra credit. If you complete extra credit, analyze it in this section of your README.md file.

The time differences among the sorting algorithms were much less significant than the number of reads and writes and the graphs look relatively similar, besides two sort which makes sense since it has to run insertion sort twice. All of the algorithms besides two sort took less than 1500 milliseconds to complete when the vector had 1000 items.
## Report
Include the following in this section of your README.md file:
* Information about your data set (you will be assigned a different grader for this project).
  
This data set contains the top 1000 streamed songs on Spotify. The fields are position in the rankings, artist, song title, number of days since release, and number of streams.

* Analyze the data. Graph the number of reads and writes for each sorting algorithm and look at how the number of reads and writes grows when the size of the data set grows. 
Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.

![Reads](data/graphs/reads.png)
![Writes](data/graphs/writes.png)
![Time](data/graphs/duration.png)

Merge sort was the most consistent and efficient sorting algorithm when comparing the number of reads as the vector size increased. It had the lowest number of reads for each vector size as well as the lowest percentage increase from a vector size of 100 to 1000 with a 1463% increase. The next lowest percent increase as vector size increased was heap sort with a 3451% increase in reads. The least efficient algorithm was bubble sort with a 10358% increase in reads and the highest number of reads for every vector size.
Selection sort had the lowest number of reads for each vector size, and both merge and selection sort had very minimal increases in writes compared to the rest of the algorithms. Selection sort had a 909% increase in writes from 100 to 1000 items, and merge sort had a 1385% increase. Bubble sort again had the highest number and percentage increase in writes with an increase of 10675%.
Overall, merge sort seems to be the most efficient algorithm of those I analyzed for minimizing reads and writes for larger vectors. It has O(N log N) time complexity and O(N) auxiliary complexity which is a time vs memory tradeoff when compared with bubble and insertion sort which have O(N^2) time complexity and O(1) auxiliary complexity. Merge sort takes less time but requires more memory. 

* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 

To sort a contacts list, I would use bubble or insertion sort since they are stable sorting algorithms that perform well on smaller vectors. They both have constant time complexity and O(N^2) time complexity so they are not ideal for larger vectors, but a contacts list is generally relatively small so they would work well in this case and require minimal memory.

  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?

To sort a database of 20 million client files from a datacenter, I would use merge sort because it is a stable, divide and conquer algorithm with O(N log N) time complexity and O(N) auxiliary complexity. Since there are a high volume of records to be sorted, it is better to use a sorting algorithm with the lowest time complexity and trade off memory.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

## Submit
You must include your source (all .cpp and .h) files, your data (.csv) file(s), CMakeLists.txt, and your updated README.md file that contains your report to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Grading
The project is out of 90 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 5 pts | Use five sorting algorithms according to the directions above. |
| 15 pts | Sort the 100, 200, … 1000 objects according to the directions above. |
| 40 pts | Record the correct number of reads and writes for each sort. |
| 20 pts | Report: content, formatting, professional, grammatically correct, cites sources. |