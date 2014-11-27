/*
 * db_vm_operands.h
 *
 *  Created on: Aug 31, 2013
 *      Author: sander
 */

#ifndef DB_VM_OPERANDS_H_
#define DB_VM_OPERANDS_H_

typedef uint8_t     B_t;
typedef uint16_t    S_t;
typedef uintptr_t   L_t;
typedef uint64_t    D_t;

/* Signed numbers */
typedef int8_t     Bs_t;
typedef int16_t    Ss_t;
typedef int32_t    Ls_t;
typedef int64_t    Ds_t;

/* Staged variables */
#define stage1_B	c.stage1.s.b._1
#define stage2_B	c.stage1.s.b._2
#define stage1_S	c.stage1.s.b._1
#define stage2_S	c.stage1.s.b._2
#define stage1_L	c.stage1.w
#define stage2_L	c.stage2.w
#define stage1_D	c.dbl
#define stage2_D	c.dbl2

/* Instructions */
#define fetch(t,l,r) fetch_##t##l##r()

/* Byte */
#define fetch_BVV	fetchIc()
#define fetch1_BVV
#define fetch2_BVV
#define op1_BVV		c.ic.b._1
#define op2_BVV		c.ic.b._2

#define fetch_BVR	fetchIc()
#define fetch1_BVR
#define fetch2_BVR
#define op1_BVR		c.ic.b._1
#define op2_BVR		*(B_t*)DB_OFFSET(reg, c.ic.b._2)

#define fetch_BVP
#define fetch1_BVP	fetchIc()
#define fetch2_BVP	fetchLo()
#define op1_BVP		c.ic.b._1
#define op2_BVP		*(B_t*)c.lo.w

#define fetch_BVQ	fetchIc()
#define fetch1_BVQ
#define fetch2_BVQ
#define op1_BVQ		c.ic.b._1
#define op2_BVQ		*(B_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_BPV
#define fetch1_BPV   fetchLo()
#define fetch2_BPV   fetchIc()
#define op1_BPV     *(B_t*)c.lo.w
#define op2_BPV     (B_t)c.ic.b._1

#define fetch_BPR
#define fetch1_BPR   fetchLo()
#define fetch2_BPR   fetchIc()
#define op1_BPR     *(B_t*)c.lo.w
#define op2_BPR     *(B_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_BPP
#define fetch1_BPP   fetchLo()
#define fetch2_BPP   fetchHi()
#define op1_BPP     *(B_t*)c.lo.w
#define op2_BPP     *(B_t*)c.hi.w

#define fetch_BPQ
#define fetch1_BPQ   fetchLo()
#define fetch2_BPQ   fetchIc()
#define op1_BPQ     *(B_t*)c.lo.w
#define op2_BPQ     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_BRV   fetchIc()
#define fetch1_BRV
#define fetch2_BRV
#define op1_BRV     *(B_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_BRV     (B_t)c.ic.b._2

#define fetch_BRR	fetchIc();
#define fetch1_BRR
#define fetch2_BRR
#define op1_BRR     *(B_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_BRR     *(B_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_BRP
#define fetch1_BRP  fetchIc()
#define fetch2_BRP  fetchLo()
#define op1_BRP     *(B_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_BRP     *(B_t*)c.lo.w

#define fetch_BRQ	fetchIc()
#define fetch1_BRQ
#define fetch2_BRQ
#define op1_BRQ     *(B_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_BRQ     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

#define fetch_BQV	fetchIc()
#define fetch1_BQV
#define fetch2_BQV
#define op1_BQV     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_BQV     (B_t)c.ic.b._2

#define fetch_BQR	fetchIc()
#define fetch1_BQR
#define fetch2_BQR
#define op1_BQR     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_BQR     *(B_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_BQP
#define fetch1_BQP  fetchIc()
#define fetch2_BQP  fetchLo()
#define op1_BQP     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_BQP     *(B_t*)c.lo.w

#define fetch_BQQ	fetchIc()
#define fetch1_BQQ
#define fetch2_BQQ
#define op1_BQQ     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_BQQ     *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

/* Short */
#define fetch_SVV	fetchIc()
#define fetch1_SVV
#define fetch2_SVV
#define op1_SVV     c.ic.b._1
#define op2_SVV     c.ic.b._2

#define fetch_SVR	fetchIc()
#define fetch1_SVR
#define fetch2_SVR
#define op1_SVR     c.ic.b._1
#define op2_SVR     *(S_t*)DB_OFFSET(reg, c.ic.b._2)

