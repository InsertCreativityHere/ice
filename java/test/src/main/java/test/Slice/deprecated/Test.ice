// Copyright (c) ZeroC, Inc.

#pragma once

[["suppress-warning:deprecated"]]

["java:identifier:test.Slice.deprecated.Test"]
module Test
{
    // Applies the deprecated metadata on various Slice definitions.

    ["deprecated"] const int MyIntConst = 42;

    ["deprecated:Use NewStringSeq instead."] sequence<string> StringSeq;
    ["deprecated"] dictionary<string, string> StringDict;

    ["deprecated"] class MyClass
    {
        int i;
    }

    class MyOtherClass
    {
        ["deprecated"] int i;
        ["deprecated"] optional(1) int j;
    }

    ["deprecated"] class MyForwardClass;

    ["deprecated"] struct MyStruct
    {
        string name;
    }

    ["deprecated"] exception MyException
    {
        string reason;
    }

    exception MyOtherException
    {
        ["deprecated"] string reason;
    }

    ["deprecated"] interface MyInterface
    {
        void opInt(int i);
    }

    ["deprecated"] enum MyEnum { A, B, C }

    enum MyOtherEnum
    {
        A,
        ["deprecated:Use A instead."] B,
        C
    }

    interface MyOtherInterface
    {
        void opClass(MyClass c);

        void opInt(int x);

        ["deprecated:Use opInt() instead."] void opLong(long x);

        void opProxy(MyInterface* proxy) throws MyException, MyOtherException;

        MyStruct opStruct(MyStruct s);
    }

    ["deprecated"] interface MyForwardInterface;

    // The definitions below use deprecated definitions without being at fault. The Java code generated for them must
    // compile without any deprecation warning: this test does not build when warnings are treated as errors otherwise.

    ["deprecated"] sequence<MyStruct> MyStructSeq;
    ["deprecated"] dictionary<MyEnum, MyStruct> MyStructDict;

    // These two are missing the deprecated metadata, but the definitions that use them are not at fault.
    sequence<MyStruct> UnmarkedStructSeq;
    dictionary<string, MyStruct> UnmarkedStructDict;

    // Only the first enumerator is deprecated. A field with this type and no default value is initialized with it.
    enum FirstDeprecatedEnum
    {
        ["deprecated"] Old,
        New
    }

    struct FieldsStruct
    {
        ["deprecated"] MyStruct s;
        ["deprecated"] MyEnum e;
        ["deprecated"] MyClass c;
        ["deprecated"] MyInterface* p;
        ["deprecated"] MyStructSeq seq;
        ["deprecated"] MyStructDict dict;
        ["deprecated"] int i = MyIntConst;
        ["deprecated"] MyOtherEnum oe = MyOtherEnum::B;
    }

    class FieldsClass
    {
        ["deprecated"] MyStruct s;
        ["deprecated"] optional(1) MyStruct os;
        ["deprecated"] optional(2) MyEnum oe = MyEnum::B;
        ["deprecated"] int i = MyIntConst;
    }

    class DerivedFieldsClass extends FieldsClass
    {
        int j;
    }

    exception FieldsException
    {
        ["deprecated"] MyStruct s;
        ["deprecated"] optional(1) MyEnum oe;
    }

    exception DerivedFieldsException extends FieldsException
    {
        int j;
    }

    struct ImplicitDefaultStruct
    {
        FirstDeprecatedEnum e;
    }

    class ImplicitDefaultClass
    {
        FirstDeprecatedEnum e;
    }

    exception ImplicitDefaultException
    {
        FirstDeprecatedEnum e;
    }

    struct UnmarkedStruct
    {
        UnmarkedStructSeq seq;
        UnmarkedStructDict dict;
    }

    class UnmarkedClass
    {
        UnmarkedStructSeq seq;
    }

    exception UnmarkedException
    {
        UnmarkedStructDict dict;
    }

    interface OperationsInterface
    {
        ["deprecated"] MyStruct opStruct(MyStruct s, out MyStruct o);

        ["deprecated"] MyEnum opEnum(MyEnum e);

        ["deprecated"] MyClass opClass(MyClass c);

        ["deprecated"] MyInterface* opProxy(MyInterface* p);

        ["deprecated"] MyStructSeq opSeq(MyStructDict d);

        ["deprecated"] optional(1) MyStruct opOptional(optional(2) MyStruct s);

        ["deprecated", "marshaled-result"] MyStruct opMarshaledResult();

        ["deprecated"] void opThrows() throws MyException;

        UnmarkedStructSeq opUnmarked(UnmarkedStructDict d);
    }
}
