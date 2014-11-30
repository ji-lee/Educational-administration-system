MAIN:=main
OBJECT:=main.o admin.o student.o teacher.o fun.o login.o stu_link.o tea_link.o show_all_stu_message.o change_stu_message.o change_tea_message.o
CC:=gcc
OPTION:=-g -Wall -rdynamic

$(MAIN):$(OBJECT)
	$(CC) $^ $(OPTION) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(OPTION)

clean:
	rm -rvf $(MAIN) $(OBJECT)
