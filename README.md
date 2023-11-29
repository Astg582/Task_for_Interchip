# Task_for_Interchip
C   ----> vectr

Step 1: Downloa
Ensure you have both Vector.h and Vector.c fi

Step 2: Include Vector.h in Your Sou
In the source file where you want to use the `Vector.h` header at the be

#include "Vector.h"

Step 3: Comp
When compiling your program, include bot `Vector.c` and your source file in the compilation command. For example:

gcc YourSourceFile.c Vector.c -o Your Executable

Step 4: Use Vector Functions in Your C
Now you can use the functions declared in `Vector.h` in your source file. Here's an example:

#include <stdio.h>
#include "Vector.h"

int main() {
    // Create a vector with size 5 and initialize all elements to 0
    Vint myVector = construct_v(5, 0);

    // Insert values
    Insert(&myVector, 2, 42);
    push_back(&myVector, 10);

    // Print the vector before sorting
    printf("Before sorting:\n");
    for (size_t i = 0; i < myVector.size; ++i) {
        printf("%d ", myVector.arr[i]);
    }

    // Sort the vector
    Sort(&myVector);

    // Print the sorted vector
    printf("\nAfter sorting:\n");
    for (size_t i = 0; i < myVector.size; ++i) {
        printf("%d ", myVector.arr[i]);
    }

    // Free the memory used by the vector
    Deletion(&myVector);

    return 0;
}

Step 5: Compile and Run Your Program
Compile your program again, and then run the executable:

./YourExecutable

This should execute your program, and you should see the output based on the functions you've used from Vector.h and `Vector.c`. Adjust the example code according to your specific requirements.


Note:
Make sure to include "Vector.h" in any source file where you want to use the vector functions.
Always compile both your source file and `Vector.c` together to ensure that the functions are properly linked.


Following these steps should help you integrate the vector functionality into your C program




Vector Usage Guide

1 Initialization:

To create an empty vector:
Vint myVector = construct_0();

To create an empty vector with a specific size:
Vint myVector = construct_s(5); // Creates a vector of size 5

To create a vector with a specific size and initialize all elements to a specific value:
Vint myVector = construct_v(3, 7); // Creates a vector of size 3 with all elements initialized to 7


2 Accessing Elements:

To access an element at a specific index:
int value = Access(&myVector, 2); // Accesses the element at index 2


3 Insertion:

To insert a value at a specific index:
Insert(&myVector, 2, 42); // Inserts the value 42 at index 2

To add a value to the end of the vector:
push_back(&myVector, 10); // Adds the value 10 to the end of the vector


4 Sorting:

To sort the vector in ascending order:
Sort(&myVector); // Sorts the vector using Bubble Sort


5 Searching:

To perform a binary search on a sorted vector
int index = seek_Binary(&myVector, 42); // Searches for the value 42 using binary search

To search for a value in an unsorted vector:
int startIndex = sotr_start(&myVector, 10); // Searches for the value 10 from the beginning
int endIndex = sotr_ending(&myVector, 10); // Searches for the value 10 from the end


6 Memory Management:

To free the memory used by the vector:

Deletion(&myVector); // Frees the memory used by the vector


Example Usage:

#include <stdio.h>

int main() {
    // Create a vector with size 5 and initialize all elements to 0
    Vint myVector = construct_v(5, 0);

    // Insert values
    Insert(&myVector, 2, 42);
    push_back(&myVector, 10);

    // Print the vector before sorting
    printf("Before sorting:\n");
    for (int i = 0; i < myVector.size; ++i) {
        printf("%d ", myVector.arr[i]);
    }

    // Sort the vector
    Sort(&myVector);

    // Print the sorted vector
    printf("\nAfter sorting:\n");
    for (int i = 0; i < myVector.size; ++i) {
        printf("%d ", myVector.arr[i]);
    }

    // Search for a value
    int index = seek_Binary(&myVector, 42);
    if (index != -1) {
        printf("\nValue 42 found at index %d\n", index);
    } else {
        printf("\nValue 42 not found\n");
    }

    // Free the memory used by the vector
    Deletion(&myVector);

    return 0;
}
