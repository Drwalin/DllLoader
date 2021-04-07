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

#ifndef CLASS_FACTORY_H
#define CLASS_FACTORY_H

#include "ModulesFactory.h"

#include <string>

template <typename T, typename... Args>
class ClassFactory : public ModulesFactory {
public:
	
	typedef T* (*ClassFactoryConstructorType)(Args...);
	
	ClassFactory(const std::string &constructorFunctionNamePattern) : pattern(constructorFunctionNamePattern) {}
	~ClassFactory() {}
	
	bool HasClass(const std::string &className) const {
		auto it = constructors.find(className);
		return it!=constructors.end();
	}
	
	T* GetNew(const std::string &className, Args... args) {
		auto it = constructors.find(className);
		if(it == constructors.end())
			return NULL;
		return it->second(args...);
	}
	
	ClassFactoryConstructorType GetConstructor(const char *className) {
		auto it = constructors.find(className);
		if(it == constructors.end())
			return NULL;
		return it->second;
	}
	
	ClassFactoryConstructorType AddClass(const char *className, const char *moduleName) {
		auto it = constructors.find(className);
		if(it != constructors.end())
			return it->second;
		
		std::shared_ptr<Dll> dll = GetModule(moduleName);
		if(dll == NULL) {
			fprintf(stderr, "\n Module: \"%s\" is not registered while getting %s class instantiator", moduleName, className);
			return NULL;
		}
		
		std::string instantiatorSymbol = pattern;
		while(true) {
			size_t pos = instantiatorSymbol.find("%");
			if(pos == std::string::npos)
				break;
			instantiatorSymbol.replace(pos, 1, className);
		}
		
		ClassFactoryConstructorType constructor = dll->Get<ClassFactoryConstructorType>(instantiatorSymbol.c_str());
		
		if(constructor == NULL) {
			fprintf(stderr, "\n Cannot get symbol: \"%s\" from: \"%s\"", instantiatorSymbol.c_str(), moduleName);
			return NULL;
		}
		
		constructors[className] = constructor;
		return constructor;
	}
	
	void RemoveClass(const char *moduleName) {
		constructors.erase(moduleName);
		RemoveModule(moduleName);
	}
	
protected:
	
	std::map<std::string, ClassFactoryConstructorType> constructors;
	const std::string pattern;
};

#endif
