#include<stdio.h>

struct process{
    int pid, at, bt, ct, tat, wt, rt;
    int type;
};

int main(){
    int n, i, time = 0, remain, done;
    float avg_wt = 0, avg_tat = 0;

    struct process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time, and type (0 = System / 1 = User) for P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].type);
        p[i].rt = p[i].bt;
    }

    remain = n;

    while(remain != 0){
        done = 1;

        for(i = 0; i < n; i++){
            if(p[i].rt > 0 && p[i].at <= time && p[i].type == 0){
                done = 0;

                time++;
                p[i].rt--;

                if(p[i].rt == 0){
                    p[i].ct = time;
                    remain--;
                }

                break;
            }
        }

        if(done == 1){
            for(i = 0; i < n; i++){
                if(p[i].rt > 0 && p[i].at <= time && p[i].type == 1){
                    done = 0;

                    time++;
                    p[i].rt--;

                    if(p[i].rt == 0){
                        p[i].ct = time;
                        remain--;
                    }

                    break;
                }
            }
        }

        if(done == 1){
            time++;
        }
    }

    for(i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("\nPID\tType\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++){
        printf("P%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               (p[i].type == 0) ? "System" : "User",
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tat/n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt/n);

    return 0;
}
