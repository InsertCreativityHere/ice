// Copyright (c) ZeroC, Inc.

package test.Slice.structure;

import com.zeroc.Ice.Communicator;
import com.zeroc.Ice.ObjectPrx;

import test.Slice.structure.Test.C;
import test.Slice.structure.Test.S1;
import test.Slice.structure.Test.S2;
import test.TestHelper;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Client extends TestHelper {
    private static void allTests(Communicator communicator) {
        System.out.print("testing equals() for Slice structures... ");
        System.out.flush();

        // Define some default values.
        C defaultC = new C(5);
        S1 defaultS = new S1("name");
        String[] defaultStringSeq = new String[]{"one", "two", "three"};
        ArrayList<Integer> defaultIntList = new ArrayList<>();
        defaultIntList.add(1);
        defaultIntList.add(2);
        defaultIntList.add(3);
        Map<String, String> defaultStringDict = new HashMap<>();
        defaultStringDict.put("abc", "def");
        ObjectPrx defaultProxy = communicator.stringToProxy("test");
        S2 s2 =
            new S2(
                true,
                (byte) 98,
                (short) 99,
                100,
                101,
                (float) 1.0,
                2.0,
                "string",
                defaultStringSeq,
                defaultIntList,
                defaultStringDict,
                defaultS,
                defaultC,
                defaultProxy);

        // Compare default-constructed structures.
        {
            test(new S2().equals(new S2()));
        }

        // Change one primitive member at a time.
        {
            S2 v;

            v = s2.clone();
            test(v.equals(s2));

            v = s2.clone();
            v.bo = false;
            test(!v.equals(s2));

            v = s2.clone();
            v.by--;
            test(!v.equals(s2));

            v = s2.clone();
            v.sh--;
            test(!v.equals(s2));

            v = s2.clone();
            v.i--;
            test(!v.equals(s2));

            v = s2.clone();
            v.l--;
            test(!v.equals(s2));

            v = s2.clone();
            v.f--;
            test(!v.equals(s2));

            v = s2.clone();
            v.d--;
            test(!v.equals(s2));

            v = s2.clone();
            v.str = "";
            test(!v.equals(s2));
        }

        // String member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.str = new String(s2.str);
            test(v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.str = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.str = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.str = null;
            v2.str = null;
            test(v1.equals(v2));
        }

        // Sequence member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.ss = s2.ss.clone();
            test(v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.ss = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.ss = null;
            test(!v1.equals(v2));
        }

        // Custom sequence member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.il = new ArrayList<>(s2.il);
            test(v1.equals(s2));

            v1 = s2.clone();
            v1.il = new ArrayList<>();
            test(!v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.il = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.il = null;
            test(!v1.equals(v2));
        }

        // Dictionary member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.sd = new HashMap<>(s2.sd);
            test(v1.equals(s2));

            v1 = s2.clone();
            v1.sd = new HashMap<>();
            test(!v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.sd = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.sd = null;
            test(!v1.equals(v2));
        }

        // Struct member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.s = s2.s.clone();
            test(v1.equals(s2));

            v1 = s2.clone();
            v1.s = new S1("name");
            test(v1.equals(s2));

            v1 = s2.clone();
            v1.s = new S1("noname");
            test(!v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.s = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.s = null;
            test(!v1.equals(v2));
        }

        // Class member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.cls = s2.cls.clone();
            test(!v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.cls = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.cls = null;
            test(!v1.equals(v2));
        }

        // Proxy member
        {
            S2 v1, v2;

            v1 = s2.clone();
            v1.prx = communicator.stringToProxy("test");
            test(v1.equals(s2));

            v1 = s2.clone();
            v1.prx = communicator.stringToProxy("test2");
            test(!v1.equals(s2));

            v1 = s2.clone();
            v2 = s2.clone();
            v1.prx = null;
            test(!v1.equals(v2));

            v1 = s2.clone();
            v2 = s2.clone();
            v2.prx = null;
            test(!v1.equals(v2));
        }

        System.out.println("ok");
    }

    public void run(String[] args) {
        try (Communicator communicator = initialize(args)) {
            allTests(communicator);
        }
    }
}
