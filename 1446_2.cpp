#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
typedef struct node{  
    char name[4];  //人名  
    int time;      //通话时间  
    int father;    //父节点  
    int rank;      //秩  
}Node;  
  
typedef struct head{  
    char name[4];  //头领姓名  
    int num;       //人数  
}Head;  
  
Node people[1010];  
Head gang[1010];   //头领  
int num;           //总人数  

int FindSet (int x){//查询节点属于那个集合  
    if (people[x].father != x){  
        people[x].father = FindSet (people[x].father);  
    }  
    return people[x].father;  
}  
  
void Union (int x, int y){//合并两节点  
    x = FindSet (x);  
    y = FindSet (y);  
    if (x == y)  
        return;  
    if (people[x].rank > people[y].rank){  
        people[y].father = x;  
        people[x].rank += people[y].rank;  
    }  
    else{  
        if (people[x].rank == people[y].rank){  
            ++people[y].rank;  
        }  
        people[x].father = y;  
    }  
}  
  
int compare1 (const void * p, const void * q){  
    Node * p1 = (Node *)p;  
    Node * q1 = (Node *)q;  
    return p1->father - q1->father;  
}  
  
int compare2 (const void * p, const void * q){  
    Head * p1 = (Head *)p;  
    Head * q1 = (Head *)q;  
    return strcmp(p1->name, q1->name);  
}  
  
int main(void){  
    int N;  
    int K;  
    char name1[4], name2[4];  
    int time;  
    int i, j, k;  
    int pre;  
    int sum;       //总的通话时间  
  
    while (scanf ("%d%d", &N, &K) != EOF){  
        num = 0;  
        while (N-- != 0){  
            scanf ("%s%s%d", name1, name2, &time);  
            ///////////////////////////////////////////////////////////////////  
            //查询输入姓名是否已在表中，如果不在，添加进表；否则，更新节点信息  
            for (i=0; i<num; ++i){  
                if (strcmp (people[i].name, name1) == 0){  
                    break;  
                }  
            }  
            if (i == num){  
                strcpy (people[i].name, name1);  
                people[i].time = time;  
                people[i].father = i;  
                people[i].rank = 0;  
                ++num;  
            }  
            else{  
                people[i].time += time;  
            }  
            ///////////////////////////////////////////////  
            for (j=0; j<num; ++j){  
                if (strcmp (people[j].name, name2) == 0){  
                    break;  
                }  
            }  
            if (j == num){  
                strcpy (people[j].name, name2);  
                people[j].time = time;  
                people[j].father = j;  
                people[j].rank = 0;  
                ++num;  
            }  
            else{  
                people[j].time += time;  
            }  
            ///////////////////////////////////////////////////////////////////  
            Union (i, j);//合并节点  
        }  
        //最后一次更新各个集合  
        for (i=0; i<num; ++i){  
            FindSet (i);  
        }  
        //按父节点大小排序  
        qsort (people, num, sizeof(Node), compare1);  
        i = j = k = 0;  
        //找到各个集合的头领及人数  
        while (i < num){  
            strcpy(gang[k].name, people[i].name);  
            pre = i;  
            ++j;  
            sum = people[i].time;  
            while ((j < num) && (people[j].father == people[i].father)){  
                if (people[j].time > people[pre].time){  
                    strcpy (gang[k].name, people[j].name);  
                    pre = j;  
                }  
                sum += people[j].time;  
                ++j;  
            }  
            if (j - i > 2 && (sum >> 1) > K){//每个时间在每个人处都加了一遍(即各个时间被加了两遍)，所以sum >> 1  
                gang[k].num = j - i;  
                ++k;  
            }  
            i = j;  
        }  
        printf ("%d\n", k);  
        qsort (gang, k, sizeof(Head), compare2);  
        for (i=0; i<k; ++i){  
            printf ("%s %d\n", gang[i].name, gang[i].num);  
        }  
    }  
  
    return 0;  
}  