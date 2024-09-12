#pragma once

#include <string>
#include "../globals/types.h"

int db_create(const char* db_name);
int db_exec(
	const char* db_name,
	std::string command,
	int (*cb)(void*,int,char**,char**) = 0,
	std::string massage_on_error = "SQL DB Error"
);
std::vector<DBData> db_get_all(const char* db_name);
int db_add(std::string db_name, QueryArgs args);
int db_remove_by_index(const char* db_name, std::vector<DBData> data, int index);
int db_toggle_check(const char* db_name, std::vector<DBData> data, int index, bool flag);
