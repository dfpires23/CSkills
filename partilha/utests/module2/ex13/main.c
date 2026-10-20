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



void run_test(int len1,  int len2, int height, int expected_res )
{
    int result; 
    result=callfunc(get_area,len1,len2,height); 

    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 


void test_Zero()
{
    run_test(0, 0, 0, 0);
}

void test_OneA()
{
    run_test(4, 2, 2, 6);
}

void test_OneB()
{
    run_test(5, 6, 5, 27);
}

void test_OneC()
{
	 run_test( 800, 70, 45, 19575);

}

void test_MinusA()
{
    run_test( 3, 5, 7, 28);
}

void test_MinusB()
{
    run_test( 1000, 1500, 1000, 1250000);
}

void test_Big()
{
   run_test(5000, 2000, 50,  175000);

}

void test_Big2()
{
   run_test(5000, 50, 80, 202000);

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






