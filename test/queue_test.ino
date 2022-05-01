#include <AUnit.h>
#include <Queue.h>

class c_Person
{
public:

    c_Person()
    {

    }

    c_Person(String firstName, String lastName, uint8_t age) 
        : FirstName(firstName), LastName(lastName), Age(age)
    {

    }

    bool operator == (const c_Person &anotherPerson)
    {
        return (this->FirstName == anotherPerson.FirstName) &&
                (this->LastName == anotherPerson.LastName) &&
                (this->Age == anotherPerson.Age);
    }

private:
    String FirstName;
    String LastName;
    uint8_t Age;
};

struct s_Person
{
    String FirstName;
    String LastName;
    uint8_t Age;
};

bool comparisonPerson(s_Person person1, s_Person person2)
{
    return (person1.FirstName == person2.FirstName) &&
                (person1.LastName == person2.LastName) &&
                (person1.Age == person2.Age);
}

test(Enqueue_Size_Front_Back)
{
    Queue<int,10> queue;

    // enqueue items and check whether the enqueueing and expected size is right
    queue.enqueue(1);
    queue.enqueue(2);
    assertTrue(queue.enqueue(3));
    assertEqual(queue.size(), 3);
    assertEqual(queue.front(),1);
    assertEqual(queue.back(), 3);

    queue.enqueue(1);
    queue.enqueue(1);
    queue.enqueue(1);
    assertEqual(queue.size(), 6);
    assertEqual(queue.front(),1);
    assertEqual(queue.back(), 1);

    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    assertTrue(queue.enqueue(8)); //this is the final item that it can be enqueued
    assertEqual(queue.size(), 10);
    assertEqual(queue.front(),1);
    assertEqual(queue.back(), 8);

    //this should return false since the queue is full
    assertFalse(queue.enqueue(-10));
    assertFalse(queue.enqueue(3)); // this should not be enqueue
    assertEqual(queue.size(), 10);
    assertEqual(queue.back(), 8);
}

test(Enqueue_Dequeue_Back_Front_Size_IsEmpty)
{
    Queue<int,5> queue;

    //enqueue items and check it
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    assertTrue(queue.enqueue(5));
    assertEqual(queue.size(), 5);
    assertEqual(queue.front(),1);
    assertEqual(queue.back(), 5);
    
    // this will check whether the dequeue is properly working and the back
    // note that this point, the tailIndex is pointing to the first index of the array
    // back should give the last item of the storage
    assertTrue(queue.dequeue());
    assertTrue(queue.enqueue(1));
    assertEqual(1,queue.back());
    assertEqual(2,queue.front());
    assertEqual(5, queue.size());

    //dequeue all items
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    //this should return false since there is no more items to dequeue
    assertFalse(queue.dequeue());
    assertTrue(queue.isEmpty());
}

// this will test the find whose type is capable of "==" operator
test(Find_1)
{
    c_Person person1 ("FirstNamePerson1","LastNamePerson1",27);
    c_Person person2 ("FirstNamePerson2","LastNamePerson2",22);
    c_Person person3 ("FirstNamePerson3","LastNamePerson3",23);
    c_Person person4 ("FirstNamePerson4","LastNamePerson4",24);
    c_Person person5 ("FirstNamePerson5","LastNamePerson5",25);

    c_Person queryInQueue ("FirstNamePerson3","LastNamePerson3",23);
    c_Person queryNotInQueue ("FirstNamePerson6","LastNamePerson3",23);

    Queue<c_Person,5> waitingLine;

    waitingLine.enqueue(person5);
    waitingLine.enqueue(person4);
    waitingLine.enqueue(person3);
    waitingLine.enqueue(person2);
    waitingLine.enqueue(person1);

    assertEqual(2, waitingLine.find(queryInQueue));
    assertEqual(-1, waitingLine.find(queryNotInQueue)); //it should return -1 since the query is not in the queue
}

