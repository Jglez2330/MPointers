# MPointers
MPointers is a library for C++ use to replace the default pointer managment an implememnt a new class MPointer that will work as a pointer but offering an easier way to interact with them for the programmer. This library also allows the programmer to set up a virtual memory that will work along side to the MPointer class.

### ADTs development
* Node<t>
* LinkedList<t>
* DoubleLinkedList<t>
### Sorting Patterns
* QuickSort
* BubbleSort
* InsertionSort
### MPointer class
* Implement Template<t>
* Overload "*"
* Overload "&"
* Overload "="
* Builder New()
* Singleton MPointerGC
### Server
* MPointer_init()
* Activity flag
* Memory managment
* Sending/Receiving data
* Read and write in memory
* Implement ID and Offset
* Searching data on memory
## User Stories
* As a user, I want a easier way to use the pointers in the C++ programming language because that would help me with the pointers managment of my program.
* As a user, I want my program to manage the memory used for the pointers because it would avoid lots of problems in my program.
* As a user, I want to save data in a virtual server because that would save many space in my computer's memory.
* As a user, I want to sort the data saved in the memory because that would allow me to get the data in a easier and faster way.
* As a user, I want a garbage collector to erase unused pointer because that would release many space in the memory.
## Data Structures
* Linked List
  The list is a data structure made of nodes. The list class save a pointer to the head and that head save a pointer to the next element in the list and is the same for the rest of the list.
* Double Linked List
  The double linked list is the same data structure as the linked list, but in this class, the nodes will save pointers to the next and the previous elements.
## Algorithms
* Quicksort
  Pick an element, called a pivot, from the array. Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation. Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
* Bubblesort
  Pick the two first consecutive elements, compare and swap them if the second element is greater than the first. Now, pick the second element a the next element and do the same as before. After comparing all the two consecutive elements, make a new loop and repeat until the array don't make any swap.
* Insertionsort
  Asume the first element as sorted, pick the next element, take it out of the array and insert it in the correct position of the sorted part of the array and now, the sorted part will be the same with the new element.
