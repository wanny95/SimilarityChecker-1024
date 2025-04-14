#include <string>

using std::string;

class SimilarityChecker {
public:
	int getLengthScore(string firstStr, string secondStr) {
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

	double getLongShortString(int firstStrLength, int secondStrLength, int& longStrLength, int& shortStrLength)
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
};