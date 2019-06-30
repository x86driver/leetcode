#include <string>
#include <gtest/gtest.h>

using namespace std;

char *longestPalindrome(char *s);
char *longestPalindrome(const char *s) {
    return longestPalindrome((char*)s);
}

TEST(Palindromic, string_cbbd) {
    EXPECT_STREQ(longestPalindrome("cbbd"), "bb");
}

TEST(Palindromic, string_abacdfgdcaba) {
    EXPECT_STREQ(longestPalindrome("abacdfgdcaba"), "aba");
}

TEST(Palindromic, string_null) {
    EXPECT_STREQ(longestPalindrome(""), "");
}

TEST(Palindromic, string_a) {
    EXPECT_STREQ(longestPalindrome("a"), "a");
}

TEST(Palindromic, string_ab) {
    EXPECT_STREQ(longestPalindrome("ab"), "a");
}

TEST(Palindromic, string_abc) {
    EXPECT_STREQ(longestPalindrome("a"), "a");
}

TEST(Palindromic, string_aaa) {
    EXPECT_STREQ(longestPalindrome("aaa"), "aaa");
}

int main() {
    testing::InitGoogleTest();
    printf("test: %d\n", RUN_ALL_TESTS());
    return 0;
}
