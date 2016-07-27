#include "jsmaths.h"
#include "jsvar.h"
#include "jswrap_math.h"
#include <stdio.h>

JsVar *caseIntAdd(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger((long long)da + (long long)db);
}

JsVar *caseIntSub(JsVar *a, JsVar *b, int op){
 
    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger((long long)da - (long long)db);
}

JsVar *caseIntMul(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger((long long)da * (long long)db);
}

JsVar *caseIntDiv(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger((JsVarFloat)da / (JsVarFloat)db);
}

JsVar *caseIntAnd(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger(da&db);
}

JsVar *caseIntOr(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger(da|db);
}

JsVar *caseIntBitXOR(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromLongInteger(da^db);
}

JsVar *caseIntMod(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return db ? jsvNewFromInteger(da%db) : jsvNewFromFloat(NAN);
}

JsVar *caseIntLShift(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromInteger(da << db);
}

JsVar *caseIntRShift(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromInteger(da >> db);
}

JsVar *caseIntUnsignedRShift(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromInteger((JsVarInt)(((JsVarIntUnsigned)da) >> db));
}

JsVar *caseIntEqual(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromBool(da==db && jsvIsNull(a)==jsvIsNull(b));
}

JsVar *caseIntNEqual(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromBool(da!=db || jsvIsNull(a)!=jsvIsNull(b));
}

JsVar *caseIntLessThan(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromBool(da<db);
}

JsVar *caseIntLeq(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromBool(da<=db);
}
JsVar *caseIntGreaterThan(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromBool(da>db);
}
JsVar *caseIntGeq(JsVar *a, JsVar *b, int op){

    JsVarInt da = jsvGetInteger(a);
    JsVarInt db = jsvGetInteger(b);
    return jsvNewFromBool(da>=db);
}
JsVar *caseIntError(JsVar *a, JsVar *b, int op){
    return jsvMathsOpError(op, "Integer");
}


JsVar *caseFloatAdd(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromFloat(da+db);
}

JsVar *caseFloatSub(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromFloat(da-db);
}

JsVar *caseFloatMul(JsVar *a, JsVar *b, int op){
 
    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromFloat(da*db);
}

JsVar *caseFloatDiv(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromFloat(da/db);
}

JsVar *caseFloatMod(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromFloat(jswrap_math_mod(da, db));
}

JsVar *caseFloatEqual(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);

    bool equal = da==db;
    if ((jsvIsNull(a) && jsvIsUndefined(b)) ||
	(jsvIsNull(b) && jsvIsUndefined(a))) equal = true;
    
    return jsvNewFromBool(equal);
}

JsVar *caseFloatNEqual(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);

    bool equal = da==db;
    if ((jsvIsNull(a) && jsvIsUndefined(b)) ||
	(jsvIsNull(b) && jsvIsUndefined(a))) equal = true;
    
    return jsvNewFromBool(((bool)!equal));
}
JsVar *caseFloatLessThan(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromBool(da<db);
}

JsVar *caseFloatLeq(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromBool(da<=db);
}

JsVar *caseFloatGreaterThan(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromBool(da>db);
}

JsVar *caseFloatGeq(JsVar *a, JsVar *b, int op){

    JsVarFloat da = jsvGetFloat(a);
    JsVarFloat db = jsvGetFloat(b);
    return jsvNewFromBool(da>=db);
}

JsVar *caseFloatError(JsVar *a, JsVar *b, int op){
    
    return jsvMathsOpError(op, "Double");
}
    
JsVar *caseObjectishEqual(JsVar *a, JsVar *b, int op){

    bool equal = a==b;

     if (jsvIsNativeFunction(a) || jsvIsNativeFunction(b)) {
      // even if one is not native, the contents will be different
      equal = a->varData.native.ptr == b->varData.native.ptr &&
          a->varData.native.argTypes == b->varData.native.argTypes &&
          jsvGetFirstChild(a) == jsvGetFirstChild(b);
    }

     return jsvNewFromBool(equal);

}

JsVar *caseObjectishNEqual(JsVar *a, JsVar *b, int op){

    bool equal = a==b;

     if (jsvIsNativeFunction(a) || jsvIsNativeFunction(b)) {
      // even if one is not native, the contents will be different
      equal = a->varData.native.ptr == b->varData.native.ptr &&
          a->varData.native.argTypes == b->varData.native.argTypes &&
          jsvGetFirstChild(a) == jsvGetFirstChild(b);
    }

     return jsvNewFromBool(!equal);
}

JsVar *caseObjectishError(JsVar *a, JsVar *b, int op){

    return jsvMathsOpError(op, jsvIsArray(a)?"Array":"Object");

}

JsVar *caseStringAdd(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }

    JsVar *v = jsvCopy(da);
      if (v) // could be out of memory
        jsvAppendStringVarComplete(v, db);
      jsvUnLock2(da, db);
      return v;
}

JsVar *caseStringEqual(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }

    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);

    return jsvNewFromBool(cmp==0);
}

