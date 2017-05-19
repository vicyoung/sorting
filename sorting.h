#ifndef __SORT_H__
#define __SORT_H__

#include <stdint.h>

enum SortType { Heap = 0, Merge };

void heapsort     (uint32_t *m_array, const size_t m_size);
void mergesort    (uint32_t *m_array, const size_t m_size);

#endif
