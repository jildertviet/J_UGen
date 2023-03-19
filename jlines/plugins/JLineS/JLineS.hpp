// PluginJLineS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JLineS {

class JLineS : public JEventBaseS::JEventBaseS {
public:
    JLineS();
    // ~JLineS();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace JLineS
