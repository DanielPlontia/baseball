#include "pch.h"
#include "../Project7/baseball.cpp"
#include <stdexcept>

class BaseballFixture : public testing::Test {
public:
    Baseball game;
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
        // game.guess() ���� ��, Exception�� �߻��ؾ� PASS �̴�.
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
}