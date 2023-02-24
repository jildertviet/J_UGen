// PluginJModifierS.hpp
// Jildert Viet (jildert.viet@site.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JModifierS{

class JModifierS : public JEventBaseS::JEventBaseS  {
public:
    JModifierS();
    ~JModifierS();

private:
    void next(int nSamples);
};

} // namespace JModifierS
