// PluginSharedMemTest.hpp
// Jildert Viet (info@jildertviet.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "SC_Reply.h"
#include "libsharedmemory.hpp"
#include <memory>

namespace SharedMemTest {

class SharedMemTest : public SCUnit {
public:
  SharedMemTest();
  // ~SharedMemTest();

  std::shared_ptr<lsm::SharedMemoryReadStream> reader;

private:
  // Calc function
  void next(int nSamples);

  // Member variables
};

} // namespace SharedMemTest
