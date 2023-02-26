// PluginJVormS.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JVormS.hpp"

namespace JVormS {

JVormS::JVormS() {
    mCalcFunc = make_calc_function<JVormS, &JVormS::next>();
    type = jevent::JVorm;
    init();
}

void JVormS::next(int nSamples) {
  JEventBaseS::next(nSamples);
}

} // namespace JVormS

PluginLoad(JVormSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JVormS::JVormS>(ft, "JVormS", false);
}
