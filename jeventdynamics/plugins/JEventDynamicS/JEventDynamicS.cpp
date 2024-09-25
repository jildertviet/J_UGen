// PluginJEventDynamicS.cpp
// Jildert Viet (info@jildertviet.com)
// Test

#include "JEventDynamicS.hpp"
#include "SC_PlugIn.hpp"

namespace JEventDynamicS {

JEventDynamicS::JEventDynamicS() {
  mCalcFunc = make_calc_function<JEventDynamicS, &JEventDynamicS::next>();
  readValues();
  init(false); // Don't create yet

  char temp = busses[0];
  memcpy(&type, &temp, 1);
  create();
  // next(1);
}

void JEventDynamicS::next(int nSamples) { JEventBaseS::next(nSamples); }

} // namespace JEventDynamicS

PluginLoad(JEventDynamicSUGens) {
  // Plugin magic
  ft = inTable;
  registerUnit<JEventDynamicS::JEventDynamicS>(ft, "JEventDynamicS", false);
  // DefineSimpleUnit(JEventDynamicS);
}
