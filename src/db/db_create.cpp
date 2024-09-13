#include <sqlite3.h>
#include <iostream>
#include "db.h"
#include "../globals/const.h"

int db_create(
	const char* db_name
) {
	sqlite3* db;

	int rc = sqlite3_open(db_name, &db);
	if (rc) {
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		return rc;
	}

	std::string db_table(DB_TABLE);
	std::string sql = "create table if not exists " + db_table + " ("
		"id int primary key not null, "
		"title text not null, "
		"completed bool not null);";

	rc = db_exec(db_name, sql, 0, "Cannot create a db");

	sqlite3_close(db);

	return rc;
}
