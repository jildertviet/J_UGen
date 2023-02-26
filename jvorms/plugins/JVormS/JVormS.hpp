// PluginJVormS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JVormS {

class JVormS : public JEventBaseS::JEventBaseS {
public:
    JVormS();
    // ~JVormS();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace JVormS
