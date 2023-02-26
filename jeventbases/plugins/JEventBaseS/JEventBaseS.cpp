// PluginJEventBaseS.cpp
// Jildert Viet (info@jildertviet.com)

#include "SC_PlugIn.hpp"
#include "JEventBaseS.hpp"

namespace JEventBaseS {
//
// JEventBaseS::JEventBaseS() {
//     // mCalcFunc = make_calc_function<JEventBaseS, &JEventBaseS::next>();
//     // next(1);
// }
//
// JEventBaseS::~JEventBaseS() {
//     // mCalcFunc = make_calc_function<JEventBaseS, &JEventBaseS::next>();
//     // next(1);
//     cout << "Delete" << endl;
//     SendNodeReply(&(this->mParent->mNode), subID, "/kill", 0, nullptr);
// }

// void JEventBaseS::init(){
//   subID = in(0)[0];
//   readValues();
//   create();
// }

// void JEventBaseS::create(){
  // SendNodeReply(&(this->mParent->mNode), encodedInt(), "/create", NUM_BUSSES, valuesToFloatArray());
// }

// bool JEventBaseS::checkTrigger(int inNumSamples){
//   const float* trig = in(1);
//   for (int j = 0; j < inNumSamples; j++) {
//       float curtrig = trig[j];
//       if (curtrig > 0.f && prevtrig <= 0.f) {
//           prevtrig = curtrig;
//           return true;
//       }
//       prevtrig = curtrig;
//       return false;
//   }
// }
//
// void JEventBaseS::update(){
//   readValues();
//   SendNodeReply(&(this->mParent->mNode), subID, "/update", NUM_BUSSES, valuesToFloatArray());
// }
//
// // void JEventBaseS::next(int nSamples) {
//
// // }
//
// void JEventBaseS::readValues(){
//   for(int i=0; i<NUM_BUSSES; i++){
//     if(values[i])
//       *values[i] = in(i+2)[0];
//   }
// }
//
// int JEventBaseS::encodedInt(){
//   char encodedBytes[4];
//   encodedBytes[0] = (char)type;
//   encodedBytes[1] = subID;
//   int encodedInt;
//   memcpy(&encodedInt, encodedBytes, sizeof(int));
//   return encodedInt;
// }

} // namespace JEventBaseS

// PluginLoad(JEventBaseSUGens) {
    // Plugin magic
    // ft = inTable;
    // registerUnit<JEventBaseS::JEventBaseS>(ft, "JEventBaseS", false);
// }
