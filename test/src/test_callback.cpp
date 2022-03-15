#include <gtest/gtest.h>

#include "kvn_safe_callback.hpp"

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

TEST(SafeCallbackTest, UninitializedCall) {
    kvn::safe_callback<void(void)> callback_void;
    kvn::safe_callback<int(void)> callback_int;

    // Unfortunately, there is not a clean way to test that the callbacks
    // are not called besides from attempting to run them and seeing if the
    // program crashes.
    callback_void();
    callback_int();
}
