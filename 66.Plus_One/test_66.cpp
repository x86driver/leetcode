#define GTEST_LINKED_AS_SHARED_LIBRARY
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

int* plusOne(int* digits, int digitsSize, int* returnSize);

TEST(normal, normal) {
    int digits[] = {1, 2, 3};
    int returnSize = 0;
    int *results = plusOne(digits, sizeof(digits)/sizeof(int), &returnSize);
    EXPECT_EQ(returnSize, 3);
    vector<int> r(results, results + returnSize);
    EXPECT_THAT(r, ElementsAre(1, 2, 4));
    free(results);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    printf("test: %d\n", RUN_ALL_TESTS());
    return 0;
}
