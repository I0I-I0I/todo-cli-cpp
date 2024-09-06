#include <iostream>

std::string todos[2][2] = {
	{"Create app", "n"},
	{"Learning c++", "n"},
};

void handle_action(char action, std::string todos[2][2], std::string actions[2][2]) {
	std::cout << action;
}

void greeting() {
	std::cout << "Welcome to ToDo cli app\n";
}

char get_action(std::string actions[2][2]) {
	char action;
	std::cout << "Choice what you want?\n";
	for (int i = 0; i < 2; i++) {
		std::cout << "\t" << actions[i][0] << ": " << actions[i][1] << "\n";
	}
	std::cout << std::endl;
	std::cin >> action;
	return action;
}

int main() {
	greeting();

	std::string actions[2][2] = {
		{ "a", "Add todo" },
		{ "r", "Remove todo" },
	};

	char action = get_action(actions);
	handle_action(action, todos, actions);

	return 0;
}