#define fetch_SVP
#define fetch1_SVP	fetchIc()
#define fetch2_SVP	fetchLo()
#define op1_SVP     c.ic.b._1
#define op2_SVP     *(S_t*)c.lo.w

#define fetch_SVQ	fetchIc()
#define fetch1_SVQ
#define fetch2_SVQ
#define op1_SVQ     c.ic.b._1
#define op2_SVQ     *(S_t*)*(void**)DB_OFFSET(reg, c.ic.b._2)

#define fetch_SPV
#define fetch1_SPV  fetchLo()
#define fetch2_SPV  fetchIc()
#define op1_SPV     *(S_t*)c.lo.w
#define op2_SPV     c.ic.s

#define fetch_SPR
#define fetch1_SPR  fetchLo()
#define fetch2_SPR  fetchIc()
#define op1_SPR     *(S_t*)c.lo.w
#define op2_SPR     *(S_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_SPP
#define fetch1_SPP  fetchLo()
#define fetch2_SPP  fetchHi()
#define op1_SPP     *(S_t*)c.lo.w
#define op2_SPP     *(S_t*)c.hi.w

#define fetch_SPQ
#define fetch1_SPQ  fetchLo()
#define fetch2_SPQ  fetchIc()
#define op1_SPQ     *(S_t*)c.lo.w
#define op2_SPQ     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_SRV	fetchIc()
#define fetch1_SRV
#define fetch2_SRV
#define op1_SRV     *(S_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_SRV     c.ic.b._2

#define fetch_SRR	fetchIc()
#define fetch1_SRR
#define fetch2_SRR
#define op1_SRR     *(S_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_SRR     *(S_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_SRP
#define fetch1_SRP  fetchIc()
#define fetch2_SRP  fetchLo()
#define op1_SRP     *(S_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_SRP     *(S_t*)c.lo.w

#define fetch_SRQ	fetchIc()
#define fetch1_SRQ
#define fetch2_SRQ
#define op1_SRQ     *(S_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_SRQ     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

#define fetch_SQV
#define fetch1_SQV  fetchIc()
#define fetch2_SQV  fetchLo()
#define op1_SQV     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_SQV     (S_t)c.lo.w

#define fetch_SQR	fetchIc()
#define fetch1_SQR
#define fetch2_SQR
#define op1_SQR     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_SQR     *(S_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_SQP
#define fetch1_SQP  fetchIc()
#define fetch2_SQP  fetchLo()
#define op1_SQP     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_SQP     *(S_t*)c.lo.w

#define fetch_SQQ	fetchIc()
#define fetch1_SQQ
#define fetch2_SQQ
#define op1_SQQ     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_SQQ     *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

/* Long */
#define fetch_LVV
#define fetch1_LVV	fetchLo()
#define fetch2_LVV	fetchHi()
#define op1_LVV		c.lo.w
#define op2_LVV		c.hi.w

#define fetch_LVR
#define fetch1_LVR	fetchLo()
#define fetch2_LVR	fetchIc()
#define op1_LVR		c.lo.w
#define op2_LVR		*(L_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_LVP
#define fetch1_LVP	fetchLo()
#define fetch2_LVP	fetchHi()
#define op1_LVP		c.lo.w
#define op2_LVP		*(L_t*)c.hi.w

#define fetch_LVQ
#define fetch1_LVQ	fetchLo()
#define fetch2_LVQ	fetchIc()
#define op1_LVQ		c.lo.w
#define op2_LVQ		*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_LRV
#define fetch1_LRV  fetchIc()
#define fetch2_LRV  fetchLo()
#define op1_LRV     *(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRV     c.lo.w

#define fetch_LRR	fetchIc()
#define fetch1_LRR
#define fetch2_LRR
#define op1_LRR     *(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRR     *(L_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_LRP
#define fetch1_LRP  fetchIc()
#define fetch2_LRP  fetchLo()
#define op1_LRP     *(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRP     *(L_t*)c.lo.w

#define fetch_LRQ	fetchIc()
#define fetch1_LRQ
#define fetch2_LRQ
#define op1_LRQ     *(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRQ     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

#define fetch_LPV
#define fetch1_LPV  fetchLo()
#define fetch2_LPV  fetchHi()
#define op1_LPV     *(L_t*)c.lo.w
#define op2_LPV     c.hi.w

