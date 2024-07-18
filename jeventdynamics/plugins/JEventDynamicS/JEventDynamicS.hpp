// PluginJEventDynamicS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JEventDynamicS {

class JEventDynamicS : public JEventBaseS::JEventBaseS {
public:
    JEventDynamicS();
    // ~JEventDynamicS();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace JEventDynamicS
