// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT license.
#ifndef INCLUDED_MI_MEMORY_HELPER_HPP
#define INCLUDED_MI_MEMORY_HELPER_HPP


#include <algorithm>
#include <MI.h>


#include "debug_tags.hpp"
#include "mi_script_extensions.hpp"
#include "traits.hpp"


#if (1)
#define _DESTROY_BOOKEND(x) SCX_BOOKEND(x)
#define _DESTROY_PRINT(x) SCX_BOOKEND_PRINT(x)
#else
#define _DESTROY_BOOKEND(x)
#define _DESTROY_PRINT(x)
#endif


#define EXPORT_PUBLIC __attribute__ ((visibility ("default")))


// MI_Destroy
// purpose: Used for freeing memory that was allocated in association with an
//          instance of an MI data type.
//------------------------------------------------------------------------------
template<typename T>
void MI_Destroy (T& val);


// MI_Delete
// purpose: Used for freeing an MI data type instance that was allocated on the
//          heap along with all the memory that was allocated in association
//          with that instance.
//------------------------------------------------------------------------------
template<typename T>
void MI_Delete (T& pVal);


// MI_Deleter
// purpose: Used in conjunction with util::unique_ptr to provide automatic
//          memory cleanup.
//------------------------------------------------------------------------------
template<typename T>
class MI_Deleter
{
public:
    void operator () (T*& pVal)
    {
        MI_Delete (pVal);
    }
};


// MI_Destroy
// purpose: An overload to handle switching for the union MI_Value.
//------------------------------------------------------------------------------
EXPORT_PUBLIC void MI_Destroy (MI_Value& pVal, MI_Type const& type);


// MI_Delete
// purpose: An overload to handle switching for the union MI_Value.
//------------------------------------------------------------------------------
EXPORT_PUBLIC void MI_Delete (MI_Value*& pVal, MI_Type const& type);


// MI_DestroyArrayItems
// purpose: Iterates over a collection calling MI_Destroy for each item.
//------------------------------------------------------------------------------
template<typename T>
void MI_DestroyArrayItems (T* array, MI_Uint32 const& count);


// MI_DeleteArrayItems
// purpose: Iterates over a collection calling MI_Delete for each item.
//------------------------------------------------------------------------------
template<typename T>
void MI_DeleteArrayItems (T* const array, MI_Uint32 const& count);


// MI_DeleteArray
// purpose: Deletes a built-in type array.
//------------------------------------------------------------------------------
template<typename T>
void MI_DeleteArray (T*& array);


// class BaseType
// purpose: Used to determine the base type of references and pointers.
//------------------------------------------------------------------------------
template<typename T>
class BaseType
{
public:
    typedef T type;
};

template<typename T>
class BaseType<T*>
{
public:
    typedef T type;
};

template<typename T>
class BaseType<T&>
{
public:
    typedef typename BaseType<T>::type type;
};

template<typename T>
class BaseType<T const*>
{
public:
    typedef T type;
};

template<typename T>
class BaseType<T const&>
{
public:
    typedef typename BaseType<T>::type type;
};

template<typename T>
class BaseType<T const* const>
{
public:
    typedef T type;
};


// class TypeTraits
// purpose: This is used in some meta-programming to generate the appropriate
//          method for detroying/deleting an C type declared in MI.h.
//------------------------------------------------------------------------------
template<typename T>
class TypeTraits;


// TypeTraits definitions for each of the supported types
//------------------------------------------------------------------------------
template<>
class TypeTraits<MI_Uint8> // also works for MI_Boolean
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Sint8>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Uint16> // also works for MI_Char16
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Sint16>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Uint32>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Sint32>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Uint64>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Sint64>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Real32>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Real64>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Datetime>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = false;
};

template<>
class TypeTraits<MI_Char*>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = true;
};

template<>
class TypeTraits<MI_Instance*>
{
public:
    static bool const IsArray = false;
    static bool const HasDestruct = true;
};

