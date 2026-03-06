#include <gtest/gtest.h>

namespace phosphor::logging
{
void cleanupBMCPosTestDir();
} // namespace phosphor::logging

namespace phosphor::logging::test
{

/**
 * @brief GoogleTest Environment for BMC position test cleanup
 *
 *  This environment ensures that the temporary BMC position test directory
 *  is cleaned up when tests complete. GoogleTest calls the destructor of
 *  Environment objects during test teardown.
 */
class BMCPosTestEnvironment : public ::testing::Environment
{
  public:
    ~BMCPosTestEnvironment() override
    {
        phosphor::logging::cleanupBMCPosTestDir();
    }
};

/**
 * @brief Static initializer to register the test environment
 */
static struct EnvironmentRegistrar
{
    EnvironmentRegistrar()
    {
        ::testing::AddGlobalTestEnvironment(new BMCPosTestEnvironment);
    }
} envRegistrar;

} // namespace phosphor::logging::test
