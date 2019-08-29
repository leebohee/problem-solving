#include <stdio.h>
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

extern void init(void);

extern void insert(int buffer_size, char *buf);

extern int query(int buffer_size, char *buf);

int main(void) {
	//freopen("input.txt", "r", stdin);
	int TestCase; 
	for (scanf("%d", &TestCase); TestCase--;) {
		int Query_N;
		scanf("%d", &Query_N);
		
		init();
		
		static int tc = 0;
		printf("#%d", ++tc);
		
		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);

			if (type == 1) { // insert
				char buf[15] = { 0, };
				scanf("%s", buf);
				
				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;
				
				insert(buffer_size, buf);
			}
			else { // query
				char buf[15] = { 0, };
				scanf("%s", buf);
				
				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}
