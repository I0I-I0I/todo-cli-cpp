#include <string>
#include "../globals/const.h"
#include "../globals/types.h"
#include "db.h"

std::string get_query_add(QueryArgs args) {
	std::string db_table(DB_TABLE);
	std::string query = "insert into " + db_table + " (id, title, completed) values (hex(randomblob(16)), ";
	query += "'" + args.title + "'" + ", ";
	query += args.completed;
	query += ");";
	return query;
}

int db_add(std::string db_name, QueryArgs args) {
	std::string query = get_query_add(args);
	int rc = db_exec(db_name.c_str(), query, 0, "Cannot add new value in db");
	return rc;
}
