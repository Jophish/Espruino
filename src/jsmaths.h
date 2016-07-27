
#ifndef JSMATHS_H_
#define JSMATHS_H_

#include "jsvar.h"

typedef struct MathsOpFlags{
    unsigned int A_JSV_IS_NUMERIC : 1;
    unsigned int B_JSV_IS_STRING : 1;
    unsigned int A_JSV_IS_INTEGERISH : 1;
    unsigned int B_JSV_IS_STRING_NUMERIC_INT : 1;
    unsigned int B_JSV_IS_NUMERIC : 1;
    unsigned int A_JSV_IS_STRING : 1;
    unsigned int B_JSV_IS_INTEGERISH: 1;
    unsigned int A_JSV_IS_STRING_NUMERIC_INT : 1;
    unsigned int A_JSV_IS_UNDEFINED : 1;
    unsigned int B_JSV_IS_UNDEFINED : 1;
    unsigned int A_JSV_IS_NULL : 1;
    unsigned int B_JSV_IS_NULL : 1;

    unsigned int A_JSV_IS_ARRAY : 1;
    unsigned int A_JSV_IS_OBJECT : 1;
    unsigned int A_JSV_IS_FUNCTION : 1;
    unsigned int B_JSV_IS_ARRAY : 1;
    unsigned int B_JSV_IS_OBJECT : 1;
    unsigned int B_JSV_IS_FUNCTION : 1;
    unsigned int A_JSV_IS_NATIVE_FUNCTION : 1;
    unsigned int B_JSV_IS_NATIVE_FUNCTION : 1;   
} MathsOpFlags;

typedef struct MathsOpData MathsOpData;

struct MathsOpData{

    MathsOpFlags *flags;
    JsVar* (*function)(JsVar *, JsVar *, int); //pointer to a function
    // also f'n pointer
    int op;
    int count; // number of times we've seen this bit of code
};


JsVar *caseIntAdd(JsVar *a, JsVar *b, int op);

JsVar *caseIntSub(JsVar *a, JsVar *b, int op);

JsVar *caseIntMul(JsVar *a, JsVar *b, int op);

JsVar *caseIntDiv(JsVar *a, JsVar *b, int op);

JsVar *caseIntAnd(JsVar *a, JsVar *b, int op);

JsVar *caseIntOr(JsVar *a, JsVar *b, int op);

JsVar *caseIntBitXOR(JsVar *a, JsVar *b, int op);
JsVar *caseIntMod(JsVar *a, JsVar *b, int op);

JsVar *caseIntLShift(JsVar *a, JsVar *b, int op);
JsVar *caseIntRShift(JsVar *a, JsVar *b, int op);
JsVar *caseIntUnsignedRShift(JsVar *a, JsVar *b, int op);

JsVar *caseIntEqual(JsVar *a, JsVar *b, int op);

JsVar *caseIntNEqual(JsVar *a, JsVar *b, int op);

JsVar *caseIntLessThan(JsVar *a, JsVar *b, int op);

JsVar *caseIntLeq(JsVar *a, JsVar *b, int op);
JsVar *caseIntGreaterThan(JsVar *a, JsVar *b, int op);
JsVar *caseIntGeq(JsVar *a, JsVar *b, int op);
JsVar *caseIntError(JsVar *a, JsVar *b, int op);
JsVar *caseFloatAdd(JsVar *a, JsVar *b, int op);
JsVar *caseFloatSub(JsVar *a, JsVar *b, int op);

JsVar *caseFloatMul(JsVar *a, JsVar *b, int op);
JsVar *caseFloatDiv(JsVar *a, JsVar *b, int op);

JsVar *caseFloatMod(JsVar *a, JsVar *b, int op);

JsVar *caseFloatEqual(JsVar *a, JsVar *b, int op);
JsVar *caseFloatNEqual(JsVar *a, JsVar *b, int op);
JsVar *caseFloatLessThan(JsVar *a, JsVar *b, int op);
JsVar *caseFloatLeq(JsVar *a, JsVar *b, int op);
JsVar *caseFloatGreaterThan(JsVar *a, JsVar *b, int op);

JsVar *caseFloatGeq(JsVar *a, JsVar *b, int op);
JsVar *caseFloatError(JsVar *a, JsVar *b, int op);
    
JsVar *caseObjectishEqual(JsVar *a, JsVar *b, int op);

JsVar *caseObjectishNEqual(JsVar *a, JsVar *b, int op);
JsVar *caseObjectishError(JsVar *a, JsVar *b, int op);

JsVar *caseStringAdd(JsVar *a, JsVar *b, int op);

JsVar *caseStringEqual(JsVar *a, JsVar *b, int op);

JsVar *caseStringNEqual(JsVar *a, JsVar *b, int op);
JsVar *caseStringLessThan(JsVar *a, JsVar *b, int op);
JsVar *caseStringLeq(JsVar *a, JsVar *b, int op);

JsVar *caseStringGreaterThan(JsVar *a, JsVar *b, int op);
JsVar *caseStringGeq(JsVar *a, JsVar *b, int op);
JsVar *caseStringError(JsVar *a, JsVar *b, int op);

JsVar *caseTypeEqual(JsVar *a, JsVar *b, int op);

JsVar *caseTypeNEqual(JsVar *a, JsVar *b, int op);


void shortPrint(char* prefix, MathsOpFlags *a);

void shortPrintData(char *prefix, MathsOpData *a);

MathsOpFlags *makeMathsOpFlags(JsVar *a, JsVar *b);

void printMathsOpFlags(MathsOpFlags *a);

MathsOpData *makeMathsOpData(JsVar *a, JsVar *b, int op);

bool equalsMathsOpFlags(MathsOpFlags *a, MathsOpFlags *b);

bool equalsMathsOpData(MathsOpData *a, MathsOpData *b);


#endif
