#include "pch.h"
#include "../Project7/baseball.cpp"
#include <stdexcept>

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
    Baseball game;
    EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}