# Queue

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