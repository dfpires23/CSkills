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
// this could be much better !!! 
void run_test(int x,  int y, int expected_res )
{
    int result; 
    result=callfunc(f,x,y); 
    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 

void run_test2(int x,  int y, int expected_res )
{
    int result; 
    result=callfunc(f2,x,y); 
    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 

void run_test3(int x,  int y, int expected_res )
{
    int result; 
    result=callfunc(f3,x,y); 
    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 
void run_test4(int x,  int y, int expected_res )
{
    int result; 
    result=callfunc(f4,x,y); 
    TEST_ASSERT_EQUAL_INT(expected_res,result); 
} 

void test_Zero()
{ 
    run_test(0, 0, 1); 
}
void test_OneA()
{ 
    run_test(1, 1, 1); 
}
void test_OneB()
{ 
    run_test(0, 1, 0); 
}
void test_Minus()
{ 
    run_test(-1000, -500, -1501); 
}
void test_MinusA()
{ 
    run_test(-1000, -50000, -51001); 
}
void test_Big()
{ 
    run_test(15000, 5000, 19999); 
}
void test_BigB()
{ 
    run_test(150001, 50000, 200000); 
}

void test_Zero2()
{ 
    run_test2(0, 0, 0); 
}
void test_OneA2()
{ 
    run_test2(1, 1, 2); 
}
void test_OneB2()
{ 
    run_test2(0, 1, 0); 
}
void test_Minus2()
{ 
    run_test2(-1000, -500, 499000); 
}
void test_MinusA2()
{ 
    run_test2(-1000, -50000, 50050000); 
}
void test_Big2()
{ 
    run_test2(15000, 5000, 74995000); 
}
void test_BigB2()
{ 
    run_test2(150001, 50000, -1089934592); 
}


void test_Zero3()
{ 
    run_test3(0, 0, -1); 
}
void test_OneA3()
{ 
    run_test3(1, 1, 2); 
}
void test_OneB3()
{ 
    run_test3(0, 1, 3); 
}
void test_Minus3()
{ 
    run_test3(-1000, -500, 0); 
}
void test_MinusA3()
{ 
    run_test3(-1000, -50000, 0); 
}
void test_Big3()
{ 
    run_test3(15000, 5000, 0); 
}
void test_BigB3()
{ 
    run_test3(150001, 50000, 0); 
}

void test_Zero4()
{ 
    run_test4(0, 0, 0); 
}
void test_OneA4()
{ 
    run_test4(1, 1, 4); 
}
void test_OneB4()
{ 
    run_test4(0, 1, 0); 
}
void test_Minus4()
{ 
    run_test4(-1000, -500, 4000000); 
}
void test_MinusA4()
{ 
    run_test4(-1000, -50000, 4000000); 
}
void test_Big4()
{ 
    run_test4(15000, 5000, 8333333); 
}
void test_BigB4()
{ 
    run_test4(150001, 50000, -598322432); 
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
    RUN_TEST(test_BigB);
    RUN_TEST(test_Zero2);
    RUN_TEST(test_OneA2);
    RUN_TEST(test_OneB2);
    RUN_TEST(test_Minus2);
    RUN_TEST(test_MinusA2);
    RUN_TEST(test_Big2);
    RUN_TEST(test_BigB2);
    RUN_TEST(test_Zero3);
    RUN_TEST(test_OneA3);
    RUN_TEST(test_OneB3);
    RUN_TEST(test_Minus3);
    RUN_TEST(test_MinusA3);
    RUN_TEST(test_Big3);
    RUN_TEST(test_BigB3);
    RUN_TEST(test_Zero4);
    RUN_TEST(test_OneA4);
    RUN_TEST(test_OneB4);
    RUN_TEST(test_Minus4);
    RUN_TEST(test_MinusA4);
    RUN_TEST(test_Big4);
    RUN_TEST(test_BigB4);
    return UNITY_END();  

  } 






