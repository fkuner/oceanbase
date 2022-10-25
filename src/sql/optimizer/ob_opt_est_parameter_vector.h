/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_SQL_OPTIMIZER_OB_OPT_EST_PARAMETER_VECTOR_
#define OCEANBASE_SQL_OPTIMIZER_OB_OPT_EST_PARAMETER_VECTOR_
#include "ob_opt_est_cost_model.h"

namespace oceanbase
{
namespace sql
{

const static double VECTOR_CPU_TUPLE_COST = 0.00264692180695;
const static double VECTOR_TABLE_SCAN_CPU_TUPLE_COST = 0.00816675438377;
const static double VECTOR_MICRO_BLOCK_SEQ_COST = 1.19603792057955;
const static double VECTOR_MICRO_BLOCK_RND_COST = 1.6742435644151;
const static double VECTOR_PROJECT_COLUMN_SEQ_INT_COST = 0.02314121667000;
const static double VECTOR_PROJECT_COLUMN_SEQ_NUMBER_COST = 0.01602888420961;
const static double VECTOR_PROJECT_COLUMN_SEQ_CHAR_COST = 0.00028227202574;
const static double VECTOR_PROJECT_COLUMN_RND_INT_COST = 0.08067736535000;
const static double VECTOR_PROJECT_COLUMN_RND_NUMBER_COST = 0.08806720526487;
const static double VECTOR_PROJECT_COLUMN_RND_CHAR_COST = 0.0025971659266159;
const static double VECTOR_FETCH_ROW_RND_COST = 2.294445334;
const static double VECTOR_CMP_INT_COST = 0.0084782994043;
const static double VECTOR_CMP_NUMBER_COST = 0.0144099836801;
const static double VECTOR_CMP_CHAR_COST = 0.03754351606603;
const static double VECTOR_INVALID_CMP_COST = -1;
const static double VECTOR_HASH_INT_COST = 0.00742821518373;
const static double VECTOR_HASH_NUMBER_COST = 0.01494804432806;
const static double VECTOR_HASH_CHAR_COST = 0.18684685876579;
const static double VECTOR_INVALID_HASH_COST = -1;
const static double VECTOR_MATERIALIZE_PER_BYTE_WRITE_COST = 0.0019941666625;
const static double VECTOR_READ_MATERIALIZED_PER_ROW_COST = 0.00279052036722;
const static double VECTOR_PER_AGGR_FUNC_COST = 0.01547711103333;
const static double VECTOR_PER_WIN_FUNC_COST = 0.6489393333;
const static double VECTOR_CPU_OPERATOR_COST = 0.00441003086296;
const static double VECTOR_JOIN_PER_ROW_COST = 0.02229222638004;
const static double VECTOR_BUILD_HASH_PER_ROW_COST = 0.12472949246032;
const static double VECTOR_PROBE_HASH_PER_ROW_COST = 0.07363102503623;
const static double VECTOR_RESCAN_COST = 0.76306366670000;
const static double VECTOR_NETWORK_SER_PER_BYTE_COST = 0.0094539370039375;
const static double VECTOR_NETWORK_DESER_PER_BYTE_COST = 0.0094539370039375;
const static double VECTOR_NETWORK_TRANS_PER_BYTE_COST = 0.011832508338;
const static double VECTOR_PX_RESCAN_PER_ROW_COST = 398.267410467;
const static double VECTOR_PX_BATCH_RESCAN_PER_ROW_COST = 49.5841472833;
const static double VECTOR_NL_SCAN_COST = 17.92;
const static double VECTOR_BATCH_NL_SCAN_COST = 15.32;
const static double VECTOR_NL_GET_COST = 6.4;
const static double VECTOR_BATCH_NL_GET_COST = 6.4;
const static double VECTOR_TABLE_LOOPUP_PER_ROW_RPC_COST = 20.9591092914652749211572741;
const static double VECTOR_INSERT_PER_ROW_COST = 6.330037500000001;
const static double VECTOR_INSERT_INDEX_PER_ROW_COST = 6.583673124999999;
const static double VECTOR_INSERT_CHECK_PER_ROW_COST = 96.2424;
const static double VECTOR_UPDATE_PER_ROW_COST = 7.562755000000001;
const static double VECTOR_UPDATE_INDEX_PER_ROW_COST = 23.969286875;
const static double VECTOR_UPDATE_CHECK_PER_ROW_COST = 92.15352;
const static double VECTOR_DELETE_PER_ROW_COST = 5.0310162499999995;
const static double VECTOR_DELETE_INDEX_PER_ROW_COST = 6.549611874999999;
const static double VECTOR_DELETE_CHECK_PER_ROW_COST = 59.4583275;

const static double comparison_params_vector[ObMaxTC+1] = {
  VECTOR_CMP_INT_COST,            // null
  VECTOR_CMP_INT_COST,            // int8, int16, int24, int32, int64.
  VECTOR_CMP_INT_COST,            // uint8, uint16, uint24, uint32, uint64.
  VECTOR_CMP_INT_COST,            // float, ufloat.
  VECTOR_CMP_INT_COST,            // double, udouble.
  VECTOR_CMP_NUMBER_COST,         // number, unumber.
  VECTOR_CMP_INT_COST,            // datetime, timestamp.
  VECTOR_CMP_INT_COST,            // date
  VECTOR_CMP_INT_COST,            // time
  VECTOR_CMP_INT_COST,            // year
  VECTOR_CMP_CHAR_COST,           // varchar, char, varbinary, binary.
  VECTOR_CMP_INT_COST,            // extend
  VECTOR_INVALID_CMP_COST,        // unknown
  VECTOR_CMP_CHAR_COST,           // TinyText,MediumText, Text ,LongText
};

const static double hash_params_vector[ObMaxTC+1] = {
  VECTOR_HASH_INT_COST,            // null
  VECTOR_HASH_INT_COST,            // int8, int16, int24, int32, int64.
  VECTOR_HASH_INT_COST,            // uint8, uint16, uint24, uint32, uint64.
  VECTOR_HASH_INT_COST,            // float, ufloat.
  VECTOR_HASH_INT_COST,            // double, udouble.
  VECTOR_HASH_NUMBER_COST,         // number, unumber.
  VECTOR_HASH_INT_COST,            // datetime, timestamp.
  VECTOR_HASH_INT_COST,            // date
  VECTOR_HASH_INT_COST,            // time
  VECTOR_HASH_INT_COST,            // year
  VECTOR_HASH_CHAR_COST,           // varchar, char, varbinary, binary.
  VECTOR_HASH_INT_COST,            // extend
  VECTOR_INVALID_HASH_COST,        // unknown
  VECTOR_HASH_CHAR_COST,           // TinyText,MediumText, Text ,LongText
};

const static ObOptEstCostModel::ObCostParams cost_params_vector(
   VECTOR_CPU_TUPLE_COST,
   VECTOR_TABLE_SCAN_CPU_TUPLE_COST,
   VECTOR_MICRO_BLOCK_SEQ_COST,
   VECTOR_MICRO_BLOCK_RND_COST,
   VECTOR_PROJECT_COLUMN_SEQ_INT_COST,
   VECTOR_PROJECT_COLUMN_SEQ_NUMBER_COST,
   VECTOR_PROJECT_COLUMN_SEQ_CHAR_COST,
   VECTOR_PROJECT_COLUMN_RND_INT_COST,
   VECTOR_PROJECT_COLUMN_RND_NUMBER_COST,
   VECTOR_PROJECT_COLUMN_RND_CHAR_COST,
   VECTOR_FETCH_ROW_RND_COST,
   VECTOR_CMP_INT_COST,
   VECTOR_CMP_NUMBER_COST,
   VECTOR_CMP_CHAR_COST,
   VECTOR_INVALID_CMP_COST,
   VECTOR_HASH_INT_COST,
   VECTOR_HASH_NUMBER_COST,
   VECTOR_HASH_CHAR_COST,
   VECTOR_INVALID_HASH_COST,
   VECTOR_MATERIALIZE_PER_BYTE_WRITE_COST,
   VECTOR_READ_MATERIALIZED_PER_ROW_COST,
   VECTOR_PER_AGGR_FUNC_COST,
   VECTOR_PER_WIN_FUNC_COST,
   VECTOR_CPU_OPERATOR_COST,
   VECTOR_JOIN_PER_ROW_COST,
   VECTOR_BUILD_HASH_PER_ROW_COST,
   VECTOR_PROBE_HASH_PER_ROW_COST,
   VECTOR_RESCAN_COST,
   VECTOR_NETWORK_SER_PER_BYTE_COST,
   VECTOR_NETWORK_DESER_PER_BYTE_COST,
   VECTOR_NETWORK_TRANS_PER_BYTE_COST,
   VECTOR_PX_RESCAN_PER_ROW_COST,
   VECTOR_PX_BATCH_RESCAN_PER_ROW_COST,
   VECTOR_NL_SCAN_COST,
   VECTOR_BATCH_NL_SCAN_COST,
   VECTOR_NL_GET_COST,
   VECTOR_BATCH_NL_GET_COST,
   VECTOR_TABLE_LOOPUP_PER_ROW_RPC_COST,
   VECTOR_INSERT_PER_ROW_COST,
   VECTOR_INSERT_INDEX_PER_ROW_COST,
   VECTOR_INSERT_CHECK_PER_ROW_COST,
   VECTOR_UPDATE_PER_ROW_COST,
   VECTOR_UPDATE_INDEX_PER_ROW_COST,
   VECTOR_UPDATE_CHECK_PER_ROW_COST,
   VECTOR_DELETE_PER_ROW_COST,
   VECTOR_DELETE_INDEX_PER_ROW_COST,
   VECTOR_DELETE_CHECK_PER_ROW_COST
);

}
}
#endif /*OCEANBASE_SQL_OPTIMIZER_OB_OPT_EST_PARAMETER_VECTOR_*/