# Java Class File Format

### Introduction
I will try to put together a very simple description of a compiled Java class file format. Obviously, loading and interpreting *.class file ithe very first thing we ne need to do in order to execute any java code so i thought it come in very handy to describe it's realatively complex nature in simple words.

### Class File Layout
The table below describes a high-level structure of the class file. Notice how the constant pool is the most important part of the class declaration. It holds not only constant values used in methods code but also names of fields, classes and interfaces and their metadata. Most of other fields are simply pointing to elements of the constant pool, which also usually contains indices to other elements of the same constant pool. This may seem mind-bending but it saves a lot of space avoiding duplications of literals.


| Field              | size | description                                                                   |
---------------------|------|-------------------------------------------------------------------------------|
| magic number       | 4    |  0xCA 0xFE 0xBA 0xBE  -  famous CAFEBABE at the very beginning of the file    | 
| major version      | 2    |  Major version of the class file                                              |
| minor version      | 2    |  Minor version of the class file                                              |
| constant pool count| 2    |  Number of elements in constant pool                                          |
| constant pool      | *    |  A list of constants used in the class. Described extensively below.          |
| acess flags        | 2    |  Access flags for the class/interface. (public, protected, private, package)  |
| this class         | 2    |  An index pointing to the contant pool element describing the class           |
| super class        | 2    |  An index pointing to the contant pool element describing the class           |
| interfaces count   | 2    |  Interfaces count - how many interfaces does the class implement              |
| interfaces         | *    |  an array of indices pointing to interfaces descriptions in constant pool     |
| fields count       | 2    |  Fields count                                                                 |
