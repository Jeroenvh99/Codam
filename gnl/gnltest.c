#include<stdio.h>
#include"get_next_line.h"

int main(){
	int fd = open("empty.txt", O_RDONLY);
	char *str = "";
	printf("test invalid fd\n");
	str = get_next_line(-13);
	printf("nl: %s", str);
	str = ""
	printf("test empty.txt\n")
	while (str){
		str = get_next_line(fd);
		printf("nl: %s", str);
		free(str);
	}
	close(fd);
	fd = open("nl.txt", O_RDONLY);
	str = ""
	printf("test nl.txt\n")
	while (str){
		str = get_next_line(fd);
		printf("nl: %s", str);
		free(str);
	}
	close(fd);
	fd = open("multiple_nl.txt", O_RDONLY);
	str = ""
	printf("test multiple_nl.txt\n")
	while (str){
		str = get_next_line(fd);
		printf("nl: %s", str);
		free(str);
	}
	close(fd);
	fd = open("nl_line_nl.txt", O_RDONLY);
	str = ""
	printf("test nl_line_nl.txt\n")
	while (str){
		str = get_next_line(fd);
		printf("nl: %s", str);
		free(str);
	}
	return (0);
}