#include <engine/engine.h>
#include <gtest/gtest.h>

int main()
{
    ZONG_CORE_TRACE("start test");

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(Hello, hello)
{
    EXPECT_TRUE("hello" == std::string("hello"));
}