#pragma once

#ifdef BUILD_MYLIB_SO
#define MYLIB_API __attribute__ ((visibility("default")))
#else
#define MYLIB_API
#endif

namespace hezel {
    MYLIB_API void Print();
}