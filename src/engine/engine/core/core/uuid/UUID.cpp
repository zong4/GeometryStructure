#include "UUID.h"

#include <random>
#include <unordered_map>

namespace zong
{

static std::random_device                      RandomDevice;
static std::mt19937_64                         Engine(RandomDevice());
static std::uniform_int_distribution<uint64_t> UniformDistribution;

} // namespace zong

zong::UUID::UUID() : _uuid(UniformDistribution(Engine))
{
}
