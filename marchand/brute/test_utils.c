#include "../../Unity-master/src/unity.h"
#include "utils.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_ListMaxIndex_with_ShortTable(void)
{
    int tab1[3]={5,4,9};
TEST_ASSERT_EQUAL(2, list_max_index(tab1,3));
    int tab2[0];
TEST_ASSERT_EQUAL(-1, list_max_index(tab2,0));
    int tab3[10]={9,8,7,6,5,4,3,2,1,0};
TEST_ASSERT_EQUAL(0, list_max_index(tab3,10));
}

void test_AverageThreeBytes_with_BiggerTable(void)
{
    int tab4[15]={5,4,9,0,0,0,0,0,0,0,0,0,0,0,10};
TEST_ASSERT_EQUAL(14, list_max_index(tab4,15));
    int tab5[15]={-5,-4,-9,0,0,0,0,0,0,0,0,0,0,0,-10};
TEST_ASSERT_EQUAL(3, list_max_index(tab5,15));
}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_ListMaxIndex_with_ShortTable);
RUN_TEST(test_AverageThreeBytes_with_BiggerTable);
return UNITY_END();
}

//gcc test_utils.c utils.c ../../Unity-master/src/unity.c -o Test_utils
//./Test_utils