// PluginJRectangleS.hpp
// Jildert Viet (info@jildertviet.com)
// Test

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBase.hpp"

namespace JRectangleS {

class JRectangleS : public SCUnit, public JEventBase {
public:
    JRectangleS();
    ~JRectangleS();

private:
    // Calc function
    void next(int inNumSamples);
    void update();
    void readValues();
    void clearUpdateArray();

    bool bNeedsUpdate[NUM_BUSSES];
    int numToSend = 0;

    float prevtrig;
    int cmdNameSize;
    char* cmdName;
};

} // namespace JRectangleS
