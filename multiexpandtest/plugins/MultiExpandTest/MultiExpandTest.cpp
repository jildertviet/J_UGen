// PluginMultiExpandTest.cpp
// Jildert Viet (info@jildertviet.com)

#include "MultiExpandTest.hpp"
#include "SC_PlugIn.hpp"
#include <iostream>

static InterfaceTable *ft;

namespace MultiExpandTest {

MultiExpandTest::MultiExpandTest() {
  std::cout << "X" << std::endl;
  mCalcFunc = make_calc_function<MultiExpandTest, &MultiExpandTest::next>();
  next(1);
}

void MultiExpandTest::next(int nSamples) {}

} // namespace MultiExpandTest

PluginLoad(MultiExpandTestUGens) {
  // Plugin magic
  ft = inTable;
  registerUnit<MultiExpandTest::MultiExpandTest>(ft, "MultiExpandTest", false);
}
