#ifndef TESTING_BASE_HPP
#define TESTING_BASE_HPP
/*******************************************************************
*						Here be Dragons
********************************************************************/

#include <type_traits>
#include <functional>
#include <cctype>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>

#define GENERATE_HAS_MEMBER_FUNCTION(functionName, memberFunction)                    \
    template <typename T, typename RESULT, typename... ARGS>                          \
    class has_##functionName                                                          \
    {                                                                                 \
        typedef std::true_type yes;                                                   \
        typedef std::false_type no;                                                   \
        template <typename U, RESULT (U::*)(ARGS...)>                                 \
        struct Check;                                                                 \
        template <typename U>                                                         \
        static yes func(Check<U, &U::memberFunction> *);                              \
        template <typename>                                                           \
        static no func(...);                                                          \
                                                                                      \
      public:                                                                         \
        typedef has_##functionName type;                                              \
        static constexpr bool value = std::is_same<decltype(func<T>(0)), yes>::value; \
    };

#define GENERATE_HAS_CONST_MEMBER_FUNCTION(functionName, memberFunction)              \
    template <typename T, typename RESULT, typename... ARGS>                          \
    class has_const_##functionName                                                    \
    {                                                                                 \
        typedef std::true_type yes;                                                   \
        typedef std::false_type no;                                                   \
        template <typename U, RESULT (U::*)(ARGS...) const>                           \
        struct Check;                                                                 \
        template <typename U>                                                         \
        static yes func(Check<U, &U::memberFunction> *);                              \
        template <typename>                                                           \
        static no func(...);                                                          \
                                                                                      \
      public:                                                                         \
        typedef has_const_##functionName type;                                        \
        static constexpr bool value = std::is_same<decltype(func<T>(0)), yes>::value; \
    };

#define GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(name) GENERATE_HAS_MEMBER_FUNCTION(name, name)
#define GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(name) GENERATE_HAS_CONST_MEMBER_FUNCTION(name, name)

/*
* 
*   Usage:
*       GENERATE_HAS_MEMBER_FUNCTION(generatedName, functionName) creates a template-based struct.
*       This struct can then be used as: has_generatedName<ClassToCheck, ExpectedReturnType, ArgType1, ArgType2,...>::value.       
*       If this value is true, then the ClassToCheck has a member method named functionName that matches the signature given.
*       The args can be empty.
*       To check for const functions, GENERATE_HAS_CONST_MEMBER_FUNCTION must be used.
*       For same generatedName and functionName, use GENERATE_SAME_NAME_HAS...
* 
*   Important!
*       This code will not be able to check for constructor, use is_constructible for this!
* 
* 
* 
* 
*/

bool TryCatchHelper(std::function<void()> Function, bool PassOnCatch, std::size_t &textIndentionLevel, std::string CurrentTest, std::string OnFailMessage)
{
    try
    {
        std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest << std::endl;
        Function();
        if(!PassOnCatch)
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest + " passed." << std::endl;
            return true;
        }
        else
        {
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest + " failed." << std::endl;
            std::cout << std::string(textIndentionLevel, '\t') + OnFailMessage << std::endl;
            --textIndentionLevel;
            return false;
        }
        
    }
    catch(const std::exception& e)
    {
        if(!PassOnCatch)
        {
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest + " caused exception with message \"" << e.what() << "\" to be thrown.\n";
            std::cout << std::string(textIndentionLevel, '\t') + OnFailMessage << std::endl;
            --textIndentionLevel;
            return false;
        }
        else
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest + " caused exception with message \"" << e.what() << "\" to be correctly thrown.\n";
            return true;                
        }
    }
    catch(...)
    {
        if(!PassOnCatch)
        {
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest + " caused exception to be thrown.\n";
            std::cout << std::string(textIndentionLevel, '\t') + OnFailMessage << std::endl;
            --textIndentionLevel;
            return false;
        }
        else
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Calling " + CurrentTest + " caused exception to be correctly thrown.\n";
            return true;                
        }
    }
}


#endif