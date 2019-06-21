#include "TestSplayTree.hpp"
#include <string>
#include <cstdlib>

static bool CORRECTLY_FINISHED = false;

void ExitCall();

void TerminateCall();

int main(/*int argc, const char *argv[]*/)
{
    std::atexit(&ExitCall);
    std::set_terminate(TerminateCall);
    try
    {
        if (UnitTests::SPLAYTREE::SplayTreeUnitTests())
        {
            std::cout << "\nAll Unit Tests passed." << std::endl;
            CORRECTLY_FINISHED = true;
            return 0;
        }
        else
        {
            std::cout << "\nUnit tests failed on one or more tests." << std::endl;
            std::cout << "Please note that all tests must pass for your submission to be assessed." << std::endl;
            CORRECTLY_FINISHED = true;
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "\nUnit tests failed with an unexpected exception. Error message: " << e.what() << '\n';
        std::cout << "Please note that all tests must pass for your submission to be assessed." << std::endl;
        CORRECTLY_FINISHED = true;
        return 2;
    }
    catch (...)
    {
        std::cout << "\nUnit tests failed with an unexpected exception." << '\n';
        std::cout << "Please note that all tests must pass for your submission to be assessed." << std::endl;
        CORRECTLY_FINISHED = true;
        return 2;
    }
}

void ExitCall()
{
    if (!CORRECTLY_FINISHED)
        throw std::runtime_error("\tUsing exit/abort-call to circumvent the Unit Tests is not a reasonable approach!\n");
}

void TerminateCall()
{
    if(!CORRECTLY_FINISHED)
    {
        std::cout << "\tUsing exit/terminate-call to circumvent the Unit Tests is not a reasonable approach!" << std::endl;
        std::cout << "\tPlease note: This error also show up on ctrl-c and other \"early exit\" methodologies during development. Those are a-okay!" << std::endl;
        CORRECTLY_FINISHED = true;
        exit(1);
    }
}