template<>
class TypeTraits<MI_BooleanA>
{
public:
    static bool const IsArray = true;
    typedef MI_Boolean aggregate_t;
};

template<>
class TypeTraits<MI_Uint8A>
{
public:
    static bool const IsArray = true;
    typedef MI_Uint8 aggregate_t;
};

template<>
class TypeTraits<MI_Sint8A>
{
public:
    static bool const IsArray = true;
    typedef MI_Sint8 aggregate_t;
};

template<>
class TypeTraits<MI_Uint16A>
{
public:
    static bool const IsArray = true;
    typedef MI_Uint16 aggregate_t;
};

template<>
class TypeTraits<MI_Sint16A>
{
public:
    static bool const IsArray = true;
    typedef MI_Sint16 aggregate_t;
};

template<>
class TypeTraits<MI_Uint32A>
{
public:
    static bool const IsArray = true;
    typedef MI_Uint32 aggregate_t;
};

template<>
class TypeTraits<MI_Sint32A>
{
public:
    static bool const IsArray = true;
    typedef MI_Sint32 aggregate_t;
};

template<>
class TypeTraits<MI_Uint64A>
{
public:
    static bool const IsArray = true;
    typedef MI_Uint64 aggregate_t;
};

template<>
class TypeTraits<MI_Sint64A>
{
public:
    static bool const IsArray = true;
    typedef MI_Sint64 aggregate_t;
};

template<>
class TypeTraits<MI_Real32A>
{
public:
    static bool const IsArray = true;
    typedef MI_Real32 aggregate_t;
};

template<>
class TypeTraits<MI_Real64A>
{
public:
    static bool const IsArray = true;
    typedef MI_Real64 aggregate_t;
};

template<>
class TypeTraits<MI_Char16A>
{
public:
    static bool const IsArray = true;
    typedef MI_Char16 aggregate_t;
};

template<>
class TypeTraits<MI_DatetimeA>
{
public:
    static bool const IsArray = true;
    typedef MI_Datetime aggregate_t;
};

template<>
class TypeTraits<MI_StringA>
{
public:
    static bool const IsArray = true;
    typedef MI_Char* aggregate_t;
};

template<>
class TypeTraits<MI_InstanceA>
{
public:
    static bool const IsArray = true;
    typedef MI_Instance* aggregate_t;
};


// class MI_DefaultDestroy
// purpose: This is used as a no op for built-in types.
//------------------------------------------------------------------------------
template<typename T>
class MI_DefaultDestroy
{
    // I would like to prevent this from ever being called.
    // It is currently commented out to create a compiler error if changes are
    // made that would call this function.
#if (0)
public:
    static void destroy (T& val)
    {
        // no op
    }
#endif
};


// class MI_BuiltInArrayDestroy
// purpose: This is used for deleting MI_Array(s) of built-in types.
//------------------------------------------------------------------------------
template<typename T>
class MI_BuiltInArrayDestroy
{
public:
    static void destroy (T& val)
    {
        _DESTROY_BOOKEND ("MI_BuiltInArrayDestory::destroy");
        MI_DeleteArray (val.data);
        val.size = 0;
    }
};


// class MI_CompoundArrayDestroy
// purpose: This is used for deleting MI_Array(s) of compound types.
//------------------------------------------------------------------------------
template<typename T>
class MI_CompoundArrayDestroy
{
public:
    static void destroy (T& val)
    {
        _DESTROY_BOOKEND ("MI_CompoundArrayDestory::destroy");
        MI_DestroyArrayItems (val.data, val.size);
        MI_DeleteArray (val.data);
        val.size = 0;
    }
};


// class MI_ArrayDestroy
// purpose: This is similar to a pure virtual class that stands in for either
//          MI_BuiltInArrayDestroy or MI_CompoundArrayDestroy
//------------------------------------------------------------------------------
template<typename T>
class MI_ArrayDestroy : public
    util::conditional<
        TypeTraits<typename TypeTraits<T>::aggregate_t>::HasDestruct,
        MI_CompoundArrayDestroy<T>,
        MI_BuiltInArrayDestroy<T> >::type
{
    // this is similar to a pure virtual class for
    // MI_CompoundArrayDestroy
    // MI_BuiltInArrayDestroy
};


