// PluginJWaveformS.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "JEventBaseS.hpp"

namespace JWaveformS {

class JWaveformS : public JEventBaseS::JEventBaseS {
public:
    JWaveformS();
    // ~JWaveformS();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace JWaveformS
