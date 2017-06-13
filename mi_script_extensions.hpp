// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT license.
#ifndef INCLUDED_MI_SCRIPT_EXTENSIONS_HPP
#define INCLUDED_MI_SCRIPT_EXTENSIONS_HPP


#include <MI.h>


#define EXPORT_PUBLIC __attribute__ ((visibility ("default")))


// struct MI_ClassDeclEx
// purpose: This extends MI_ClassDecl to include MI_ScriptProviderFT.
//------------------------------------------------------------------------------
struct MI_ClassDeclEx : public MI_ClassDecl
{
    MI_Uint32 functionTableFlags;
    MI_Char const* owningClassName;
};


EXPORT_PUBLIC MI_ClassDeclEx const*
findClassDecl (
    MI_Char const* const pClassName,
    MI_SchemaDecl const* const pSchemaDecl);


EXPORT_PUBLIC MI_MethodDecl const*
findMethodDecl (
    MI_Char const* const pMethodName,
    MI_ClassDecl const* const pClassDecl);


#undef EXPORT_PUBLIC


#endif // INCLUDED_MI_SCRIPT_EXTENSIONS_HPP