// class MI_DestroyHelper
// purpose: This is similar to a pure virtual class that stands in for either
//          MI_DefaultDestroy or MI_ArrayDestroy
//------------------------------------------------------------------------------
template<typename T>
class MI_DestroyHelper : public
    util::conditional<TypeTraits<typename BaseType<T>::type>::IsArray,
               MI_ArrayDestroy<typename BaseType<T>::type>,
               MI_DefaultDestroy<typename BaseType<T>::type> >::type
{
    // this is similar to a pure virtual class for
    // MI_ArrayDestroy
    // MI_DefaultDestroy
};

// specialization for MI_Char* (MI_String)
template<>
class MI_DestroyHelper<MI_Char*>
{
public:
    static void destroy (MI_Char*& pString)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_Char*>::destroy");
        if (NULL != pString)
        {
            delete[] pString;
            pString = NULL;
        }
    }
};

// specialization for MI_QualifierDecl
template<>
class MI_DestroyHelper<MI_QualifierDecl>
{
public:
    static void destroy (MI_QualifierDecl& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_QualifierDecl>::destroy");
        MI_Destroy (val.name);
        MI_Delete (
            const_cast<MI_Value*&>(
                reinterpret_cast<MI_Value const*&>(val.value)),
            static_cast<MI_Type>(val.type));
    }
};

// specialization for MI_Qualifier
template<>
class MI_DestroyHelper<MI_Qualifier>
{
public:
    static void destroy (MI_Qualifier& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_Qualifier>::destroy");
        MI_Destroy (val.name);
        MI_Delete (
            const_cast<MI_Value*&>(
                reinterpret_cast<MI_Value const*&>(val.value)),
            static_cast<MI_Type>(val.type));
    }
};

// specialization for MI_PropertyDecl
template<>
class MI_DestroyHelper<MI_PropertyDecl>
{
public:
    static void destroy (MI_PropertyDecl& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_PropertyDecl>::destroy");
        MI_Destroy (val.name);
        MI_DeleteArrayItems (val.qualifiers, val.numQualifiers);
        MI_DeleteArray (val.qualifiers);
        val.numQualifiers = 0;
        MI_Destroy (val.className);
        MI_Destroy (val.origin);
        MI_Destroy (val.propagator);
        MI_Delete (
            const_cast<MI_Value*&>(
                reinterpret_cast<MI_Value const*&>(val.value)),
            static_cast<MI_Type>(val.type));
    }
};

// specialization for MI_ParameterDecl
template<>
class MI_DestroyHelper<MI_ParameterDecl>
{
public:
    static void destroy (MI_ParameterDecl& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_ParameterDecl>::destroy");
        MI_Destroy (val.name);
        MI_DeleteArrayItems (val.qualifiers, val.numQualifiers);
        MI_DeleteArray (val.qualifiers);
        val.numQualifiers = 0;
        MI_Destroy (val.className);
    }
};

// specialization for MI_MethodDecl
template<>
class MI_DestroyHelper<MI_MethodDecl>
{
public:
    static void destroy (MI_MethodDecl& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_MethodDecl>::destroy");
        MI_Destroy (val.name);
        MI_DeleteArrayItems (val.qualifiers, val.numQualifiers);
        MI_DeleteArray (val.qualifiers);
        val.numQualifiers = 0;
        MI_DeleteArrayItems (val.parameters, val.numParameters);
        MI_DeleteArray (val.parameters);
        val.numParameters = 0;
        MI_Destroy (val.origin);
        MI_Destroy (val.propagator);
    }
};

// specialization for MI_ProviderFT
template<>
class MI_DestroyHelper<MI_ProviderFT>
{
public:
    static void destroy (MI_ProviderFT& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_ProviderFT>::destroy");
        // no op
    }
};

