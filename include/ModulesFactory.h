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

#ifndef MODULES_FACTORY_H
#define MODULES_FACTORY_H

#include "DllImporter.h"

#include <map>
#include <string>
#include <memory>

class ModulesFactory {
public:

	ModulesFactory();
	~ModulesFactory();
	
	std::shared_ptr<Dll> GetModule(const char *name);
	
	std::shared_ptr<Dll> AddModule(const char *path);
	void RemoveModule(const char *name);
	
protected:
	
	std::map<std::string, std::shared_ptr<Dll> > dlls;
	
};

#endif
