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

#define fetch_BRR    fetchIc();
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


/* Label instructions */
#define fetch_BVL
#define fetch1_BVL    fetchIc()
#define fetch2_BVL    fetchLo()
#define op1_BVL        c.ic.b._1
#define op2_BVL        (cx_vmOp*)c.lo.w

#define fetch_BRL
#define fetch1_BRL  fetchIc()
#define fetch2_BRL  fetchLo()
#define op1_BRL        *(B_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_BRL        (cx_vmOp*)c.lo.w

#define fetch_BPL
#define fetch1_BPL  fetchLo()
#define fetch2_BPL  fetchHi()
#define op1_BPL        *(B_t*)c.lo.w
#define op2_BPL        (cx_vmOp*)c.hi.w

#define fetch_BQL
#define fetch1_BQL  fetchIc()
#define fetch2_BQL  fetchLo()
#define op1_BQL        *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_BQL        (cx_vmOp*)c.lo.w

#define fetch_SVL
#define fetch1_SVL  fetchIc()
#define fetch2_SVL  fetchLo()
#define op1_SVL        c.ic.b._1
#define op2_SVL        (cx_vmOp*)c.lo.w

#define fetch_SRL
#define fetch1_SRL  fetchIc()
#define fetch2_SRL  fetchLo()
#define op1_SRL        *(S_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_SRL        (cx_vmOp*)c.lo.w

#define fetch_SPL
#define fetch1_SPL  fetchLo()
#define fetch2_SPL  fetchHi()
#define op1_SPL        *(S_t*)c.lo.w
#define op2_SPL        (cx_vmOp*)c.hi.w

#define fetch_SQL
#define fetch1_SQL  fetchIc()
#define fetch2_SQL  fetchLo()
#define op1_SQL        *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_SQL        (cx_vmOp*)c.lo.w

#define fetch_LVL
#define fetch1_LVL  fetchLo()
#define fetch2_LVL  fetchHi()
#define op1_LVL        c.lo.w
#define op2_LVL        (cx_vmOp*)c.hi.w

#define fetch_LRL
#define fetch1_LRL  fetchIc()
#define fetch2_LRL  fetchLo()
#define op1_LRL        *(L_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_LRL        (cx_vmOp*)c.lo.w

#define fetch_LPL
#define fetch1_LPL  fetchLo()
#define fetch2_LPL  fetchHi()
#define op1_LPL        *(L_t*)c.lo.w
#define op2_LPL        (cx_vmOp*)c.hi.w

#define fetch_LQL
#define fetch1_LQL  fetchIc()
#define fetch2_LQL  fetchLo()
#define op1_LQL        *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_LQL        (cx_vmOp*)c.lo.w

#define fetch_WVL
#define fetch1_WVL  fetchLo()
#define fetch2_WVL  fetchHi()
#define op1_WVL        c.lo.w
#define op2_WVL        (cx_vmOp*)c.hi.w

#define fetch_WRL
#define fetch1_WRL  fetchIc()
#define fetch2_WRL  fetchLo()
#define op1_WRL        *(W_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_WRL        (cx_vmOp*)c.lo.w

#define fetch_WPL
#define fetch1_WPL  fetchLo()
#define fetch2_WPL  fetchHi()
#define op1_WPL        *(W_t*)c.lo.w
#define op2_WPL        (cx_vmOp*)c.hi.w

#define fetch_WQL
#define fetch1_WQL  fetchIc()
#define fetch2_WQL  fetchLo()
#define op1_WQL        *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_WQL        (cx_vmOp*)c.lo.w

#define fetch_DVL    /* This instruction cannot be encoded and has to be split up */
#define fetch1_DVL
#define fetch2_DVL
#define op1_DVL        c.lo.w
#define op2_DVL        c.lo.w

#define fetch_DRL
#define fetch1_DRL  fetchIc()
#define fetch2_DRL  fetchLo()
#define op1_DRL        *(D_t*)CX_OFFSET(reg,c.ic.b._1)
#define op2_DRL        (cx_vmOp*)c.lo.w

#define fetch_DPL
#define fetch1_DPL  fetchLo()
#define fetch2_DPL  fetchHi()
#define op1_DPL        *(D_t*)c.lo.w
#define op2_DPL        (cx_vmOp*)c.hi.w

#define fetch_DQL    fetchIc(); fetchLo()
#define fetch1_DQL  fetchIc()
#define fetch2_DQL  fetchLo()
#define op1_DQL        *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)
#define op2_DQL        (cx_vmOp*)c.lo.w

/* 3-op operand templates */

/* LR*V */
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

/* LP*V */
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

/* LQ*V */
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

/* Single operand templates */
#define fetch_BV    fetchIc();
#define opx_BV      ic.b._1
#define op_BV       (B_t)c.opx_BV

#define fetch_BR    fetchIc();
#define op_BR      *(B_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_BP    fetchLo()
#define op_BP      *(B_t*)c.lo.w

#define fetch_BQ    fetchIc();
#define op_BQ       *(B_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_SV    fetchIc();
#define opx_SV      ic.b._1
#define op_SV       c.opx_SV

#define fetch_SR    fetchIc();
#define op_SR       *(S_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_SP    fetchLo()
#define op_SP       *(S_t*)c.lo.w

#define fetch_SQ    fetchIc();
#define op_SQ       *(S_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LV    fetchLo()
#define opx_LV      lo.w
#define op_LV       c.opx_LV

#define fetch_LR    fetchIc();
#define op_LR       *(L_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_LP    fetchLo()
#define op_LP       *(L_t*)c.lo.w

#define fetch_LQ    fetchIc();
#define op_LQ       *(L_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WV    fetchLo()
#define opx_WV      lo.w
#define op_WV       c.opx_WV

#define fetch_WR    fetchIc();
#define op_WR       *(W_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_WP    fetchLo()
#define op_WP       *(W_t*)c.lo.w

#define fetch_WQ    fetchIc();
#define op_WQ       *(W_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DV    fetchDbl()
#define opx_DV      lo.w
#define op_DV       c.dbl

#define fetch_DR    fetchIc();
#define op_DR       *(D_t*)CX_OFFSET(reg,c.ic.b._1)

#define fetch_DP    fetchLo()
#define op_DP       *(D_t*)c.lo.w

#define fetch_DQ    fetchIc();
#define op_DQ       *(D_t*)*(void**)CX_OFFSET(reg,c.ic.b._1)

#endif /* CX_VM_OPERANDS_H_ */
