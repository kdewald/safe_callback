#pragma once

#include <atomic>
#include <functional>
#include <memory>
#include <mutex>

namespace kvn {

template <typename _Signature>
class safe_callback;

template <class _Res, class... _ArgTypes>
class safe_callback<_Res(_ArgTypes...)> {
  public:
    void load(std::function<_Res(_ArgTypes...)> callback) {
        std::scoped_lock{_mutex};
        _callback = callback;
        if (callback != nullptr) {
            _is_loaded = true;
        }
    }

    void unload() {
        std::scoped_lock{_mutex};
        _callback = nullptr;
        _is_loaded = false;
    }

    bool is_loaded() { return _is_loaded; }

    _Res operator()(_ArgTypes... arguments) {
        if (_is_loaded) {
            std::scoped_lock{_mutex};
            return _callback(arguments...);
        } else {
            return _Res();
        }
    }

  protected:
    std::atomic_bool _is_loaded{false};
    std::function<_Res(_ArgTypes...)> _callback;
    std::recursive_mutex _mutex;
};

}  // namespace kvn
