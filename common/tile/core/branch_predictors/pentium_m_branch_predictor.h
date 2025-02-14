//
// pentium_m_branch_predictor.h
//
// Copyright (C) 2011 Trevor E. Carlson
//

#ifndef PENTIUM_M_BRANCH_PREDICTOR_H
#define PENTIUM_M_BRANCH_PREDICTOR_H

#include "branch_predictor.h"
#include "branch_predictor_return_value.h"
#include "pentium_m_global_predictor.h"
#include "pentium_m_branch_target_buffer.h"
#include "pentium_m_bimodal_table.h"
#include "pentium_m_loop_branch_predictor.h"

#include <vector>

class PentiumMBranchPredictor : public BranchPredictor
{
public:
   PentiumMBranchPredictor();
   ~PentiumMBranchPredictor();

   bool predict(IntPtr ip, IntPtr target);

   void update(bool predicted, bool actual, IntPtr ip, IntPtr target);

   void outputSummary(std::ostream &os);

private:

   void update_pir(bool actual, IntPtr ip, IntPtr target, BranchPredictorReturnValue::BranchType branch_type);
   IntPtr hash_function(IntPtr ip, IntPtr pir);

   PentiumMGlobalPredictor m_global_predictor;
   PentiumMBranchTargetBuffer m_btb;
   PentiumMBimodalTable m_bimodal_table;
   PentiumMLoopBranchPredictor m_lpb;

   IntPtr m_pir;

};

#endif
