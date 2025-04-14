#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;

class SimilarityChecker {
public:
	int getSimilarityScore(const string& firstStr, const string& secondStr) const {
		return getLengthScore(firstStr, secondStr) + getAlphabetScore(firstStr, secondStr);
	}

	int getLengthScore(const string& firstStr, const string& secondStr) const {
		int firstStrLength = firstStr.length();
		int secondStrLength = secondStr.length();

		double gap = 0;
		int longStrLength = 0;
		int shortStrLength = 0;

		gap = getLongShortString(firstStrLength, secondStrLength, longStrLength, shortStrLength);

		if (longStrLength >= shortStrLength * 2)
			return 0;

		int result = (1 - (gap / shortStrLength)) * 60;
		result = result >= 0 ? result : 0;
		return result;
	}

	int getAlphabetScore(const string& firstStr, const string& secondStr) const {
		set<char> firstStringSet = getUniqueSet(firstStr);
		set<char> secondStringSet = getUniqueSet(secondStr);

		set<char> totalStringSet = getTotalAlphabetSet(firstStringSet, secondStringSet);

		int totalCount = totalStringSet.size();
		int sameCount = 0;

		for (char ch : firstStringSet) {
			if (secondStringSet.count(ch) > 0) ++sameCount;
		}

		return ((double)(sameCount)) / totalCount * 40;
	}

private:
	double getLongShortString(int firstStrLength, int secondStrLength, int& longStrLength, int& shortStrLength) const
	{
		double gap = 0;
		if (firstStrLength >= secondStrLength) {
			gap = firstStrLength - secondStrLength;
			longStrLength = firstStrLength;
			shortStrLength = secondStrLength;
		}
		else {
			gap = secondStrLength - firstStrLength;
			longStrLength = secondStrLength;
			shortStrLength = firstStrLength;
		}
		return gap;
	}

	set<char> getUniqueSet(const string& firstStr) const {
		set<char> stringSet;

		for (auto ch : firstStr) {
			stringSet.insert(ch);
		}

		return stringSet;
	}

	set<char> getTotalAlphabetSet(const set<char>& firstStrSet, const set<char>& secondStrSet) const {
		set<char> totalStringSet = firstStrSet;
		totalStringSet.insert(secondStrSet.begin(), secondStrSet.end());
		return totalStringSet;
	}
};