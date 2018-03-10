#include "aux.h"
#include "umix.h"
#include "mykernel4.h"

#define NUMYIELDS 5

static int square, cube;  // global variables, shared by threads

void Main ()
{
  int i, t, me; 
  void printSquares (), printCubes (), doNothing();

  InitThreads (); 

  me = GetThread (); 
  t = CreateThread (doNothing, 1);
  t = CreateThread (doNothing, 2); 
  t = CreateThread (doNothing, 3); 
  t = CreateThread (doNothing, 4); 
  t = CreateThread (doNothing, 5); 
  t = CreateThread (doNothing, 6); 
  t = CreateThread (doNothing, 7); 
  t = CreateThread (doNothing, 8); 
  t = CreateThread (doNothing, 0); 


  //main is running in zero, yield to 1 (naturally from one we yield to everyone else in fifo order)
  YieldThread(1);
  //all 9 threads should have exited at this point
  //create 3 more on top where the old ones used to be
  t = CreateThread (doNothing, 1);
  t = CreateThread (doNothing, 2); 
  t = CreateThread (doNothing,3); 
  t = CreateThread (doNothing,4); 
  t = CreateThread (doNothing,5); 
  t = CreateThread (doNothing,6); 
  t = CreateThread (doNothing,7); 
  t = CreateThread (doNothing,8); 
  t = CreateThread (doNothing,9); 
  YieldThread(1);
  YieldThread(3);
  YieldThread(5);
  YieldThread(7);

  ExitThread (); 
}

void printSquares (t) 
  int t;        // thread to yield to
{
  int i;

  for (i = 0; i < NUMYIELDS; i++) {
    square = i * i;
    Printf ("T%d: %d squared = %d\n", GetThread (), i, square);
    YieldThread (t);
  }
}

void doNothing(x)
  int x;
{
  Printf("\n%d\n",x);
}

void printCubes (t) 
  int t;        // thread to yield to
{
  int i;

  for (i = 0; i < NUMYIELDS; i++) {
    cube = i * i * i;
    Printf ("T%d: %d cubed = %d\n", GetThread (), i, cube);
    YieldThread (t);
  }
}

