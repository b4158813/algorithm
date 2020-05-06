#include<stdio.h>
#include<algorithm>
using namespace std;
pair <int,int> box[6];//注意书写方式
int i;
int main(){
    while(1){
        for(i=0;i<6;i++){
            if(scanf("%d%d",&box[i].first,&box[i].second)!=2) return 0;
            if(box[i].first>box[i].second)
                swap(box[i].first,box[i].second);
        }
        sort(box,box+6);//我试了一下，此处排序是按照先first递增，其次second递增排序
        puts(box[0].first==box[1].first&&box[1].first==box[2].first&&box[2].first==box[3].first&&
             box[0].second==box[1].second&&box[1].second==box[4].first&&box[4].first==box[5].first&&
             box[2].second==box[3].second&&box[3].second==box[4].second&&box[4].second==box[5].second?
             "POSSIBLE":"IMPOSSIBLE");
    }
    return 0; 
} 

