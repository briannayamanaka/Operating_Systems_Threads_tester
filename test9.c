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

  
  //from thread 0, create 9 threads
  CreateThread (doNothing, 1);
  CreateThread (doNothing, 2); 
  CreateThread (doNothing, 3); 
  CreateThread (doNothing, 4); 
  CreateThread (doNothing, 5); 
  CreateThread (doNothing, 6); 
  CreateThread (doNothing, 7); 
  CreateThread (doNothing, 8); 
  CreateThread (doNothing, 9); 

  //Yield from 0 to 2
  YieldThread(2);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = CreateThread (doNothing, 1); 
  t = CreateThread (doNothing, 2); 
  t = CreateThread (doNothing, 3); 
  t = CreateThread (doNothing, 4); 
  t = CreateThread (doNothing, 5); 
  t = CreateThread (doNothing, 6); 
  t = CreateThread (doNothing, 7); 
  t = CreateThread (doNothing, 8); 
  t = CreateThread (doNothing, 9); 

  //Yield from 0 to 6
  YieldThread(6);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = CreateThread (doNothing, 1); 
  t = CreateThread (doNothing, 2); 
  t = CreateThread (doNothing, 3); 
  t = CreateThread (doNothing, 4); 
  t = CreateThread (doNothing, 5); 
  t = CreateThread (doNothing, 6); 
  t = CreateThread (doNothing, 7); 
  t = CreateThread (doNothing, 8); 
  t = CreateThread (doNothing, 9); 


  //Yield from 0 to 9
  YieldThread(9);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = CreateThread (doNothing, 1); 
  t = CreateThread (doNothing, 2); 
  t = CreateThread (doNothing, 3); 
  t = CreateThread (doNothing, 4); 
  t = CreateThread (doNothing, 5); 
  t = CreateThread (doNothing, 6); 
  t = CreateThread (doNothing, 7); 
  t = CreateThread (doNothing, 8); 
  t = CreateThread (doNothing, 9); 

  //Yield from 0 to 8
  YieldThread(8);

  //once all 9 threads finish, we're back in thread 0, where we create 9 threads
  t = CreateThread (doNothing, 1); 
  t = CreateThread (doNothing, 2); 
  t = CreateThread (doNothing, 3); 
  t = CreateThread (doNothing, 4); 
  t = CreateThread (doNothing, 5); 
  t = CreateThread (doNothing, 6); 
  t = CreateThread (doNothing, 7); 
  t = CreateThread (doNothing, 8); 
  t = CreateThread (doNothing, 9); 

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
  /*
  if(x==4){
    YieldThread("8");
  }
  Printf("\n%d\n",x);
  */
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

