#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main()
{
    int cache[100][100],temp[100][100],m,n,i,j,k,set_num;
    int index,check=0,track,hit=0;
    system("color 3F");
    cout<<"\t****Assignment-2****\n\n"<<endl;
    cout<<"\t****N-way set associative cache(LRU)****\n\n"<<endl;
    cout<<"Enter the set associativity of the cache no (n): ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the total number of indices in the cache (m): ";
    cin>>m;
    cout<<endl;
    set_num=m/n;
    cout<<" the total number of set in the cache: ";
    cout<<set_num<<endl;
    for(i=0; i<set_num; i++)
    {
        for(j=0; j<n; j++)
        {
            cache[i][j]=-1;
            temp[i][j]=-1;

        }
    }
//   for(i=0;i<set_num;i++)
//       {
//           for(j=0;j<n;j++){
//           cout<<cache[i][j]<<" ";
//
//           }
//           cout<<endl;
//       }
    int input;
    cout<<"Enter the inputs: ";
    while(cin>>input)
    {
        if(input==-1)
            exit(0);
        else
        {
            int index,ch=0,track,hit=0;
            index=input%set_num;
            //cout<<index<<" ";
            for(i=0; i<n; i++)
            {
                //cout<<i<<" ";

                if(cache[index][i]!=input)
                {
                    check=0;

                }
                else
                {
                    check=1;
                    system("color 2F");
                    cout<<"\nHIT"<<endl;
                    hit=1;
                    track=i;
                    break;
                }
            }
            if(hit==1)
            {
                temp[index][track]=cnt+1;
                cnt++;
                for(k=0; k<set_num; k++)
                {
                    for(j=0; j<n; j++)
                    {
                        cout<<cache[k][j]<<" ";
                    }
                    cout<<endl;
                }

            }

            if(check==0)
            {
                cout<<"\n Miss"<<" ";
                system("color 5F");
                int mini=100000;
                for(i=0; i<n; i++)
                {
                    if(temp[index][i]< mini)
                    {
                        mini=temp[index][i];
                        track=i;
                        // temp[index][i]=cnt+1;
                    }

                }
                cache[index][track]=input;
                temp[index][track]=cnt+1;
                cnt++;
                for(k=0; k<set_num; k++)
                {
                    for(j=0; j<n; j++)
                    {
                        cout<<cache[k][j]<<" ";

                    }
                    cout<<endl;
                }


            }


        }
    }

    return 0;
}
