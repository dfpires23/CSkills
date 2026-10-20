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



void run_test(int x,  int y, int expected_sum )
{
    int result; 
    result=callfunc(sum,x,y); 

    TEST_ASSERT_EQUAL_INT(expected_sum,result); 
} 
void test_Zero()
{ 
    run_test( 0, 0, 0); 

}

void test_OneA()
{ 
    run_test( 1, 0, 1); 

}

void test_OneB()
{ 
    run_test( 0, 1, 1); 

}

void test_Minus()
{ 
    run_test( 0, -1, -1); 

}

void test_Big()
{ 
    run_test( 5000, 5000, 10000); 

}

void test_Big2()
{ 
    run_test( 50000, 50000, 100000); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_Minus);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






