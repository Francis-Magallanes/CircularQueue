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

/**
 * @brief This template defines the queue data structure which follows
 * a first in, first out (FIFO) principle. Since it uses template, it
 * has the capability of accomodating different data types whether it
 * is primitive or user-defined.
 *
 * @tparam T datatype of item the that the queue will be storing.
 * @tparam sizeQueue maximum possible size of the queue through its usage.
 */
template <typename T, int sizeQueue>
class Queue
{

public:
    /**
     * @brief Constructor that will create the instance of the queue.Note that
     * there is no form of error handling used in this implementation so make sure
     * that the queue is not empty.
     *
     */
    Queue() : headIndex(0), tailIndex(0), sizeStorage(sizeQueue + 1)
    {
    }

    /**
     * @brief It will return the first item of the queue.Note that
     * there is no form of error handling used in this implementation so make sure
     * that the queue is not empty.
     *
     * @return T first item of the queue
     */
    T front()
    {
        return storage[headIndex];
    }

    /**
     * @brief It will return a pointer to the first item of the queue.Note that
     * there is no form of error handling used in this implementation so make sure
     * that the queue is not empty.
     *
     * @return T pointer to the first item of the queue
     */
    T* p_Front()
    {
        return &storage[headIndex];
    }

    /**
     * @brief It will return the last item of the queue.Note that
     * there is no form of error handling used in this implementation so make sure
     * that the queue is not empty.
     *
     * @return T last item of the queue
     */
    T back()
    {
        return storage[((tailIndex - 1) + sizeStorage) % sizeStorage];
    }

    /**
     * @brief It will return a pointer to the last item of the queue.Note that
     * there is no form of error handling used in this implementation so make sure
     * that the queue is not empty.
     *
     * @return T pointer to the last item of the queue
     */
    T* p_Back()
    {
        return &storage[((tailIndex - 1) + sizeStorage) % sizeStorage];
    }

    /**
     * @brief It will return the item found at the inputted index. Note that
     * there is no form error handling used in this implementation so make sure
     * that the index is valid.
     * 
     * @param index - location of the target item in the queue. Note that
     * that the index starts at zero.
     * @return T - item with type T that is located at the specified index
     */
    T at(int index)
    {
        return storage[(headIndex + index) % sizeStorage];
    }

    /**
     * @brief It will return the a pointer of the item found at the inputted index. Note that
     * there is no form error handling used in this implementation so make sure
     * that the index is valid.
     * 
     * @param index location of the target item in the queue. Note that
     * that the index starts at zero.
     * @return T* pointer to the item with type T that is located at the specified index
     */
    T* p_At(int index)
    {
        return &storage[(headIndex + index) % sizeStorage];
    }

    /**
     * @brief It will indicate whether the queue is empty or not.
     *
     * @return true The queue is empty
     * @return false The queue is not empty
     */
    bool isEmpty()
    {
        return headIndex == tailIndex;
    }

    /**
     * @brief It will return the amount of items that is being stored in the
     * queue.
     *
     * @return int amount of stored items in the queue.
     */
    int size()
    {
        return (((tailIndex - headIndex) + sizeStorage) % sizeStorage);
    }

    /**
     * @brief It will place the input item at the back of queue. It will
     * also indicate whether the placement of the item in the queue
     * is sucessful.
     *
     * @param item the data that will stored in the queue.
     * @return true the data is succesfully placed in the queue.
     * @return false the data is not sucessfully placed in the queue because
     * the queue is full.
     */
    bool enqueue(T item)
    {
        if (size() < sizeQueue)
        {
            // put the item at the tailIndex
            storage[tailIndex] = item;

            // update the tailIndex to point the next free space
            tailIndex = (tailIndex + 1) % sizeStorage;

            return true;
        }

        return false;
    }

    /**
     * @brief It will remove the first item in the queue. It will
     * also indicate whether the placement of the item in the queue
     * is sucessful.
     *
     * @return true the first item of the queue is succesfully removed in the queue.
     * @return false no item is removed because the queue is empty.
     */
    bool dequeue()
    {
        if (size() > 0)
        {
            // update the head index. This will remove the item in the queue
            headIndex = (headIndex + 1) % sizeStorage;

            return true;
        }

        return false;
    }

    /**
     * @brief It will find the query inside the queue. It will return the
     * index where the item will be found. If return value is -1, then
     * the query is not at the queue. Make sure that the type T can be compared
     * using "==" or else it will crash the program.
     *
     * Note that the index starts at 0. Also, it will return the first item statisfies the
     * equality comparison. Thus, it will not return the indices for duplicate ite scenario.
     *
     * @param query the item being searched in the queue.
     * @return int index where the item will be found. -1 means
     * doesn't find in the query in the queue.
     */
    int find(const T &query)
    {
        // you want to stop the searching when it points outside the queue ( == tailIndex)
        for (int i = headIndex; i != tailIndex; i = ((i + 1) % sizeStorage))
        {
            if (storage[i] == query)
            {
                return ((i - headIndex) + sizeStorage) % sizeStorage;
            }
        }

        return -1;
    }

    /**
     * @brief This an alternative for finding an item in the queue that cannot be
     * compared using "==" operator. It uses the comparison parameter to make the equality
     * comparison when finding the query in the queue. It will return the index where the
     * item will be found. If return value is -1, then the query is not at the queue.
     *
     * Note that the index starts at 0. Also, it will return the first item statisfies the
     * equality comparison. Thus, it will not return the indices for duplicate ite scenario.
     *
     * @param query the item being searched in the queue.
     * @param comparison a function pointer that will compare the two T items whether it is
     * equal or not. It should return true if the two items are equal.
     * @return int index where the item will be found. -1 means
     * doesn't find in the query in the queue.
     */
    int find(const T &query, bool (*comparison)(T, T))
    {
        // you want to stop the searching when it points outside the queue ( == tailIndex)
        for (int i = headIndex; i != tailIndex; i = ((i + 1) % sizeStorage))
        {
            if (comparison(storage[i], query))
            {
                return ((i - headIndex) + sizeStorage) % sizeStorage;
            }
        }

        return -1;
    }

    /**
     * @brief It will remove the item based on the inputted index
     *
     * @param index location of the item in the queue which will be deleted. Note
     * that the index starts at 0.
     * @return true the deletion is successful.
     * @return false the deletion is not successfull because the input index is not
     * within the range of indices based on the current size of the queue.
     */
    bool dequeueAt(int index)
    {
        // index should not be negative and it should be less than the current size of queue
        // this avoid the index out of bound error in the queue
        if ((index < size()) && (index >= 0))
        {
            //for the case that the item is at the start of the queue
            if(index == 0)
            {
                dequeue();
            }
            //for the case that the item is at the end of the queue
            else if(index == size() - 1)
            {
                tailIndex = ((tailIndex - 1) + sizeStorage) % sizeStorage;
            }
            //for the case that the item is at middle part of the queue
            else
            {
                // this will move the items
                for (int i = headIndex + index; i != ((tailIndex - 1) + sizeStorage) % sizeStorage; i = ((i + 1) % sizeStorage))
                {
                    // move the item
                    storage[i] = storage[((i + 1) % sizeStorage)];
                }

                // update the tailIndex since there is a deleted item
                tailIndex = ((tailIndex - 1) + sizeStorage) % sizeStorage;
            }
           
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