#!/bin/bash
#echo "hey"

make -f Makefile
echo
echo
echo
echo "compiled all files"
echo
echo
echo
echo "running tests"
echo
echo
echo

################# test1 ######################
#put expected results in a file
./test1 > r1

#put actual results in a file
./mytest1 > myr1

#remove first line from files
echo "$(tail +2 r1)" > r1
echo "$(tail +2 myr1)" > myr1

#compare the expected with actual
echo "***** Test1 *****"
if cmp -s r1 myr1
then
   echo "PASS"
else
   echo "FAIL"
   diff -C 100 r1 myr1 > failure_test1
fi


################# test2 ######################
#put expected results in a file
./test2 > r2
#put actual results in a file
./mytest2 > myr2

#remove first line from files
echo "$(tail +2 r2)" > r2
echo "$(tail +2 myr2)" > myr2

#compare the expected with actual
echo "***** Test2 *****"
if cmp -s r2 myr2
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r2 myr2 > failure_test2
fi


################# test3 ######################
#put expected results in a file
./test3 > r3
#put actual results in a file
./mytest3 > myr3

#remove first line from files
echo "$(tail +2 r3)" > r3
echo "$(tail +2 myr3)" > myr3

#compare the expected with actual
echo "***** Test3 *****"
if cmp -s r3 myr3
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r3 myr3 > failure_test3
fi


################# test4 ######################
#put expected results in a file
./test4 > r4
#put actual results in a file
./mytest4 > myr4

#remove first line from files
echo "$(tail +2 r4)" > r4
echo "$(tail +2 myr4)" > myr4

#compare the expected with actual
echo "***** Test4 *****"
if cmp -s r4 myr4
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r4 myr4 > failure_test4

fi



################# test4 ######################
#put expected results in a file
./test5 > r5
#put actual results in a file
./mytest5 > myr5

#remove first line from files
echo "$(tail +2 r5)" > r5
echo "$(tail +2 myr5)" > myr5

#compare the expected with actual
echo "***** Test5 *****"
if cmp -s r5 myr5
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r5 myr5 > failure_test5
fi
