#include <functional>
#include <unordered_map>
#include <vector>
#include "actions.h"
#include "../globals/const.h"
#include "../globals/types.h"

std::function<int(ActionStruct&)> handle_action(
	std::vector<TodosStruct> &todos,
	std::vector<CommandsStruct> &commands,
	std::vector<ActionsStruct> &actions
) {
	return [&todos, &commands, &actions](ActionStruct &action) {
		std::unordered_map<std::string, std::function<int(std::vector<TodosStruct>&, const ActionStruct&)>> actions_func_list;
		std::unordered_map<std::string, std::function<int()>> commands_func_list;
		for (ActionsStruct act : actions) {
			actions_func_list[act.key] = act.func;
		}
		for (CommandsStruct command : commands) {
			commands_func_list[command.key] = command.func;
		}

		for (ActionsStruct act : actions) {
			if (action.action == act.key) {
				return actions_func_list[act.key](todos, action);
			}
		}

		for (CommandsStruct command : commands) {
			if (action.action == command.key) {
				return commands_func_list[command.key]();
			} else if (action.action == "help") {
				return HELP;
			}
		}

		return WRONG_COMMAND;
	};
}

