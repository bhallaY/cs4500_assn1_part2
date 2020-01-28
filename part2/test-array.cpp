// Lang:CwC
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "object.h"
#include "string.h"
#include "array.h"

int main() {
    printf("Starting Tests for Arrays \n");
    test_size();
    test_size_create_with_objects();
    test_get_1();
    test_get_2();
    test_get_3();
    test_get_4();
    test_add();
    test_add_2();
    test_add_3();
    test_add_4();
    test_remove();
    test_remove_2();
    test_remove_3();
    test_remove_4();
    test_indexOf();
    test_indexOf_not_in_array();
    test_indexOf_2();
    test_indexOf_not_in_array_2();
    test_replace();
    test_replace_2();
    test_hash_me_();
    test_equals();
    printf("SUCCESS! All Pass! \n");
};

void test_size() {
    printf("Test 1 for add\n");
    Array* arr = new Array(10);
    if(!(arr->size()== 10)) {
        exit(-1);
    }
    printf("Test 1 for add passed \n");
    delete[] arr;
}

void test_size_create_with_objects() {
    printf("Test 2 for add\n");
    String* s1 = new String("hi");
    String* s2 = new String("hi");
    String* s3 = new String("hi");
    Object* objs[3]  = {s1, s2, s3};
    Array* arr = new Array(objs);
    if(!(arr->size()==3)) {
        exit(-1);
        std::cout << "expected size " << 3 << " actual " << arr->size(); 
    }
    delete[] arr;
    delete s1;
    delete s2;
    delete s3;
    delete objs;
}

