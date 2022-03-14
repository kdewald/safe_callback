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

License
-------

All components within this project that have not been bundled from
external creators, are licensed under the terms of the `MIT Licence`_.

.. Links

.. _MIT Licence: LICENCE.md
