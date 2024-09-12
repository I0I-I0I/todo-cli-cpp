#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
#include "actions/actions.h"
#include "utils/utils.h"
#include "commands/commands.h"
#include "globals/types.h"
#include "globals/const.h"
#include "db/db.h"

int main(int argc, char* argv[]) {
	std::vector<TodosStruct> todos = {};
	std::vector<ActionsStruct> actions = {
		{ add_todo, "add", "Add todo" },
		{ remove_todo, "remove", "Remove todo" },
		{ check_todo, "check", "Check todo" },
		{ uncheck_todo, "uncheck", "Uncheck todo" },
		{ print_todo, "print", "Print all todo" },
	};
	std::vector<CommandsStruct> commands = {
		{ quit, "quit", "Quit" },
	};

	std::function<int()> help_inner = help(commands, actions);
	std::function<int(ActionStruct&)> handle_inner = handle_action(todos, commands, actions);

	db_create(DB_NAME);

	if (argc > 1) {
		std::string data = argv[1];
		int sep;
		do {
			sep = data.find(';');
			std::string current = data.substr(0, sep);
			data = data.substr(sep + 1);

			ActionStruct action = get_action(current);
			int flag = handle_inner(action);

			if (flag == WRONG_COMMAND) {
				std::cout << "Wrong command!" << std::endl;
				return WRONG_COMMAND;
			} else if (flag == HELP) {
				help_inner();
			}
		} while (sep != -1);
	} else {
		std::cout << "Welcome to ToDo cli app" << std::endl;
		while (true) {
			ActionStruct action = get_action();
			int flag = handle_inner(action);

			if (flag == QUIT) {
				break;
			} else if (flag == HELP) {
				help_inner();
			} else if (flag == WRONG_COMMAND) {
				std::cout << "Wrong command!" << std::endl;
			}
		}
	}

	return 0;
}
