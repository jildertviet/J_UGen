// PluginJModifierS.cpp
// Jildert Viet

#include "SC_PlugIn.hpp"
#include "JModifierS.hpp"

namespace JModifierS {

JModifierS::JModifierS() {
    mCalcFunc = make_calc_function<JModifierS, &JModifierS::next>();
    // next(1);
    readValues();
    switch((int)mode){
      case 0: type = jevent::JModifierArray; break;
      case 1: type = jevent::JModifierRedraw; break;
    }
    // type = jevent::JModifierS;
    init();
    // Send msg: /connect, connectionType::modifier, targetSubID
    float* msg = new float[2];
    msg[0] = (float)jevent::ConnectionType::Modifier;
    msg[1] = *(values[22]); // Target subID
    SendNodeReply(&(this->mParent->mNode), subID, "/connect", 2, msg);
}

JModifierS::~JModifierS(){

}

void JModifierS::next(int nSamples) {
  JEventBaseS::next(nSamples);
}

} // namespace JModifierS

PluginLoad(JModifierSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JModifierS::JModifierS>(ft, "JModifierS", false);
}
