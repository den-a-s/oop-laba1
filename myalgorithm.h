#pragma once

template<class T>
int findIdx(const T &item, const T *array, int sizeArray)
{
    for (int i = 0; i < sizeArray; ++i) {
        if (array[i] == item) return i;
    }
    return -1;
}
