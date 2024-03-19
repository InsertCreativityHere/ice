//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#pragma once

module Test
{

class OneOptional
{
    optional(1) int a;
}

interface MyInterface
{
    void op();
}

enum MyEnum
{
    MyEnumMember
}

struct SmallStruct
{
    byte m;
}

struct FixedStruct
{
    int m;
}

struct VarStruct
{
    string m;
}

struct ClassVarStruct
{
    int a;
}

sequence<byte> ByteSeq;
sequence<bool> BoolSeq;
sequence<short> ShortSeq;
sequence<int> IntSeq;
sequence<long> LongSeq;
sequence<float> FloatSeq;
sequence<double> DoubleSeq;
sequence<string> StringSeq;
sequence<MyEnum> MyEnumSeq;
sequence<SmallStruct> SmallStructSeq;
sequence<SmallStruct> SmallStructList;
sequence<FixedStruct> FixedStructSeq;
sequence<FixedStruct> FixedStructList;
sequence<VarStruct> VarStructSeq;
sequence<MyInterface*> MyInterfacePrxSeq;

sequence<byte> Serializable;

dictionary<int, int> IntIntDict;
dictionary<string, int> StringIntDict;
dictionary<int, MyEnum> IntEnumDict;
dictionary<int, FixedStruct> IntFixedStructDict;
dictionary<int, VarStruct> IntVarStructDict;
dictionary<int, OneOptional> IntOneOptionalDict;
dictionary<int, MyInterface*> IntMyInterfacePrxDict;

class MultiOptional
{
    optional(1) byte a;
    optional(2) bool b;
    optional(3) short c;
    optional(4) int d;
    optional(5) long e;
    optional(6) float f;
    optional(7) double g;
    optional(8) string h;
    optional(9) MyEnum i;
    optional(10) MyInterface* j;
    optional(11) ByteSeq bs;
    optional(12) StringSeq ss;
    optional(13) IntIntDict iid;
    optional(14) StringIntDict sid;
    optional(15) FixedStruct fs;
    optional(16) VarStruct vs;

    optional(17) ShortSeq shs;
    optional(18) MyEnumSeq es;
    optional(19) FixedStructSeq fss;
    optional(20) VarStructSeq vss;
    optional(21) MyInterfacePrxSeq mips;

    optional(22) IntEnumDict ied;
    optional(23) IntFixedStructDict ifsd;
    optional(24) IntVarStructDict ivsd;
    optional(25) IntMyInterfacePrxDict imipd;

    optional(26) BoolSeq bos;

    optional(27) Serializable ser;
}

class A
{
    int requiredA;
    optional(1) int ma;
    optional(50) int mb;
    optional(500) int mc;
}

class B extends A
{
    int requiredB;
    optional(10) int md;
}

class C extends B
{
    string ss;
    optional(890) string ms;
}

class WD
{
    optional(1) int a = 5;
    optional(2) string s = "test";
}

exception OptionalException
{
    bool req = false;
    optional(1) int a = 5;
    optional(2) string b;
    optional(50) OneOptional o;
}

exception DerivedException extends OptionalException
{
    string d1;
    optional(600) string ss = "test";
    optional(601) OneOptional o2;
    string d2;
}

exception RequiredException extends OptionalException
{
    string ss = "test";
    OneOptional o2;
}

class OptionalWithCustom
{
    optional(1) SmallStructList l;
    ["protected"] optional(2) SmallStructList lp;
    optional(3) ClassVarStruct s;
}

class E
{
    A ae;
}

class F extends E
{
    optional(1) A af;
}

class G1
{
    string a;
}

class G2
{
    long a;
}

class G
{
    optional(1) G1 gg1Opt;
    G2 gg2;
    optional(0) G2 gg2Opt;
    G1 gg1;
}

interface Initial
{
    void shutdown();

    Object pingPong(Object o);

    void opOptionalException(optional(1) int a, optional(2) string b, optional(3) OneOptional o)
        throws OptionalException;

    void opDerivedException(optional(1) int a, optional(2) string b, optional(3) OneOptional o)
        throws OptionalException;

    void opRequiredException(optional(1) int a, optional(2) string b, optional(3) OneOptional o)
        throws OptionalException;

    optional(1) byte opByte(optional(2) byte p1, out optional(3) byte p3);

    optional(1) bool opBool(optional(2) bool p1, out optional(3) bool p3);

    optional(1) short opShort(optional(2) short p1, out optional(3) short p3);

    optional(1) int opInt(optional(2) int p1, out optional(3) int p3);

