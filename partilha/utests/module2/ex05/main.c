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



void run_test(int x,  int y, int expected_res )
{
    int result; 
    result=callfunc(parallel,x,y); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 
void test_One()
{ 
    run_test( 2, 2, 1); 

}

void test_OneA()
{ 
    run_test( 10, 5, 3); 

}

void test_OneB()
{ 
    run_test( 5, 10, 3); 

}

void test_OneC()
{ 
    run_test( 20, 30, 12); 

}

void test_Big()
{ 
    run_test( 5000, 5000, 2500); 

}

void test_Big2()
{ 
    run_test( 50000, 10000, 8333); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_One);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_OneC);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






