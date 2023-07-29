#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <future>
#include <sched.h>

#include "pipeline/pipeline.hpp"

class topLevelManager
{
public:
    Pipeline* localPipeline;
    topLevelManager();

private:
    void detectHWAndConfig();
    void setupThreads();
};