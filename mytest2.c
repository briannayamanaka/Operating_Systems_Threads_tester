#include "aux.h"
#include "umix.h"
#include "mykernel4.h"

#define NUMYIELDS 5

static int square, cube;  // global variables, shared by threads

void Main ()
{
  int i, t, me; 
  void printSquares (), printCubes (); 

  MyInitThreads (); 

  me = GetThread (); 
  t = CreateThread (printSquares, me);
  t = CreateThread (printCubes, t); 
  t = MyCreateThread (printSquares, t); 
  t = MyCreateThread (printSquares, t); 
  t = MyCreateThread (printSquares, t); 
  t = MyCreateThread (printSquares, t); 
  t = MyCreateThread (printSquares, t); 


  for (i = 0; i < NUMYIELDS; i++) {
    MyYieldThread (t);
    Printf ("T%d: square = %d, cube = %d\n", me, square, cube);
  }

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

