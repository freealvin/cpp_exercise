/*
 * 荷兰国旗问题描述：
 * 相同的颜色的球放一起，按顺序输出红白蓝三种颜色的球，
 * 可以用012表示，要求只能扫描一次数组
 * 将乱序的红白蓝三色小球排列成有序的红白蓝三色的同颜色在一起的小球组
 *
 * 解决方法：
 * 类似快排partition过程，用三个指针，
 * 前：begin
 * 中：current
 * 后：end
 * current遍历数组
 * 1. current指0，与begin交换，然后current++，begin++
 * 2. current指1，不做任何交换（球不动），然后current++
 * 3. current指2，与end交换，然后current指针不动，end--
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "holand.h"

#define MAX 20
#define DEBUG 1



int
main(void){
	int n;
	int balls[MAX];

	while (scanf("%d", &n) > 0){
		int i;
		for ( i = 0; i < n; i += 1){
			scanf("%d", &balls[i]);
		}

		sort_balls(balls, n);
		display(balls, n);
	}

	return EXIT_SUCCESS;
}




