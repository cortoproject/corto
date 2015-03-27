/*
 * cx_vm_operands.h
 *
 *  Created on: Aug 31, 2013
 *      Author: sander
 */

#ifndef CX_VM_OPERANDS_H_
#define CX_VM_OPERANDS_H_

typedef uint8_t     B_t;
typedef uint16_t    S_t;
typedef uint32_t    L_t;
typedef intptr_t    W_t;
typedef uint64_t    D_t;

/* Signed numbers */
typedef int8_t     Bs_t;
typedef int16_t    Ss_t;
typedef int32_t    Ls_t;
typedef int64_t    Ds_t;

/* Staged variables */
#define stage1_B    c.stage1.s.b._1
#define stage2_B    c.stage1.s.b._2
#define stage1_S    c.stage1.s.b._1
#define stage2_S    c.stage1.s.b._2
#define stage1_L    c.stage1.w
#define stage2_L    c.stage2.w
#define stage1_W    (sizeof(uintptr_t) == 4 ? (uintptr_t)stage1_L : (uintptr_t)stage1_D)
#define stage2_W    (sizeof(uintptr_t) == 4 ? (uintptr_t)stage2_L : (uintptr_t)stage2_D)
#define stage1_D    c.dbl
#define stage2_D    c.dbl2

/* Instructions */
#define fetch(t,l,r) fetch_##t##l##r()

/* Byte */
#define fetch_BVV    fetchIc()
#define fetch1_BVV
#define fetch2_BVV
#define op1_BVV        c.ic.b._1
#define op2_BVV        c.ic.b._2

#define fetch_BVR    fetchIc()
#define fetch1_BVR
#define fetch2_BVR
#define op1_BVR        c.ic.b._1
#define op2_BVR        *(B_t*)CX_OFFSET(reg, c.ic.b._2)

#define fetch_BVP
#define fetch1_BVP    fetchIc()
#define fetch2_BVP    fetchLo()
#define op1_BVP        c.ic.b._1
#define op2_BVP        *(B_t*)c.lo.w

#define fetch_BVQ    fetchIc()
#define fetch1_BVQ
#define fetch2_BVQ
#define op1_BVQ        c.ic.b._1
#define op2_BVQ        *(B_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_BPV
#define fetch1_BPV   fetchLo()
#define fetch2_BPV   fetchIc()
#define op1_BPV     *(B_t*)c.lo.w
#define op2_BPV     (B_t)c.ic.b._1

#define fetch_BPR
#define fetch1_BPR   fetchLo()
#define fetch2_BPR   fetchIc()
#define op1_BPR     *(B_t*)c.lo.w
#define op2_BPR     *(B_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_BPP
#define fetch1_BPP   fetchLo()
#define fetch2_BPP   fetchHi()
#define op1_BPP     *(B_t*)c.lo.w
#define op2_BPP     *(B_t*)c.hi.w

#define fetch_BPQ
#define fetch1_BPQ   fetchLo()
#define fetch2_BPQ   fetchIc()
#define op1_BPQ     *(B_t*)c.lo.w
#define op2_BPQ     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_BRV   fetchIc()
#define fetch1_BRV
#define fetch2_BRV
#define op1_BRV     *(B_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_BRV     (B_t)c.ic.b._2

#define fetch_BRR    fetchIc()
#define fetch1_BRR
#define fetch2_BRR
#define op1_BRR     *(B_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_BRR     *(B_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_BRP
#define fetch1_BRP  fetchIc()
#define fetch2_BRP  fetchLo()
#define op1_BRP     *(B_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_BRP     *(B_t*)c.lo.w

#define fetch_BRQ    fetchIc()
#define fetch1_BRQ
#define fetch2_BRQ
#define op1_BRQ     *(B_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_BRQ     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

#define fetch_BQV    fetchIc()
#define fetch1_BQV
#define fetch2_BQV
#define op1_BQV     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_BQV     (B_t)c.ic.b._2

#define fetch_BQR    fetchIc()
#define fetch1_BQR
#define fetch2_BQR
#define op1_BQR     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_BQR     *(B_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_BQP
#define fetch1_BQP  fetchIc()
#define fetch2_BQP  fetchLo()
#define op1_BQP     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_BQP     *(B_t*)c.lo.w

#define fetch_BQQ    fetchIc()
#define fetch1_BQQ
#define fetch2_BQQ
#define op1_BQQ     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_BQQ     *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

/* Short */
#define fetch_SVV    fetchIc()
#define fetch1_SVV
#define fetch2_SVV
#define op1_SVV     c.ic.b._1
#define op2_SVV     c.ic.b._2

