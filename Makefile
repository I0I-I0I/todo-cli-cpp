all: 
	@mkdir build && echo "build folder was created" || echo "build folder already exists"
	@mkdir db && echo "db folder was created" || echo "db folder already exists"
	g++\
		src/main.cpp\
		src/actions/handle_action.cpp\
		src/actions/add_todo.cpp\
		src/actions/remove_todo.cpp\
		src/actions/check_todo.cpp\
		src/actions/print_todo.cpp\
		src/commands/help.cpp\
		src/commands/quit.cpp\
		src/utils/trim.cpp\
		src/utils/get_args.cpp\
		src/utils/get_action.cpp\
		src/utils/handle_prompt.cpp\
		src/db/db_exec.cpp\
		src/db/db_create.cpp\
		src/db/db_add.cpp\
		src/db/db_get.cpp\
		src/db/db_remove_by_index.cpp\
		src/db/db_check_todo.cpp\
		-lsqlite3 -o build/main

clean:
	@echo "Cleaning files"
	rm build/*
