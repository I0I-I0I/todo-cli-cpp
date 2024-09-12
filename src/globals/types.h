#pragma once

#include <functional>
#include <string>
#include <vector>

struct ActionStruct {
	std::string action;
	std::string args;
};

struct TodosStruct {
	std::string title;
	char state;
};

struct ActionsStruct {
	std::function<int(std::vector<TodosStruct> &, ActionStruct)> func;
	std::string key;
	std::string desc;
};

struct CommandsStruct {
	std::function<int()> func;
	std::string key;
	std::string desc;
};

struct QueryArgs {
	std::string title;
	std::string completed;
};

struct DBData {
	std::string id;
	std::string title;
	bool completed;
};
