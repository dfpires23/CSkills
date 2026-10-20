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
    result=callfunc(six_packs,x); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 
void test_Zero()
{ 
    run_test( 0, 0); 
}
void test_OneA()
{ 
    run_test( 1, 1); 
}
void test_OneB()
{ 
    run_test( 6, 1); 
}
void test_OneC()
{ 
    run_test( 5, 1); 
}
void test_Big()
{ 
    run_test( 24, 4); 
}

void test_Big2()
{ 
    run_test( 25, 5); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_OneC);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






