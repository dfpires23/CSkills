#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

int callfunc(int (*f)(int x, int y, int z, int w),int x, int y, int z, int w);


void setUp(void) {
    // set stuff up here
     
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int a,  int b, int c, int d, int expected_res )
{
    int result; 
    result=callfunc(compute, a, b, c, d); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 



void test_Zero()
{ 
    run_test(0, 0, 0, 2, 0); 
}

void test_ZeroA()
{ 
    run_test(0, 0, 0, -2, 0); 
}

void test_Two()
{ 
    run_test(2, 2, 0, 2, 2); 
}

void test_Case1()
{ 
    run_test(8000, -8000, 40, -10, 6432000); 
}

void test_Case2()
{ 
    run_test(3000, -5000, 8000, 70, -557142); 
}

void test_Case3()
{ 
    run_test(1000, 1000, 1000, 10, 0); 
}

void test_Case4()
{ 
    run_test(50, 5, 50005, -9, 277777); 
}

void test_Case5()
{ 
    run_test(50000, -50, 6, 7, -400000); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_ZeroA);
    RUN_TEST(test_Two);
    RUN_TEST(test_Case1);
    RUN_TEST(test_Case2);
    RUN_TEST(test_Case3);
    RUN_TEST(test_Case4);
    RUN_TEST(test_Case5);
    return UNITY_END();  

  } 





