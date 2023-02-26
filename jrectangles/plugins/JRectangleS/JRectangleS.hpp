// PluginJRectangleS.hpp
// Jildert Viet (info@jildertviet.com)
// Test

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JRectangleS {

class JRectangleS : public JEventBaseS::JEventBaseS {
public:
    JRectangleS();
    // ~JRectangleS();

private:
    // Calc function
    void next(int inNumSamples);

    // bool bNeedsUpdate[NUM_BUSSES];
    // int numToSend = 0;


};

} // namespace JRectangleS
