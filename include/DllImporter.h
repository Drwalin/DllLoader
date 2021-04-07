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

#ifndef DLL_IMPORTER_H
#define DLL_IMPORTER_H

#ifdef __cplusplus
extern "C" {
#endif

void *DllLoad(const char *file);
void DllRelease(void *handle);
void *DllGetObject(void *handle, const char *objectName);
char *DllGetErrorString();

const char *GetDllExtension();

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

#include <string>

class Dll {
public:
	
	Dll();
	Dll(const char *dllFileName);
	
	~Dll();
	
	bool IsValid() const;
	void* Open(const char *dllFileName, bool addAppropriateExtension=true);
	void Close();
	
	template <typename T>
	T Get(const char *objectName) {
		return reinterpret_cast<T>(DllGetObject(this->handle, objectName));
	}
	
	static const std::string &GetExtension();
	
private:
	
	void *handle;
};

#endif

#endif
