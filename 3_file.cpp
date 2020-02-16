#include<iostream>
#include<fstream>
using namespace std;

class test
{
public:
	void writedata();
	void readdata();
    void searchword();
	void replaceword();
	void deleteword();
};

void test::writedata()
{
	fstream fp;
	char ch;
	fp.open("it.txt",ios::out|ios::app);
	cin>>ch;
	while (ch!='.')
 	{
 		fp.put(ch);
 		cin>>ch;
 	}
	fp.close();
}

void test::readdata()
{
	fstream fp;
	char ch;
	fp.open("it.txt",ios::in);
	ch=fp.get();
	while(!fp.eof())
	{
		cout<<ch;
		ch=fp.get(); 
	}
	fp.close();
}

void test::searchword()
{
	fstream fp;
	size_t pos;
	string line,word;
	fp.open("it.txt",ios::in);
	cout << "Enter word to search";
	cin>>word;
	//while(getline(fp,line))
	getline(fp,line);
	fp.close();
	pos=line.find(word);
	if(pos!=string::npos)
	{
		cout << "Found!";
	}
	else
	{
		cout << "Not Found.";
	}
}

void test::replaceword()
{
	fstream fp;
	size_t pos;
	string line,old_word,new_word;
	fp.open("it.txt",ios::in);
	cout << "Enter word to be replaced";
	cin>>old_word;
	cout << "Enter word to be replaced by";
	cin>>new_word;
	getline(fp,line);
	fp.close();
	pos=line.find(old_word);
	if(pos!=string::npos)
	{
		line.replace(pos,old_word.length(),new_word);
		fp.open("it.txt",ios::out|ios::trunc);
		fp << line;
		fp.close();
	}
	else
	{
		cout << "Not Found.";
	}
}
 
void test::deleteword()
{
	fstream fp;
	size_t pos;
	string line,old_word,new_word;
	fp.open("it.txt",ios::in);
	cout << "Enter word to be deleted";
	cin>>old_word;
	new_word="";
	getline(fp,line);
	fp.close();
	pos=line.find(old_word);
	if(pos!=string::npos)
	{
		line.replace(pos,old_word.length(),new_word);
		fp.open("it.txt",ios::out|ios::trunc);
		fp << line;
		fp.close();
	}
	else
	{
		cout << "Not Found.";
	}
}
 
int main()
{
  test ob;
  int ch;
  do
  {
   cout<<"\n1.Write\n2.Read\n3.Search\n4.Replace\n5.Delete\n6.Exit";
   cout<<"\nEnter your choice= ";
   cin>>ch;
   switch(ch)
   {
    case 1:
	ob.writedata();
    break;
    case 2:
	ob.readdata();
    break;
    case 3:
	ob.searchword();
    break;
    case 4:
	ob.replaceword();
    break;
    case 5:
	ob.deleteword();
    break;
   }
  }while(ch!=6);
}
