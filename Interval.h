#ifndef Interval_h
#define Interval_h

#include <iostream>
#include <chrono>
#include <string>
#include <thread>

/* // Usage
std::chrono::seconds s(10);
std::chrono::milliseconds ms(100);
cout << s << "s" << '\n';
cout << ms << "ms" << '\n';
cout << ms.count() << '\n';  //equal

auto now = std::chrono::system_clock::now();
cout << now ;

cout << current();

*/
template< class T, class U>
std::ostream& operator<<(std::ostream& os,const std::chrono::duration<T,U >& dur)
{ 
  os << dur.count();
  return os; 
}

template<class T ,class U>
std::ostream& operator<<( std::ostream& os,const std::chrono::time_point<T,U>& point )
{
  std::time_t strtime = std::chrono::system_clock::to_time_t( point);

  os << "epoch:" <<point.time_since_epoch() 
    << " = " 
    << std::ctime(&strtime);
  return os; 
}


/* 
// Usage

#include <unistd.h>
#include <vector>
int main(int argc ,char **argv){
	using namespace std;
	using namespace Tool;

  {
  	Interval t1( "local intreval" )
  	sleep(1);
  }

	{
		Interval t2 , t3; // using default name
	}

	{
		// vector record
		vector<Interval> v;
		v.reserve(2); // avoid copy constructor

		v.push_back( Interval("1") );
		v.push_back( Interval("2") );

		// cal copy constructor 2 times
		v.push_back( Interval("3") );
		v.push_back( Interval("4") );
	}

	{
		vector<Interval> vv;
		vv.reserve(10);
		Interval t1;
		
		//using rvalue ref , t1 message only show 1 time.
		vv.push_back( t1 );
	}

}
*/




/* Useage */
/* 
 * Tool::sleep_for( 20s );
 * Tool::sleep_until( Tool::Clock::now()+5s );
 */
namespace Tool{
	using Clock = std::chrono::system_clock;
	using Time = std::chrono::time_point<Clock>;

	const auto& current_count = 
		[]{ return  Clock::now().time_since_epoch().count();} ;

	/* using namespace std::chrono_literals; */
	//"y" "d" "h" "min" "s" "ms" "us" "ns" 
	// ex: 3d, 5h,  12.2ms

	// shorten function name()
	template<class Rep, class Period>
		void sleep_for( const std::chrono::duration<Rep,Period>& sleep_duration)
	{ std::this_thread::sleep_for( sleep_duration ); }

  /* const auto &sleep_for = [](const auto& time) */
  /*           { std::this_thread::sleep_for(time); }; */

	// shorten function name()
	template<class Clock, class Duration>
		void sleep_until(const std::chrono::time_point<Clock, Duration>& __atime)
	{ 
		std::this_thread::sleep_until(__atime ); }

	// for: use Duration< int or float?  ,  time unit>
	// until: use time_point< Clock? system ot other,  Duration unint >
}



namespace Tool{
	using namespace std::chrono;
	using namespace std;

	const auto& current = Clock::now;
	class Interval{
		private:
			static u_int countId;
			bool ref = true;
			time_point<system_clock, nanoseconds> interval;
			string message;
		public:
			// Default name: Record 1, Record 2 .....
			Interval():message("Record ") { 
				++countId; message += to_string(countId); 
				log(); line();
				interval = system_clock::now();
			}

			// Contr.
			Interval(string message)
			:message(message){
				log();line();
				interval = system_clock::now();
			}

			// Copy.
			Interval(const Interval& other )
			:interval(other.interval) ,message(other.message) {
				this->message = other.message + " (copy)";
        log();line();
			}

			// Rvalue ref. Avoid showing message of <other> again.
			Interval(Interval&& other)
			:interval(other.interval) ,message(other.message) {
				other.ref = false;
			}

			~Interval(){
				if(ref){
					duration<double> diff = system_clock::now() - interval;
					log();
					cout << "--> cost " << diff.count() << " sec.\n";
				}
			}

			void log() { cout << "\n============ " << message << " ============\n"; }
      void line() { cout << string(message.size()+2 ,'=') << "========================\n"; }

	};

	uint Interval::countId = 0;
}

#endif 
