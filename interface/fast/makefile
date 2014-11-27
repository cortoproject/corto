
TARGET =	fast

LEX		=	fast.l
YACC	= 	fast.y

SOURCES	=	fastmain.c \
			Fast__api.c \
			Fast__meta.c \
			Fast__wrapper.c \
			Fast.c \
			Fast_BinaryExpr.c \
			Fast_Block.c \
			Fast_Boolean.c \
			Fast_Call.c \
			Fast_CastExpr.c \
			Fast_Character.c \
            Fast_CommaExpr.c \
			Fast_Define.c \
			Fast_DynamicInitializer.c \
			Fast_ElementExpr.c \
			Fast_Expression.c \
			Fast_FloatingPoint.c \
			Fast_If.c \
			Fast_Initializer.c \
			Fast_Integer.c \
			Fast_Literal.c \
			Fast_Local.c \
			Fast_MemberExpr.c \
			Fast_NewExpr.c \
			Fast_Node.c \
			Fast_Null.c \
			Fast_Object.c \
			Fast_ObjectBase.c \
			Fast_Parser.c \
			Fast_PostfixExpr.c \
			fast_pp.c \
            Fast_InitializerExpr.c \
			Fast_SignedInteger.c \
			Fast_StaticInitializer.c \
			Fast_String.c \
			Fast_Template.c \
            Fast_TernaryExpr.c \
			Fast_UnaryExpr.c \
			Fast_Update.c \
			Fast_Variable.c \
			Fast_Wait.c \
			Fast_While.c

INCLUDE = 	$(BUILDHOME)/db/include \
			$(BUILDHOME)/public/c/include \
			include \
			$(BUILDHOME)/dev/include \
			$(BUILDHOME)/interface/api/include

LIBS	=	lang api hyvedev fl

include $(BUILD)/lexyacc.makefile

