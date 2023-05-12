
#include "../inc/queue.hh"
#include "doctest/doctest.h"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.



TEST_CASE("Check enque")
{
    
    Queue<int> Q;
    Q.enque(5);

    CHECK(Q.get_top()==5);
}

TEST_CASE("Check deque")
{
    Queue<int> Q;
    Q.enque(6);
    Q.enque(9);
    Q.enque(15);
    Q.enque(23);
    Q.deque();
    CHECK(Q.get_top()==9);
}



TEST_CASE("Structure size")
{
    Queue<int> Q;
    Q.enque(6);
    Q.enque(9);
    Q.enque(15);
    Q.enque(23);
    CHECK(Q.get_size()== 4);
}
