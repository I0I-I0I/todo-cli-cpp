#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
#include "actions/actions.h"
#include "utils/utils.h"
#include "commands/commands.h"
#include "globals/types.h"
#include "globals/const.h"

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

	if (argc > 1) {
		std::string data = argv[1];
	}

	std::cout << "Welcome to ToDo cli app" << std::endl;

	while (true) {
		ActionStruct action = get_action();
		int flag = handle_action(todos, commands, actions, action);

		if (flag == QUIT) {
			break;
		} else if (flag == HELP) {
			help_inner();
		} else if (flag == WRONG_COMMAND) {
			std::cout << "Wrong command!" << std::endl;
		}
	}

	return 0;
}