#define fetch_LPR
#define fetch1_LPR  fetchLo()
#define fetch2_LPR  fetchIc()
#define op1_LPR     *(L_t*)c.lo.w
#define op2_LPR     *(L_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_LPP
#define fetch1_LPP  fetchLo()
#define fetch2_LPP  fetchHi()
#define op1_LPP     *(L_t*)c.lo.w
#define op2_LPP     *(L_t*)c.hi.w

#define fetch_LPQ
#define fetch1_LPQ  fetchLo()
#define fetch2_LPQ  fetchIc()
#define op1_LPQ     *(L_t*)c.lo.w
#define op2_LPQ     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_LQV
#define fetch1_LQV  fetchIc()
#define fetch2_LQV  fetchLo()
#define op1_LQV     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQV     (L_t)c.lo.w

#define fetch_LQR	fetchIc()
#define fetch1_LQR
#define fetch2_LQR
#define op1_LQR     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQR     *(L_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_LQP
#define fetch1_LQP  fetchIc()
#define fetch2_LQP  fetchLo()
#define op1_LQP     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQP     *(L_t*)c.lo.w

#define fetch_LQQ	fetchIc()
#define fetch1_LQQ
#define fetch2_LQQ
#define op1_LQQ     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQQ     *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

/* Double */
#define fetch_DVV	/* This instruction cannot be encoded and has to be split up */
#define fetch1_DVV
#define fetch2_DVV
#define op1_DVV     c.lo.w	/* Placeholder */
#define op2_DVV     c.lo.w	/* Placeholder */

#define fetch_DVR
#define fetch1_DVR	fetchDbl()
#define fetch2_DVR	fetchIc()
#define op1_DVR     c.dbl
#define op2_DVR     *(D_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_DVP	/* This instruction cannot be encoded and has to be split up */
#define fetch1_DVP
#define fetch2_DVP
#define op1_DVP     c.lo.w /* Placeholder */
#define op2_DVP     c.lo.w /* Placeholder */

#define fetch_DVQ
#define fetch1_DVQ	fetchDbl()
#define fetch2_DVQ	fetchIc()
#define op1_DVQ     c.dbl /* Placeholder */
#define op2_DVQ     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_DRV
#define fetch1_DRV  fetchIc()
#define fetch2_DRV  fetchDbl()
#define op1_DRV     *(D_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_DRV     c.dbl

#define fetch_DRR	fetchIc()
#define fetch1_DRR
#define fetch2_DRR
#define op1_DRR     *(D_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_DRR     *(D_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_DRP
#define fetch1_DRP  fetchIc()
#define fetch2_DRP  fetchLo()
#define op1_DRP     *(D_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_DRP     *(D_t*)c.lo.w

#define fetch_DRQ	fetchIc()
#define fetch1_DRQ
#define fetch2_DRQ
#define op1_DRQ     *(D_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_DRQ     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)

#define fetch_DPV
#define fetch1_DPV  fetchIc()
#define fetch2_DPV  fetchDbl()
#define op1_DPV		*(D_t*)c.ic.w
#define op2_DPV		c.dbl

#define fetch_DPR
#define fetch1_DPR  fetchLo()
#define fetch2_DPR  fetchIc()
#define op1_DPR     *(D_t*)c.lo.w
#define op2_DPR     *(D_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_DPP
#define fetch1_DPP  fetchLo()
#define fetch2_DPP  fetchHi()
#define op1_DPP     *(D_t*)c.lo.w
#define op2_DPP     *(D_t*)c.hi.w

#define fetch_DPQ
#define fetch1_DPQ  fetchLo()
#define fetch2_DPQ  fetchIc()
#define op1_DPQ     *(D_t*)c.lo.w
#define op2_DPQ     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_DQV
#define fetch1_DQV  fetchIc()
#define fetch2_DQV  fetchDbl()
#define op1_DQV     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_DQV     c.dbl

#define fetch_DQR	fetchIc()
#define fetch1_DQR
#define fetch2_DQR
#define op1_DQR     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_DQR     *(D_t*)DB_OFFSET(reg,c.ic.b._2)

#define fetch_DQP
#define fetch1_DQP  fetchIc()
#define fetch2_DQP  fetchLo()
#define op1_DQP     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_DQP     *(D_t*)c.lo.w