#define fetch_SVR    fetchIc()
#define fetch1_SVR
#define fetch2_SVR
#define op1_SVR     c.ic.b._1
#define op2_SVR     *(S_t*)CX_OFFSET(reg, c.ic.b._2)

#define fetch_SVP
#define fetch1_SVP    fetchIc()
#define fetch2_SVP    fetchLo()
#define op1_SVP     c.ic.b._1
#define op2_SVP     *(S_t*)c.lo.w

#define fetch_SVQ    fetchIc()
#define fetch1_SVQ
#define fetch2_SVQ
#define op1_SVQ     c.ic.b._1
#define op2_SVQ     *(S_t*)*(void**)CX_OFFSET(reg, c.ic.b._2)

#define fetch_SPV
#define fetch1_SPV  fetchLo()
#define fetch2_SPV  fetchIc()
#define op1_SPV     *(S_t*)c.lo.w
#define op2_SPV     c.ic.s

#define fetch_SPR
#define fetch1_SPR  fetchLo()
#define fetch2_SPR  fetchIc()
#define op1_SPR     *(S_t*)c.lo.w
#define op2_SPR     *(S_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_SPP
#define fetch1_SPP  fetchLo()
#define fetch2_SPP  fetchHi()
#define op1_SPP     *(S_t*)c.lo.w
#define op2_SPP     *(S_t*)c.hi.w

#define fetch_SPQ
#define fetch1_SPQ  fetchLo()
#define fetch2_SPQ  fetchIc()
#define op1_SPQ     *(S_t*)c.lo.w
#define op2_SPQ     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_SRV    fetchIc()
#define fetch1_SRV
#define fetch2_SRV
#define op1_SRV     *(S_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_SRV     c.ic.b._2

#define fetch_SRR    fetchIc()
#define fetch1_SRR
#define fetch2_SRR
#define op1_SRR     *(S_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_SRR     *(S_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_SRP
#define fetch1_SRP  fetchIc()
#define fetch2_SRP  fetchLo()
#define op1_SRP     *(S_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_SRP     *(S_t*)c.lo.w

#define fetch_SRQ    fetchIc()
#define fetch1_SRQ
#define fetch2_SRQ
#define op1_SRQ     *(S_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_SRQ     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

#define fetch_SQV
#define fetch1_SQV  fetchIc()
#define fetch2_SQV  fetchLo()
#define op1_SQV     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_SQV     (S_t)c.lo.w

#define fetch_SQR    fetchIc()
#define fetch1_SQR
#define fetch2_SQR
#define op1_SQR     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_SQR     *(S_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_SQP
#define fetch1_SQP  fetchIc()
#define fetch2_SQP  fetchLo()
#define op1_SQP     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_SQP     *(S_t*)c.lo.w

#define fetch_SQQ    fetchIc()
#define fetch1_SQQ
#define fetch2_SQQ
#define op1_SQQ     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_SQQ     *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

/* Long */
#define fetch_LVV
#define fetch1_LVV    fetchLo()
#define fetch2_LVV    fetchHi()
#define op1_LVV        c.lo.w
#define op2_LVV        c.hi.w

#define fetch_LVR
#define fetch1_LVR    fetchLo()
#define fetch2_LVR    fetchIc()
#define op1_LVR        c.lo.w
#define op2_LVR        *(L_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LVP
#define fetch1_LVP    fetchLo()
#define fetch2_LVP    fetchHi()
#define op1_LVP        c.lo.w
#define op2_LVP        *(L_t*)c.hi.w

#define fetch_LVQ
#define fetch1_LVQ    fetchLo()
#define fetch2_LVQ    fetchIc()
#define op1_LVQ        c.lo.w
#define op2_LVQ        *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LRV
#define fetch1_LRV  fetchIc()
#define fetch2_LRV  fetchLo()
#define op1_LRV     *(L_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_LRV     c.lo.w

#define fetch_LRR    fetchIc()
#define fetch1_LRR
#define fetch2_LRR
#define op1_LRR     *(L_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_LRR     *(L_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_LRP
#define fetch1_LRP  fetchIc()
#define fetch2_LRP  fetchLo()
#define op1_LRP     *(L_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_LRP     *(L_t*)c.lo.w

#define fetch_LRQ    fetchIc()
#define fetch1_LRQ
#define fetch2_LRQ
#define op1_LRQ     *(L_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_LRQ     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

#define fetch_LPV
#define fetch1_LPV  fetchLo()
#define fetch2_LPV  fetchHi()
#define op1_LPV     *(L_t*)c.lo.w
#define op2_LPV     c.hi.w

