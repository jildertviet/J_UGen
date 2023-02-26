// PluginJRectangleS.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JRectangleS.hpp"

// static InterfaceTable* ft;

namespace JRectangleS {

JRectangleS::JRectangleS() {
    mCalcFunc = make_calc_function<JRectangleS, &JRectangleS::next>();
    type = jevent::JRectangle;

    init(); // readValues + create
    // next(1); // Am I missing the first trigger if I don't do this?
}

// void JRectangleS::clearUpdateArray(){
  // memset(bNeedsUpdate, 0x00, sizeof(bool)*NUM_BUSSES); // All false?
  // numToSend = 0;
// }

// JRectangleS::~JRectangleS(){

// }

void JRectangleS::next(int inNumSamples) {
    JEventBaseS::next(inNumSamples);
}

} // namespace JRectangleS

PluginLoad(JRectangleSUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<JRectangleS::JRectangleS>(ft, "JRectangleS", false);
}