JsVar *caseStringNEqual(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }

    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);

    return jsvNewFromBool(cmp!=0);
}

JsVar *caseStringLessThan(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }

    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);

    return jsvNewFromBool(cmp<0);
}

JsVar *caseStringLeq(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }

    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);

    return jsvNewFromBool(cmp<=0);
}

JsVar *caseStringGreaterThan(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }

    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);

    return jsvNewFromBool(cmp>0);
}

JsVar *caseStringGeq(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    

    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }
    
    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);
    
    return jsvNewFromBool(cmp>=0);
}

JsVar *caseStringError(JsVar *a, JsVar *b, int op){
    JsVar *da = jsvAsString(a, false);
    JsVar *db = jsvAsString(b, false);
    
    if (!da || !db) { // out of memory
      jsvUnLock2(da, db);
      return 0;
    }
    int cmp = jsvCompareString(da,db,0,0,false);
    jsvUnLock2(da, db);
    return jsvMathsOpError(op, "String");
}

JsVar *caseTypeEqual(JsVar *a, JsVar *b, int op){

    bool eql = jsvMathsOpTypeEqual(a,b);
    return jsvNewFromBool(eql);
}

JsVar *caseTypeNEqual(JsVar *a, JsVar *b, int op){
  
    bool eql = jsvMathsOpTypeEqual(a,b);

    return jsvNewFromBool(!eql);
}


void shortPrint(char* prefix, MathsOpFlags *a){
    printf("%s:%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u\n\r",
	   prefix,
	   a->A_JSV_IS_NUMERIC,
	   a->B_JSV_IS_NUMERIC,
	   a->A_JSV_IS_STRING,
	   a->B_JSV_IS_STRING,
	   a->A_JSV_IS_INTEGERISH,
	   a->B_JSV_IS_INTEGERISH,
	   a->A_JSV_IS_STRING_NUMERIC_INT,
	   a->B_JSV_IS_STRING_NUMERIC_INT,
	   a->A_JSV_IS_UNDEFINED,
	   a->B_JSV_IS_UNDEFINED,
	   a->A_JSV_IS_NULL,
	   a->B_JSV_IS_NULL,
	   a->A_JSV_IS_ARRAY,
	   a->B_JSV_IS_ARRAY,
	   a->A_JSV_IS_FUNCTION,
	   a->B_JSV_IS_FUNCTION,
	   a->A_JSV_IS_OBJECT,
	   a->B_JSV_IS_OBJECT,
	   a->A_JSV_IS_NATIVE_FUNCTION,
	   a->B_JSV_IS_NATIVE_FUNCTION);
}

void shortPrintData(char *prefix, MathsOpData *a){
    shortPrint(prefix, a->flags);
}

