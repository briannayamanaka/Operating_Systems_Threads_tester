#include "aux.h"
#include "umix.h"
#include "mykernel4.h"

#define NUMYIELDS 5

static int square, cube;  // global variables, shared by threads

void Main ()
{
  int i, t, me; 
  void printSquares (), printCubes (), doNothing();

  MyInitThreads (); 

  //from thread 0, create 9 threads
  MyCreateThread (doNothing, 1);
  MyCreateThread (doNothing, 2); 
  MyCreateThread (doNothing, 3); 
  MyCreateThread (doNothing, 4); 
  MyCreateThread (doNothing, 5); 
  MyCreateThread (doNothing, 6); 
  MyCreateThread (doNothing, 7); 
  MyCreateThread (doNothing, 8); 
  MyCreateThread (doNothing, 9); 

  //Yield from 0 to 2
  MyYieldThread(2);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = MyCreateThread (doNothing, 1); 
  t = MyCreateThread (doNothing, 2); 
  t = MyCreateThread (doNothing, 3); 
  t = MyCreateThread (doNothing, 4); 
  t = MyCreateThread (doNothing, 5); 
  t = MyCreateThread (doNothing, 6); 
  t = MyCreateThread (doNothing, 7); 
  t = MyCreateThread (doNothing, 8); 
  t = MyCreateThread (doNothing, 9); 

  //Yield from 0 to 6
  MyYieldThread(6);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = MyCreateThread (doNothing, 1); 
  t = MyCreateThread (doNothing, 2); 
  t = MyCreateThread (doNothing, 3); 
  t = MyCreateThread (doNothing, 4); 
  t = MyCreateThread (doNothing, 5); 
  t = MyCreateThread (doNothing, 6); 
  t = MyCreateThread (doNothing, 7); 
  t = MyCreateThread (doNothing, 8); 
  t = MyCreateThread (doNothing, 9); 


  //Yield from 0 to 9
  MyYieldThread(9);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = MyCreateThread (doNothing, 1); 
  t = MyCreateThread (doNothing, 2); 
  t = MyCreateThread (doNothing, 3); 
  t = MyCreateThread (doNothing, 4); 
  t = MyCreateThread (doNothing, 5); 
  t = MyCreateThread (doNothing, 6); 
  t = MyCreateThread (doNothing, 7); 
  t = MyCreateThread (doNothing, 8); 
  t = MyCreateThread (doNothing, 9); 

  //Yield from 0 to 8
  MyYieldThread(8);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = MyCreateThread (doNothing, 1); 
  t = MyCreateThread (doNothing, 2); 
  t = MyCreateThread (doNothing, 3); 
  t = MyCreateThread (doNothing, 4); 
  t = MyCreateThread (doNothing, 5); 
  t = MyCreateThread (doNothing, 6); 
  t = MyCreateThread (doNothing, 7); 
  t = MyCreateThread (doNothing, 8); 
  t = MyCreateThread (doNothing, 9); 


  MyExitThread (); 
}

void printSquares (t) 
  int t;        // thread to yield to
{
  int i;

  for (i = 0; i < NUMYIELDS; i++) {
    square = i * i;
    Printf ("T%d: %d squared = %d\n", MyGetThread (), i, square);
    MyYieldThread (t);
  }
}

void doNothing(x)
  int x;
{
  /*
  if(x==4){
    MyYieldThread("8");
  }
  */
  Printf("\n%d\n",x);
}

void printCubes (t) 
  int t;        // thread to yield to
{
  int i;

  for (i = 0; i < NUMYIELDS; i++) {
    cube = i * i * i;
    Printf ("T%d: %d cubed = %d\n", MyGetThread (), i, cube);
    MyYieldThread (t);
  }
}

