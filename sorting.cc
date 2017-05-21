#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "sorting.h"

#include <algorithm>

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
	if(m_size>1){
		uint32_t a[m_size/2];
		uint32_t b[m_size - m_size/2];          // In case m_size is odd.
        copy(m_array,m_array+m_size/2,a);       // Memcpy did't work for me so chose to use copy().
        copy(m_array+m_size/2,m_array+m_size,b);
        mergesort(a,m_size/2);
		mergesort(b,m_size - m_size/2);
        merge(m_array,a,b,m_size);
	}					
}
void merge(uint32_t *m_array,uint32_t *a, uint32_t *b,size_t m_size) {
	size_t i = 0, j = 0;
    for(size_t k = 0; k < m_size;k++) {
		if(a[i] < b[j]){                        // Add the smaller one first.
			m_array[k] = a[i];
			i++;
		}
		else if(b[j] < a[i]){
			m_array[k] = b[j];
			j++;
		}
		if(i == m_size/2){
			// Array 'a' has no element to be added
            copy(b + j,b + m_size - m_size/2,m_array+k+1);
			break;
		}
		else if(j == m_size - m_size/2){
			// Array 'b' has no element to be added.
            copy(a+i,a+m_size/2,m_array+k+1);
            break;
		}
	}
}
			
		
