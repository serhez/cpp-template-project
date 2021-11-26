#ifndef TEMPLATE_HPP //TODO : Change
#define TEMPLATE_HPP //TODO : Change

#include <vector>

namespace example
{
    // IGNORE
    class BaseClass
    {
    public:
        BaseClass(int x) {}
    };
    // END IGNORE

    /**
 * @brief Docs
 */
    class ExampleClass : public example::BaseClass
    {
    public:
        /**
         * @CONSTANT_EXAMPLE An example constant
         */
        static constexpr int EXAMPLE_CONSTANT = 1;

        /**
         * @brief Instantiates an ExampleClass
         *
         * @param arg1 The first argument
         * @param arg2 The second argument
         */
        ExampleClass(const int arg1, const int arg2);

        /**
         * @brief An example pure virtual method
         *
         * @param arg1 The first argument
         * @param arg2 The second argument
         * @return The result
         */
        virtual int examplePureVirtualMethod(const int arg1, const int arg2) const = 0;

        /**
         * @brief An example method
         *
         * @param arg The argument
         * @return The result
         */
        int exampleMethod(const int arg);

        /**
         * @brief An inline method (e.g., a getter)
         *
         * @return The result
         */
        int inlineMethod() const { return 0; }

    private:
        /**
         * @m_var Some private(member) variable
         */
        const int m_var;
    };

} // namespace example

#endif
