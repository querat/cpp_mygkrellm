##
## Makefile for  in /home/querat_g/piscine/piscine_cpp_d01/ex01
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Jan  6 14:27:54 2016 querat_g
## Last update Sun Jan 24 06:26:36 2016 Adrien Schmouker
##

RM	=	rm -f

CC	=	g++

LDFLAGS	=	-I./include
LDFLAGS	+=	`ncurses6-config --cflags --libs`
LDFLAGS	+=	-lpanel
LDFLAGS	+=	-I./src/
LDFLAGS	+=	-I./src/MonitorCore/
LDFLAGS	+=	-I./src/MonitorModule/
LDFLAGS	+=	-I./src/MonitorModule/RamModule/
LDFLAGS	+=	-I./src/MonitorModule/CpuModule/
LDFLAGS	+=	-I./src/MonitorModule/OSKernelModule/
LDFLAGS	+=	-I./src/MonitorModule/DateTimeModule/
LDFLAGS	+=	-I./src/MonitorModule/MachineUserNameModule/
LDFLAGS	+=	-I./src/MonitorDisplay/

CXXFLAGS =	-W -Wall -Wextra -Wunused  -g -g3 -std=c++11 #-Werror 
CXXFLAGS +=	$(LDFLAGS)

SRCS	=	src/main.cpp \
		src/GKrellM.cpp \
		src/MonitorCore/MonitorCore.cpp \
		src/MonitorModule/MonitorModule.cpp \
		src/MonitorModule/RamModule/RamModule.cpp \
		src/MonitorModule/CpuModule/CpuModule.cpp \
		src/MonitorModule/CpuModule/CpuUsage.cpp \
		src/MonitorModule/OSKernelModule/OSKernelModule.cpp \
		src/MonitorModule/DateTimeModule/DateTimeModule.cpp \
		src/MonitorModule/MachineUserNameModule/MachineUserNameModule.cpp \
		src/MonitorDisplay/NCurses.cpp \
		src/MonitorDisplay/myPanel.cpp \

NAME 	=	mygkrellm

NAMET	=	mygkrellmTest

OBJS	=	$(SRCS:.cpp=.o)

SRCT	=	src/mainTest.cpp \
		src/GKrellM.cpp \
		src/MonitorCore/MonitorCore.cpp \
		src/MonitorModule/MonitorModule.cpp \
		src/MonitorModule/RamModule/RamModule.cpp \
		src/MonitorModule/CpuModule/CpuModule.cpp \
		src/MonitorModule/CpuModule/CpuUsage.cpp \
		src/MonitorModule/OSKernelModule/OSKernelModule.cpp \
		src/MonitorModule/DateTimeModule/DateTimeModule.cpp \
		src/MonitorModule/MachineUserNameModule/MachineUserNameModule.cpp \
		src/MonitorDisplay/NCurses.cpp \
		src/MonitorDisplay/myPanel.cpp \

OBJT	=	$(SRCT:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(CXXFLAGS) $(OBJS) $(LIB)

test:		$(OBJT)
		$(CC) -o $(NAMET) $(CXXFLAGS) $(OBJT) $(LIB)

clean:
		$(RM) $(OBJS)
		$(RM) $(OBJT)

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAMET)

re:		fclean all
