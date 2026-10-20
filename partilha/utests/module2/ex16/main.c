#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

int callfunc(int (*f)(int x),int x);


void setUp(void) {
    // set stuff up here
     
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x,int expected_res )
{
    int result; 
    result=callfunc(steps,x); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 

void test_Zero()
{ 
    run_test(0, 10); 
}

void test_One()
{ 
    run_test(1, 10); 
}

void test_Two()
{ 
    run_test(2, 10); 
}

void test_Eight()
{ 
    run_test( 800, 10); 
}

void test_MinusA()
{ 
    run_test( -1, 10); 
}

void test_MinusB()
{ 
    run_test( -1000,  10); 
}

void test_Big()
{ 
   run_test(50,  10); 
}

void test_Big2()
{ 
   run_test(50000,  10); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Eight);
    RUN_TEST(test_MinusA);
    RUN_TEST(test_MinusB);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