#define fetch_LPR
#define fetch1_LPR  fetchLo()
#define fetch2_LPR  fetchIc()
#define op1_LPR     *(L_t*)c.lo.w
#define op2_LPR     *(L_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LPP
#define fetch1_LPP  fetchLo()
#define fetch2_LPP  fetchHi()
#define op1_LPP     *(L_t*)c.lo.w
#define op2_LPP     *(L_t*)c.hi.w

#define fetch_LPQ
#define fetch1_LPQ  fetchLo()
#define fetch2_LPQ  fetchIc()
#define op1_LPQ     *(L_t*)c.lo.w
#define op2_LPQ     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LQV
#define fetch1_LQV  fetchIc()
#define fetch2_LQV  fetchLo()
#define op1_LQV     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_LQV     (L_t)c.lo.w

#define fetch_LQR    fetchIc()
#define fetch1_LQR
#define fetch2_LQR
#define op1_LQR     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_LQR     *(L_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_LQP
#define fetch1_LQP  fetchIc()
#define fetch2_LQP  fetchLo()
#define op1_LQP     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_LQP     *(L_t*)c.lo.w

#define fetch_LQQ    fetchIc()
#define fetch1_LQQ
#define fetch2_LQQ
#define op1_LQQ     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_LQQ     *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)


/* Word */
#define fetch_WVV
#define fetch1_WVV    fetchLo()
#define fetch2_WVV    fetchHi()
#define op1_WVV        c.lo.w
#define op2_WVV        c.hi.w

#define fetch_WVR
#define fetch1_WVR    fetchLo()
#define fetch2_WVR    fetchIc()
#define op1_WVR        c.lo.w
#define op2_WVR        *(W_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WVP
#define fetch1_WVP    fetchLo()
#define fetch2_WVP    fetchHi()
#define op1_WVP        c.lo.w
#define op2_WVP        *(W_t*)c.hi.w

#define fetch_WVQ
#define fetch1_WVQ    fetchLo()
#define fetch2_WVQ    fetchIc()
#define op1_WVQ        c.lo.w
#define op2_WVQ        *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WRV
#define fetch1_WRV  fetchIc()
#define fetch2_WRV  fetchLo()
#define op1_WRV     *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRV     c.lo.w

#define fetch_WRR    fetchIc()
#define fetch1_WRR
#define fetch2_WRR
#define op1_WRR     *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRR     *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WRP
#define fetch1_WRP  fetchIc()
#define fetch2_WRP  fetchLo()
#define op1_WRP     *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRP     *(W_t*)c.lo.w

#define fetch_WRQ    fetchIc()
#define fetch1_WRQ
#define fetch2_WRQ
#define op1_WRQ     *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRQ     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WPV
#define fetch1_WPV  fetchLo()
#define fetch2_WPV  fetchHi()
#define op1_WPV     *(W_t*)c.lo.w
#define op2_WPV     c.hi.w

#define fetch_WPR
#define fetch1_WPR  fetchLo()
#define fetch2_WPR  fetchIc()
#define op1_WPR     *(W_t*)c.lo.w
#define op2_WPR     *(W_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WPP
#define fetch1_WPP  fetchLo()
#define fetch2_WPP  fetchHi()
#define op1_WPP     *(W_t*)c.lo.w
#define op2_WPP     *(W_t*)c.hi.w

#define fetch_WPQ
#define fetch1_WPQ  fetchLo()
#define fetch2_WPQ  fetchIc()
#define op1_WPQ     *(W_t*)c.lo.w
#define op2_WPQ     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WQV
#define fetch1_WQV  fetchIc()
#define fetch2_WQV  fetchLo()
#define op1_WQV     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQV     (W_t)c.lo.w

#define fetch_WQR    fetchIc()
#define fetch1_WQR
#define fetch2_WQR
#define op1_WQR     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQR     *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WQP
#define fetch1_WQP  fetchIc()
#define fetch2_WQP  fetchLo()
#define op1_WQP     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQP     *(W_t*)c.lo.w

#define fetch_WQQ    fetchIc()
#define fetch1_WQQ
#define fetch2_WQQ
#define op1_WQQ     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQQ     *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)



/* Double */
#define fetch_DVV    
#define fetch1_DVV    fetchLo()
#define fetch2_DVV    fetchHi()
#define op1_DVV     c.lo.w    /* Placeholder */
#define op2_DVV     c.hi.w    /* Placeholder */

#define fetch_DVR
#define fetch1_DVR    fetchDbl()
#define fetch2_DVR    fetchIc()
#define op1_DVR     c.dbl
#define op2_DVR     *(D_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DVP    /* This instruction cannot be encoded and has to be split up */
#define fetch1_DVP
#define fetch2_DVP
#define op1_DVP     c.lo.w /* Placeholder */
#define op2_DVP     c.lo.w /* Placeholder */

