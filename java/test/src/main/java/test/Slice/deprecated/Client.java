// Copyright (c) ZeroC, Inc.

package test.Slice.deprecated;

import test.Slice.deprecated.Test.AsyncMyInterface;
import test.Slice.deprecated.Test.AsyncMyOtherInterface;
import test.Slice.deprecated.Test.AsyncOperationsInterface;
import test.Slice.deprecated.Test.DerivedFieldsClass;
import test.Slice.deprecated.Test.DerivedFieldsException;
import test.Slice.deprecated.Test.FieldsClass;
import test.Slice.deprecated.Test.FieldsException;
import test.Slice.deprecated.Test.FieldsStruct;
import test.Slice.deprecated.Test.FirstDeprecatedEnum;
import test.Slice.deprecated.Test.ImplicitDefaultClass;
import test.Slice.deprecated.Test.ImplicitDefaultException;
import test.Slice.deprecated.Test.ImplicitDefaultStruct;
import test.Slice.deprecated.Test.MyClass;
import test.Slice.deprecated.Test.MyEnum;
import test.Slice.deprecated.Test.MyException;
import test.Slice.deprecated.Test.MyIntConst;
import test.Slice.deprecated.Test.MyInterface;
import test.Slice.deprecated.Test.MyInterfacePrx;
import test.Slice.deprecated.Test.MyOtherClass;
import test.Slice.deprecated.Test.MyOtherEnum;
import test.Slice.deprecated.Test.MyOtherException;
import test.Slice.deprecated.Test.MyOtherInterface;
import test.Slice.deprecated.Test.MyOtherInterfacePrx;
import test.Slice.deprecated.Test.MyStruct;
import test.Slice.deprecated.Test.MyStructDictHelper;
import test.Slice.deprecated.Test.MyStructSeqHelper;
import test.Slice.deprecated.Test.OperationsInterface;
import test.Slice.deprecated.Test.OperationsInterfacePrx;
import test.Slice.deprecated.Test.StringDictHelper;
import test.Slice.deprecated.Test.UnmarkedClass;
import test.Slice.deprecated.Test.UnmarkedException;
import test.Slice.deprecated.Test.UnmarkedStruct;
import test.Slice.deprecated.Test._MyInterfacePrxI;
import test.Slice.deprecated.Test._MyOtherInterfacePrxI;
import test.Slice.deprecated.Test._OperationsInterfacePrxI;
import test.TestHelper;

import java.lang.reflect.AnnotatedElement;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.List;

