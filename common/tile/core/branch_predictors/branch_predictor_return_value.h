//
// branch_predictor_return_value.h
//
// Copyright (C) 2011 Trevor E. Carlson
//

#ifndef BRANCH_PREDICTOR_RETURN_VALUE
#define BRANCH_PREDICTOR_RETURN_VALUE

#include <ostream>
#include <ios>
#include <boost/io/ios_state.hpp>

#include "fixed_types.h"

class BranchPredictorReturnValue {

public:

   enum BranchType
   {
      InvalidBranch = 0,
      DirectBranch,
      IndirectBranch,
      UnconditionalBranch,
      ConditionalBranch
   };

   static const char* BranchTypeNames[];

   bool prediction;
   bool hit;
   IntPtr target;
   BranchType type;

   friend std::ostream& operator <<(std::ostream& stream, const BranchPredictorReturnValue& value);

};

inline std::ostream& operator <<(std::ostream& stream, const BranchPredictorReturnValue& value)
{

   boost::io::ios_flags_saver ifs(stream);

   stream
      << "Pred = " << value.prediction
      << " Hit = " << value.hit
      << " Tgt = " << std::hex << value.target << std::dec
      << " Type = " << BranchPredictorReturnValue::BranchTypeNames[value.type];

   return stream;
}

#endif /* BRANCH_PREDICTOR_RETURN_VALUE */
