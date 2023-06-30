#pragma once

#include <type_traits>

namespace zong
{
namespace util
{

template <typename value_type>
concept IsNumber = std::is_same_v<value_type, int> || std::is_same_v<value_type, double>; // TODO: type union

} // namespace util
} // namespace zong