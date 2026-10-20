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
    result=callfunc(in_order,x,y,z); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 
void test_Zero()
{ 
    run_test( 0, 0, 0, 0); 
}

void test_OneA()
{ 
    run_test( 1, 0, -1, 1); 

}

void test_OneB()
{ 
    run_test( 0, 1, 0, 0); 

}

void test_Minus()
{ 
    run_test( -1000, -500,-50, 0); 
}
void test_MinusA()
{ 
    run_test( -1000, -50000,-60000, 1); 
}

void test_Big()
{ 
    run_test( 150000, 50000,10, 1); 
}

void test_Big2()
{ 
    run_test( 1500001, 1500002, 0, 0); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_Minus);
    RUN_TEST(test_MinusA);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






