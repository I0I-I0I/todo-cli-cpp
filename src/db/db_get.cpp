#include <cstring>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "db.h"
#include "../globals/types.h"

std::string from_char_to_string(const unsigned char* text) {
	int length = std::strlen(reinterpret_cast<const char*>(text));
	std::string str(reinterpret_cast<const char*>(text), length);
	return str;
}

const char* get_query() {
	const char* query = "select * from todos;";
	return query;
}

std::vector<DBData> db_get_all(const char* db_name) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	const char* tail;
	std::vector<DBData> data;

	int rc = sqlite3_open(db_name, &db);
	rc = sqlite3_prepare_v2(db, get_query(), -1, &stmt, &tail);
	if (rc != SQLITE_OK) {
		std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
	}

	while((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		std::string id = from_char_to_string(sqlite3_column_text(stmt, 0));
		std::string title = from_char_to_string(sqlite3_column_text(stmt, 1));
		std::string completed = from_char_to_string(sqlite3_column_text(stmt, 2));
		DBData row = {id, title, completed == "0" ? false : true};
		data.push_back(row);
	}

	sqlite3_close(db);

	return data;
}
