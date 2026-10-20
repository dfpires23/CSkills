#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

int callfunc(int (*f)(int x, int y),int x, int y);


void setUp(void) {
    // set stuff up here
     
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int expected_res )
{
    int result; 
    result=callfunc(needed_time,x,y); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 


void test_Zero()
{
    run_test(0, 0, 0);
}

void test_OneA()
{
    run_test(0, 10, 30*60);
}

void test_OneB()
{
    run_test(2, 3, 3*60);
}

void test_OneC()
{
    run_test( -2, -1, 3*60);
}

void test_MinusA()
{
    run_test( 5, 3, 8*60);
}

void test_MinusB()
{
    run_test( 5, -5, 40*60);
}

void test_Big()
{
   run_test(50, 100, 150*60);

}

void test_Big2()
{
   run_test(5, 55, 150*60);

}


int main()
  {

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_OneC);
    RUN_TEST(test_MinusA);
    RUN_TEST(test_MinusB);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();

  }