public class Client extends TestHelper {
    // This method refers to deprecated generated types and members on purpose.
    @SuppressWarnings("deprecation")
    private static void allTests() {
        System.out.print("testing @Deprecated annotations in generated code... ");
        System.out.flush();

        // Deprecated definitions carry the annotation.
        testDeprecated(MyIntConst.class);
        testDeprecated(MyClass.class);
        testDeprecated(MyStruct.class);
        testDeprecated(MyException.class);
        testDeprecated(MyEnum.class);
        testDeprecated(MyInterfacePrx.class);
        testDeprecated(_MyInterfacePrxI.class);
        testDeprecated(field(MyOtherClass.class, "i"));
        testDeprecated(field(MyOtherException.class, "reason"));
        testDeprecated(field(MyOtherEnum.class, "B"));
        testDeprecated(methods(MyOtherInterfacePrx.class, "opLong"));
        testDeprecated(methods(MyOtherInterfacePrx.class, "opLongAsync"));

        // A deprecated optional field carries the annotation on the field and on all its accessors.
        testDeprecated(field(MyOtherClass.class, "j"));
        for (String accessor : List.of("getJ", "setJ", "hasJ", "clearJ", "optionalJ")) {
            testDeprecated(methods(MyOtherClass.class, accessor));
        }

        // The skeleton side never carries the annotation: implementing a deprecated interface or operation must
        // not warn.
        testNotDeprecated(MyInterface.class);
        testNotDeprecated(AsyncMyInterface.class);
        testNotDeprecated(methods(MyOtherInterface.class, "opLong"));
        testNotDeprecated(methods(AsyncMyOtherInterface.class, "opLongAsync"));

        // Definitions that are not deprecated don't get the annotation.
        testNotDeprecated(MyOtherClass.class);
        testNotDeprecated(MyOtherException.class);
        testNotDeprecated(MyOtherEnum.class);
        testNotDeprecated(field(MyOtherEnum.class, "A"));
        testNotDeprecated(MyOtherInterfacePrx.class);
        testNotDeprecated(_MyOtherInterfacePrxI.class);
        testNotDeprecated(methods(MyOtherInterfacePrx.class, "opInt"));
        testNotDeprecated(methods(MyOtherInterfacePrx.class, "opIntAsync"));

        // The helper class generated for a deprecated sequence or dictionary is not deprecated.
        testNotDeprecated(StringDictHelper.class);
        testNotDeprecated(MyStructSeqHelper.class);
        testNotDeprecated(MyStructDictHelper.class);

        System.out.println("ok");

        // The code generated for the definitions below references deprecated definitions. This code must not
        // trigger any deprecation warning: this test does not build when warnings are treated as errors otherwise.
        // Here we check that these definitions are deprecated only where the Slice definitions say so.
        System.out.print("testing definitions that use deprecated definitions... ");
        System.out.flush();

        // A deprecated field with a deprecated type, or with a deprecated default value.
        testNotDeprecated(FieldsStruct.class);
        for (String name : List.of("s", "e", "c", "p", "seq", "dict", "i", "oe")) {
            testDeprecated(field(FieldsStruct.class, name));
        }
        var fieldsStruct = new FieldsStruct();
        test(fieldsStruct.s != null);
        test(fieldsStruct.e == MyEnum.A);
        test(fieldsStruct.i == MyIntConst.value);
        test(fieldsStruct.oe == MyOtherEnum.B);

        testNotDeprecated(FieldsClass.class);
        testNotDeprecated(DerivedFieldsClass.class);
        for (String name : List.of("s", "os", "oe", "i")) {
            testDeprecated(field(FieldsClass.class, name));
        }
        for (String accessor : List.of("getOs", "setOs", "hasOs", "clearOs", "optionalOs", "getOe", "setOe")) {
            testDeprecated(methods(FieldsClass.class, accessor));
        }
        var derivedFieldsClass = new DerivedFieldsClass();
        test(derivedFieldsClass.s != null);
        test(derivedFieldsClass.getOe() == MyEnum.B);
        test(derivedFieldsClass.i == MyIntConst.value);

        testNotDeprecated(FieldsException.class);
        testNotDeprecated(DerivedFieldsException.class);
        testDeprecated(field(FieldsException.class, "s"));
        testDeprecated(field(FieldsException.class, "oe"));
        test(new DerivedFieldsException().s != null);

        // A field initialized with the first enumerator of its enum type, when this enumerator is deprecated.
        testNotDeprecated(FirstDeprecatedEnum.class);
        testDeprecated(field(FirstDeprecatedEnum.class, "Old"));
        testNotDeprecated(ImplicitDefaultStruct.class, field(ImplicitDefaultStruct.class, "e"));
        testNotDeprecated(ImplicitDefaultClass.class, field(ImplicitDefaultClass.class, "e"));
        testNotDeprecated(ImplicitDefaultException.class, field(ImplicitDefaultException.class, "e"));
        test(new ImplicitDefaultStruct().e == FirstDeprecatedEnum.Old);
        test(new ImplicitDefaultClass().e == FirstDeprecatedEnum.Old);
        test(new ImplicitDefaultException().e == FirstDeprecatedEnum.Old);

        // A field whose type is a sequence or dictionary of a deprecated type, but is not itself deprecated.
        testNotDeprecated(UnmarkedStruct.class);
        testNotDeprecated(field(UnmarkedStruct.class, "seq"), field(UnmarkedStruct.class, "dict"));
        testNotDeprecated(UnmarkedClass.class, field(UnmarkedClass.class, "seq"));
        testNotDeprecated(UnmarkedException.class, field(UnmarkedException.class, "dict"));

        // Deprecated operations whose parameters, return value, or exceptions have a deprecated type.
        testNotDeprecated(OperationsInterfacePrx.class);
        testNotDeprecated(_OperationsInterfacePrxI.class);
        testNotDeprecated(OperationsInterface.class);
        testNotDeprecated(AsyncOperationsInterface.class);
        testNotDeprecated(OperationsInterface.OpStructResult.class);
        testNotDeprecated(OperationsInterface.OpMarshaledResultMarshaledResult.class);
        List<String> operations =
            List.of("opStruct", "opEnum", "opClass", "opProxy", "opSeq", "opOptional", "opMarshaledResult", "opThrows");
        for (String operation : operations) {
            testDeprecated(methods(OperationsInterfacePrx.class, operation));
            testDeprecated(methods(OperationsInterfacePrx.class, operation + "Async"));
            testNotDeprecated(methods(OperationsInterface.class, operation));
            testNotDeprecated(methods(AsyncOperationsInterface.class, operation + "Async"));
        }
        testNotDeprecated(methods(OperationsInterfacePrx.class, "opUnmarked"));
        testNotDeprecated(methods(OperationsInterfacePrx.class, "opUnmarkedAsync"));

        System.out.println("ok");
    }

    // Returns the field of 'type' named 'name'.
    private static Field field(Class<?> type, String name) {
        try {
            return type.getDeclaredField(name);
        } catch (NoSuchFieldException ex) {
            throw new RuntimeException(ex);
        }
    }

    // Returns the methods of 'type' named 'name'. There can be several of them: for example, a proxy interface
    // provides two methods with the same name for each operation, with and without a context parameter.
    private static Method[] methods(Class<?> type, String name) {
        Method[] methods =
            Arrays.stream(type.getDeclaredMethods()).filter(m -> m.getName().equals(name)).toArray(Method[]::new);
        test(methods.length > 0);
        return methods;
    }

    private static void testDeprecated(AnnotatedElement... elements) {
        for (AnnotatedElement element : elements) {
            test(element.isAnnotationPresent(Deprecated.class));
        }
    }

    private static void testNotDeprecated(AnnotatedElement... elements) {
        for (AnnotatedElement element : elements) {
            test(!element.isAnnotationPresent(Deprecated.class));
        }
    }

    public void run(String[] args) {
        allTests();
    }
}
