#include <iostream>
#include <sqlite3.h>
#include <string>
#include "db.h"
#include "../globals/const.h"

int db_exec(
	const char* db_name,
	std::string command,
	int (*cb)(void*,int,char**,char**),
	std::string message_on_error
) {
	sqlite3* db;
	char* err_msg = 0;
	int rc;

	rc = sqlite3_open(db_name, &db);
	if (rc) {
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		return rc;
	}

	rc = sqlite3_exec(db, command.c_str(), cb, 0, &err_msg);
	if (rc != SQLITE_OK) {
		std::cerr << message_on_error << std::endl;
		return -1;
	}

	sqlite3_close(db);

	return 0;
}
