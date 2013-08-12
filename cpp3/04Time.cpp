#include<iostream>
using namespace std;
class Time
{
	int days;
	int hours;
	int minutes;
	int seconds;
	void adjust();
	public:
		Time(int days, int hours, int minutes, int seconds);
		~Time(){}
		int total_seconds();
		void output();
		Time(int s);
		Time operator+(Time t);
		Time operator-(Time t);
		Time operator*(Time t);
		Time operator/(Time t);
};


Time::Time(int d, int h, int m, int s)
{
	days = d;
	hours = h;
	minutes = m;
	seconds = s;
	
	adjust();
}

void Time::output()
{
	cout<< days << " days, " << hours << " hours, " << minutes << " minutes, "<< seconds << " seconds."<<endl;
}

void Time::adjust()
{
	while(seconds>=60)
	{
		seconds -= 60;
		minutes += 1;
	}

	while(minutes>=60)
	{
		minutes -= 60;
		hours += 1;
	}

	while(hours>=24)
	{
		hours -= 24;
		days += 1;
	}
}

Time::Time(int s)
{
	seconds = s;
	days = hours = minutes = 0;
	adjust();
}

int Time::total_seconds()
{
	return (seconds + minutes*60 + hours*60*60 + days*24*60*60);
}


Time Time::operator+(Time t)
{
	return Time(total_seconds() + t.total_seconds());
}

Time Time::operator-(Time t)
{
	return Time(total_seconds() - t.total_seconds());
}

Time Time::operator*(Time t)
{
	return Time(total_seconds() * t.total_seconds());
}

Time Time::operator/(Time t)
{
	return Time(total_seconds() / t.total_seconds());
}
int main()
{

	Time t(0);
	cout << " first addition "<< endl;
	t = t + Time(2, 13, 40, 20);
	t = t + 2;//2:constructed with Time(int s)
	t.output();

	cout << "Multiply by 2 " << endl;
	t = t * 2;
	t.output();

	cout << " Sub time" << endl;
	t = t - 3600;
	t.output();
	
	return 0;
}
