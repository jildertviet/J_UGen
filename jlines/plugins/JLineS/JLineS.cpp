// PluginJLineS.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JLineS.hpp"

namespace JLineS {

JLineS::JLineS() {
    mCalcFunc = make_calc_function<JLineS, &JLineS::next>();
    type = jevent::JLine;
    init();
    // next(1);
}

void JLineS::next(int nSamples) {
    JEventBaseS::next(nSamples);
}

} // namespace JLineS

PluginLoad(JLineSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JLineS::JLineS>(ft, "JLineS", false);
}
