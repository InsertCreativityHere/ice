//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#pragma once

#include <Ice/BuiltinSequences.ice>

module Test
{

enum MyEnum
{
    enum1,
    enum2,
    enum3
}

interface MyInterface;
class MyClass;

struct SmallStruct
{
    bool bo;
    byte by;
    short sh;
    int i;
    long l;
    float f;
    double d;
    string str;
    MyEnum e;
    MyInterface* p;
}

class OptionalClass
{
    bool bo;
    byte by;
    tag(1) short sh;
    tag(2) int i;
}

sequence<MyEnum> MyEnumS;
sequence<SmallStruct> SmallStructS;
sequence<MyClass> MyClassS;

sequence<Ice::BoolSeq> BoolSS;
sequence<Ice::ByteSeq> ByteSS;
sequence<Ice::ShortSeq> ShortSS;
sequence<Ice::IntSeq> IntSS;
sequence<Ice::LongSeq> LongSS;
sequence<Ice::FloatSeq> FloatSS;
sequence<Ice::DoubleSeq> DoubleSS;
sequence<Ice::StringSeq> StringSS;
sequence<MyEnumS> MyEnumSS;
sequence<SmallStructS> SmallStructSS;
sequence<MyClassS> MyClassSS;

dictionary<byte, bool> ByteBoolD;
dictionary<short, int> ShortIntD;
dictionary<long, float> LongFloatD;
dictionary<string, string> StringStringD;
dictionary<string, MyClass> StringMyClassD;

class MyClass
{
    MyClass c;
    Object o;
    SmallStruct s;
    Ice::BoolSeq seq1;
    Ice::ByteSeq seq2;
    Ice::ShortSeq seq3;
    Ice::IntSeq seq4;
    Ice::LongSeq seq5;
    Ice::FloatSeq seq6;
    Ice::DoubleSeq seq7;
    Ice::StringSeq seq8;
    MyEnumS seq9;
    MyClassS seq10;
    StringMyClassD d;
}

interface MyInterface
{
}

exception MyException
{
    MyClass c;
}

module Sub
{
    enum NestedEnum
    {
        nestedEnum1,
        nestedEnum2,
        nestedEnum3
    }

    struct NestedStruct
    {
        bool bo;
        byte by;
        short sh;
        int i;
        long l;
        float f;
        double d;
        string str;
        NestedEnum e;
    }

    exception NestedException
    {
        string str;
    }
}
}

module Test2
{
module Sub2
{
    enum NestedEnum2
    {
        nestedEnum4,
        nestedEnum5,
        nestedEnum6
    }

    struct NestedStruct2
    {
        bool bo;
        byte by;
        short sh;
        int i;
        long l;
        float f;
        double d;
        string str;
        NestedEnum2 e;
    }

    exception NestedException2
    {
        string str;
    }
}
}
