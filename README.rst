Safe Callback
==========

A wrapper around std::function with some thread-safety guarantees.

Overview
--------

This library was conceived to solve the problem of using callbacks in systems
where objects can be destroyed while a callback is still pending or running,
which can happen in multithreaded applications and will lead to a crash.

This library is header-only and does not depend on any other library, so feel
free to just copy it into your project or append the `include` directory to
your project's include path.

If you need help using this library, **please do not hesitate to reach out!**

* Contact me: ``kevin at dewald dot me``

Usage
-----

The following code briefly describes how to use the safe callback.::

    #include <kvn_safe_callback.hpp>

    // Create a callback wrapper
    kvn::safe_callback<int(int)> cb;

    // Load a lambda function into the callback wrapper
    cb.load([] (int i) -> int {
        std::cout << "Callback called with " << i << std::endl;
        return i * 2;
    });

    // Call the callback and print the result
    int result = cb(42);
    std::cout << "Result: " << result << std::endl;

A few notes that need to be highlighted on the behavior of the safe callback:

* If the callback wrapper is not loaded, attempting to call the callback will
  be a no-op.
* In the cases where the callback wrapper is not loaded and the internal function
  returns a value, the return value will be the default value of the return type.
  This means that all return types need to be default constructible.

License
-------

All components within this project that have not been bundled from
external creators, are licensed under the terms of the `MIT Licence`_.

.. Links

.. _MIT Licence: LICENCE.md
