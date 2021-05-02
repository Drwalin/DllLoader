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

#ifndef MODULES_FACTORY_CPP
#define MODULES_FACTORY_CPP

#include "../include/ModulesFactory.h"

inline std::string GetCoreName(const std::string &name) {
	std::string ret(name);
	int s1 = ret.rfind("/");
	int s2 = ret.rfind("\\");
	int slash = std::max( ((size_t)s1!=std::string::npos?s1:-1), ((size_t)s2!=std::string::npos?s2:-1) );
	if(slash != -1)
		ret = ret.substr(slash+1);
	int dot = ret.rfind(".");
	if((size_t)dot != std::string::npos)
		ret = ret.substr(0,dot);
	return ret;
}

std::shared_ptr<Dll> ModulesFactory::GetModule(const char *name) {
	auto it = dlls.find(GetCoreName(name));
	if(it != dlls.end())
		return it->second;
	return NULL;
}

void ModulesFactory::RemoveModule(const char *name) {
	dlls.erase(GetCoreName(name));
}

std::shared_ptr<Dll> ModulesFactory::AddModule(const char *path) {
	std::string name = GetCoreName(path);
	auto it = dlls.find(name);
	if(it != dlls.end()) {
		return it->second;
	}
	std::shared_ptr<Dll> dll(new Dll(path));
	if(dll->IsValid() == false) {
		fprintf(stderr, "\n Cannot register module \"%s\" as \"%s\"", path, name.c_str());
		return NULL;
	}
	auto pair = std::make_pair(std::string(name), dll);
	dlls.insert(pair);
	return dll;
}

ModulesFactory::ModulesFactory() {}
ModulesFactory::~ModulesFactory() {
	dlls.clear();
}

#endif

