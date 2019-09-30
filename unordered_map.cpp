#include<iostream>
#include<vector>
#include<list>

using namespace std;


#define SIZE 100

template <class A,class B>
class unordered_map{

private:
	
	vector< list <pair <A, B> > > map;

public:

	unordered_map() {
		map.resize(SIZE);
	}

	int calculate_hash(int key) {

	    key = ((key >> 16) ^ key) * 0x45d9f3b;
	    key = ((key >> 16) ^ key) * 0x45d9f3b;
	    key = (key >> 16) ^ key;
	    return key;

	}



	int calculate_hash(string key)
	{

       int seed = 131; 
       unsigned long hash = 0;
       for(int i = 0; i < key.length(); i++)
       {
          hash = (hash * seed) + key[i];
       }
    
       return hash;

   } 

	


	void insert(A key,B value)
	{
		int flag=0;
		int index = calculate_hash(key)%SIZE;
		for(auto it=map[index].begin();it!=map[index].end();it++)
		{
			if(it->first==key)
			 {
			 	it->second=value;
			 	flag=1;
			 	break;
			 }

		}


			 if(!flag)
			  map[index].push_back(make_pair(key,value));	

	}



	void deleteEle(A key, B value)
	{
		int flag=0;
		int index = calculate_hash(key)%SIZE;

		for(auto it=map[index].begin();it!=map[index].end();it++)
		{
			if(it->first==key)
			 {
			 	flag=1;
			 	map[index].remove(make_pair(key,value));
			 	break;
			 }
		}

		if(!flag)
		 cout<<"element doesnot exist";

	}


	void search(A key)
	{
		int flag=0;
		int index = calculate_hash(key)%SIZE;

		for(auto it=map[index].begin();it!=map[index].end();it++)
		{
			if(it->first==key)
			 {
			 	cout<<"value is"<<it->second;
			 	return ;
			 }
		}


		 cout<<"element doesnot exist";


	}


	void display()
	{
		for(int i = 0; i < map.size(); i++) {
			for(auto it=map[i].begin();it!=map[i].end();it++) {
				cout<< it->first << " " << it->second;
			}
		}
	}
};

int main()
{
	unordered_map<string,int> mp;
	mp.insert("hey",12);
	mp.display();
	mp.search("hey");
	mp.deleteEle("bi",9);

	return 0;
}
