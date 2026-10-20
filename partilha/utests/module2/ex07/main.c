#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

int callfunc(int (*f)(int x, int y, int z),int x, int y, int z);


void setUp(void) {
    // set stuff up here
     
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x,  int y, int z, int expected_res )
{
    int result; 
    result=callfunc(my_remainder,x,y,z); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 
void test_Zero()
{ 
    run_test( 0, 0, 0, 0); 
}
void test_One()
{ 
    run_test( 0, 3, 2, 1); 
}
void test_OneA()
{ 
    run_test( 2, 1, 2, 1); 
}
void test_OneB()
{ 
    run_test( 10, 5, 4, 3); 
}
void test_OneC()
{ 
    run_test( 3, 12, 4, 3); 
}
void test_Big()
{ 
    run_test( 300, 300, 30,0); 
}
void test_Big2()
{ 
    run_test( 10000, 100099, 100, 99); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_OneC);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