void test_get_1() {
    printf("Test 1 for get\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);
    if (!(tester->get(0)->equals(o1))) {
        exit(-1);
    }

    printf("Test 1 for get passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
}

void test_get_2() {
    printf("Test 2 for get\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);
    if (!(tester->get(2)->equals(o3))) {
        exit(-1);
    }

    printf("Test 2 for get passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
}

void test_get_3() {
    printf("Test 3 for get\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);
    if (!(tester->get(2)->equals(s3))) {
        exit(-1);
    }

    printf("Test 3 for get passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
}

void test_get_4() {
    printf("Test 4 for get\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);
    if (!(tester->get(0)->equals(s1))) {
        exit(-1);
    }

    printf("Test 4 for get passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
}

void test_add() {
    printf("Test 1 for add\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Array* tester = new Array(3);
    tester->add(0, o1);
    if (!(tester->get(0)->equals(o1))) {
        exit(-1);
    }

    printf("Test 1 for add passed \n");
    delete[] tester;
    delete o1;
    delete o2;
    delete o3;
}

void test_add_2() {
    printf("Test 2 for add\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Array* tester = new Array(3);
    tester->add(1, o1);
    if(!(tester->get(1)->equals(o1))) {
        exit(-1);
    }
    printf("Test 2 for add passed \n");
    delete[] tester;
    delete o1;
    delete o2;
    delete o3;
}

void test_add_3() {
    printf("Test 3 for add\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    Array* tester = new Array(3);
    tester->add(0, s1);
    if(!(tester->get(0)->equals(s1))) {
        exit(-1);
    }
    printf("Test 3 for add passed \n");
    delete[] tester;
    delete s1;
    delete s2;
    delete s3;
}

void test_add_4() {
    printf("Test 4 for add\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    Array* tester = new Array(3);
    tester->add(1, s1);
    if(!(tester->get(1)->equals(s1))) {
        exit(-1);
    }
    printf("Test 4 for add passed \n");
    delete[] tester;
    delete s1;
    delete s2;
    delete s3;
}

void test_remove() {
    printf("Test 1 for remove\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);
    // confirm element is where we expect.
    if (!(tester->get(0)->equals(o1))) {
        exit(-1);
    }
    // size of array should not change.
    assert(tester->size() == 3);
    // remove element
    tester->remove(0);
    //now element should not be at that index.
    if ((tester->get(0)->equals(o1))) {
        exit(-1);
    }
    // size of array should not change.
    assert(tester->size() == 3);

    printf("Test 1 for remove passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
}

void test_remove_2() {
    printf("Test 2 for remove\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);
    // confirm element is where we expect.
    if (!(tester->get(1)->equals(o2))) {
        exit(-1);
    }
    // remove element
    tester->remove(1);
    //now element should not be at that index.
    if ((tester->get(1)->equals(o2))) {
        exit(-1);
    }

    printf("Test 2 for remove passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
}

void test_remove_3() {
    printf("Test 3 for remove\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);
    // confirm element is where we expect.
    if (!(tester->get(0)->equals(s1))) {
        exit(-1);
    }
    // size of array should not change.
    assert(tester->size() == 3);
    // remove element
    tester->remove(0);
    //now element should not be at that index.
    if ((tester->get(0)->equals(s1))) {
        exit(-1);
    }
    // size of array should not change.
    assert(tester->size() == 3);

    printf("Test 3 for remove passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
}

void test_remove_4() {
    printf("Test 4 for remove\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);
    // confirm element is where we expect.
    if (!(tester->get(1)->equals(s2))) {
        exit(-1);
    }
    // remove element
    tester->remove(1);
    //now element should not be at that index.
    if ((tester->get(1)->equals(s2))) {
        exit(-1);
    }

    printf("Test 4 for remove passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
}

void test_indexOf() {
    printf("Test 1 for indexOf\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);

    assert(tester->indexOf(o1) == 0);

    printf("Test 1 for indexOf passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
}

void test_indexOf_not_in_array() {
    printf("Test 2 for indexOf\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);

    assert(tester->indexOf(o4) == -1);

    printf("Test 2 for indexOf passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
}

void test_indexOf_2() {
    printf("Test 3 for indexOf\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    String* s4 = new String("Woooo");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);

    assert(tester->indexOf(s1) == 0);

    printf("Test 3 for indexOf passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void test_indexOf_not_in_array_2() {
    printf("Test 4 for indexOf\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    String* s4 = new String("Woooo");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);

    assert(tester->indexOf(s4) == -1);

    printf("Test 4 for indexOf passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void test_replace() {
    printf("Test 1 for replace\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);

    if(!(tester->get(0)->equals(o1))) {
        exit(-1);
    }

    tester->replace(0, o4);

    if(!(tester->get(0)->equals(o4))) {
        exit(-1);
    }

    printf("Test 1 for replace passed \n");
    delete[] tester;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
}

void test_replace_2() {
    printf("Test 2 for replace\n");
    String* s1 = new String("hello");
    String* s2 = new String("world");
    String* s3 = new String("!");
    String* s4 = new String("Woooo");
    Object* objs[3]  = {s1, s2, s3};
    Array* tester = new Array(objs);

    if(!(tester->get(0)->equals(s1))) {
        exit(-1);
    }

    tester->replace(0, s4);

    if(!(tester->get(0)->equals(s4))) {
        exit(-1);
    }

    printf("Test 2 for replace passed \n");
    delete[] tester;
    delete objs;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

// hash_me_ not tested because it is up 
// to the implementer to pick an algorithm to hash. 
// HOWEVER, because we define two Arrays as equal if their elements are equal
// we indirectly test this by making sure whatever hash comes for one array, must
// be the same for a second identical array. 

void test_hash_me_() {
    printf("Test 1 for hash_me_\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);
    Array* tester2 = new Array(objs);

    // hash must be equal because equivalent arrays
    if(tester->hash_me_() != tester2->hash_me_()) {
        exit(-1);
    }

    printf("Test 1 for hash_me_ passed \n");
    delete[] tester;
    delete[] tester2;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
}

void test_equals() {
    printf("Test 1 for equals\n");
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* objs[3]  = {o1, o2, o3};
    Array* tester = new Array(objs);
    Array* tester2 = new Array(objs);

    //  must be equal because equivalent arrays
    if(!(tester->equals(tester2))) {
        exit(-1);
    }

    printf("Test 1 for equals passed \n");
    delete[] tester;
    delete[] tester2;
    delete objs;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
}
