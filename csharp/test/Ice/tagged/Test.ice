//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#pragma once

[[3.7]]
[[suppress-warning:reserved-identifier]]

module ZeroC::Ice::Test::Tagged
{

class OneTagged
{
    tag(1) int? a;
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

sequence<ushort> UShortSeq;
sequence<varulong> VarULongSeq;

[cs:generic:List] sequence<byte> ByteList;
[cs:generic:List] sequence<bool> BoolList;
[cs:generic:List] sequence<short> ShortList;
[cs:generic:List] sequence<int> IntList;
[cs:generic:List] sequence<long> LongList;
[cs:generic:List] sequence<float> FloatList;
[cs:generic:List] sequence<double> DoubleList;
[cs:generic:List] sequence<string> StringList;
[cs:generic:List] sequence<varint> VarIntList;

sequence<SmallStruct> SmallStructSeq;
[cs:generic:List] sequence<SmallStruct> SmallStructList;
sequence<FixedStruct> FixedStructSeq;
[cs:generic:LinkedList] sequence<FixedStruct> FixedStructList;
sequence<VarStruct> VarStructSeq;

[cs:serializable:ZeroC.Ice.Test.Tagged.SerializableClass]
sequence<byte> Serializable;

dictionary<int, int> IntIntDict;
dictionary<string, int> StringIntDict;
dictionary<int, MyEnum> IntEnumDict;
dictionary<int, FixedStruct> IntFixedStructDict;
dictionary<int, VarStruct> IntVarStructDict;

class MultiTagged
{
    tag(1) byte? a;
    tag(2) bool? b;
    tag(3) short? c;
    tag(4) int? d;
    tag(5) long? e;
    tag(6) float? f;
    tag(7) double? g;
    tag(8) string? h;
    tag(9) MyEnum? i;

    tag(12) ByteSeq? bs;
    tag(13) StringSeq? ss;
    tag(14) IntIntDict? iid;
    tag(15) StringIntDict? sid;
    tag(16) FixedStruct? fs;
    tag(17) VarStruct? vs;

    tag(18) ShortSeq? shs;
    tag(19) MyEnumSeq? es;
    tag(20) FixedStructSeq? fss;
    tag(21) VarStructSeq? vss;

    tag(24) IntEnumDict? ied;
    tag(25) IntFixedStructDict? ifsd;
    tag(26) IntVarStructDict? ivsd;

    tag(29) BoolSeq? bos;

    tag(30) Serializable? ser;

    tag(31) ushort? us;
    tag(32) uint? ui;
    tag(33) ulong? ul;
    tag(34) varint? vi;
    tag(35) varlong? vl;
    tag(36) varuint? vui;
    tag(37) varulong? vul;

    tag(38) UShortSeq? uss;
    tag(39) VarULongSeq? vuls;
    tag(40) VarIntList? vil;
}

class A
{
    int requiredA;
    tag(1) int? ma;
    tag(50) int? mb;
    tag(500) int? mc;
}

[preserve-slice]
class B : A
{
    int requiredB;
    tag(10) int? md;
}

class C : B
{
    string ss;
    tag(890) string? ms;
}

class WD
{
    tag(1) int? a = 5;
    tag(2) string? s = "test";
}

exception TaggedException
{
    bool req = false;
    tag(1) int? a = 5;
    tag(2) string? b;
    tag(50) VarStruct? vs;
}

exception DerivedException : TaggedException
{
    tag(600) string? ss = "test";
    tag(601) VarStruct? vs2;
}

exception RequiredException : TaggedException
{
    string ss = "test";
    VarStruct vs2;
}

[cs:property]
class TaggedWithCustom
{
    tag(1) SmallStructList? l;
    tag(2) SmallStructList? lp;
    tag(3) ClassVarStruct? s;
}

interface Initial
{
    void shutdown();

    Object pingPong(Object o);

    void opTaggedException(tag(1) int? a, tag(2) string? b, optional(3) VarStruct vs);

    void opDerivedException(tag(1) int? a, tag(2) string? b, optional(3) VarStruct vs);

    void opRequiredException(tag(1) int? a, tag(2) string? b, optional(3) VarStruct vs);

    tag(1) byte? opByte(tag(2) byte? p1, out tag(3) byte? p3);

    tag(1) bool? opBool(tag(2) bool? p1, out tag(3) bool? p3);

    tag(1) short? opShort(tag(2) short? p1, out tag(3) short? p3);

    tag(1) int? opInt(tag(2) int? p1, out tag(3) int? p3);

    tag(3) long? opLong(tag(1) long? p1, out tag(2) long? p3);

    tag(1) float? opFloat(tag(2) float? p1, out tag(3) float? p3);

