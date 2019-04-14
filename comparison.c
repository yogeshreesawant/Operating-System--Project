#include <stdio.h>
#include<string.h>
int main() 
{
    //DECLARING OF THE VARIABLES FOR PROCESS
    //sjf preemptive  
    int at[10], bt[20], temp[10];
    int i, s, count = 0, time,n;
    double wt = 0, tat = 0, end;
    float awt, atat;
    
    //sjf non-preemptive
    int i1,n1,p[10],min,k=1,bt_1=0;
    int bt1[20],temp1,j1,at1[10],wt1[10],tt1[10],ta1=0,sum1=0;
    float awt1=0,atat1=0,tsum1=0,wsum1=0;
    
    //priority
    int bt2[20],at2[10],n2,i2,j2,temp2,p1[10],st1[10],ft1[10],wt2[10],ta2[10];
    int twt1=0,ttat1=0;
    float awt2,atat2;
    char pn[10][10],t[10];
    
    //COMPARISON
    float lowawt, lowatat;
    
    printf("\n*******************PROCESS SCHEDULING ALGORITHMS*******************\n");
    
    //ENTRY OF TOTAL NUMBER OF PROCESSES
    //printf("\nEnter the Total Number of Processes : \t");
    scanf("%d", &n); //sjf preemptive
    n1 = n; //sjf non-preemptive
    n2 = n; //priority
    
    //VALUES OF PROCESS NAME, BURST TIME, ARRIVAL TIME AND PRIORITY OF THE PROCESSES
    //priority
    for(i2=0; i2<n2; i2++)
    {
       // printf("Enter process name,Arrival time,Burst time & Priority : ");
        scanf("%s%d%d%d",pn[i2],&at2[i2],&bt2[i2],&p1[i2]);
    }
    
    //PRINT THE VALUE IN TABLE
    printf("\nPname \t Arrival time \t Burst time \t Priority \n");
    for(i2=0; i2<n2; i2++)
        printf("\n%s \t\t%5d \t\t%5d \t\t%5d \t\t\n",pn[i2],at2[i2],bt2[i2],p1[i2]);
    
    //sjf preemptive
    for(i = 0; i < n; i++)
    {
        at[i] = at2[i];
        bt[i] = bt2[i];
        temp[i] = bt[i];
        }
    
    //sjf non-preemptive
    for(i1=0;i1<n1;i1++)    
    {
        bt1[i1] = bt2[i1];
        at1[i1] = at2[i1];
    }
    
    //sjf preemptive
    bt[9] = 9999;  
    for(time = 0; count != n; time++)
    {
        s = 9;
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && bt[i] < bt[s] && bt[i] > 0)
            {
                s = i;
            }
        }
        bt[s]--;
        if(bt[s] == 0)
        {
            count++;
            end = time + 1;
            wt = wt + end - at[s] - temp[s];
            tat = tat + end - at[s];
        }
    }
    awt = wt / n; 
    atat = tat / n;
    
    printf("\n*******************SJP PREEMPTIVE PROCESS SCHEDULING ALGORITHMS*******************\n");
    
    printf("\n\nAverage Waiting Time:\t%lf\n", awt);
    printf("Average Turnaround Time:\t%lf\n", atat);
    //END of SJF PREEMPTIVE
    
    //sjf non-preemptive
    /*Sorting According to Arrival Time*/
    for(i1=0;i1<n1;i1++)
    {
        for(j1=0;j1<n1;j1++)
        {
            if(at1[i1]<at1[j1])
            {
                temp1=p[j1];
                p[j1]=p[i1];
                p[i1]=temp1;
                temp1=at1[j1];
                at1[j1]=at1[i1];
                at1[i1]=temp1;
                temp1=bt1[j1];
                bt1[j1]=bt1[i1];
                bt1[i1]=temp1;
            }
        }
    }

    /*Arranging the table according to Burst time,
    Execution time and Arrival Time
    Arrival time <= Execution time
    */

    for(j1=0;j1<n1;j1++)
    {
        bt_1=bt_1+bt1[j1];
        min=bt1[k];
        for(i1=k;i1<n1;i1++)
        {
            if (bt_1>=at1[i1] && bt1[i1]<min)
            {
                temp1=p[k];
                p[k]=p[i1];
                p[i1]=temp1;
                temp1=at1[k];
                at1[k]=at1[i1];
                at1[i1]=temp1;
                temp1=bt1[k];
                bt1[k]=bt1[i1];
                bt1[i1]=temp1;
            }
        }
        k++;
    }
    wt1[0]=0;
    for(i1=1;i1<n1;i1++)
    {
        sum1=sum1+bt1[i1-1];
        wt1[i1]=sum1-at1[i1];
        wsum1=wsum1+wt1[i1];
    }

    awt1=(wsum1/n1);
    for(i1=0;i1<n1;i1++)
    {
        ta1=ta1+bt1[i1];
        tt1[i1]=ta1-at1[i1];
        tsum1=tsum1+tt1[i1];
    }

    atat1=(tsum1/n1);

    /*printf("************************");
    printf("\n RESULT:-");
    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
    for(i1=0;i1<n1;i1++)
    {
        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i1],bt1[i1],at1[i1],wt1[i1],tt1[i1]);
    }
    */
    printf("\n*******************SJP NON-PREEMPTIVE PROCESS SCHEDULING ALGORITHMS*******************\n");

    printf("\n\nAVERAGE WAITING TIME : %lf",awt1);
    printf("\nAVERAGE TURN AROUND TIME : %lf",atat1);
    //END of SJF NON-PREEMPTIVE
    
    //priority
    for(i2=0; i2<n2; i2++)
        for(j2=0; j2<n2; j2++)
        {
            if(p1[i2]<p1[j2])
            {
                temp2=p1[i2];
                p1[i2]=p1[j2];
                p1[j2]=temp2;
                temp2=at2[i2];
                at2[i2]=at2[j2];
                at2[j2]=temp2;
                temp2=bt2[i2];
                bt2[i2]=bt2[j2];
                bt2[j2]=temp2;
                strcpy(t,pn[i2]);
                strcpy(pn[i2],pn[j2]);
                strcpy(pn[j2],t);
            }
        }
    for(i2=0; i2<n2; i2++)
 
    {
 
        if(i2==0)
        {
            st1[i2]=at2[i2];
            wt2[i2]=st1[i2]-at2[i2];
            ft1[i2]=st1[i2]+bt2[i2];
            ta2[i2]=ft1[i2]-at2[i2];
        }
        else
        {
            st1[i2]=ft1[i2-1];
            wt2[i2]=st1[i2]-at2[i2];
            ft1[i2]=st1[i2]+bt2[i2];
            ta2[i2]=ft1[i2]-at2[i2];
        }
        twt1+=wt2[i2];
        ttat1+=ta2[i2];
    }
    awt2=(float)twt1/n2;
    atat2=(float)ttat1/n2;
    /*printf("\nPname\tArrival time\tBurst time\tPriority\tWaiting Time\tTAT");
    for(i2=0; i2<n2; i2++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i2],at2[i2],bt2[i2],p1[i2],wt2[i2],ta2[i2]);
    */
    printf("\n*******************PRIORITY PREEMPTIVE PROCESS SCHEDULING ALGORITHMS*******************\n");

    printf("\nAverage Waiting Time is:%lf",awt2);
    printf("\nAverage Turn Around Time is:%lf",atat2);
    //END of PRIORITY
    
    printf("\n*******************COMPARISON*******************\n");

    lowawt = awt < awt1 ? (awt < awt2 ? awt : awt2) : (awt1 < awt2 ? awt1 : awt2) ;
    lowatat = atat < atat1 ? (atat < atat2 ? atat : atat2) : (atat1 < atat2 ? atat1 : atat2) ;
    
    if(lowawt == awt && lowatat == atat)
        printf("\nSJF PREEMPTIVE PROCESS SCHEDULING ALGORITHM GIVES BETTER RESULT OF ALL PROCESS.");
    else if(lowawt == awt1 && lowatat == atat1)
        printf("\nSJF NON-PREEMPTIVE PROCESS SCHEDULING ALGORITHM GIVES BETTER RESULT OF ALL PROCESS."); 
    else if(lowawt == awt2 && lowatat == atat2)
        printf("\nPRIORITY PROCESS SCHEDULING ALGORITHM GIVES BETTER RESULT OF ALL PROCESS.");
    else
        printf("\nERROR");
    
    return 0;
}
