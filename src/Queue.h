/**
 * @file Queue.h
 * @author Francis John N. Magallanes
 * @brief This will contain the templated code for the Queue
 * data structure
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <Arduino.h>

template<typename T, int sizeQueue>
class Queue
{

public:
    
    Queue():headIndex(0), tailIndex(0),sizeStorage(sizeQueue + 1)
    {

    }

    T front()
    {
        return storage[headIndex];
    }

    T back()
    {
        return storage[((tailIndex - 1) + sizeStorage) % sizeStorage];
    }
    
    bool isEmpty()
    {
        return headIndex == tailIndex;
    }

    int size()
    {
        return (((tailIndex - headIndex) + sizeStorage) % sizeStorage);
    }

    bool enqueue(T item)
    {
        if(size() < sizeStorage)
        {
            //put the item at the tailIndex 
            storage[tailIndex] = item;

            //update the tailIndex to point the next free space
            tailIndex = (tailIndex + 1) % sizeStorage;

            return true;
        }

        return false;
    }

    bool dequeue()
    {
        if(size() > 0)
        {
            //update the head index. This will remove the item in the queue
            headIndex = (headIndex + 1) % sizeStorage;

            return true;
        }

        return false;
    }

    int find(const T &query)
    {
        // you want to stop the searching when it points outside the queue ( == tailIndex)
        for(int i = headIndex; i != tailIndex; i = ((i + 1) % sizeStorage))
        {
            if(storage[i] == query)
            {
                return ((i - headIndex) + sizeStorage) % sizeStorage;
            }
        }

        return -1;
    }

    int find(const T &query, bool (*comparison)(T,T))
    {
        // you want to stop the searching when it points outside the queue ( == tailIndex)
        for(int i = headIndex; i != tailIndex; i = ((i + 1) % sizeStorage))
        {
            if(comparison(storage[i],query))
            {
                return ((i - headIndex) + sizeStorage) % sizeStorage;
            }
        }

        return -1;
    }

    bool dequeueAt(int index)
    {
        // index should not be negative and it should be less than the current size of queue
        // this avoid the index out of bound error in the queue
        if((size() > index) && (index < 0))
        {
            // this will move the items
            for(int i = headIndex + i; i != ((tailIndex - 1) + sizeStorage) % sizeStorage; i = ((i + 1) % sizeStorage))
            {
                //move the item
                storage[i] = storage[((i + 1) % sizeStorage)];
            }

            //update the tailIndex since there is a deleted item
            tailIndex = ((tailIndex - 1) + sizeStorage) % sizeStorage;

            return true;
        }

        return false;
    }

private:

    // "container" for the queue data structure
    T storage[sizeQueue + 1];

    int headIndex;

    // this will point to the free space at end of queue where
    // the next enqueue item will be placed
    int tailIndex;

    // this indicates the actual size of the storage (or the queue)
    // On the other hand, sizeQueue indicates the size of queue
    int sizeStorage;
};