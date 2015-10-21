# ::test
### functionToResolve(int32 a,int32 b)
#### a
#### b
### ol_any(::test::Color a)
#### a
### ol_any(bool a)
#### a
### ol_any(char a)
#### a
### ol_any(float32 a)
#### a
### ol_any(int32 a)
#### a
### ol_any(object a)
#### a
### ol_any(string a)
#### a
### ol_bool(bool a)
#### a
### ol_inherit(::test::Animal a)
#### a
### ol_inherit(::test::Dog a)
#### a
### ol_int(int32 a)
#### a
### ol_null(bool a)
#### a
### ol_null(object a)
#### a
### ol_null(string a)
#### a
### ol_num(float64 a)
#### a
### ol_num(int32 a)
#### a
### ol_object(object a)
#### a
### ol_string(string a)
#### a
### ol_uint(int32 a)
#### a
### ol_wildcard(float32 a,string b)
#### a
#### b
### ol_wildcard(int32 a,string b)
#### a
#### b

## Animal
### a

## Bar
### __dummy
### init()
#### Returns

## Cat
### b

## Color
### Blue
### Green
### Orange
### Red
### Yellow

## CompositeCollection
### points

## DeclaredParent
### foo

## DefinedParent
### foo

## Dog
### b

## Event
### et
### setup()
### tc_onDeclare()
### tc_onDeclareScope()
### tc_onDeclareSelf()
### tc_onDeclareTree()
### tc_onDefine()
### tc_onDefineScope()
### tc_onDefineSelf()
### tc_onDefineTree()
### tc_onDelete()
### tc_onDeleteScope()
### tc_onDeleteSelf()
### tc_onDeleteTree()
### tc_onUpdate()
### tc_onUpdateScope()
### tc_onUpdateSelf()
### tc_onUpdateTree()
### tc_updateUndefined()
### tc_updateVoidErr()
### teardown()

## EventTest
### construct()
#### Returns
### countDeclare
### countDeclareScope
### countDeclareSelf
### countDeclareTree
### countDefine
### countDefineScope
### countDefineSelf
### countDefineTree
### countDelete
### countDeleteScope
### countDeleteSelf
### countDeleteTree
### countUpdate
### countUpdateScope
### countUpdateSelf
### countUpdateTree
### lastObservable
### lastThis
### onDeclare
#### observable
### onDeclareScope
#### observable
### onDeclareSelf
#### observable
### onDeclareTree
#### observable
### onDefine
#### observable
### onDefineScope
#### observable
### onDefineSelf
#### observable
### onDefineTree
#### observable
### onDelete
#### observable
### onDeleteScope
#### observable
### onDeleteSelf
#### observable
### onDeleteTree
#### observable
### onUpdate
#### observable
### onUpdateScope
#### observable
### onUpdateSelf
#### observable
### onUpdateTree
#### observable
### scope

## Foo
### construct()
#### Returns
### destruct()
### fail
### init()
#### Returns
### x
### y

## Fullname
### tc_null()
### tc_nullBuffer()
### tc_onelevel()
### tc_root()
### tc_twolevels()

## GoldenRetriever
### c

## Line
### start
### stop

## MethodResolver
### tc_inheritOverload()
### tc_inheritOverloadBaseClass()
### tc_inheritOverloadBaseInt()
### tc_inheritOverloadBaseString()
### tc_inheritOverloadBaseTwoArgs()
### tc_inheritOverloadClass()
### tc_inheritOverloadNoArgs()
### tc_inheritSimple()
### tc_inheritSimpleNoArgs()
### tc_inheritVirtualOverload()
### tc_inheritVirtualOverloadNoArgs()
### tc_nonexisting()
### tc_onearg()
### tc_oneargErr()
### tc_oneargErrType()
### tc_oneargNoArgs()
### tc_overloadAmbiguous()
### tc_overloadClass()
### tc_overloadInt()
### tc_overloadString()
### tc_overloadTwoArgs()
### tc_redeclare()
### tc_simple()
### tc_simpleErr()
### tc_simpleErrType()
### tc_simpleNoArgs()
### tc_twoargs()
### tc_twoargsNoArgs()
### tc_twoargsSpaces()
### tc_virtualOverload()
### tc_virtualOverloadArg()
### tc_virtualOverloadNoArgs()
### tc_virtualSimple()
### tc_virtualSimpleNoArgs()