MathsOpFlags *makeMathsOpFlags(JsVar *a, JsVar *b){
    MathsOpFlags *temp = malloc(sizeof(MathsOpFlags));
    temp->A_JSV_IS_NUMERIC = jsvIsNumeric(a);
    temp->B_JSV_IS_STRING = jsvIsString(b);
    temp->A_JSV_IS_INTEGERISH = jsvIsIntegerish(a);
    temp->A_JSV_IS_STRING = jsvIsString(a);
    
    if (temp->A_JSV_IS_STRING){
	temp->A_JSV_IS_STRING_NUMERIC_INT = jsvIsStringNumericInt(a, false);
    }
    else{
	temp->A_JSV_IS_STRING_NUMERIC_INT = 0;
    }
    if (temp->B_JSV_IS_STRING){
	temp->B_JSV_IS_STRING_NUMERIC_INT = jsvIsStringNumericInt(b, false);
    }
    else{
	temp->B_JSV_IS_STRING_NUMERIC_INT = 0;
    }

    temp->B_JSV_IS_NUMERIC = jsvIsNumeric(b);
    
    temp->B_JSV_IS_INTEGERISH = jsvIsIntegerish(b);


    
    

    
    temp->A_JSV_IS_UNDEFINED = jsvIsUndefined(a);
    temp->B_JSV_IS_UNDEFINED = jsvIsUndefined(b);
    temp->A_JSV_IS_NULL = jsvIsNull(a);
    temp->B_JSV_IS_NULL = jsvIsNull(b);

    temp->A_JSV_IS_ARRAY = jsvIsArray(a);
    temp->B_JSV_IS_ARRAY = jsvIsArray(b);
    temp->A_JSV_IS_FUNCTION = jsvIsFunction(a);
    temp->A_JSV_IS_OBJECT = jsvIsArray(a);
    temp->B_JSV_IS_OBJECT = jsvIsArray(b);
    temp->B_JSV_IS_FUNCTION = jsvIsFunction(b);
    temp->A_JSV_IS_NATIVE_FUNCTION = jsvIsNativeFunction(a);
    temp->A_JSV_IS_NATIVE_FUNCTION = jsvIsNativeFunction(a);
    //shortPrint(temp);
    return temp;
}	   

	   
void printMathsOpFlags(MathsOpFlags *a){
    printf("A_JSV_IS_NUMERIC: %u\n\r", a->A_JSV_IS_NUMERIC);
    printf("B_JSV_IS_NUMERIC: %u\n\r", a->B_JSV_IS_NUMERIC);

    printf("A_JSV_IS_STRING: %u\n\r", a->A_JSV_IS_STRING);
    printf("B_JSV_IS_STRING: %u\n\r", a->B_JSV_IS_STRING);
    
    printf("A_JSV_IS_INTEGERISH: %u\n\r", a->A_JSV_IS_INTEGERISH);
    printf("B_JSV_IS_INTEGERISH: %u\n\r", a->B_JSV_IS_INTEGERISH);
    
    printf("A_JSV_IS_STRING_NUMERIC_INT: %u\n\r", a->A_JSV_IS_STRING_NUMERIC_INT);
    printf("B_JSV_IS_STRING_NUMERIC_INT: %u\n\r", a->B_JSV_IS_STRING_NUMERIC_INT);
    
    printf("A_JSV_IS_UNDEFINED: %u\n\r", a->A_JSV_IS_UNDEFINED);
    printf("B_JSV_IS_UNDEFINED: %u\n\r", a->B_JSV_IS_UNDEFINED);

    printf("A_JSV_IS_NULL: %u\n\r", a->A_JSV_IS_NULL);
    printf("B_JSV_IS_NULL: %u\n\r", a->B_JSV_IS_NULL);

    printf("A_JSV_IS_ARRAY: %u\n\r", a->A_JSV_IS_ARRAY);
    printf("B_JSV_IS_ARRAY: %u\n\r", a->B_JSV_IS_ARRAY);

    printf("A_JSV_IS_FUNCTION: %u\n\r", a->A_JSV_IS_FUNCTION);
    printf("B_JSV_IS_FUNCTION: %u\n\r", a->B_JSV_IS_FUNCTION);

    printf("A_JSV_IS_OBJECT: %u\n\r", a->A_JSV_IS_OBJECT);
    printf("B_JSV_IS_OBJECT: %u\n\r", a->B_JSV_IS_OBJECT);

    printf("A_JSV_IS_NATIVE_FUNCTION: %u\n\r", a->A_JSV_IS_NATIVE_FUNCTION);
    printf("B_JSV_IS_NATIVE_FUNCTION: %u\n\r", a->B_JSV_IS_NATIVE_FUNCTION);

}

MathsOpData *makeMathsOpData(JsVar *a, JsVar *b, int op){
    MathsOpData *pointer = malloc(sizeof(MathsOpData));
    pointer->flags = makeMathsOpFlags(a, b);
    pointer->op = op;
    pointer->count = 1;
    return pointer;

}


bool equalsMathsOpFlags(MathsOpFlags *a, MathsOpFlags *b){
    
    return (a->A_JSV_IS_NUMERIC == b->A_JSV_IS_NUMERIC &&
	    a->B_JSV_IS_STRING == b->B_JSV_IS_STRING &&
	    a->A_JSV_IS_INTEGERISH == b->A_JSV_IS_INTEGERISH &&
	    a->B_JSV_IS_STRING_NUMERIC_INT == b->B_JSV_IS_STRING_NUMERIC_INT &&
	    a->B_JSV_IS_NUMERIC == b->B_JSV_IS_NUMERIC &&
	    a->A_JSV_IS_STRING == b->A_JSV_IS_STRING &&
	    a->B_JSV_IS_INTEGERISH == b->B_JSV_IS_INTEGERISH &&
	    a->A_JSV_IS_STRING_NUMERIC_INT == b->A_JSV_IS_STRING_NUMERIC_INT &&
	    a->A_JSV_IS_UNDEFINED == b->A_JSV_IS_UNDEFINED &&
	    a->B_JSV_IS_UNDEFINED == b->B_JSV_IS_UNDEFINED &&
	    a->A_JSV_IS_NULL == b->A_JSV_IS_NULL &&
	    a->B_JSV_IS_NULL == b->B_JSV_IS_NULL &&
	    a->A_JSV_IS_ARRAY == b->A_JSV_IS_ARRAY &&
	    a->B_JSV_IS_ARRAY == b->B_JSV_IS_ARRAY &&
	    a->A_JSV_IS_FUNCTION == b->A_JSV_IS_FUNCTION &&
	    a->B_JSV_IS_FUNCTION == b->B_JSV_IS_FUNCTION &&
	    a->A_JSV_IS_OBJECT == b->A_JSV_IS_OBJECT &&
	    a->B_JSV_IS_OBJECT == b->B_JSV_IS_OBJECT &&
	    a->A_JSV_IS_NATIVE_FUNCTION == b->A_JSV_IS_NATIVE_FUNCTION &&
	    a->B_JSV_IS_NATIVE_FUNCTION == b->B_JSV_IS_NATIVE_FUNCTION);
	    
}

bool equalsMathsOpData(MathsOpData *a, MathsOpData *b){
    return (equalsMathsOpFlags(a->flags, b->flags) && (a->op == b->op));
}

