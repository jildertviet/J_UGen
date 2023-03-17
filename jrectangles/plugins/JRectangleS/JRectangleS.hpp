// PluginJRectangleS.hpp
// Jildert Viet (info@jildertviet.com)

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
    void next(int inNumSamples);
};

} // namespace JRectangleS
