#include <stdio.h>


const int process=3,resources=3;
  void calculate_safe_sequence(int [][resources],int [][resources],int [][resources],int *,int *); 

  //calculate need matrix

 void calculate(int need[][resources],int max[][resources],int allocated[][resources]){

     for(int i=0;i<process;i++){
         for(int j=0;j<resources;j++){
             need[i][j]=max[i][j]-allocated[i][j];
                      }
     }
    


 }
 //check request can be granted or not and update accordingly 
void request(int *processarr,int *availbale,int *requestarr,int allocated[][resources],int max[][resources],int index)
{
        int need[process][resources];
             int ava[resources];
                  int alloc[process][resources];
                  //memcpy(ava,availbale,sizeof(availbale));
                   for(int i=0;i<resources;i++)ava[i]=availbale[i];
                  
          for(int i=0;i<process;i++){
         for(int j=0;j<resources;j++){
            alloc[i][j]=allocated[i][j];
                      }
     }
        calculate(need,max,allocated);
       
        
    int j=0;
        for( j=0;j<resources;j++){
            if(requestarr[j]>need[index][j]||requestarr[j]>availbale[j]){
              printf("Request can't be granted for process %d\n",index);
                return ;
            }
        }
        if(j==resources){
            for(int y=0;y<resources;y++){
                    //updation
                    ava[y]-=requestarr[y];
                    alloc[index][y]+=requestarr[y];
                    need[index][y]-=requestarr[y];

            }
        }  
    
      printf("Request can be granted for process %d\n",index);

        calculate_safe_sequence(need,alloc,max,ava,processarr);

}

//calculating safe sequence with updated value
void calculate_safe_sequence(int need[][resources],int allocated[][resources],int max[][resources],int *availbale,int *processarr)

{  //unfinished process
 

     int finish[3]={0,0,0};
    int safe[process];
    int count=0; 
    while(count<process){
        int found=0;
    for(int i=0;i<process;i++){
       
        if(finish[i]==0){
            int g=0;
            for( g=0;g<resources;g++){
                if(need[i][g]>availbale[g]){
                    break;
                }
            }
            if(g==resources){
                for(int y=0;y<resources;y++){
                        availbale[y]+=allocated[i][y];

            }

        finish[i]=1;
        found=1;
        safe[count++]=processarr[i];

            }
    }
    }
    if(found==0){
            printf("OOPS! No safe sequence exist\n");
        return;
    }



    }
    //printing the safe sequenece
  printf("safe sequence is:\n");
        for(int i=0;i<process;i++)printf("%d ",safe[i]);


}
int main() {
    
        //cin>>process>>resources;
        int processarr[3]={0,1,2};
        int availbale[3]={3,2,2};

        
        int allocated[3][3]={
                      {0, 0, 1},
                      {3, 2, 0},
                      {2, 1, 1},
                     };
        int max[3][3]={
                     {8, 4, 3},
                     {6, 2, 0},
                     {3, 3, 3},
                    };
        int number_of_request;
        scanf("%d",&number_of_request);
          int requestarr[resources];
          
            while(number_of_request--){
                int index_of_process;
                    scanf("%d",&index_of_process);
                for(int j=0;j<resources;j++){
                    scanf("%d",&requestarr[j]);
                }

            request(processarr,availbale,requestarr,allocated,max,index_of_process);

            }
       

}
