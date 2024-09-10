#pragma once

#include <vector>
#include "../globals/types.h"

std::function<int(ActionStruct&)> handle_action(
	std::vector<TodosStruct> &todos,
	std::vector<CommandsStruct> &commands,
	std::vector<ActionsStruct> &actions
);

int add_todo(std::vector<TodosStruct> &todos, ActionStruct action);
int remove_todo(std::vector<TodosStruct> &todos, ActionStruct action);
int check_todo(std::vector<TodosStruct> &todos, ActionStruct action);
int uncheck_todo(std::vector<TodosStruct> &todos, ActionStruct action);
int print_todo(std::vector<TodosStruct> &todos, ActionStruct action);