#define fetch_DVQ
#define fetch1_DVQ    fetchDbl()
#define fetch2_DVQ    fetchIc()
#define op1_DVQ     c.dbl /* Placeholder */
#define op2_DVQ     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DRV
#define fetch1_DRV  fetchIc()
#define fetch2_DRV  fetchDbl()
#define op1_DRV     *(D_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_DRV     c.dbl

#define fetch_DRR    fetchIc()
#define fetch1_DRR
#define fetch2_DRR
#define op1_DRR     *(D_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_DRR     *(D_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_DRP
#define fetch1_DRP  fetchIc()
#define fetch2_DRP  fetchLo()
#define op1_DRP     *(D_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_DRP     *(D_t*)c.lo.w

#define fetch_DRQ    fetchIc()
#define fetch1_DRQ
#define fetch2_DRQ
#define op1_DRQ     *(D_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_DRQ     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

#define fetch_DPV
#define fetch1_DPV  fetchIc()
#define fetch2_DPV  fetchDbl()
#define op1_DPV        *(D_t*)c.ic.w
#define op2_DPV        c.dbl

#define fetch_DPR
#define fetch1_DPR  fetchLo()
#define fetch2_DPR  fetchIc()
#define op1_DPR     *(D_t*)c.lo.w
#define op2_DPR     *(D_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DPP
#define fetch1_DPP  fetchLo()
#define fetch2_DPP  fetchHi()
#define op1_DPP     *(D_t*)c.lo.w
#define op2_DPP     *(D_t*)c.hi.w

#define fetch_DPQ
#define fetch1_DPQ  fetchLo()
#define fetch2_DPQ  fetchIc()
#define op1_DPQ     *(D_t*)c.lo.w
#define op2_DPQ     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DQV
#define fetch1_DQV  fetchIc()
#define fetch2_DQV  fetchDbl()
#define op1_DQV     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_DQV     c.dbl

#define fetch_DQR    fetchIc()
#define fetch1_DQR
#define fetch2_DQR
#define op1_DQR     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_DQR     *(D_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_DQP
#define fetch1_DQP  fetchIc()
#define fetch2_DQP  fetchLo()
#define op1_DQP     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_DQP     *(D_t*)c.lo.w

#define fetch_DQQ    fetchIc();
#define fetch1_DQQ
#define fetch2_DQQ
#define op1_DQQ     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_DQQ     *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)


/* Address instructions */
#define fetch_BVA
#define fetch1_BVA    fetchIc()
#define fetch2_BVA    fetchLo()
#define op1_BVA        c.ic.b._1
#define op2_BVA        (void*)c.lo.w

#define fetch_BRA
#define fetch1_BRA  fetchIc()
#define fetch2_BRA  fetchLo()
#define op1_BRA        *(B_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_BRA        (void*)c.lo.w

#define fetch_BPA
#define fetch1_BPA  fetchLo()
#define fetch2_BPA  fetchHi()
#define op1_BPA        *(B_t*)c.lo.w
#define op2_BPA        (void*)c.hi.w

#define fetch_BQA
#define fetch1_BQA  fetchIc()
#define fetch2_BQA  fetchLo()
#define op1_BQA        *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_BQA        (void*)c.lo.w

#define fetch_SVA
#define fetch1_SVA  fetchIc()
#define fetch2_SVA  fetchLo()
#define op1_SVA        c.ic.b._1
#define op2_SVA        (void*)c.lo.w

#define fetch_SRA
#define fetch1_SRA  fetchIc()
#define fetch2_SRA  fetchLo()
#define op1_SRA        *(S_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_SRA        (void*)c.lo.w

#define fetch_SPA
#define fetch1_SPA  fetchLo()
#define fetch2_SPA  fetchHi()
#define op1_SPA        *(S_t*)c.lo.w
#define op2_SPA        (void*)c.hi.w

#define fetch_SQA
#define fetch1_SQA  fetchIc()
#define fetch2_SQA  fetchLo()
#define op1_SQA        *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_SQA        (void*)c.lo.w

#define fetch_LVA
#define fetch1_LVA  fetchLo()
#define fetch2_LVA  fetchHi()
#define op1_LVA        c.lo.w
#define op2_LVA        (void*)c.hi.w

#define fetch_LRA
#define fetch1_LRA  fetchIc()
#define fetch2_LRA  fetchLo()
#define op1_LRA        *(L_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_LRA        (void*)c.lo.w

#define fetch_LPA
#define fetch1_LPA fetchLo()
#define fetch2_LPA  fetchHi()
#define op1_LPA        *(L_t*)c.lo.w
#define op2_LPA        (void*)c.hi.w