// this will test the find method whose comparison basis is the inputted function 
test(Find_2)
{
    s_Person person1 = {"FirstNamePerson1","LastNamePerson1",27};
    s_Person person2 = {"FirstNamePerson2","LastNamePerson2",22};
    s_Person person3 = {"FirstNamePerson3","LastNamePerson3",23};
    s_Person person4 = {"FirstNamePerson4","LastNamePerson4",24};
    s_Person person5 = {"FirstNamePerson5","LastNamePerson5",25};

    s_Person queryInQueue = {"FirstNamePerson3","LastNamePerson3",23};
    s_Person queryNotInQueue = {"FirstNamePerson6","LastNamePerson3",23};

    Queue<s_Person,5> waitingLine;

    waitingLine.enqueue(person5);
    waitingLine.enqueue(person4);
    waitingLine.enqueue(person3);
    waitingLine.enqueue(person2);
    waitingLine.enqueue(person1);

    assertEqual(2, waitingLine.find(queryInQueue, comparisonPerson));
    assertEqual(-1, waitingLine.find(queryNotInQueue, comparisonPerson)); //it should return -1 since the query is not in the queue
}

test(DeleteAt_Dequeue_Enqueue_Size_Front_Back)
{
    Queue<int,5> queue;

    //enqueue items and check it
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    assertTrue(queue.enqueue(5));
    assertEqual(queue.size(), 5);
    assertEqual(queue.front(),1);
    assertEqual(queue.back(), 5);

    //remove number 3 which is at index 2 in the queue
    assertTrue(queue.dequeueAt(2));
    assertEqual(queue.size(), 4);
    assertEqual(queue.front(),1);
    assertEqual(queue.back(), 5);
    
    //remove three front items in the queue
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    //it is expected that the number 4 will be the first item
    assertEqual(5,queue.front());
    assertEqual(5,queue.back());
    assertEqual(1,queue.size());
    
    //another test of deleteAt 
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);
    assertTrue(queue.dequeueAt(queue.find(2)));
    assertEqual(3, queue.size());
    assertEqual(5,queue.front());
    assertEqual(1,queue.back());

    //test whether it can dequeue the first item
    assertTrue(queue.dequeueAt(0));
    assertTrue(queue.dequeueAt(queue.size() - 1)); //dequeue the last item
    assertEqual(1,queue.size());

    //test whether it will dequeue an item when the size is zero
    queue.dequeue();
    assertFalse(queue.dequeueAt(0));
}

test(At_Enqueue)
{
    c_Person person1 ("FirstNamePerson1","LastNamePerson1",27);
    c_Person person2 ("FirstNamePerson2","LastNamePerson2",22);
    c_Person person3 ("FirstNamePerson3","LastNamePerson3",23);
    c_Person person4 ("FirstNamePerson4","LastNamePerson4",24);
    c_Person person5 ("FirstNamePerson5","LastNamePerson5",25);

    Queue<c_Person,5> waitingLine;

    waitingLine.enqueue(person5);
    waitingLine.enqueue(person4);
    waitingLine.enqueue(person3);
    waitingLine.enqueue(person2);
    waitingLine.enqueue(person1);

    assertTrue((person5 == waitingLine.at(0)));
    assertTrue((person4 == waitingLine.at(1)));
    assertTrue((person3 == waitingLine.at(2)));
    assertTrue((person2 == waitingLine.at(3)));
    assertTrue((person1 == waitingLine.at(4)));

    //this will test whether the method is pass by value
    c_Person firstPerson = waitingLine.at(0);
    waitingLine.dequeue();
    waitingLine.dequeue();
    waitingLine.dequeue();
    waitingLine.dequeue();
    waitingLine.dequeue();
    waitingLine.enqueue(person3);
    waitingLine.enqueue(person2);
    assertTrue(waitingLine.enqueue(person1));
    assertTrue((person5 == firstPerson));
}

void setup()
{
    Serial.begin(9600);

    aunit::TestRunner::setTimeout(10);
}

void loop()
{
    aunit::TestRunner::run();
}