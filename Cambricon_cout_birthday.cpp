//输入：yy mm dd id, id为int.
//按mm dd year id 大小顺序输出生日  
/*
test case 
5
2016 3 20 0
2017 2 2 1
2016 3 10 2
2017 12 15 10
2017 12 15 8
*/

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<string> birthday;
    int yy,mm,dd,id;
    for(int i=0;i<n;i++)
    {
        cin>>yy>>mm>>dd>>id;
        string temp="";
        if(mm<10)
            temp+="0"+to_string(mm);
        else temp+=to_string(mm);
        if(dd<10)
            temp+="0"+to_string(dd);
        else temp+=to_string(dd);
        temp+=to_string(yy);  // temp+=to_string(yy)+to_string(id); 原先未对id进行排序，case通过60%

        int idAdd0=32-(int)to_string(id).size();    //将id转换用32位字符串表示
        int j=0;
        while(j<idAdd0){
            temp+="0";
            j++;
        }
        temp+=to_string(id);
        birthday.push_back(temp);
    }
    
    sort(birthday.begin(),birthday.end());
    for(int i=0;i<(int)birthday.size();i++){
        string temp = birthday[i];
        //cout<<temp<<endl;
        int month,day,year,idnum;
        month=stoi(temp.substr(0,2));
        day=stoi(temp.substr(2,2));
        year=stoi(temp.substr(4,4));
        idnum=stoi(temp.substr(8,(int)temp.size()-8));
        cout<<month<<" "<<day<<" "<<year<<" "<<idnum<<endl;
    }
    return 0;
}