#define fetch_LQA
#define fetch1_LQA  fetchIc()
#define fetch2_LQA  fetchLo()
#define op1_LQA        *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_LQA        (void*)c.lo.w

#define fetch_WVA
#define fetch1_WVA  fetchLo()
#define fetch2_WVA  fetchHi()
#define op1_WVA        c.lo.w
#define op2_WVA        (void*)c.hi.w

#define fetch_WRA
#define fetch1_WRA  fetchIc()
#define fetch2_WRA  fetchLo()
#define op1_WRA        *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRA        (void*)c.lo.w

#define fetch_WPA
#define fetch1_WPA  fetchLo()
#define fetch2_WPA  fetchHi()
#define op1_WPA        *(W_t*)c.lo.w
#define op2_WPA        (void*)c.hi.w

#define fetch_WQA
#define fetch1_WQA  fetchIc()
#define fetch2_WQA  fetchLo()
#define op1_WQA        *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQA        (void*)c.lo.w

#define fetch_DVA    /* This instruction cannot be encoded and has to be split up */
#define fetch1_DVA
#define fetch2_DVA
#define op1_DVA        c.lo.w
#define op2_DVA        c.lo.w

#define fetch_DRA
#define fetch1_DRA  fetchIc()
#define fetch2_DRA  fetchLo()
#define op1_DRA        *(D_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_DRA        (void*)c.lo.w

#define fetch_DPA
#define fetch1_DPA  fetchLo()
#define fetch2_DPA  fetchHi()
#define op1_DPA       *(D_t*)c.lo.w
#define op2_DPA        (void*)c.hi.w

#define fetch_DQA    fetchIc(); fetchLo()
#define fetch1_DQA  fetchIc()
#define fetch2_DQA  fetchLo()
#define op1_DQA        *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_DQA        (void*)c.lo.w

/* 3-op operand templates */

/* WR*V */
#define fetch_WRVV
#define fetch1_WRVV fetchIc()
#define fetch2_WRVV fetchLo()
#define fetch3_WRVV fetchHi()
#define op1_WRVV    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRVV    c.lo.w
#define op3_WRVV    c.hi.w

#define fetch_WRRV    fetchIc();
#define fetch1_WRRV
#define fetch2_WRRV
#define fetch3_WRRV    fetchLo()
#define op1_WRRV    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRRV    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRRV    c.lo.w

#define fetch_WRPV
#define fetch1_WRPV    fetchIc()
#define fetch2_WRPV    fetchLo()
#define fetch3_WRPV fetchHi()
#define op1_WRPV    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRPV    *(W_t*)c.lo.w
#define op3_WRPV    c.hi.w

#define fetch_WRQV    fetchIc();
#define fetch1_WRQV
#define fetch2_WRQV
#define fetch3_WRQV    fetchLo()
#define op1_WRQV    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRQV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRQV    c.lo.w
/* ---- */

/* ---- WP*V */
#define fetch_WPVV
#define fetch1_WPVV fetchIc()
#define fetch2_WPVV fetchLo()
#define fetch3_WPVV fetchHi()
#define op1_WPVV    *(W_t*)c.ic.w
#define op2_WPVV    c.lo.w
#define op3_WPVV    c.hi.w

#define fetch_WPRV
#define fetch1_WPRV fetchLo()
#define fetch2_WPRV fetchIc()
#define fetch3_WPRV    fetchHi()
#define op1_WPRV    *(W_t*)c.ic.w
#define op2_WPRV    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op3_WPRV    c.hi.w

#define fetch_WPPV
#define fetch1_WPPV    fetchIc()
#define fetch2_WPPV    fetchLo()
#define fetch3_WPPV fetchHi()
#define op1_WPPV    *(W_t*)c.ic.w
#define op2_WPPV    *(W_t*)c.lo.w
#define op3_WPPV    c.hi.w

#define fetch_WPQV
#define fetch1_WPQV    fetchLo()
#define fetch2_WPQV    fetchIc()
#define fetch3_WPQV    fetchHi()
#define op1_WPQV    *(W_t*)c.lo.w
#define op2_WPQV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op3_WPQV    c.hi.w
/* ---- */

/* ---- WQ*V */
#define fetch_WQVV
#define fetch1_WQVV fetchIc()
#define fetch2_WQVV fetchLo()
#define fetch3_WQVV fetchHi()
#define op1_WQVV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQVV    c.lo.w
#define op3_WQVV    c.hi.w

#define fetch_WQRV    fetchIc();
#define fetch1_WQRV
#define fetch2_WQRV
#define fetch3_WQRV    fetchLo()
#define op1_WQRV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQRV    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQRV    c.lo.w