    tag(1) double? opDouble(tag(2) double? p1, out tag(3) double? p3);

    tag(1) string? opString(tag(2) string? p1, out tag(3) string? p3);

    tag(1) MyEnum? opMyEnum(tag(2) MyEnum? p1, out tag(3) MyEnum? p3);

    tag(1) SmallStruct? opSmallStruct(tag(2) SmallStruct? p1, out tag(3) SmallStruct? p3);

    tag(1) FixedStruct? opFixedStruct(tag(2) FixedStruct? p1, out tag(3) FixedStruct? p3);

    tag(1) VarStruct? opVarStruct(tag(2) VarStruct? p1, out tag(3) VarStruct? p3);

    tag(1) ByteSeq? opByteSeq(tag(2) ByteSeq? p1, out tag(3) ByteSeq? p3);
    tag(1) ByteList? opByteList(tag(2) ByteList? p1, out tag(3) ByteList? p3);

    tag(1) BoolSeq? opBoolSeq(tag(2) BoolSeq? p1, out tag(3) BoolSeq? p3);
    tag(1) BoolList? opBoolList(tag(2) BoolList? p1, out tag(3) BoolList? p3);

    tag(1) ShortSeq? opShortSeq(tag(2) ShortSeq? p1, out tag(3) ShortSeq? p3);
    tag(1) ShortList? opShortList(tag(2) ShortList? p1, out tag(3) ShortList? p3);

    tag(1) IntSeq? opIntSeq(tag(2) IntSeq? p1, out tag(3) IntSeq? p3);
    tag(1) IntList? opIntList(tag(2) IntList? p1, out tag(3) IntList? p3);

    tag(1) LongSeq? opLongSeq(tag(2) LongSeq? p1, out tag(3) LongSeq? p3);
    tag(1) LongList? opLongList(tag(2) LongList? p1, out tag(3) LongList? p3);

    tag(1) FloatSeq? opFloatSeq(tag(2) FloatSeq? p1, out tag(3) FloatSeq? p3);
    tag(1) FloatList? opFloatList(tag(2) FloatList? p1, out tag(3) FloatList? p3);

    tag(1) DoubleSeq? opDoubleSeq(tag(2) DoubleSeq? p1, out tag(3) DoubleSeq? p3);
    tag(1) DoubleList? opDoubleList(tag(2) DoubleList? p1, out tag(3) DoubleList? p3);

    tag(1) StringSeq? opStringSeq(tag(2) StringSeq? p1, out tag(3) StringSeq? p3);
    tag(1) StringList? opStringList(tag(2) StringList? p1, out tag(3) StringList? p3);

    tag(1) SmallStructSeq? opSmallStructSeq(tag(2) SmallStructSeq? p1, out tag(3) SmallStructSeq? p3);

    tag(1) SmallStructList? opSmallStructList(tag(2) SmallStructList? p1, out tag(3) SmallStructList? p3);

    tag(1) FixedStructSeq? opFixedStructSeq(tag(2) FixedStructSeq? p1, out tag(3) FixedStructSeq? p3);

    tag(1) FixedStructList? opFixedStructList(tag(2) FixedStructList? p1, out tag(3) FixedStructList? p3);

    tag(1) VarStructSeq? opVarStructSeq(tag(2) VarStructSeq? p1, out tag(3) VarStructSeq? p3);

    tag(1) Serializable? opSerializable(tag(2) Serializable? p1, out tag(3) Serializable? p3);

    tag(1) IntIntDict? opIntIntDict(tag(2) IntIntDict? p1, out tag(3) IntIntDict? p3);

    tag(1) StringIntDict? opStringIntDict(tag(2) StringIntDict? p1, out tag(3) StringIntDict? p3);

    void opClassAndUnknownTagged(A p);

    void opVoid();

    [marshaled-result] tag(1) SmallStruct? opMStruct1();
    [marshaled-result] tag(1) SmallStruct? opMStruct2(tag(2) SmallStruct? p1, out tag(3) SmallStruct? p2);

    [marshaled-result] tag(1) StringSeq? opMSeq1();
    [marshaled-result] tag(1) StringSeq? opMSeq2(tag(2) StringSeq? p1, out tag(3) StringSeq? p2);

    [marshaled-result] tag(1) StringIntDict? opMDict1();
    [marshaled-result] tag(1) StringIntDict? opMDict2(tag(2) StringIntDict? p1, out tag(3) StringIntDict? p2);

    bool supportsRequiredParams();

    bool supportsJavaSerializable();

    bool supportsCsharpSerializable();

    bool supportsCppStringView();

    bool supportsNullTagged();
}

}