## MethodTester
### __dummy
### onearg(int32 a)
#### a
### overload(::test::MethodTester m)
#### m
### overload(int32 a)
#### a
### overload(int32 a,int32 b)
#### a
#### b
### overload(string a)
#### a
### simple()
### twoargs(int32 a,int32 b)
#### a
#### b
### virtualOverload()
### virtualOverload(int32 a)
#### a
### virtualSimple()

## MethodTesterInherit
### overload(::test::MethodTesterInherit m)
#### m
### overload(string a,string b)
#### a
#### b
### simple()
### virtualOverload(int32 a)
#### a

## ObjectMgmt
### prevAttr
### setup()
### tc_createChildFoo()
### tc_createChildFooAttr0()
### tc_createChildInitFail()
### tc_createChildInt()
### tc_createChildIntAttr0()
### tc_createChildInvalidType()
### tc_createChildNested()
### tc_createChildNullType()
### tc_createChildParentStateErr()
### tc_createChildParentTypeErr()
### tc_createChildVoid()
### tc_createChildVoidAttr0()
### tc_createFoo()
### tc_createFooAttr0()
### tc_createInitFail()
### tc_createInt()
### tc_createIntAttr0()
### tc_createInvalidType()
### tc_createNullType()
### tc_createVoid()
### tc_createVoidAttr0()
### tc_declareChildFoo()
### tc_declareChildFooAttr0()
### tc_declareChildInitFail()
### tc_declareChildInt()
### tc_declareChildIntAttr0()
### tc_declareChildInvalidType()
### tc_declareChildNullType()
### tc_declareChildParentStateErr()
### tc_declareChildParentTypeErr()
### tc_declareChildVoid()
### tc_declareChildVoidAttr0()
### tc_declareExistingWithParentState()
### tc_declareFoo()
### tc_declareFooAttr0()
### tc_declareInitFail()
### tc_declareInt()
### tc_declareIntAttr0()
### tc_declareInvalidType()
### tc_declareNullType()
### tc_declareVoid()
### tc_declareVoidAttr0()
### tc_defineFoo()
### tc_defineFooAttr0()
### tc_defineFooFail()
### tc_defineInt()
### tc_defineIntAttr0()
### tc_defineVoid()
### tc_defineVoidAttr0()
### tc_drop()
### tc_invalidate()
### teardown()

## Overload
### tc_ambiguous()
### tc_ambiguousNull()
### tc_ambiguousWildcard()
### tc_anyChar()
### tc_anyColor()
### tc_anyFloat32()
### tc_anyFloat64()
### tc_anyInt16()
### tc_anyInt32()
### tc_anyInt64()
### tc_anyInt8()
### tc_anyOctet()
### tc_anyString()
### tc_anyUint16()
### tc_anyUint32()
### tc_anyUint64()
### tc_anyUint8()
### tc_anyWord()
### tc_inheritanceBase()
### tc_inheritanceMatchSub()
### tc_inheritanceSub()
### tc_inheritSibling()
### tc_nullBool()
### tc_nullObject()
### tc_nullString()
### tc_numChar()
### tc_numColor()
### tc_numFloat32()
### tc_numFloat64()
### tc_numInt16()
### tc_numInt32()
### tc_numInt64()
### tc_numInt8()
### tc_numOctet()
### tc_numString()
### tc_numUint16()
### tc_numUint32()
### tc_numUint64()
### tc_numUint8()
### tc_numWord()
### tc_wildcard()

