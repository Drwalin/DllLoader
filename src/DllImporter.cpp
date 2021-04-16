/*
 *  This file is part of Drwalin's Dll Importer.
 *  Copyright (C) 2018-2021 Marek Zalewski aka Drwalin
 *
 *  ICon3 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ICon3 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef DLL_IMPORTER_CPP
#define DLL_IMPORTER_CPP

#include "../include/DllImporter.h"

#if defined __cplusplus
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#else
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#endif

struct DllHandleCounterElement
{
	intptr_t handle;
	int counter;
};

DllHandleCounterElement *dllHandleCounterMap = (DllHandleCounterElement*)malloc(sizeof(DllHandleCounterElement)*16);
int dllHandleCounterElements = 0;
int dllHandleCounterAllocatedElements = 16;

DllHandleCounterElement *DllHandleCounterGetElement(void *handle) {
	intptr_t value = (intptr_t)handle;
	int i;
	for(i=0; i<dllHandleCounterElements; ++i) {
		if(dllHandleCounterMap[i].handle == value)
			return &(dllHandleCounterMap[i]);
	}
	
	if(dllHandleCounterElements == dllHandleCounterAllocatedElements) {
		dllHandleCounterAllocatedElements *= 2;
		dllHandleCounterMap = (DllHandleCounterElement*)realloc(dllHandleCounterMap, sizeof(DllHandleCounterElement)*dllHandleCounterAllocatedElements);
	}
	
	++dllHandleCounterElements;
	DllHandleCounterElement *ret = &(dllHandleCounterMap[dllHandleCounterElements-1]);
	ret->handle = value;
	ret->counter = 0;
	return ret;
}

void DllHandleCounterIncrement(void *handle) {
	DllHandleCounterGetElement(handle)->counter += 1;
}

void DllHandleCounterDecrement(void *handle) {
	DllHandleCounterGetElement(handle)->counter -= 1;
}

int DllHandleCounterGet(void *handle) {
	DllHandleCounterElement *ptr = DllHandleCounterGetElement(handle);
	if(ptr) {
		return ptr->counter;
	}
	return 0;
}



#if defined __WIN32__ || defined _WIN64

#include <windows.h>

void *DllLoad(const char *file) {
	if(file) {
		void *handle = LoadLibrary(file);
		DllHandleCounterIncrement(handle);
		return handle;
	}
	return nullptr;
}

void DllRelease(void *handle) {
	if(handle) {
		DllHandleCounterDecrement(handle);
		if(DllHandleCounterGetElement(handle)->counter <= 0) {
			FreeLibrary((HINSTANCE)handle);
			DllHandleCounterGetElement(handle)->counter = 0;
		}
	}
}

void *DllGetObject(void *handle, const char *objectName) {
	if(handle && objectName) {
		return (void*)GetProcAddress((HINSTANCE)handle, objectName);
	}
	return nullptr;
}

char *DllGetErrorString() {
	const int msgSize = 1024;
	static char msg[msgSize];
	DWORD err = GetLastError();
	if(err == 0)
		return (msg[0]=0,msg);
	FormatMessageA(	FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
					msg, msgSize, NULL);
	
	return msg;
}

const char *GetDllExtension() {
	return ".dll";
}

const char *GetPathSeparator() {
	return "\\";
}

#elif defined __unix__

#include <dlfcn.h>

void *DllLoad(const char *file) {
	if(file) {
		void *handle = dlopen(file, RTLD_NOW);	// RTLD_LAZY);
		DllHandleCounterIncrement(handle);
		return handle;
	}
	return nullptr;
}

void DllRelease(void *handle) {
	if(handle) {
		DllHandleCounterDecrement(handle);
		if(DllHandleCounterGetElement(handle)->counter <= 0) {
			dlclose(handle);
			DllHandleCounterGetElement(handle)->counter = 0;
		}
	}
}

void *DllGetObject(void *handle, const char *objectName) {
	if(handle && objectName) {
		return dlsym(handle, objectName);
	}
	return nullptr;
}

char *DllGetErrorString() {
	return dlerror();
}

const char *GetDllExtension() {
	return ".so";
}

const char *GetPathSeparator() {
	return "/";
}

#else

#  error Unknown system, or not defined symbol (__unix__ or __WIN32__ or _WIN64)

#endif		// system type



#if defined __cplusplus

bool Dll::IsValid() const {
	return handle != NULL;
}

void* Dll::Open(const char *dllFileName, bool addAppropriateExtension) {
	Close();
	const int bufferSize = 4096;
	char fileName[bufferSize];
	snprintf(fileName, bufferSize, "%s%s", dllFileName, addAppropriateExtension?GetDllExtension():"");
	handle = DllLoad(fileName);
	if(handle == NULL)
		printf("\n Dll::Open error <%s>:\n   %s\n", fileName, DllGetErrorString());
	return handle;
}

void Dll::Close() {
	if(handle)
		DllRelease(handle);
	handle = NULL;
}

Dll::Dll() {
	handle = NULL;
}

Dll::Dll(const char *dllFileName) {
	handle = NULL;
	Open(dllFileName);
}

Dll::~Dll() {
	Close();
}

const std::string &Dll::GetExtension() {
	static const std::string extension(GetDllExtension());
	return extension;
}

#endif

#endif		// DLL_IMPORTER_CPP

