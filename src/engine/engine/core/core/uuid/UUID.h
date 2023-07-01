#pragma once

namespace zong
{

class UUID
{
private:
    uint64_t _uuid;

public:
    UUID();
    UUID(uint64_t uuid) : _uuid(uuid) {}

    inline operator uint64_t() const { return _uuid; }
};

} // namespace zong

namespace std
{
template <typename T>
struct hash;

template <>
struct hash<zong::UUID>
{
    std::size_t operator()(zong::UUID const& uuid) const { return (uint64_t)uuid; }
};

} // namespace std