## Point
### x
### y

## Point3D
### z

## PrimitiveCollection
### ints

## RelativeName
### child
### disjunct
### obj
### setup()
### tc_fromChild()
### tc_fromDisjunct()
### tc_fromOneUp()
### tc_fromParent()
### tc_fromRoot()
### tc_fromSelf()
### tc_fromThreeUp()
### tc_fromTwoUp()
### teardown()
### tier1
### tier2
### tier3

## Resolver
### setup()
### tc_caseInsensitive()
### tc_resolveAll()
### tc_resolveAnonymous()
### tc_resolveCorto()
### tc_resolveEmptyString()
### tc_resolveFunctionArgs()
### tc_resolveFunctionNoArgs()
### tc_resolveIo()
### tc_resolveLang()
### tc_resolveNull()
### tc_resolveParenthesesNoFunction()
### tc_resolveParenthesesNoFunctionArgs()
### tc_resolveParenthesesNoFunctionArgsScoped()
### tc_resolveParenthesesNoFunctionMatchingArgs()
### tc_resolveParenthesesNoFunctionMatchingArgsScoped()
### tc_resolveParenthesesNoFunctionScoped()
### tc_resolveRoot()
### tc_resolveString()
### tc_resolveThis()
### teardown()

## Select
### collect(object scope,string expr)
#### scope
#### expr
#### Returns
### setup()
### tc_selectErrParentAst()
### tc_selectErrParentId()
### tc_selectErrParentTree()
### tc_selectErrParentWc()
### tc_selectErrScopeScope()
### tc_selectIdentifier()
### tc_selectParent()
### tc_selectScopedIdentifier()
### tc_selectScopedParent()
### tc_selectScopedThis()
### tc_selectThis()
### teardown()

## selectItem
### name
### parent
### type

## StringDeserializer
### setup()
### tc_deserBoolFalse()
### tc_deserBoolInvalid()
### tc_deserBoolTrue()
### tc_deserChar()
### tc_deserCharEscape()
### tc_deserCharEscapeQuoted()
### tc_deserCharNull()
### tc_deserCharNullQuoted()
### tc_deserCharQuoted()
### tc_deserCollection()
### tc_deserCollectionComplex()
### tc_deserComposite()
### tc_deserCompositeMembers()
### tc_deserCompositeMixed()
### tc_deserCompositeNested()
### tc_deserCompositeNestedMembers()
### tc_deserCompositeNestedMixed()
### tc_deserCompositeNoType()
### tc_deserCompositeWhitespace()
### tc_deserExisting()
### tc_deserExisting_w_type()
### tc_deserInheritance()
### tc_deserInheritanceMembers()
### tc_deserInheritanceMixed()
### tc_deserInt16()
### tc_deserInt16Minus()
### tc_deserInt16Overflow()
### tc_deserInt32()
### tc_deserInt32Minus()
### tc_deserInt32Overflow()
### tc_deserInt64()
### tc_deserInt64Minus()
### tc_deserInt8()
### tc_deserInt8Minus()
### tc_deserInt8Overflow()
### tc_deserString()
### tc_deserStringEscape()
### tc_deserStringQuotes()
### tc_deserStringQuotesWhitespaces()
### tc_deserStringWhitespace()
### tc_deserStringWhitespaceTrailing()
### tc_deserStringWhitespaceTrailingNoType()
### tc_deserUint16()
### tc_deserUint16Overflow()
### tc_deserUint32()
### tc_deserUint32Overflow()
### tc_deserUint64()
### tc_deserUint8()
### tc_deserUint8Overflow()
### tc_errExcessElements()
### tc_errMissingType()
### tc_errNotAType()
### tc_errTypeMismatch()
### tc_errUnresolvedMember()
### tc_errUnresolvedType()
### teardown()

## VoidParent
### foo
