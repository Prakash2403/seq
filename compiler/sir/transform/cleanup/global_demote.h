#pragma once

#include "sir/transform/pass.h"

namespace seq {
namespace ir {
namespace transform {
namespace cleanup {

/// Demotes global variables that are used in only one
/// function to locals of that function.
class GlobalDemotionPass : public Pass {
private:
  /// number of variables we've demoted
  int numDemotions;

public:
  static const std::string KEY;

  GlobalDemotionPass() : Pass(), numDemotions(0) {}

  std::string getKey() const override { return KEY; }
  void run(Module *v) override;

  /// @return number of variables we've demoted
  int getNumDemotions() const { return numDemotions; }
};

} // namespace cleanup
} // namespace transform
} // namespace ir
} // namespace seq