#define fetch_DQQ	fetchIc();
#define fetch1_DQQ
#define fetch2_DQQ
#define op1_DQQ     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_DQQ     *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)


/* Label instructions */
#define fetch_BVL
#define fetch1_BVL	fetchIc()
#define fetch2_BVL	fetchLo()
#define op1_BVL		c.ic.b._1
#define op2_BVL		(db_vmOp*)c.lo.w

#define fetch_BRL
#define fetch1_BRL  fetchIc()
#define fetch2_BRL  fetchLo()
#define op1_BRL		*(B_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_BRL		(db_vmOp*)c.lo.w

#define fetch_BPL
#define fetch1_BPL  fetchLo()
#define fetch2_BPL  fetchHi()
#define op1_BPL		*(B_t*)c.lo.w
#define op2_BPL		(db_vmOp*)c.hi.w

#define fetch_BQL
#define fetch1_BQL  fetchIc()
#define fetch2_BQL  fetchLo()
#define op1_BQL		*(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_BQL		(db_vmOp*)c.lo.w

#define fetch_SVL
#define fetch1_SVL  fetchIc()
#define fetch2_SVL  fetchLo()
#define op1_SVL		c.ic.b._1
#define op2_SVL		(db_vmOp*)c.lo.w

#define fetch_SRL
#define fetch1_SRL  fetchIc()
#define fetch2_SRL  fetchLo()
#define op1_SRL		*(S_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_SRL		(db_vmOp*)c.lo.w

#define fetch_SPL
#define fetch1_SPL  fetchLo()
#define fetch2_SPL  fetchHi()
#define op1_SPL		*(S_t*)c.lo.w
#define op2_SPL		(db_vmOp*)c.hi.w

#define fetch_SQL
#define fetch1_SQL  fetchIc()
#define fetch2_SQL  fetchLo()
#define op1_SQL		*(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_SQL		(db_vmOp*)c.lo.w

#define fetch_LVL
#define fetch1_LVL  fetchLo()
#define fetch2_LVL  fetchHi()
#define op1_LVL		c.lo.w
#define op2_LVL		(db_vmOp*)c.hi.w

#define fetch_LRL
#define fetch1_LRL  fetchIc()
#define fetch2_LRL  fetchLo()
#define op1_LRL		*(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRL		(db_vmOp*)c.lo.w

#define fetch_LPL
#define fetch1_LPL  fetchLo()
#define fetch2_LPL  fetchHi()
#define op1_LPL		*(L_t*)c.lo.w
#define op2_LPL		(db_vmOp*)c.hi.w

#define fetch_LQL
#define fetch1_LQL  fetchIc()
#define fetch2_LQL  fetchLo()
#define op1_LQL		*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQL		(db_vmOp*)c.lo.w

#define fetch_DVL	/* This instruction cannot be encoded and has to be split up */
#define fetch1_DVL
#define fetch2_DVL
#define op1_DVL		c.lo.w
#define op2_DVL		c.lo.w

#define fetch_DRL
#define fetch1_DRL  fetchIc()
#define fetch2_DRL  fetchLo()
#define op1_DRL		*(D_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_DRL		(db_vmOp*)c.lo.w

#define fetch_DPL
#define fetch1_DPL  fetchLo()
#define fetch2_DPL  fetchHi()
#define op1_DPL		*(D_t*)c.lo.w
#define op2_DPL		(db_vmOp*)c.hi.w

#define fetch_DQL	fetchIc(); fetchLo()
#define fetch1_DQL  fetchIc()
#define fetch2_DQL  fetchLo()
#define op1_DQL		*(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_DQL		(db_vmOp*)c.lo.w

/* 3-op operand templates */

/* LR*V */
#define fetch_LRVV
#define fetch1_LRVV fetchIc()
#define fetch2_LRVV fetchLo()
#define fetch3_LRVV fetchHi()
#define op1_LRVV	*(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRVV	c.lo.w
#define op3_LRVV	c.hi.w

#define fetch_LRRV	fetchIc();
#define fetch1_LRRV
#define fetch2_LRRV
#define fetch3_LRRV	fetchLo()
#define op1_LRRV	*(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRRV	*(L_t*)DB_OFFSET(reg,c.ic.b._2)
#define op3_LRRV	c.lo.w

#define fetch_LRPV
#define fetch1_LRPV	fetchIc()
#define fetch2_LRPV	fetchLo()
#define fetch3_LRPV fetchHi()
#define op1_LRPV	*(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRPV	*(L_t*)c.lo.w
#define op3_LRPV	c.hi.w

