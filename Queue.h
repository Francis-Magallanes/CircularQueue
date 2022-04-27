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

template<typename T, uint32_t size>
class Queue
{

public:
    T front();
    
    bool isEmpty();

    uint32_t size();

    bool enqueue();

    bool dequeue();

    find(const T &query);

    dequeueAt(uint32_t index);

private:
    T storage[size];
    
};