#define fetch_WQPV
#define fetch1_WQPV    fetchIc()
#define fetch2_WQPV    fetchLo()
#define fetch3_WQPV fetchHi()
#define op1_WQPV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQPV    *(W_t*)c.lo.w
#define op3_WQPV    c.hi.w

#define fetch_WQQV    fetchIc();
#define fetch1_WQQV
#define fetch2_WQQV
#define fetch3_WQQV    fetchLo()
#define op1_WQQV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQQV    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQQV    c.lo.w
/* ---- */

/* ---- WR*R */
#define fetch_WRVR  fetchIc()
#define fetch1_WRVR 
#define fetch2_WRVR fetchLo()
#define fetch3_WRVR
#define op1_WRVR    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRVR    c.lo.w
#define op3_WRVR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WRRR    fetchIc();
#define fetch1_WRRR
#define fetch2_WRRR
#define fetch3_WRRR    fetchLo()
#define op1_WRRR    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRRR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRRR    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)

#define fetch_WRPR     fetchIc()
#define fetch1_WRPR    
#define fetch2_WRPR    fetchLo()
#define fetch3_WRPR
#define op1_WRPR    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRPR    *(W_t*)c.lo.w
#define op3_WRPR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WRQR    fetchIc();
#define fetch1_WRQR
#define fetch2_WRQR
#define fetch3_WRQR    fetchLo()
#define op1_WRQR    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRQR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRQR    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
// ----

// ---- WP*R
#define fetch_WPVR
#define fetch1_WPVR fetchIc()
#define fetch2_WPVR fetchLo()
#define fetch3_WPVR fetchHi()
#define op1_WPVR    *(W_t*)c.ic.w
#define op2_WPVR    c.lo.w
#define op3_WPVR    *(W_t*)CX_OFFSET(reg,c.hi.s.b._1)

#define fetch_WPRR  fetchLo()
#define fetch1_WPRR fetchIc()
#define fetch2_WPRR
#define fetch3_WPRR
#define op1_WPRR    *(W_t*)c.ic.w
#define op2_WPRR    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPRR    *(W_t*)CX_OFFSET(reg,c.lo.s.b._2)

#define fetch_WPPR
#define fetch1_WPPR    fetchIc()
#define fetch2_WPPR    fetchLo()
#define fetch3_WPPR fetchHi()
#define op1_WPPR    *(W_t*)c.ic.w
#define op2_WPPR    *(W_t*)c.lo.w
#define op3_WPPR    *(W_t*)CX_OFFSET(reg,c.hi.s.b._1)

#define fetch_WPQR     fetchIc()
#define fetch1_WPQR    fetchLo()
#define fetch2_WPQR    
#define fetch3_WPQR
#define op1_WPQR    *(W_t*)c.lo.w
#define op2_WPQR    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op3_WPQR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
/* ---- */

/* ---- WQ*R */
#define fetch_WQVR  fetchIc()
#define fetch1_WQVR 
#define fetch2_WQVR fetchLo()
#define fetch3_WQVR
#define op1_WQVR    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQVR    c.lo.w
#define op3_WQVR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WQRR    fetchIc();
#define fetch1_WQRR
#define fetch2_WQRR
#define fetch3_WQRR    fetchLo()
#define op1_WQRR    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQRR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQRR    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)

#define fetch_WQPR     fetchIc()
#define fetch1_WQPR    
#define fetch2_WQPR    fetchLo()
#define fetch3_WQPR
#define op1_WQPR    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQPR    *(W_t*)c.lo.w
#define op3_WQPR    *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WQQR    fetchIc();
#define fetch1_WQQR
#define fetch2_WQQR
#define fetch3_WQQR    fetchLo()
#define op1_WQQR    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQQR    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQQR    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
/* ---- */

/* ---- WQ*P */
#define fetch_WRVP
#define fetch1_WRVP fetchIc()
#define fetch2_WRVP fetchLo()
#define fetch3_WRVP fetchHi()
#define op1_WRVP    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRVP    c.lo.w
#define op3_WRVP    *(W_t*)c.hi.w

#define fetch_WRRP    fetchIc();
#define fetch1_WRRP
#define fetch2_WRRP
#define fetch3_WRRP    fetchLo()
#define op1_WRRP    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRRP    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRRP    *(W_t*)c.lo.w

#define fetch_WRPP
#define fetch1_WRPP    fetchIc()
#define fetch2_WRPP    fetchLo()
#define fetch3_WRPP fetchHi()
#define op1_WRPP    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRPP    *(W_t*)c.lo.w
#define op3_WRPP    *(W_t*)c.hi.w

#define fetch_WRQP    fetchIc();
#define fetch1_WRQP
#define fetch2_WRQP
#define fetch3_WRQP    fetchLo()
#define op1_WRQP    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRQP    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRQP    *(W_t*)c.lo.w
/* ---- */

