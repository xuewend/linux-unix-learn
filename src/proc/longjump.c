/*
 * longjump.c
 *
 *  Created on: Aug 17, 2016
 *      Author: fishmov
 */

/**
 * 函数跳转语句
 * setjmp(),设置一个跳转点，如果返回0，表示初始调用，其他则由longjump设定的值
 */

#include <setjmp.h>
#include "../lib/tlpi_hdr.h"

static jmp_buf jmpenv;

static void f2(void) {
	longjmp(jmpenv, 2);
}

static void f1(int argc) {
	if (argc == 1) {
		longjmp(jmpenv, 1);
	}

	f2();
}

int main(int argc, char *argv[]) {
	switch (setjmp(jmpenv)) {
	case 0: /* This is the return after the initial setjmp() */
		printf("Calling f1() after initial setjmp()\n");
		f1(argc); /* Never returns... */
		break;

	case 1:
		printf("We jumped back from f1()\n");
		break;

	case 2:
		printf("We jumped back from f2()\n");
		break;
	}

	exit(EXIT_SUCCESS);
}
