#include <gtest/gtest.h>

#include "kvn_safe_callback.h"

TEST(SafeCallbackTest, CallWithIntReturnVoid) {
    int destination = 0;

    kvn::safe_callback<void(int)> callback;
    callback.load([&](int value) { destination = value; });

    callback(42);
    ASSERT_EQ(destination, 42);
}

TEST(SafeCallbackTest, CallWithVoidReturnInt) {
    int destination = 0;

    kvn::safe_callback<int(void)> callback;
    callback.load([&]() -> int { return 42; });

    destination = callback();
    ASSERT_EQ(destination, 42);
}
