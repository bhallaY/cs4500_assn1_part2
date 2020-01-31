#pragma once
#include "object.h"

/**
 * Basic API for an Array.
 * As this is an API, this specifies the essential operations for an Array, 
 * but cannot make a guarantee on the types that are held in the Array. To guarantee
 * type that can be held, subclass and enforce the specific type that should be held.
*/
class Array : public Object {
public:

    /**
     * Array Constructor
     */
    Array (size_t size) {};

    /**Constructor to simultaneously create and add specified elements in Array.
     * @optional: if extending this class, replace this with one similar
     * that replaces Object with specific data type you want array to hold.
    */
    Array (Object** elements, size_t size) : Object(){};

    /**
     * Array Destructor. Frees up memory taken by this array.
     */
    virtual ~Array(){};

    /**
     * Adds the given element to this array at the given index.
     * @param index The index where the element should be inserted
     * @param obj The element to add to this array.
     *
     * Exit(1) - Doesn't allow for inserting at an index larger than the current size of this array.
     */
    virtual void add(size_t index, Object* obj){};

    /**
      * Returns the element at index
      * @param index the index of the element to be returned
      * @return The string at the given index in this array.
      *
      * Exit(1) - Doesn't allow for getting at an index larger than the current size of this array.
      */
    virtual Object* get(size_t index) {};

    /**
     * Removes the element at the given index from this array.
     * @param i The index of the element to be removed from this array.
     * @return The string element at the given index.
     *
     * Exit(1) - Doesn't allow for removing at an index larger than the current size of this list.
     */
    virtual Object* remove(size_t index){};

    /**
     * Attempts to search for given the element in this array.
     * @param obj The element to search the array for.
     *  @return The index of the given element OR size of array + 1 if the given object isn't in the array.
     */
    virtual size_t indexOf(Object* obj){};

    /** 
     * Replaces the element at given array index with the given element.
     * @param index The index of element to be replaced in this array. 
     * @param obj The element that is going to replace the element at the given index. 
     * @sideeffect: replaces the specified element with the given element. 
     * @errors: if the index given is invalid (negative or out of bounds of this array).
    */
   virtual void replace(size_t index, Object* obj) {};

    /**
     * Gets the current number of elements in the array.
     * @return The number of elements in the array.
     */
    virtual size_t size(){};

    /**
     * Calculate the hash code for this array.
     * @return The hash code for this array.
     */
    virtual size_t hash_me_() {};

    /**
     * Check if this array is equal to the Object given. Arrays should be equal if all their elements are equal.
     * Equality for elements of an Array are left to the element definitons of equality.
     * @param other The Object to compare to this array.
     * @return True if other is equal to this; false otherwise.
     */
    virtual bool equals(Object* other) {};

    /** Returns this Array's contents as a string, with a ',' and a space 
     * after between each element printed*/
    virtual char* to_string() {};

    /* Print the contents of this Array to stdout*/
    virtual void print() {};

};