#pragma once
//lang::CwC
#include "object.h"

/**
 * An immutable string class. Represents a char*.
 */
class String : public Object {
public:
    char* val_; // char* that is being stored.
    size_t size_; // number of characters (excluding \0)

    /** Constructors **/

    /** Construct a string copying s. Does not take ownership of s. */
    String(char* s) {};

    /** Construct a string copying s. Does not take ownership of s. */
    String(const char* s) {};

    /** Copy Constructor taking the same values as passed in String.*/
    String(String &copy) {};

    /** Delete the string and free its data */
    ~String () {};

    /** Compare strings for equality. Equality is defined as being part of the same class
     * and having the same values for all fields of Object and this String. Another way
     * to check equality is to see if this and other have the same hash.
    */
    bool equals(Object* other) {};

    /** Returns 0 if strings are equal, > 0 if this string is larger,
     *  < 0 otherwise. A string is considered 'larger' if this would come before tgt
     * in a dictionary (it is either shorter in length or character is alphabetically before 
     * tgt's corresponding character) */
    int compare(String* tgt) {};

    /** Computes the hash of this String.*/
    size_t hash_me_() {};

    /** Number of non \0 characters in this string */
    size_t length() {};

    /** Concatenate the strings, return a new object. Other is added to the end of this String */
    String* concat(String* other) {};

    /** Return a newly allocated char* with this string value */
    char* to_string() {};

    /** Print this string on stdout. */
    void print() {};

    /**
     * Returns a new String object that contains the characters within this string that 
     * are bound by the given start_idx and end_idx. Includes characters at the 
     * start and end index given. 
     * Note: if start index > end index, errors out. 
     * Note: if end_idx > length this string, just stops at end of this String. 
     * Indexes cannot be negative. 
    */
    String splice(size_t start_idx, size_t end_idx);
};