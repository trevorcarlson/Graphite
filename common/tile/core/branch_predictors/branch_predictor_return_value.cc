//
// branch_predictor_return_value.cc
//
// Copyright (C) 2011 Trevor E. Carlson
//

#include "branch_predictor_return_value.h"

const char* BranchPredictorReturnValue::BranchTypeNames[] =
   {
      "InvalidBranch",
      "DirectBranch",
      "IndirectBranch",
      "UnconditionalBranch",
      "ConditionalBranch"
   };

