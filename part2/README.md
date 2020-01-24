# Assignment One Part Two Array API Explanation

Authors: Yash Bhalla and Mike Eiden

## Part Two Overview

This directory contains our submission for Assignmnet 1 Part 2. We include object.h, string.h, array.h, and test-array.cpp as per assignment guidelines. Object, String, and Array header files contain what we consider the most essential features (methods) for each. test-array.cpp 
only validates a successful implementation of Array.h, as that is the data structure we chose to describe. It will not validate a proper 
implementation of Object or String, as their respective behavior is separate from the Array API. Everything is written in CwC code, except test-array.cpp.

### Object

Object is the base class that is on top of the hierarchy of **all** classes.
It guarantees the most basic behaviours: equality, hashing, converting to a string, and printing to stdout. All of these methods are 
virtual to have every subclass has the behavior. Ideally, subclasses should override these methods. 

### String 

String is essentially a _nice_ wrapper class around char[]. It is an immutable representation of strings.
It contains three constructors: to copy another string, and to accept both const char* and char* inputs. It subclasses Object and should override equals and the hash methods to define equality for the class. 

In addition to the methods it inherits from Object, it allows for concatenation of strings, obtaining length, comparing this string to another, and splicing a string. 
Comparisons between Strings is done by checking if this string would come earlier in the dictionary than another string.  

### Array

Array subclasses Object. It contains only the methods we consider essential to being an Array. These methods boil down to five features: traversing the array, updating array elements, adding array elements, deleting array elements, and searching for an element. The Array we specify is of **fixed-length**.

Currently, our Array API only specifically handles objects of type Object. It shoudl be able to handle objects of subclasses of Object, however, this may lead to Arrays being abused and containing multiple different subclasses per Array instance. 
If the implementor or other users want type safety, we recommend to fully implement the Array interface we present and then subclass that, adding a constructor to only take the desired type as well as changing the public field to only accept an array of that type. Because we are required to specify constructors and we **cannot** use generics, this is the most efficient way we think could handle multiple types. 
There should not be a burdensome code duplication this way. The methods replace, indexOf, and add would have to be overriden and essentially type check "obj" parameter, to instead only allow for objects of the type that is desired. The easiest way to do this may be to dynamic cast the given "obj", and if that fails, return an error, and if it succeeds, proceed with the given functionality. 

The test-array.cpp allows an implementor to check their implementation and see if it holds faithful to our specifications. Any confusion about what a method should do, should be cleared up by looking at the tests. We do not test to_string nor print.