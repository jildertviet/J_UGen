// PluginJModifierS.cpp
// Jildert Viet (jildert.viet@site.com)

#include "SC_PlugIn.hpp"
#include "JModifierS.hpp"

namespace JModifierS {

JModifierS::JModifierS() {
    mCalcFunc = make_calc_function<JModifierS, &JModifierS::next>();
    // next(1);
    readValues();
    switch((int)mode){
      case 0: type = jevent::JModifierArray;
    }
    // type = jevent::JModifierS;
    init();
}

JModifierS::~JModifierS(){

}

void JModifierS::next(int nSamples) {
  if(checkTrigger(nSamples))
    update();
}

} // namespace JModifierS

PluginLoad(JModifierSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JModifierS::JModifierS>(ft, "JModifierS", false);
}
