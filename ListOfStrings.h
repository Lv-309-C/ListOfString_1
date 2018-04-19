#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "stdafx.h"


void MenuPrint();
void StrListPrint(char**);
void StrListInit(char***);
void StrListDestroy(char***);
size_t StrListSize(char**);
size_t StrListIndexOf(char**, char*);
void StrListAdd(char***, char*);
bool StrListRemove(char***, char*);
void StrListReplaceStrings(char**, char*, char*);
char* StrElementOf(char**, char*);
void StrListSort(char**);
void StrListRemoveDuplicates(char**);
