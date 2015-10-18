# ::corto::ic

## accumulator

### construct()

#### Returns

## address

### construct()

#### Returns

### value

## derefKind

### DEREF_ADDRESS

### DEREF_VALUE

## element

### base

### construct()

#### Returns

### index

### variableIndex

## function

### construct()

#### Returns

### function

### str(string in)

#### in

#### Returns

## kind

### ADDRESS

### FUNCTION

### LABEL

### LITERAL

### OP

### SCOPE

### STORAGE

## label

### construct()

#### Returns

### id

### str(string in)

#### in

#### Returns

## literal

### construct()

#### Returns

### str(string in)

#### in

#### Returns

### value

## member

### base

### construct()

#### Returns

### member

## node

### construct()

#### Returns

### kind

### str(string in)

#### in

#### Returns

## object

### construct()

#### Returns

### ptr

## op

### construct()

#### Returns

### kind

### line

### s1

### s1Any

### s1Deref

### s2

### s2Deref

### s3

### s3Deref

### str(string in)

#### in

#### Returns

### validate()

#### Returns

## opKind

### add

### and

### call

### cast

### cond_and

### cond_eq

### cond_gt

### cond_gteq

### cond_lt

### cond_lteq

### cond_neq

### cond_not

### cond_or

### dec

### define

### deinit

### div

### free

### inc

### init

### jeq

### jneq

### jump

### keep

### mod

### mul

### new

### not

### or

### push

### ret

### set

### shift_left

### shift_right

### stop

### strcat

### strcpy

### sub

### update

### updatebegin

### updatecancel

### updateend

### wait

### waitfor

### xor

### opKindFromOperator(operatorKind operator)

#### operator

#### Returns

## program

### accumulatorSp

### accumulatorStack

### add(node n)

#### n

### assemble()

#### Returns

### autoAccId

### construct()

#### Returns

### declareVariable(string name,type type,bool isReference,bool holdsReturn,bool isParameter,bool isReturn)

#### name

#### type

#### isReference

#### holdsReturn

#### isParameter

#### isReturn

#### Returns

### errors

### filename

### functions

### get()

#### Returns

### getAccId()

#### Returns

### getElement(storage base,node index)

#### base

#### index

#### Returns

### getLabel()

#### Returns

### getMember(storage base,member m)

#### base

#### m

#### Returns

### getObject(object o)

#### o

#### Returns

### getVariable(string name)

#### name

#### Returns

### labelCount

### labels

### literals

### ops

### popAccumulator()

### popScope()

### pushAccumulator(type type,bool isReference,bool holdsReturn)

#### type

#### isReference

#### holdsReturn

#### Returns

### pushFunction(function function)

#### function

#### Returns

### pushScope()

#### Returns

### run(word result,sequence{string} argv)

#### result

#### argv

#### Returns

### scope

### scopes

### storages

### str()

#### Returns

### vmprogram

## scope

### add(node n)

#### n

### addStorage(storage s)

#### s

### construct()

#### Returns

### isFunction

### lookupStorage(string name,bool recursive)

#### name

#### recursive

#### Returns

### parent

### program

### storages

### str(string in)

#### in

#### Returns

## storage

### base

### construct()

#### Returns

### free()

### holdsReturn

### isReference

### kind

### name

### scope

### str(string in)

#### in

#### Returns

### type

### used

## storageKind

### ACCUMULATOR

### ELEMENT

### MEMBER

### OBJECT

### VARIABLE

## variable

### construct()

#### Returns

### isParameter

### isReturn

