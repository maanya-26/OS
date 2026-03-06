#include<stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};
int main(){
    int n,i,j;
    float avg_wt=0,avg_tat=0,avg_rt=0;
    struct process p[20],temp;

    printf("enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("enter at and bt for P%d: ",p[i].pid);
        scanf("%d %d" , &p[i].at,&p[i].bt);
    }
    for(i = 0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
     p[0].ct = p[0].at + p[0].bt;
    for(i = 1; i < n; i++){
        if(p[i].at > p[i-1].ct)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = p[i-1].ct + p[i].bt;
    }

    for(i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        p[i].rt = p[i].wt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
        avg_rt += p[i].rt;
    }
    printf("\npid\tat\tbt\tct\ttat\twt\trt\n");

    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt,
               p[i].rt);
    }

    printf("\naverage tat= %.2f", avg_tat/n);
    printf("\naverage wt = %.2f", avg_wt/n);
    printf("\naverage rt = %.2f\n", avg_rt/n);

    return 0;
}
