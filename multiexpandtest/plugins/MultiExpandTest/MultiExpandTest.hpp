// PluginMultiExpandTest.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace MultiExpandTest {

class MultiExpandTest : public SCUnit {
public:
  MultiExpandTest();
  // ~MultiExpandTest();

private:
  // Calc function
  void next(int nSamples);

  // Member variables
};

} // namespace MultiExpandTest
