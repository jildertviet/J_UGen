// PluginJFunctionTrigger.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JFunctionTrigger {

class JFunctionTrigger : public JEventBaseS::JEventBaseS {
public:
    JFunctionTrigger();
    // ~JFunctionTrigger();

private:
    // Calc function
    void next(int inNumSamples);
};

} // namespace JFunctionTrigger
