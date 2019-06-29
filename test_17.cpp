#include <string>
#include <gtest/gtest.h>

using namespace std;

char ** letterCombinations(char * digits, int* returnSize);

TEST(Combination, letter_23) {
    int returnSize = 0;
    char **result = letterCombinations((char*)"23", &returnSize);
    //abc def
    string compare[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    for (auto i = 0; i < returnSize; ++i) {
        EXPECT_STREQ(compare[i].c_str(), result[i]);
    }
    EXPECT_EQ(returnSize, 9);
}

TEST(Combination, letter_null) {
    int returnSize = 0;
    char **result = letterCombinations((char*)"", &returnSize);
    ASSERT_STREQ(*result, nullptr);
    EXPECT_EQ(returnSize, 0);
}

int main() {
    testing::InitGoogleTest();
    printf("test: %d\n", RUN_ALL_TESTS());
    return 0;
}
