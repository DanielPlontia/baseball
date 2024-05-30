#include <stdexcept>
using namespace std;
struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};
class Baseball {
public:
    const int maxDigitCount = 3;
    explicit Baseball(const string& question)
        : question{ question } {}

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
        int strikes = countStrikes(guessNumber);
        return {checkSolved(strikes), strikes, countBalls(guessNumber)};
    }
    int countStrikes(const string& guessNumber) {
        int strikes = 0;
        for (int number = 0; number < maxDigitCount; number++)
        {
            if (question[number] == guessNumber[number]) strikes++;
        }
        return strikes;
    }

    int countBalls(const string& guessNumber) {
        int balls = 0;
        if (question[0] == guessNumber[1] || question[0] == guessNumber[2]) balls++;
        if (question[1] == guessNumber[0] || question[1] == guessNumber[2]) balls++;
        if (question[2] == guessNumber[0] || question[2] == guessNumber[1]) balls++;
        return balls;
    }
    bool checkSolved(int strikes) {
        if (strikes == maxDigitCount) return true;
        return false;
    }

    void assertIllegalArgument(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3) {
            throw length_error("Must be three letters.");
        }
        for (char ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;
            throw invalid_argument("Must be Number");
        }
        if (isDuplicatedNumber(guessNumber)) {
            throw invalid_argument("Must not have the same number");
        }
    }
    bool isDuplicatedNumber(string guessNumber) {
        return (guessNumber[0] == guessNumber[1] || guessNumber[0] == guessNumber[2] || guessNumber[1] == guessNumber[2]);
    }
private:
    string question;
};