// specialization for MI_ClassDeclEx
template<>
class MI_DestroyHelper<MI_ClassDeclEx>
{
public:
    static void destroy (MI_ClassDeclEx& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_ClassDeclEx>::destroy");
        MI_Destroy (val.name);
        MI_DeleteArrayItems (val.qualifiers, val.numQualifiers);
        MI_DeleteArray (val.qualifiers);
        val.numQualifiers = 0;
        MI_DeleteArrayItems (val.properties, val.numProperties);
        MI_DeleteArray (val.properties);
        val.numProperties = 0;
        MI_Destroy (val.superClass);
        MI_DeleteArrayItems (val.methods, val.numMethods);
        MI_DeleteArray (val.methods);
        val.numMethods = 0;
        MI_Delete (val.providerFT);
        MI_Destroy (val.owningClassName);
    }
};

// specialization for MI_SchemaDecl
template<>
class MI_DestroyHelper<MI_SchemaDecl>
{
public:
    static void destroy (MI_SchemaDecl& val)
    {
        _DESTROY_BOOKEND ("MI_DestroyHelper<MI_SchemaDecl>::destroy");
        MI_DeleteArrayItems (val.qualifierDecls, val.numQualifierDecls);
        MI_DeleteArray (val.qualifierDecls);
        val.numQualifierDecls = 0;
        MI_DeleteArrayItems (
            reinterpret_cast<MI_ClassDeclEx const* const*>(val.classDecls),
            val.numClassDecls);
        MI_DeleteArray (val.classDecls);
        val.numClassDecls = 0;
    }
};


// ConstRemover
// purpose: A utility to remove const from a data type.
//          This prevents having to implement both non-const and const versions
//          of each MI_DetroyHelper specialization.
//------------------------------------------------------------------------------
template<typename T>
class ConstRemover
{
public:
    typedef T type;
};

template<typename T>
class ConstRemover<T const>
{
public:
    typedef T type;
};

template<typename T>
class ConstRemover<T const*>
{
public:
    typedef T* type;
};

template<typename T>
class ConstRemover<T const* const>
{
public:
    typedef T* type;
};


// MI_Destroy
// purpose: Used for freeing memory that was allocated in association with an
//          instance of an MI data type.
//------------------------------------------------------------------------------
template<typename T>
void MI_Destroy (T& val)
{
    MI_DestroyHelper<typename ConstRemover<T>::type>::destroy (
        const_cast<typename ConstRemover<T>::type&>(val));
}


// MI_Delete
// purpose: Used for freeing an MI data type instance that was allocated on the
//          heap along with all the memory that was allocated in association
//          with that instance.
//------------------------------------------------------------------------------
template<typename T>
void MI_Delete (T& pVal)
{
    if (NULL != pVal)
    {
        MI_Destroy (*pVal);
        delete pVal;
        const_cast<typename ConstRemover<T>::type&>(pVal) = NULL;
    }
}


// MI_DestroyArrayItems
// purpose: Iterates over a collection calling MI_Destroy for each item.
//------------------------------------------------------------------------------
template<typename T>
void MI_DestroyArrayItems (T* const array, MI_Uint32 const& count)
{
    if (NULL != array)
    {
        std::for_each (array, array + count, MI_Destroy<T>);
    }
}


// MI_DeleteArrayItems
// purpose: Iterates over a collection calling MI_Delete for each item.
//------------------------------------------------------------------------------
template<typename T>
void MI_DeleteArrayItems (T* const array, MI_Uint32 const& count)
{
    if (NULL != array)
    {
        std::for_each (array, array + count, MI_Delete<T>);
    }
}


// MI_DeleteArray
// purpose: Deletes a built-in type array.
//------------------------------------------------------------------------------
template<typename T>
void MI_DeleteArray (T*& array)
{
    if (NULL != array)
    {
        delete[] array;
        array = NULL;
    }
}


#undef EXPORT_PUBLIC


#endif // INCLUDED_MI_MEMORY_HELPER_HPP
