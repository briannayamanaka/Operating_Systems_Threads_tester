# cse120_pa4
test cases

- files with names that start with "mytest" are tests that call YOUR implemented functions (actual results)
- files with names that start with "test" are tests that call GIVEN implemented functions (expected results)
- script.sh runs both and compares the two
- script.sh also cleans existing executables, recompiles everything, runs tests with your implementations, runs the same tests with the given implementations and compares the two
- PASS = no differences between the output of given functions and your implemented functions
- FAIL = differences between the output of given functions and your implemented functions
- every test additionally produces two files, expected output and actual output. for example, test1 produces r1 (expected output) and myr1 (actual output) these outputs are compared to check for correctness
- if you fail a test the failure gets put in a file called failure_test# so you can see what the differences between your functions and the given functions are
- the test script results will be a lot clearer if you comment out all your DPrint'f's
- the test script won't work if you have any additional Printf's apart from the ones that were given in the original code



---------------------------------------------------------------------------------------------------------------------------------------


1. add all files to pa4 directory
2. might have to add permissions to run script:
   %chmod 777 script.sh
3. run script:
   %./script.sh
