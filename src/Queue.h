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
    
    Queue():headIndex(0), tailIndex(0),maxSizeQueue(sizeQueue + 1)
    {

    }

    T front()
    {
        return storage[headIndex];
    }

    T back()
    {
        return storage[tailIndex];
    }
    
    bool isEmpty()
    {
        return headIndex == tailIndex;
    }

    int size()
    {
        return (((tailIndex - headIndex) + maxSizeQueue) % maxSizeQueue);
    }

    bool enqueue(T item)
    {
        if(size() < maxSizeQueue)
        {
            //put the item at the tailIndex 
            storage[tailIndex] = item;

            //update the tailIndex to point the next free space
            tailIndex = (tailIndex + 1 + maxSizeQueue) % maxSizeQueue;

            return true;
        }

        return false;
    }

    bool dequeue()
    {
        if(size() < maxSizeQueue)
        {
            //update first the head index
            headIndex = (headIndex + 1 + maxSizeQueue) % maxSizeQueue;

            return true;
        }

        return false;
    }

    int find(const T &query)
    {
        // you want to stop the searching when it points outside the queue ( == tailIndex)
        for(int i = headIndex; i != tailIndex; i = ((i + 1) % maxSizeQueue))
        {
            if(storage[i] == query)
            {
                return ((i + maxSizeQueue) - headIndex) % maxSizeQueue;
            }
        }

        return -1;
    }

    int find(const T &query, bool (*conditionStatement)(T,T))
    {
        // you want to stop the searching when it points outside the queue ( == tailIndex)
        for(int i = headIndex; i != tailIndex; i = ((i + 1) % maxSizeQueue))
        {
            if(conditionStatement(storage[i],query))
            {
                return ((i + maxSizeQueue) - headIndex) % maxSizeQueue;
            }
        }

        return -1;
    }

    bool dequeueAt(int index)
    {
        if((size() > index + 1) && (index < 0))
        {
            for(int i = headIndex + i; i != tailIndex - 1; i = ((i + 1) % maxSizeQueue))
            {
                //move the items
                storage[i] = storage[((i + 1) % maxSizeQueue)];
            }

            //update the tailIndex since there is deleted item
            tailIndex = tailIndex - 1;

            return true;
        }

        return false;
    }

private:
    T storage[sizeQueue + 1];
    int headIndex;
    int tailIndex;
    int maxSizeQueue;
};