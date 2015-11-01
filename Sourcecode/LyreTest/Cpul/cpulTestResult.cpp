#include "LyreTest/cpul/cpulTestResult.h"
#include "LyreTest/cpul/cpulFailure.h"
#include <iostream>

TestResult::TestResult()
:
    failureCount (0)
{
}

void TestResult::testWasRun()
{
}

void TestResult::startTests ()
{
}

void TestResult::addFailure (Failure failure)
{
    std::cout << failure << std::endl;
    failureCount++;
}

void TestResult::endTests ()
{
}

int TestResult::getFailureCount() const
{
    return failureCount;
}
