#ifndef LOGLIB_ASSERT_H
#define LOGLIB_ASSERT_H

#define ASSERT_2(cond, msg) __assert(cond, #cond, msg)
#define ASSERT_1(cond) __assert(cond, #cond)
#define ASSERT_0() __assert(false, '<nop>')


#define FUNC_ASSERT(_f1, _f2, _f3, ...) _f3
#define FUNC_RECOMPOSER(argsWithParentheses) FUNC_ASSERT argsWithParentheses
#define ASSERT_FROM_ARG_COUNT(...) FUNC_RECOMPOSER((__VA_ARGS__, ASSERT_2, ASSERT_1, ))
#define NO_ARG_EXPANDER() ,,ASSERT_0
#define MACRO_ASSERT(...) ASSERT_FROM_ARG_COUNT(NO_ARG_EXPANDER __VA_ARGS__ ())
#define ASSERT(...) MACRO_ASSERT(__VA_ARGS__)(__VA_ARGS__)



namespace loglibns {
}

#endif
