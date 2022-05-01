# ArduinoQueue
## By Francis John N. Magallaes

This library implements Queue Data Structure for Arduino using statically allocated and fixed length array. Its implementation follows a circular buffer implementation which uses modulo arithmetic. Through statically allocated array, the chances of memeory fragmentation in the RAM of an arduino baord is greatly reduced. Also, you can have a better idea on how much the program uses the RAM when using this library since the buffer (or the array) is statically allocated rather than dynamically allocated (which will be determined during run time). For this to happen, the queue should not be declared using the "new" keyword. See the examples on how the library is being used and see this [documentation](src/README.md) for overview of the implementation of the Queue data structure.

### Testing

This library is tested through the [AUnit](https://github.com/bxparks/AUnit) by Brian Park. The test is deployed to Arduino Due board, Arduino Mega, and Arduino Uno. As of May 1,2022, all of the test passed for the three mentioned boards. These tests shows that this library will work Arduino Due, Arduino Mega, and Arduino Uno and this test will also work with other boards of Arduino since the code doesn't use any board specific commands (unless the arduino board doesn't use C++ 11). You can view the test made under the test folder.

### Issues and Feature Request

If you found a bug, feel free to open an issue in this github repository. Make sure that you describe the bug as accurate as possible. If you have any question, feel free to open an issue so that we can discuss it there. If you have a feature request, feel free to open an issues in this repository. You can also make pull request for any feature enhancement for this library (feel free to do it).

