#pragma once

#include <memory>
#include <string>
#include <functional>
#include <type_traits>
#include <sstream>
#include "log.h"

#ifdef HZ_PLATFORM_LINUX
    #include "window.h"
#endif