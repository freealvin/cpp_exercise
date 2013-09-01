#include<iostream>
using namespace std;

class Database{
	public:
		virtual void connect()const
		{
		}
		
		virtual void query(const char * sql)const{
			
		}
};

class SqlServer : public Database{
	void connect()const{
		cout << "连接Sqlserver成功" << endl; 
	}
	
	void query(const char * sql)const{
		cout << "Sqlserver 执行查询语句：" << sql << endl;	
	}
};	

class Access : public Database{
	void connect()const{
		cout << "连接Access成功" << endl; 
	}
	
	void query(const char * sql)const{
		cout << "Access 执行查询语句：" << sql << endl;	
	}
};	


class Oracle : public Database{
	void connect()const{
		cout << "连接Oracle成功" << endl; 
	}
	
	void query(const char * sql)const{
		cout << "Oracle 执行查询语句：" << sql << endl;	
	}
};	
class Program
{
	public:
		void visit(Database* p){
			p->connect();
			p->query("select * from t");		
		}

};

int main()
{
	Database *p1 = new Access;
	Database *p2 = new SqlServer;
	Database *p3 = new Oracle;

	Program pro;
	pro.visit(p1);

	pro.visit(p2);
	
	pro.visit(p3);
	return 0;
}
