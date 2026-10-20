#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

long long callfunc(long long (*f)(long long x, long long y),long long x, long long y);


void setUp(void) {
    // set stuff up here
     
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(long long x,  long long y, long long expected_sum )
{
    long long result; 
    result=callfunc(big_sum,x,y); 

    TEST_ASSERT_EQUAL_INT64(expected_sum,result); 
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
    run_test( -1LL, -1LL, -2LL); 

}

void test_Big()
{ 
    run_test( 50000000, 50000000, 100000000); 

}

void test_Big2()
{ 
    run_test( 5000000000LL, 600000000LL, 5600000000LL); 

}

void test_Picky1()
{ 
    run_test( -1LL, 0, -1LL); 
}

void test_Picky2()
{ 
    run_test( 0, -1LL, -1LL); 
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
    RUN_TEST(test_Picky1);
    RUN_TEST(test_Picky2);
    return UNITY_END();  

  } 






