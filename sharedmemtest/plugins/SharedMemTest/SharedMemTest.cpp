// PluginSharedMemTest.cpp
// Jildert Viet (info@jildertviet.com)

#include "SharedMemTest.hpp"
#include "SC_PlugIn.hpp"
#include <iostream>
static InterfaceTable *ft;
namespace SharedMemTest {

SharedMemTest::SharedMemTest() {
  mCalcFunc = make_calc_function<SharedMemTest, &SharedMemTest::next>();
  reader =
      std::make_shared<lsm::SharedMemoryReadStream>("strPipe", 65535, false);
  std::string data = reader->readString();
  std::cout << data << std::endl;
}

void SharedMemTest::next(int nSamples) {}

} // namespace SharedMemTest

PluginLoad(SharedMemTestUGens) {
  // Plugin magic
  ft = inTable;
  registerUnit<SharedMemTest::SharedMemTest>(ft, "SharedMemTest", false);
}
