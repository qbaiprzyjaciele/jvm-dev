# Java Class File Format

### Introduction
I will try to put together a very simple description of a compiled Java class file format. Obviously, loading and interpreting *.class file ithe very first thing we ne need to do in order to execute any java code so i thought it come in very handy to describe it's realatively complex nature in simple words.

### Class File Layout


| Field        | size | description                                                               |
---------------|------|---------------------------------------------------------------------------|
| magic number | 4    |  0xCA 0xFE 0xBA 0xBE  -  famous CAFEBABE at the very beginning of the file| 


