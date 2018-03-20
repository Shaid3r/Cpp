#include <iostream>
#include <string>

// OutputPolicy -- void print(const T& message)
// LanguagePolicy -- T message()
template <typename OutputPolicy, typename LanguagePolicy>
class HelloWorld : private OutputPolicy, private LanguagePolicy
{
    using OutputPolicy::print;
    using LanguagePolicy::message;

public:
    // Behaviour method
    void run() const
    {
        // Two policy methods
        print(message());
    }
};

class OutputPolicyWriteToCout
{
protected:
    template<typename MessageType>
    void print(const MessageType &message) const
    {
        std::cout << message << std::endl;
    }
};

class LanguagePolicyEnglish
{
protected:
    std::string message() const
    {
        return "Hello, World!";
    }
};

class LanguagePolicyGerman
{
protected:
    std::string message() const
    {
        return "Hallo Welt!";
    }
};

int main()
{
    using HelloWorldEnglish = HelloWorld<OutputPolicyWriteToCout, LanguagePolicyEnglish>;

    HelloWorldEnglish hello_world;
    hello_world.run(); // "Hello, World!"

    using  HelloWorldGerman = HelloWorld<OutputPolicyWriteToCout, LanguagePolicyGerman>;

    HelloWorldGerman hello_world2;
    hello_world2.run(); // "Hallo Welt!"
}
