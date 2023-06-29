#include <core/geometry/geometry/Point.h>
#include <core/log/log.h>
#include <gtest/gtest.h>

int main()
{
    zong::common::Log::init();
    ZONG_CORE_TRACE("start test");

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(Hello, hello)
{
    EXPECT_TRUE("hello" == std::string("hello"));
}