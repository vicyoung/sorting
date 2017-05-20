#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "sorting.h"

using namespace std;

// Heapsort
void heapsort(uint32_t *m_array, const size_t m_size) {
    /* Implement your code. */
	uint32_t heap[m_size+1];
	for(size_t i = 0;i < m_size;i++) {
		heap[i+1] = *(m_array+i);
		size_t j = i+1;
		while(heap[j]<heap[j/2]&&j!=1){
			uint32_t tmp = heap[j];
			heap[j] = heap[j/2];
			heap[j/2] = tmp;
			j/=2;
		}
	}
	for(size_t i = 0;i < m_size;i++) {
		*(m_array+i) = heap[1];
		size_t j = 1;
		while(heap[2*j]!= 0){
			if(heap[2*j] < heap[2*j+1]){
				heap[j] = heap[2*j];
				j = 2*j;			
			}
			else{
				heap[j] = heap[2*j+1];			
				j = 2*j+1;
			}
		}
		if(heap[j+1]!=0){
			size_t k = j+1;
			while(heap[k+1]!=0){
				k++;
			}
			heap[j] = heap[k];
			heap[k] = 0;
		}
		while(heap[j]<heap[j/2]&&j!=1){
              uint32_t tmp = heap[j];
              heap[j] = heap[j/2];
              heap[j/2] = tmp;
              j/=2;
        }
	}

}

void mergesort(uint32_t *m_array, const size_t m_size) {
    /* Implement your code. */
}