#define fetch_LRQV	fetchIc();
#define fetch1_LRQV
#define fetch2_LRQV
#define fetch3_LRQV	fetchLo()
#define op1_LRQV	*(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op2_LRQV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)
#define op3_LRQV	c.lo.w

/* LP*V */
#define fetch_LPVV
#define fetch1_LPVV fetchIc()
#define fetch2_LPVV fetchLo()
#define fetch3_LPVV fetchHi()
#define op1_LPVV	*(L_t*)c.ic.w
#define op2_LPVV	c.lo.w
#define op3_LPVV	c.hi.w

#define fetch_LPRV
#define fetch1_LPRV fetchLo()
#define fetch2_LPRV fetchIc()
#define fetch3_LPRV	fetchHi()
#define op1_LPRV	*(L_t*)c.ic.w
#define op2_LPRV	*(L_t*)DB_OFFSET(reg,c.ic.b._1)
#define op3_LPRV	c.hi.w

#define fetch_LPPV
#define fetch1_LPPV	fetchIc()
#define fetch2_LPPV	fetchLo()
#define fetch3_LPPV fetchHi()
#define op1_LPPV	*(L_t*)c.ic.w
#define op2_LPPV	*(L_t*)c.lo.w
#define op3_LPPV	c.hi.w

#define fetch_LPQV
#define fetch1_LPQV	fetchLo()
#define fetch2_LPQV	fetchIc()
#define fetch3_LPQV	fetchHi()
#define op1_LPQV	*(L_t*)c.lo.w
#define op2_LPQV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op3_LPQV	c.hi.w

/* LQ*V */
#define fetch_LQVV
#define fetch1_LQVV fetchIc()
#define fetch2_LQVV fetchLo()
#define fetch3_LQVV fetchHi()
#define op1_LQVV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQVV	c.lo.w
#define op3_LQVV	c.hi.w

#define fetch_LQRV	fetchIc();
#define fetch1_LQRV
#define fetch2_LQRV
#define fetch3_LQRV	fetchLo()
#define op1_LQRV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQRV	*(L_t*)DB_OFFSET(reg,c.ic.b._2)
#define op3_LQRV	c.lo.w

#define fetch_LQPV
#define fetch1_LQPV	fetchIc()
#define fetch2_LQPV	fetchLo()
#define fetch3_LQPV fetchHi()
#define op1_LQPV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQPV	*(L_t*)c.lo.w
#define op3_LQPV	c.hi.w

#define fetch_LQQV	fetchIc();
#define fetch1_LQQV
#define fetch2_LQQV
#define fetch3_LQQV	fetchLo()
#define op1_LQQV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)
#define op2_LQQV	*(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._2)
#define op3_LQQV	c.lo.w

/* Single operand templates */
#define fetch_BV	fetchIc();
#define opx_BV      ic.b._1
#define op_BV       (B_t)c.opx_BV

#define fetch_BR	fetchIc();
#define op_BR      *(B_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_BP    fetchLo()
#define op_BP      *(B_t*)c.lo.w

#define fetch_BQ	fetchIc();
#define op_BQ       *(B_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_SV	fetchIc();
#define opx_SV      ic.b._1
#define op_SV       c.opx_SV

#define fetch_SR	fetchIc();
#define op_SR       *(S_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_SP    fetchLo()
#define op_SP       *(S_t*)c.lo.w

#define fetch_SQ	fetchIc();
#define op_SQ       *(S_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_LV    fetchLo()
#define opx_LV      lo.w
#define op_LV       c.opx_LV

#define fetch_LR	fetchIc();
#define op_LR       *(L_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_LP    fetchLo()
#define op_LP       *(L_t*)c.lo.w

#define fetch_LQ	fetchIc();
#define op_LQ       *(L_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#define fetch_DV    fetchDbl()
#define opx_DV      lo.w
#define op_DV       c.dbl

#define fetch_DR	fetchIc();
#define op_DR       *(D_t*)DB_OFFSET(reg,c.ic.b._1)

#define fetch_DP    fetchLo()
#define op_DP       *(D_t*)c.lo.w

#define fetch_DQ	fetchIc();
#define op_DQ       *(D_t*)*(void**)DB_OFFSET(reg,c.ic.b._1)

#endif /* DB_VM_OPERANDS_H_ */
