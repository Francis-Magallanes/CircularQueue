# CircularQueue
## By Francis John N. Magallaes

This library implements Queue Data Structure for Arduino using statically allocated and fixed length array. Its implementation follows a circular buffer implementation which uses modulo arithmetic. Through statically allocated array, the chances of memeory fragmentation in the RAM of an arduino baord is greatly reduced. Also, you can have a better idea on how much the program uses the RAM when using this library since the buffer (or the array) is statically allocated rather than dynamically allocated (which will be determined during run time). For this to happen, the queue should not be declared using the "new" keyword. See the examples on how the library is being used and see the "Queue Data Structure" portion for overview of the implementation of the Queue data structure.

### Queue Data Structure

Queue follows a "Last In, Last Out" or "First In, First Out" scheme. Most of the methods of the Queue class implements this scheme. This is implemented through the Queue class with the use of arrays. There are also additional methods that the Queue class implements which are "at", "find", and "dequeueAt". Below show the description of the methods. For more information, read code documentation (via the comments) in the Queue.h 

|Method|Description|
|---|---------|
|front|It will return the first item of the queue.|
|back|It will return the last item of the queue.|
|at|It will return the item found at the inputted index.|
|isEmpty|It will indicate whether the queue is empty or not.|
|size|It will return the amount of items that is being stored in the queue.|
|enqueue|It will place the input item at the back of queue. It will also indicate whether the placement of the item in the queue is sucessful.|
|dequeue|It will remove the first item in the queue. It will also indicate whether the placement of the item in the queue is sucessful.|
|find|It will return the index where the item will be found based on the inputted query parameter.|
|dequeueAt|It will remove the item based on the inputted index.|

### Testing

This library is tested through the [AUnit](https://github.com/bxparks/AUnit) by Brian Park. The test is deployed to Arduino Due board, Arduino Mega, and Arduino Uno. As of May 1,2022, all of the test passed for the three mentioned boards. These tests shows that this library will work Arduino Due, Arduino Mega, and Arduino Uno and this test will also work with other boards of Arduino since the code doesn't use any board specific commands (unless the arduino board doesn't use C++ 11). You can view the test made under the test folder.

### Issues and Feature Request

If you found a bug, feel free to open an issue in this github repository. Make sure that you describe the bug as accurate as possible. If you have any question, feel free to open an issue so that we can discuss it there. If you have a feature request, feel free to open an issues in this repository. You can also make pull request for any feature enhancement for this library (feel free to do it).

