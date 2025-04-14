#include "gmock/gmock.h"
#include <string>
#include "SimilarityChecker.cpp"

using std::string;

class SimilarityFixture : public ::testing::Test {
public:
	SimilarityChecker sc;

	int getSimilarityLengthScore(string firstStr, string secondStr) {
		return sc.getLengthScore(firstStr, secondStr);
	}

	int getSimilarityAlphabetScore(string firstStr, string secondStr) {
		return sc.getSimilarityAlphabetScore(firstStr, secondStr);
	}
};

TEST_F(SimilarityFixture, TC1) {
	int actual = getSimilarityLengthScore("ABCDE", "ABCDE");

	EXPECT_EQ(60, actual);
}

TEST_F(SimilarityFixture, TC2) {
	int actual = getSimilarityLengthScore("ABCD", "ABCDE");

	EXPECT_EQ(45, actual);
}

TEST_F(SimilarityFixture, TC3) {
	int actual = getSimilarityLengthScore("AB", "ABCDE");

	EXPECT_EQ(0, actual);
}

TEST_F(SimilarityFixture, TC4) {
	int actual = getSimilarityLengthScore("AB", "ABCD");

	EXPECT_EQ(0, actual);
}

TEST_F(SimilarityFixture, TC5) {
	int actual = getSimilarityAlphabetScore("ASD", "DSA");

	EXPECT_EQ(40, actual);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}