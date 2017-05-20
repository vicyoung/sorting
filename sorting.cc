#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "sorting.h"

using namespace std;

// Heapsort
void heapsort(uint32_t *m_array, const size_t m_size) {
	uint32_t heap[m_size+1];
	size_t count = 0;		// Count of heap.
	for(size_t i = 0;i < m_size;i++) {
		// Make heap, start from index 1.
		heap[i+1] = *(m_array+i);
		size_t j = i+1;
		while(heap[j]<heap[j/2]&&j!=1){
			// Swapping
			uint32_t tmp = heap[j];
			heap[j] = heap[j/2];
			heap[j/2] = tmp;
			j/=2;
		}
		count++;
	}

	for(size_t i = 0;i < m_size;i++) {
		// Pop heap, assign to m_array.
		*(m_array+i) = heap[1];
		size_t j = 1;
		while(2*j <= count){
			// Swapping with smaller child.		
			if(2*j == count || heap[2*j] < heap[2*j+1]){
				heap[j] = heap[2*j];
				j = 2*j;			
			}
			else{
				heap[j] = heap[2*j+1];			
				j = 2*j+1;
			}
		}
		if(j != count){
			// Fill the blank with the last element.
			heap[j] = heap[count];
		}
		while(heap[j]<heap[j/2]&&j!=1){
			// Check the filled element.					
			uint32_t tmp = heap[j];
			heap[j] = heap[j/2];
            heap[j/2] = tmp;
            j/=2;
        }
		count--;
	}

}

void mergesort(uint32_t *m_array, const size_t m_size) {
    /* Implement your code. */
}

