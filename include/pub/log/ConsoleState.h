#ifndef H3090285C_852A_47FB_89A9_DD944AAC9611
#define H3090285C_852A_47FB_89A9_DD944AAC9611

#include "pub/base/Types.h"

#include <iostream>


////////////////////////////////////////////////////////
struct ConsoleState
{
   bool isColorful() const
   {
      return colorful;
   }

protected:
   ConsoleState(bool c)
      : colorful(c)
   {}

private:
   bool colorful;
};

////////////////////////////////////////////////////////
#define DEF_COLOR_STATE(state)                       \
struct state :  ConsoleState                         \
{                                                    \
   state(bool colorful) : ConsoleState(colorful)     \
   {}                                                \
};                                                   \
std::ostream& operator<<(std::ostream& os, const state& succ);

////////////////////////////////////////////////////////
DEF_COLOR_STATE(SuccState)
DEF_COLOR_STATE(FailState)
DEF_COLOR_STATE(NormalState)
DEF_COLOR_STATE(InfoState)
DEF_COLOR_STATE(WarnState)
DEF_COLOR_STATE(DebugState)

///////////////////////////////////////////////////////
struct StdoutListener
{
    static StdoutListener* create(bool colorful);
    static StdoutListener& getInstance();

    void println(const U8 level, const char* msg);

private:
    StdoutListener(bool colorful);

    template <typename STATE>
    void doPrint(const STATE& state, const char* msg);

private:
    SuccState succ;
    FailState fail;
    NormalState normal;
    InfoState info;
    WarnState warn;
    DebugState debug;
};


#endif
