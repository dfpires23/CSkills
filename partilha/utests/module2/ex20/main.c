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



void run_test(int current_salary,  int code, int expected_res )
{
    int result; 
    result=callfunc(new_salary,current_salary,code); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 


void test_Zero()
{
    run_test(0, 0, 250);
}

void test_OneA()
{
    run_test(0, 10, 500);
}

void test_OneB()
{
    run_test(0, 11, 400);
}

void test_OneC()
{
    run_test( 0, 12, 300);
}

void test_MinusA()
{
    run_test( 1000,15, 1250);
}

void test_MinusB()
{
    run_test( 1000, 12, 1300);
}

void test_Big()
{
   run_test( 1000, 11, 1400);

}

void test_Big2()
{
   run_test(1000, 10,  1500);

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








