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
    result=callfunc(sigma,x); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 

void test_Zero()
{ 
    run_test(0, 0); 

}

void test_One()
{ 
    run_test( 1,6); 

}

void test_Two()
{ 
    run_test(2, 33 ); 

}

void test_Minus()
{ 
    run_test( -10, 0); 

}

void test_Big()
{ 
   run_test(22,25616 ); 

}

void test_Big2()
{ 
   run_test( 33,84570); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Minus);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






