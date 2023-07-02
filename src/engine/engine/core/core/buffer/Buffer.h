#pragma once

#include <stdint.h>

#include <cstring>

namespace zong
{
namespace core
{

// Non-owning raw buffer class
struct Buffer
{
    // TODO: add inline get
    uint8_t* _data = nullptr;
    uint64_t _size = 0;

    Buffer() = default;
    Buffer(uint64_t size) { allocate(size); }
    Buffer(Buffer const&) = default;

    static Buffer Copy(Buffer other) // deep copy
    {
        Buffer result(other._size);
        memcpy(result._data, other._data, other._size);
        return result;
    }

    void allocate(uint64_t size)
    {
        release();

        _data = new uint8_t[size];
        _size = size;
    }

    void release()
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
    }

    template <typename T>
    T* as()
    {
        return static_cast<T*>(_data);
    }

    operator bool() const { return static_cast<bool>(_data); }
};

struct ScopedBuffer
{
private:
    Buffer _buffer;

public:
    uint8_t* Data() { return _buffer._data; }
    uint64_t Size() { return _buffer._size; }

public:
    ScopedBuffer(Buffer buffer) : _buffer(buffer) {}
    ScopedBuffer(uint64_t size) : _buffer(size) {}
    ~ScopedBuffer() { _buffer.release(); }

    template <typename T>
    T* as()
    {
        return _buffer.as<T>();
    }

    operator bool() const { return _buffer; }
};

} // namespace core
} // namespace zong