/* ---- WP*P */
#define fetch_WPVP
#define fetch1_WPVP fetchIc()
#define fetch2_WPVP fetchLo()
#define fetch3_WPVP fetchHi()
#define op1_WPVP    *(W_t*)c.ic.w
#define op2_WPVP    c.lo.w
#define op3_WPVP    *(W_t*)c.hi.w

#define fetch_WPRP
#define fetch1_WPRP    fetchIc()
#define fetch2_WPRP    fetchLo()
#define fetch3_WPRP    fetchHi()
#define op1_WPRP    *(W_t*)c.ic.w
#define op2_WPRP    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPRP    *(W_t*)c.hi.w

#define fetch_WPPP
#define fetch1_WPPP    fetchIc()
#define fetch2_WPPP    fetchLo()
#define fetch3_WPPP    fetchHi()
#define op1_WPPP    *(W_t*)c.ic.w
#define op2_WPPP    *(W_t*)c.lo.w
#define op3_WPPP    *(W_t*)c.hi.w

#define fetch_WPQP
#define fetch1_WPQP    fetchIc()
#define fetch2_WPQP    fetchLo()
#define fetch3_WPQP    fetchHi()
#define op1_WPQP    *(W_t*)c.ic.w
#define op2_WPQP    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPQP    *(W_t*)c.hi.w
/* ---- */

/* ---- WQ*P */
#define fetch_WQVP
#define fetch1_WQVP fetchIc()
#define fetch2_WQVP fetchLo()
#define fetch3_WQVP fetchHi()
#define op1_WQVP    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQVP    c.lo.w
#define op3_WQVP    *(W_t*)c.hi.w

#define fetch_WQRP    fetchIc();
#define fetch1_WQRP
#define fetch2_WQRP
#define fetch3_WQRP    fetchLo()
#define op1_WQRP    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQRP    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQRP    *(W_t*)c.lo.w

#define fetch_WQPP
#define fetch1_WQPP    fetchIc()
#define fetch2_WQPP    fetchLo()
#define fetch3_WQPP fetchHi()
#define op1_WQPP    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQPP    *(W_t*)c.lo.w
#define op3_WQPP    *(W_t*)c.hi.w

#define fetch_WQQP    fetchIc();
#define fetch1_WQQP
#define fetch2_WQQP
#define fetch3_WQQP    fetchLo()
#define op1_WQQP    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQQP    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQQP    *(W_t*)c.lo.w
/* ---- */

/* ---- WR*Q */
#define fetch_WPVQ
#define fetch1_WPVQ fetchIc()
#define fetch2_WPVQ fetchLo()
#define fetch3_WPVQ fetchHi()
#define op1_WPVQ    *(W_t*)c.ic.w
#define op2_WPVQ    c.lo.w
#define op3_WPVQ    *(W_t*)*(void**)CX_OFFSET(reg,c.hi.s.b._1)

#define fetch_WPRQ     fetchLo()
#define fetch1_WPRQ    fetchIc()
#define fetch2_WPRQ    
#define fetch3_WPRQ
#define op1_WPRQ    *(W_t*)c.ic.w
#define op2_WPRQ    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPRQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._2)

#define fetch_WPPQ
#define fetch1_WPPQ    fetchIc()
#define fetch2_WPPQ    fetchLo()
#define fetch3_WPPQ    fetchHi()
#define op1_WPPQ    *(W_t*)c.ic.w
#define op2_WPPQ    *(W_t*)c.lo.w
#define op3_WPPQ    *(W_t*)*(void**)CX_OFFSET(reg,c.hi.s.b._1)

#define fetch_WPQQ     fetchLo()
#define fetch1_WPQQ    fetchIc()
#define fetch2_WPQQ
#define fetch3_WPQQ
#define op1_WPQQ    *(W_t*)c.ic.w
#define op2_WPQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._2)
/* ---- */

/* ---- WR*V */
#define fetch_WRVQ  fetchIc()
#define fetch1_WRVQ
#define fetch2_WRVQ fetchLo()
#define fetch3_WRVQ
#define op1_WRVQ    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRVQ    c.lo.w
#define op3_WRVQ    *(W_t*)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WRRQ     fetchIc();
#define fetch1_WRRQ
#define fetch2_WRRQ
#define fetch3_WRRQ    fetchLo()
#define op1_WRRQ    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRRQ    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRRQ    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)

#define fetch_WRPQ     fetchIc()
#define fetch1_WRPQ
#define fetch2_WRPQ    fetchLo()
#define fetch3_WRPQ
#define op1_WRPQ    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRPQ    *(W_t*)c.lo.w
#define op3_WRPQ    *(W_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WRQQ     fetchIc()
#define fetch1_WRQQ
#define fetch2_WRQQ
#define fetch3_WRQQ    fetchLo()
#define op1_WRQQ    *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRQQ    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WRQQ    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
/* ---- */

