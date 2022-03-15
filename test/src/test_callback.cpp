#include <gtest/gtest.h>

#include "kvn_safe_callback.hpp"

// TODO: Multithreading tests need to be implemented.

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

TEST(SafeCallbackTest, ExplicitBool) {
    kvn::safe_callback<void(void)> callback_void;

    if (callback_void) {
        FAIL() << "Uninitialized callback should not be true.";
    }

    callback_void.load([](void) {});

    if (!callback_void) {
        FAIL() << "Initialized callback should be true.";
    }
}

// Uncomment the following lines to test if non default constructible classes
// are correctly identified.
/*
class NonDefaultConstructible {
 public:
  NonDefaultConstructible(int) {}
};

TEST(SafeCallbackTest, NonDefaultConstructible) {
    kvn::safe_callback<NonDefaultConstructible(void)> callback;
    auto value = callback();
}
*/