    optional(3) long opLong(optional(1) long p1, out optional(2) long p3);

    optional(1) float opFloat(optional(2) float p1, out optional(3) float p3);

    optional(1) double opDouble(optional(2) double p1, out optional(3) double p3);

    optional(1) string opString(optional(2) string p1, out optional(3) string p3);

    optional(1) MyEnum opMyEnum(optional(2) MyEnum p1, out optional(3) MyEnum p3);

    optional(1) SmallStruct opSmallStruct(optional(2) SmallStruct p1, out optional(3) SmallStruct p3);

    optional(1) FixedStruct opFixedStruct(optional(2) FixedStruct p1, out optional(3) FixedStruct p3);

    optional(1) VarStruct opVarStruct(optional(2) VarStruct p1, out optional(3) VarStruct p3);

    optional(1) MyInterface* opMyInterfaceProxy(optional(2) MyInterface* p1, out optional(3) MyInterface* p3);

    optional(1) ByteSeq opByteSeq(optional(2) ByteSeq p1, out optional(3) ByteSeq p3);

    optional(1) BoolSeq opBoolSeq(optional(2) BoolSeq p1, out optional(3) BoolSeq p3);

    optional(1) ShortSeq opShortSeq(optional(2) ShortSeq p1, out optional(3) ShortSeq p3);

    optional(1) IntSeq opIntSeq(optional(2) IntSeq p1, out optional(3) IntSeq p3);

    optional(1) LongSeq opLongSeq(optional(2) LongSeq p1, out optional(3) LongSeq p3);

    optional(1) FloatSeq opFloatSeq(optional(2) FloatSeq p1, out optional(3) FloatSeq p3);

    optional(1) DoubleSeq opDoubleSeq(optional(2) DoubleSeq p1, out optional(3) DoubleSeq p3);

    optional(1) StringSeq opStringSeq(optional(2) StringSeq p1, out optional(3) StringSeq p3);

    optional(1) SmallStructSeq opSmallStructSeq(optional(2) SmallStructSeq p1, out optional(3) SmallStructSeq p3);

    optional(1) SmallStructList opSmallStructList(optional(2) SmallStructList p1, out optional(3) SmallStructList p3);

    optional(1) FixedStructSeq opFixedStructSeq(optional(2) FixedStructSeq p1, out optional(3) FixedStructSeq p3);

    optional(1) FixedStructList opFixedStructList(optional(2) FixedStructList p1, out optional(3) FixedStructList p3);

    optional(1) VarStructSeq opVarStructSeq(optional(2) VarStructSeq p1, out optional(3) VarStructSeq p3);

    optional(1) Serializable opSerializable(optional(2) Serializable p1, out optional(3) Serializable p3);

    optional(1) IntIntDict opIntIntDict(optional(2) IntIntDict p1, out optional(3) IntIntDict p3);

    optional(1) StringIntDict opStringIntDict(optional(2) StringIntDict p1, out optional(3) StringIntDict p3);

    optional(1) IntOneOptionalDict opIntOneOptionalDict(optional(2) IntOneOptionalDict p1,
                                                        out optional(3) IntOneOptionalDict p3);

    void opClassAndUnknownOptional(A p);

    void sendOptionalStruct(bool req, optional(1) FixedStruct o);

    void returnOptionalStruct(bool req, out optional(1) FixedStruct o);

    G opG(G g);

    void opVoid();

    ["marshaled-result"] optional(1) SmallStruct opMStruct1();
    ["marshaled-result"] optional(1) SmallStruct opMStruct2(optional(2) SmallStruct p1,
                                                            out optional(3)SmallStruct p2);

    ["marshaled-result"] optional(1) StringSeq opMSeq1();
    ["marshaled-result"] optional(1) StringSeq opMSeq2(optional(2) StringSeq p1,
                                                       out optional(3) StringSeq p2);

    ["marshaled-result"] optional(1) StringIntDict opMDict1();
    ["marshaled-result"] optional(1) StringIntDict opMDict2(optional(2) StringIntDict p1,
                                                            out optional(3) StringIntDict p2);

    ["marshaled-result"] optional(1) G opMG1();
    ["marshaled-result"] optional(1) G opMG2(optional(2) G p1, out optional(3) G p2);

    bool supportsRequiredParams();

    bool supportsJavaSerializable();

    bool supportsCsharpSerializable();

    bool supportsNullOptional();
}

interface Echo
{
    void setConnection();
    void startBatch();
    void flushBatch();
    void shutdown();
}

}
