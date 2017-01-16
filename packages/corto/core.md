# /corto/core
Contains core infrastructure types.


## attr
### ATTR_DEFAULT
### ATTR_OBSERVABLE
### ATTR_PERSISTENT
### ATTR_SCOPED
### ATTR_WRITABLE

## dispatcher
### post(event e)
#### e

## equalityKind
### EQ
### GT
### LT
### NEQ

## event
### handle()
### handled
### kind
### uniqueKind()
#### Returns

## eventMask
### ON_DECLARE
### ON_DEFINE
### ON_DELETE
### ON_INVALIDATE
### ON_METAVALUE
### ON_SCOPE
### ON_SELF
### ON_TREE
### ON_UPDATE
### ON_VALUE

## invokeEvent
### args
### function
### handle()
### instance
### replicator

## notifyAction

## observableEvent
### handle()
### me
### observable
### observer
### source

## observer
### construct()
#### Returns
### dispatcher
### init()
#### Returns
### listen(object observable,object me)
#### observable
#### me
#### Returns
### mask
### me
### observable
### setDispatcher(core/dispatcher dispatcher)
#### dispatcher
### silence(object me)
#### me
#### Returns
### template
### destruct(observer object)
#### object

## observerseq
Sequence of observer elements.


## operatorKind
### ADD
### AND
### ASSIGN
### ASSIGN_ADD
### ASSIGN_AND
### ASSIGN_DIV
### ASSIGN_MOD
### ASSIGN_MUL
### ASSIGN_OR
### ASSIGN_SUB
### ASSIGN_UPDATE
### ASSIGN_XOR
### COND_AND
### COND_EQ
### COND_GT
### COND_GTEQ
### COND_LT
### COND_LTEQ
### COND_NEQ
### COND_NOT
### COND_OR
### DEC
### DIV
### INC
### MOD
### MUL
### NOT
### OR
### REF
### SHIFT_LEFT
### SHIFT_RIGHT
### SUB
### XOR

## package
### url

## query
### from
### mask

## replicator
### construct()
#### Returns
### contentType
### destruct()
#### instance
#### proc
#### args
### mount
### on_declare
#### observable
### on_delete
#### observable
### on_update
#### observable
### onDeclare(object observable)
#### observable
### onDelete(object observable)
#### observable
### onInvoke(object instance,function proc,octetseq args)
#### instance
#### proc
#### args
### onRequest(string parent,string expr,bool setContent)
#### parent
#### expr
#### setContent
#### Returns
### onUpdate(object observable)
#### observable
### post(event e)
#### e
### query
### request(string parent,string expr,bool setContent)
#### parent
#### expr
#### setContent
#### Returns
### setContentType(string type)
#### type
#### Returns

## result
### getText()
#### Returns
### name
### parent
### type
### value

## resultIter

## resultList