/* ---- WP*Q */
#define fetch_WPVQ
#define fetch1_WPVQ fetchIc()
#define fetch2_WPVQ fetchLo()
#define fetch3_WPVQ fetchHi()
#define op1_WPVQ    *(W_t*)c.ic.w
#define op2_WPVQ    c.lo.w
#define op3_WPVQ    *(W_t*)*(void**)CX_OFFSET(reg,c.hi.s.b._1)

#define fetch_WPRQ     fetchLo()
#define fetch1_WPRQ    fetchIc()
#define fetch2_WPRQ    
#define fetch3_WPRQ
#define op1_WPRQ    *(W_t*)c.ic.w
#define op2_WPRQ    *(W_t*)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPRQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._2)

#define fetch_WPPQ
#define fetch1_WPPQ    fetchIc()
#define fetch2_WPPQ    fetchLo()
#define fetch3_WPPQ    fetchHi()
#define op1_WPPQ    *(W_t*)c.ic.w
#define op2_WPPQ    *(W_t*)c.lo.w
#define op3_WPPQ    *(W_t*)*(void**)CX_OFFSET(reg,c.hi.s.b._1)

#define fetch_WPQQ     fetchLo()
#define fetch1_WPQQ    fetchIc()
#define fetch2_WPQQ
#define fetch3_WPQQ
#define op1_WPQQ    *(W_t*)c.ic.w
#define op2_WPQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._1)
#define op3_WPQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._2)
/* ---- */

/* ---- WQ*Q */
#define fetch_WQVQ  fetchIc()
#define fetch1_WQVQ
#define fetch2_WQVQ fetchLo()
#define fetch3_WQVQ
#define op1_WQVQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQVQ    c.lo.w
#define op3_WQVQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)

#define fetch_WQRQ     fetchIc();
#define fetch1_WQRQ
#define fetch2_WQRQ
#define fetch3_WQRQ    fetchLo()
#define op1_WQRQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQRQ    *(W_t*)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQRQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._1)

#define fetch_WQPQ     fetchIc()
#define fetch1_WQPQ
#define fetch2_WQPQ    fetchLo()
#define fetch3_WQPQ
#define op1_WQPQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQPQ    *(W_t*)c.lo.w
#define op3_WQPQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WQQQ     fetchIc()
#define fetch1_WQQQ
#define fetch2_WQQQ
#define fetch3_WQQQ    fetchLo()
#define op1_WQQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._2)
#define op3_WQQQ    *(W_t*)*(void**)CX_OFFSET(reg,c.lo.s.b._1)
/* ---- */

/* Single operand templates */
#define fetch_BV    fetchIc();
#define op1x_BV      ic.b._1
#define op1_BV       (B_t)c.op1x_BV

#define fetch_BR    fetchIc();
#define op1_BR      *(B_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_BP    fetchLo()
#define op1_BP      *(B_t*)c.lo.w

#define fetch_BQ    fetchIc();
#define op1_BQ       *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_SV    fetchIc();
#define op1x_SV      ic.b._1
#define op1_SV       c.op1x_SV

#define fetch_SR    fetchIc();
#define op1_SR       *(S_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_SP    fetchLo()
#define op1_SP       *(S_t*)c.lo.w

#define fetch_SQ    fetchIc();
#define op1_SQ       *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LV    fetchLo()
#define op1x_LV      lo.w
#define op1_LV       c.op1x_LV

#define fetch_LR    fetchIc();
#define op1_LR       *(L_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LP    fetchLo()
#define op1_LP       *(L_t*)c.lo.w

#define fetch_LQ    fetchIc();
#define op1_LQ       *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WV    fetchLo()
#define op1x_WV      lo.w
#define op1_WV       c.op1x_WV

#define fetch_WA    fetchLo();
#define op1x_WA      lo.w
#define op1_WA      c.op1x_WV

#define fetch_WR    fetchIc();
#define op1_WR       *(W_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WP    fetchLo()
#define op1_WP       *(W_t*)c.lo.w

#define fetch_WQ    fetchIc();
#define op1_WQ       *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DV    fetchDbl()
#define op1x_DV      lo.w
#define op1_DV       c.dbl

#define fetch_DR    fetchIc();
#define op1_DR       *(D_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DP    fetchLo()
#define op1_DP       *(D_t*)c.lo.w

#define fetch_DQ    fetchIc();
#define op1_DQ       *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#endif /* CX_VM_OPERANDS_H_ */
