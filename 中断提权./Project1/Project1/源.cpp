#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
DWORD go_tmp;

void __declspec(naked) IdtEntry() {
	__asm {
		mov eax, dword ptr ds : [0x8003f400] ;
		mov go_tmp, eax;
		iretd
	}
}
void go() {
	__asm {
		int 0x20;
	}
}
//
//
//

int main() {
	if ((DWORD)IdtEntry != 0x401040) {
		printf("wrong addr: %p", IdtEntry);
		exit(-1);
	}
	printf("%p\n", IdtEntry);
	go();
	printf("%p\n", go_tmp);
	system("pause");
	return 0;
}