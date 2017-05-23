#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "file_handler.h"
#include "sorting.h"
#include "stopwatch.h"

using namespace std;

int main(void) {
    file_handler_t file_numbers;    // Input file handler for a random number file
    stopwatch_t stopwatch;          // Stopwatch to measure elapsed time
    string input_set;               // Input data set
    string sorting_type;            // Sorting algorithm type
    void (*sort)(uint32_t*,size_t); // Function pointer to a sorting algorithm

    // Get the input sort type.
    while(sorting_type.empty()) {
        cout << "Select sorting type, heapsort(h) or mergesort(m): ";
        cin >> sorting_type;
             if(sorting_type == "h") { sort = &heapsort;  }
        else if(sorting_type == "m") { sort = &mergesort; }
        else {
            cout << "Invalid sort type " << sorting_type << endl;
            sorting_type.clear();
        }
    }





    /****************************************************
     * TEST YOUR CODE HERE TO SEE IF SORTING IS WORKING *
     ****************************************************/
    // Input array
    uint32_t array[20] = { 9,76 , 51, 17, 23,
                          79, 85,13, 76, 13,
                          31, 9, 15, 94, 12,
                          28, 79, 30, 55, 55};
    // Sort the input array
    sort(/* input array */ array, /* array size */ 20);

    // Show the elements of sorted array.
    for(size_t i = 0; i < 20; i++) { cout << array[i] << " "; } cout << endl;
    /********************
     * END OF TEST CODE *
     ********************/





    // Get the input set: last digit of student ID.
    while(input_set.empty()) {
        cout << endl << "Last digit of your student ID: ";
        cin >> input_set;
        if((input_set.find_first_not_of("0123456789") != string::npos) ||
           (input_set.size() > 1)) {
            cout << "Invalid digit " << input_set << endl;
            input_set.clear();
        }
    }

    // Choose different input data set for different sorting functions.
    unsigned offset = atoi(input_set.c_str());
    if(sorting_type == "h") { offset += Heap;  }
    else { offset += Merge; }
    stringstream ss; ss << offset%5; input_set = ss.str();
    file_numbers.read("inputs/"+input_set+"/sort.data");

    // Run and measure the execution time of sorting function.
    cout << endl << "Sorting " << file_numbers.size() << " numbers:" << endl;
    stopwatch.reset();
    stopwatch.start();
    sort(file_numbers.get(), file_numbers.size());
    stopwatch.stop();
    stopwatch.display(msec);

    // Show 2017th element in the sorted array to check correctness.
    cout << "array[2017] after sorting = " << file_numbers.get()[2017] << endl << endl;

    if(sorting_type == "h") { cout << "Heapsort ";  }
    else { cout << "Mergesort "; }
    cout << "done." << endl;

    return 0;
}

