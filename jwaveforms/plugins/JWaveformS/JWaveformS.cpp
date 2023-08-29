// PluginJWaveformS.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JWaveformS.hpp"

namespace JWaveformS {

JWaveformS::JWaveformS() {
    mCalcFunc = make_calc_function<JWaveformS, &JWaveformS::next>();
    type = jevent::JWaveform;
    init();
    // next(1);
}

void JWaveformS::next(int nSamples) {
    JEventBaseS::next(nSamples);
}

} // namespace JWaveformS

PluginLoad(JWaveformSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JWaveformS::JWaveformS>(ft, "JWaveformS", false);
}
